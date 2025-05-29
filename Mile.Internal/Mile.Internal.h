/*
 * PROJECT:   Mouri Internal Library Essentials
 * FILE:      Mile.Internal.h
 * PURPOSE:   Definition for the Windows Internal API
 *
 * LICENSE:   The MIT License
 *
 * MAINTAINER: MouriNaruto (Kenji.Mouri@outlook.com)
 */

#ifndef MILE_WINDOWS_INTERNAL
#define MILE_WINDOWS_INTERNAL

#include "Mile.Internal.Implementation/phnt_windows.h"

#include <SDKDDKVer.h>

#ifdef _MSC_VER
#if (_MSC_VER >= 1200)
#pragma warning(push)
// nonstandard extension used : nameless struct/union
#pragma warning(disable:4201)
// 'struct_name' : structure was padded due to __declspec(align())
#pragma warning(disable:4324)
// 'enumeration': a forward declaration of an unscoped enumeration must have an
// underlying type (int assumed)
#pragma warning(disable:4471)
#endif // (_MSC_VER >= 1200)
#endif // _MSC_VER

#ifndef PHNT_MODE
#ifdef _KERNEL_MODE
#define PHNT_MODE PHNT_MODE_KERNEL
#else
#define PHNT_MODE PHNT_MODE_USER
#endif
#endif // !PHNT_MODE

#ifndef PHNT_VERSION
#if (NTDDI_VERSION >= NTDDI_WIN11_GE)
#define PHNT_VERSION PHNT_WINDOWS_11_24H2
#elif (NTDDI_VERSION >= NTDDI_WIN10_NI)
#define PHNT_VERSION PHNT_WINDOWS_11_23H2
#elif (NTDDI_VERSION >= NTDDI_WIN10_CO)
#define PHNT_VERSION PHNT_WINDOWS_11
#elif (NTDDI_VERSION >= NTDDI_WIN10_VB)
#define PHNT_VERSION PHNT_WINDOWS_10_22H2
#elif (NTDDI_VERSION >= NTDDI_WIN10_19H1)
#define PHNT_VERSION PHNT_WINDOWS_10_19H2
#elif (NTDDI_VERSION >= NTDDI_WIN10_RS5)
#define PHNT_VERSION PHNT_WINDOWS_10_RS5
#elif (NTDDI_VERSION >= NTDDI_WIN10_RS4)
#define PHNT_VERSION PHNT_WINDOWS_10_RS4
#elif (NTDDI_VERSION >= NTDDI_WIN10_RS3)
#define PHNT_VERSION PHNT_WINDOWS_10_RS3
#elif (NTDDI_VERSION >= NTDDI_WIN10_RS2)
#define PHNT_VERSION PHNT_WINDOWS_10_RS2
#elif (NTDDI_VERSION >= NTDDI_WIN10_RS1)
#define PHNT_VERSION PHNT_WINDOWS_10_RS1
#elif (NTDDI_VERSION >= NTDDI_WIN10_TH2)
#define PHNT_VERSION PHNT_WINDOWS_10_TH2
#elif (NTDDI_VERSION >= NTDDI_WIN10)
#define PHNT_VERSION PHNT_WINDOWS_10
#elif (NTDDI_VERSION >= NTDDI_WINBLUE)
#define PHNT_VERSION PHNT_WINDOWS_8_1
#elif (NTDDI_VERSION >= NTDDI_WIN8)
#define PHNT_VERSION PHNT_WINDOWS_8
#elif (NTDDI_VERSION >= NTDDI_WIN7)
#define PHNT_VERSION PHNT_WINDOWS_7
#elif (NTDDI_VERSION >= NTDDI_VISTA)
#define PHNT_VERSION PHNT_WINDOWS_VISTA
#elif (NTDDI_VERSION >= NTDDI_WS03)
#define PHNT_VERSION PHNT_WINDOWS_SERVER_2003
#elif (NTDDI_VERSION >= NTDDI_WINXP)
#define PHNT_VERSION PHNT_WINDOWS_XP
#else
#define PHNT_VERSION PHNT_WINDOWS_ANCIENT
#endif
#endif // !PHNT_VERSION

#include "Mile.Internal.Implementation/phnt.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#if (PHNT_MODE != PHNT_MODE_KERNEL)

#include "Mile.Internal.Implementation/ntafd.h"
#include "Mile.Internal.Implementation/ntgdi.h"
#include "Mile.Internal.Implementation/ntintsafe.h"
#include "Mile.Internal.Implementation/ntsmss.h"
#include "Mile.Internal.Implementation/ntstrsafe.h"
#include "Mile.Internal.Implementation/smbios.h"
#include "Mile.Internal.Implementation/subprocesstag.h"
#include "Mile.Internal.Implementation/usermgr.h"
#include "Mile.Internal.Implementation/winsta.h"
#include <cfg.h>

#endif // (PHNT_MODE != PHNT_MODE_KERNEL)

#ifdef __cplusplus
}
#endif // __cplusplus

#if (PHNT_MODE != PHNT_MODE_KERNEL)

#pragma comment(lib,"ntdll.lib")
#pragma comment(lib,"samlib.lib")
#pragma comment(lib,"winsta.lib")

#endif // (PHNT_MODE != PHNT_MODE_KERNEL)

#ifdef _MSC_VER
#if (_MSC_VER >= 1200)
#pragma warning(pop)
#endif // (_MSC_VER >= 1200)
#endif // _MSC_VER

#endif // !MILE_WINDOWS_INTERNAL
