// TestHid.cpp: 定义控制台应用程序的入口点。
//


#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include "UsbDll.h"

// Headers needed for sleeping.
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


#include <iostream>
using namespace std;

static CRITICAL_SECTION _locker;
static BOOL _isLocker = FALSE;


int(__stdcall MyCallBack)(DWORD dwType, void* pData, void* pParam)
{
	if (_isLocker) return 0;
	EnterCriticalSection(&_locker);
	if (_isLocker) return 0;
	_isLocker = TRUE;
	LeaveCriticalSection(&_locker);

	cout << "++++++++ " << (int)(pParam) << endl;
	Sleep(5000);
	cout << "-------- end" << endl;

	_isLocker = FALSE;

	return 0;
}

int(__stdcall GetCPUCallbackFun)(DWORD dwType, void* pData, void* pParam) {

	float* p = (float*)pParam;
	*p = 4.8;

	return 0;
}

int(__stdcall GetModeCallbackFunc)(DWORD dwType, void* pData, void* pParam) {
	int* p = (int*)pParam;
	*p = 1;

	return 0;
}

int(__stdcall GetOverLockStateCallbackFunc)(DWORD dwType, void* pData, void* pParam) {
	int* p = (int*)pParam;
	*p = 1;

	return 0;
}

void MyTest() {
	InitializeCriticalSection(&_locker);

	int select;

	if (!Init()) {

		cout << "0: Exit" << endl;
		cout << "1: SetFq" << endl;
		cout << "2: SetMode" << endl;
		cout << "3: SetState" << endl;

		RegisterOverLock(&MyCallBack, (void*)NULL);
		RegisterGetOverLockState(&GetOverLockStateCallbackFunc, (void*)NULL);
		RegisterGetCPU(&GetCPUCallbackFun, (void*)NULL);
		RegisterGetMode(&GetModeCallbackFunc, (void*)NULL);

		do
		{
			cin >> select;

			switch (select) {
			case 1:
				cout << "vvvvvvvvvvvvvvvvvv SetFq" << endl;
				SetFq(3);
				cout << "****************** End SetFq" << endl;
				break;
			case 2:
				cout << "vvvvvvvvvvvvvvvvvv SetMode" << endl;
				SetMode(1);
				cout << "****************** End SetMode" << endl;
				break;
			case 3:
				cout << "vvvvvvvvvvvvvvvvvv SetState" << endl;
				SetOverLockState(1);
				cout << "****************** End SetState" << endl;
				break;

			default:

				break;
			}

		} while (select);


		Release();

		DeleteCriticalSection(&_locker);

		cout << "To be Exit!!!!!!!!!!!!!!!!" << endl;
		Sleep(2000);
	}
}
int main()
{
	MyTest();

	/*****************************************/
	getchar();

	return 0;
}





