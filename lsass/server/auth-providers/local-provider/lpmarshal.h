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
 *        lpmarshal.h
 *
 * Abstract:
 *
 *        BeyondTrust Security and Authentication Subsystem (LSASS)
 *
 *        Local Authentication Provider (Defines)
 *
 *        Marshal from DIRECTORY structures to lsass info levels
 *
 * Authors: Krishna Ganugapati (krishnag@likewisesoftware.com)
 *          Sriram Nambakam (snambakam@likewisesoftware.com)
 */

#ifndef __LP_MARSHAL_H__
#define __LP_MARSHAL_H__

DWORD
LocalMarshalAttrToInteger(
    PDIRECTORY_ENTRY pEntry,
    PWSTR            pwszAttrName,
    PDWORD           pdwValue
    );

DWORD
LocalMarshalAttrToLargeInteger(
    PDIRECTORY_ENTRY pEntry,
    PWSTR            pwszAttrName,
    PLONG64          pllValue
    );

DWORD
LocalMarshalAttrToANSIString(
    PDIRECTORY_ENTRY pAttr,
    PWSTR            pwszAttrName,
    PSTR*            ppszValue
    );

DWORD
LocalMarshalAttrToUnicodeString(
    PDIRECTORY_ENTRY pEntry,
    PWSTR            pwszAttrName,
    PWSTR*           ppwszValue
    );

DWORD
LocalMarshalAttrToANSIFromUnicodeString(
    PDIRECTORY_ENTRY pAttr,
    PWSTR            pwszAttrName,
    PSTR*            ppszValue
    );

DWORD
LocalMarshalAttrToOctetStream(
    PDIRECTORY_ENTRY pAttr,
    PWSTR            pwszAttrName,
    PBYTE*           ppData,
    PDWORD           pdwDataLen
    );

DWORD
LocalMarshalAttrToBOOLEAN(
    PDIRECTORY_ENTRY pAttr,
    PWSTR            pwszAttrName,
    PBOOLEAN         pbValue
    );

DWORD
LocalMarshalAttrToSid(
    PDIRECTORY_ENTRY  pEntry,
    PWSTR             pwszAttrName,
    PSID             *ppSid
    );

DWORD
LocalMarshalEntryToSecurityObject(
    PDIRECTORY_ENTRY pEntry,
    PLSA_SECURITY_OBJECT* ppObject
    );

#endif /* __LP_MARSHAL_H__ */
