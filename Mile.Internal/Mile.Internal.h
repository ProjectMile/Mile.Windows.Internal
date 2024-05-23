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
#define PHNT_VERSION PHNT_WIN11_24H2
#elif (NTDDI_VERSION >= NTDDI_WIN10_NI)
#define PHNT_VERSION PHNT_WIN11_23H2
#elif (NTDDI_VERSION >= NTDDI_WIN10_CO)
#define PHNT_VERSION PHNT_WIN11
#elif (NTDDI_VERSION >= NTDDI_WIN10_VB)
#define PHNT_VERSION PHNT_WIN10_22H2
#elif (NTDDI_VERSION >= NTDDI_WIN10_19H1)
#define PHNT_VERSION PHNT_19H2
#elif (NTDDI_VERSION >= NTDDI_WIN10_RS5)
#define PHNT_VERSION PHNT_REDSTONE5
#elif (NTDDI_VERSION >= NTDDI_WIN10_RS4)
#define PHNT_VERSION PHNT_REDSTONE4
#elif (NTDDI_VERSION >= NTDDI_WIN10_RS3)
#define PHNT_VERSION PHNT_REDSTONE3
#elif (NTDDI_VERSION >= NTDDI_WIN10_RS2)
#define PHNT_VERSION PHNT_REDSTONE2
#elif (NTDDI_VERSION >= NTDDI_WIN10_RS1)
#define PHNT_VERSION PHNT_REDSTONE
#elif (NTDDI_VERSION >= NTDDI_WIN10_TH2)
#define PHNT_VERSION PHNT_THRESHOLD2
#elif (NTDDI_VERSION >= NTDDI_WIN10)
#define PHNT_VERSION PHNT_THRESHOLD
#elif (NTDDI_VERSION >= NTDDI_WINBLUE)
#define PHNT_VERSION PHNT_WINBLUE
#elif (NTDDI_VERSION >= NTDDI_WIN8)
#define PHNT_VERSION PHNT_WIN8
#elif (NTDDI_VERSION >= NTDDI_WIN7)
#define PHNT_VERSION PHNT_WIN7
#elif (NTDDI_VERSION >= NTDDI_VISTA)
#define PHNT_VERSION PHNT_VISTA
#elif (NTDDI_VERSION >= NTDDI_WS03)
#define PHNT_VERSION PHNT_WS03
#elif (NTDDI_VERSION >= NTDDI_WINXP)
#define PHNT_VERSION PHNT_WINXP
#else
#define PHNT_VERSION PHNT_WIN2K
#endif
#endif // !PHNT_VERSION

#include "Mile.Internal.Implementation/phnt.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#if (PHNT_MODE != PHNT_MODE_KERNEL)

#include "Mile.Internal.Implementation/ntgdi.h"
#include "Mile.Internal.Implementation/ntsmss.h"
#include "Mile.Internal.Implementation/subprocesstag.h"
#include "Mile.Internal.Implementation/usermgr.h"
#include "Mile.Internal.Implementation/winsta.h"
#include "Mile.Internal.Implementation/ntwmi.h"

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
