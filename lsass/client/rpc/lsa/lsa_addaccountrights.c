/* -*- mode: c; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*-
 * ex: set softtabstop=4 tabstop=8 expandtab shiftwidth=4: *
 * Editor Settings: expandtabs and use 4 spaces for indentation */

/*
 * Copyright © BeyondTrust Software 2004 - 2019
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * BEYONDTRUST MAKES THIS SOFTWARE AVAILABLE UNDER OTHER LICENSING TERMS AS
 * WELL. IF YOU HAVE ENTERED INTO A SEPARATE LICENSE AGREEMENT WITH
 * BEYONDTRUST, THEN YOU MAY ELECT TO USE THE SOFTWARE UNDER THE TERMS OF THAT
 * SOFTWARE LICENSE AGREEMENT INSTEAD OF THE TERMS OF THE APACHE LICENSE,
 * NOTWITHSTANDING THE ABOVE NOTICE.  IF YOU HAVE QUESTIONS, OR WISH TO REQUEST
 * A COPY OF THE ALTERNATE LICENSING TERMS OFFERED BY BEYONDTRUST, PLEASE CONTACT
 * BEYONDTRUST AT beyondtrust.com/contact
 */

/*
 * Copyright (C) BeyondTrust Software. All rights reserved.
 *
 * Module Name:
 *
 *        lsa_addaccountrights.c
 *
 * Abstract:
 *
 *        Remote Procedure Call (RPC) Client Interface
 *
 *        LsaAddAccountRights function
 *
 * Authors: Rafal Szczesniak (rafal@likewise.com)
 */

#include "includes.h"


NTSTATUS
LsaAddAccountRights(
    IN LSA_BINDING     hBinding,
    IN POLICY_HANDLE   hPolicy,
    IN PSID            pAccountSid,
    IN PWSTR          *pAccountRights,
    IN DWORD           NumAccountRights
    )
{
    NTSTATUS ntStatus = STATUS_SUCCESS;
    DWORD err = ERROR_SUCCESS;
    LSA_ACCOUNT_RIGHTS accountRights = {0};
    DWORD i = 0;

    BAIL_ON_INVALID_PTR(hBinding, ntStatus);
    BAIL_ON_INVALID_PTR(hPolicy, ntStatus);
    BAIL_ON_INVALID_PTR(pAccountSid, ntStatus);
    BAIL_ON_INVALID_PTR(pAccountRights, ntStatus);

    err = LwAllocateMemory(
                     sizeof(accountRights.pAccountRight[0]) * NumAccountRights,
                     OUT_PPVOID(&accountRights.pAccountRight));
    BAIL_ON_LSA_ERROR(err);

    for (i = 0; i < NumAccountRights; i++)
    {
        err = LwAllocateUnicodeStringFromWc16String(
                                  &accountRights.pAccountRight[i],
                                  pAccountRights[i]);
        BAIL_ON_LSA_ERROR(err);
    }

    accountRights.NumAccountRights = NumAccountRights;

    DCERPC_CALL(ntStatus, cli_LsaAddAccountRights(
                              (handle_t)hBinding,
                              hPolicy,
                              pAccountSid,
                              &accountRights));
    BAIL_ON_NT_STATUS(ntStatus);

error:
    if (accountRights.pAccountRight)
    {
        for (i = 0; i < accountRights.NumAccountRights; i++)
        {
            LwFreeUnicodeString(&accountRights.pAccountRight[i]);
        }
        LW_SAFE_FREE_MEMORY(accountRights.pAccountRight);
    }

    if (ntStatus == STATUS_SUCCESS &&
        err != ERROR_SUCCESS)
    {
        ntStatus = LwWin32ErrorToNtStatus(err);
    }

    return ntStatus;
}
