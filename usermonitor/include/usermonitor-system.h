/* Editor Settings: expandtabs and use 4 spaces for indentation
 * ex: set softtabstop=4 tabstop=8 expandtab shiftwidth=4: *
 * -*- mode: c, c-basic-offset: 4 -*- */

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
 *        evtfwd-system.h
 *
 * Abstract:
 *
 *        User monitor service for local users and groups
 *
 *        System Headers
 *
 * Authors: Krishna Ganugapati (krishnag@likewisesoftware.com)
 *
 */
#ifdef UNICODE
      #undef UNICODE
#endif


#ifdef WIN32

   #include <windows.h>
   #include <rpc.h>
   #define SECURITY_WIN32
   #include <security.h>
   #include <ntsecapi.h>
#endif

   #include <stdio.h>
   #include <stdlib.h>
   #include <fcntl.h>
   #include <sys/time.h>
   #include <time.h>
   #include <string.h>

#ifdef HAVE_STDBOOL_H
   #include <stdbool.h>
#endif

#ifndef WIN32
  #include <stdarg.h>
  #include <errno.h>	
  #include <netdb.h>
#ifdef HAVE_INTTYPES_H
  #include <inttypes.h>
#endif
  #include <ctype.h>
  #include <wctype.h>
  #include <sys/types.h>
  #include <pthread.h>
  #include <syslog.h>
  #include <signal.h>
  #include <limits.h>
  #include <unistd.h>
  #include <sys/stat.h>
  #include <dirent.h>
  #include <pwd.h>
  #include <grp.h>
  #include <regex.h>
  #include <sys/un.h>
  #include <dlfcn.h>
  #include <arpa/inet.h>
  #include <arpa/nameser.h>
  #include <netinet/in.h>
  #include <resolv.h>

#ifdef HAVE_SOCKET_H
  #include <socket.h>
#endif

#ifdef HAVE_SYS_SOCKET_H
  #include <sys/socket.h>
#endif

#endif

#if HAVE_WC16STR_H
#include <wc16str.h>
#endif

/*
local variables:
mode: c
c-basic-offset: 4
indent-tabs-mode: nil
tab-width: 4
end:
*/
