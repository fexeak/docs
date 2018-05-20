/*******************************************************
HIDAPI - Multi-Platform library for
communication with HID devices.

Alan Ott
Signal 11 Software

8/22/2009

Copyright 2009, All Rights Reserved.

At the discretion of the user of this library,
this software may be licensed under the terms of the
GNU General Public License v3, a BSD-Style license, or the
original HIDAPI license as outlined in the LICENSE.txt,
LICENSE-gpl3.txt, LICENSE-bsd.txt, and LICENSE-orig.txt
files located at the root of the source distribution.
These files may also be found in the public source
code repository located at:
http://github.com/signal11/hidapi .
********************************************************/

/** @file
* @defgroup API hidapi API
*/

#ifndef USBDLL_H__
#define USBDLL_H__

#include <wchar.h>


#define HID_API_EXPORT __declspec(dllexport)
#define HID_API_CALL

#define HID_API_EXPORT_CALL HID_API_EXPORT HID_API_CALL /**< API export and call macro*/

#ifdef __cplusplus
extern "C" {
#endif
	/* ==================================   MY CUSTOM API =========================================*/
	typedef unsigned long DWORD;

#define OVERLOCK_TYPE_START		(0)
#define OVERLOCK_TYPE_STOP		(1)

	typedef int(__stdcall *CallbackFunction)(DWORD dwType, void* pData, void* pParam);
	int HID_API_EXPORT_CALL RegisterOverLock(CallbackFunction OverLockFunc, void* pParam);
	int HID_API_EXPORT_CALL RegisterGetOverLockState(CallbackFunction func, void* pParam);
	int HID_API_EXPORT_CALL RegisterGetCPU(CallbackFunction func, void* pParam);
	int HID_API_EXPORT_CALL RegisterGetMode(CallbackFunction func, void* pParam);

	void HID_API_EXPORT_CALL SetOverLockState(int state);

	void HID_API_EXPORT_CALL SetFq(float fq);

	void HID_API_EXPORT_CALL SetMode(int mode);

	int HID_API_EXPORT_CALL Init();

	int HID_API_EXPORT_CALL Release();

	/* ==================================   MY CUSTOM API END   ===================================*/
#ifdef __cplusplus
}
#endif

#endif

