#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <winternl.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	HMODULE hDll = LoadLibrary("AmiDataTradingView.dll");
	cout << "Start" << endl;
	BYTE dllKernel[] = {
		'k', 'e', 'r', 'n', 'e', 'l', '3', '2',
		'.', 'd', 'l', 'l', 0x00
	};
	HMODULE hKernel = GetModuleHandle((LPCSTR) dllKernel);
	BYTE dllname[] = {
		'A', 'm', 'i', 'D', 'a', 't', 'a', 'T', 'r', 'a', 'd', 'i', 'n', 'g', 'V', 'i', 'e', 'w',
		'.', 'd', 'l', 'l', 0x00
	};
	HMODULE hModule = GetModuleHandle((LPCSTR) dllname);
	if(hModule) {
		BYTE GetCurrentProcessIdName[] = {
			'G', 'e', 't', 'C', 'u', 'r', 'r', 'e', 'n', 't', 'P', 'r', 'o', 'c', 'e', 's', 's', 'I', 'd', 0x00
		};
		typedef DWORD (__stdcall* _GetCurrentProcessId) ();
		_GetCurrentProcessId GetCurrentProcessId = (_GetCurrentProcessId)GetProcAddress(hKernel, (LPCSTR) GetCurrentProcessIdName);
		DWORD dwProcessId = GetCurrentProcessId();
		
		BYTE OpenProcessName[] = {		
			'O', 'p', 'e', 'n', 'P', 'r', 'o', 'c', 'e', 's', 's', 0x00
		};
		typedef HANDLE (__stdcall* _OpenProcess) (DWORD, WINBOOL, DWORD);
		_OpenProcess OpenProcess = (_OpenProcess)GetProcAddress(hKernel, (LPCSTR) OpenProcessName);
		HANDLE hProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_QUERY_INFORMATION, 0, dwProcessId);
		
		BYTE VirtualProtectExName[] = {		
			'V', 'i', 'r', 't', 'u', 'a', 'l', 'P', 'r', 'o', 't', 'e', 'c', 't', 'E', 'x', 0x00
		};
		typedef WINBOOL (__stdcall* _VirtualProtectEx) (HANDLE, LPVOID, SIZE_T, DWORD, PDWORD);
		_VirtualProtectEx VirtualProtectEx = (_VirtualProtectEx)GetProcAddress(hKernel, (LPCSTR) VirtualProtectExName);
		
		BYTE WriteProcessMemoryName[] = {		
			'W', 'r', 'i', 't', 'e', 'P', 'r', 'o', 'c', 'e', 's', 's', 'M', 'e', 'm', 'o', 'r', 'y', 0x00
		};
		typedef WINBOOL (__stdcall* _WriteProcessMemory) (HANDLE, LPVOID, LPCVOID, SIZE_T, SIZE_T*);
		_WriteProcessMemory WriteProcessMemory = (_WriteProcessMemory)GetProcAddress(hKernel, (LPCSTR) WriteProcessMemoryName);
		
		BYTE bytes[] = {
			0x68, 0xD4, 0x1F, 0x00, 0x00,
			0x68, 0x1A, 0x46, 0x00, 0x00,
			0x68, 0xE2, 0x87, 0x00, 0x00,
			0x68, 0x36, 0x90, 0x00, 0x00,
			0x90,
			0x8B, 0xB5, 0x64, 0xFF, 0xFF, 0xFF
		};
		ULONG oldProtection;
		LPVOID addr = (LPVOID) ((DWORD) hModule + 0x4AA9A);
		if (VirtualProtectEx(hProcess, addr, 27, PAGE_READWRITE, &oldProtection)) {
		    WriteProcessMemory(hProcess, addr, (LPVOID) bytes, 27, NULL);
		    VirtualProtectEx(hProcess, addr, 27, oldProtection, &oldProtection);
		}
		BYTE bytes0[] = {
			0x00, 0x00, 0x00, 0x00
		};
		addr = (LPVOID) ((DWORD) hModule + 0x215b58);
		if (VirtualProtectEx(hProcess, addr, 4, PAGE_READWRITE, &oldProtection)) {
		    WriteProcessMemory(hProcess, addr, (LPVOID) bytes0, 4, NULL);
		    VirtualProtectEx(hProcess, addr, 4, oldProtection, &oldProtection);
		}
		addr = (LPVOID) ((DWORD) hModule + 0x215afc);
		if (VirtualProtectEx(hProcess, addr, 4, PAGE_READWRITE, &oldProtection)) {
		    WriteProcessMemory(hProcess, addr, (LPVOID) bytes0, 4, NULL);
		    VirtualProtectEx(hProcess, addr, 4, oldProtection, &oldProtection);
		}
		addr = (LPVOID) ((DWORD) hModule + 0x2159b8);
		if (VirtualProtectEx(hProcess, addr, 4, PAGE_READWRITE, &oldProtection)) {
		    WriteProcessMemory(hProcess, addr, (LPVOID) bytes0, 4, NULL);
		    VirtualProtectEx(hProcess, addr, 4, oldProtection, &oldProtection);
		}
		BYTE info[] = {
			'r', 't', 'b', 'r', 'o', 'k', 'e', 'r',
			'p', 'l', 'u', 'g', 'i', 'n', '@', 'g',
			'm', 'a', 'i', 'l', '.', 'c', 'o', 'm',
			'\r', '\n', 'R', 'i', 'g', 'h', 't', ' ',
			'c', 'l', 'i', 'c', 'k', ' ', 'h', 'e',
			'r', 'e', ' ', 'f', 'o', 'r', ' ', 't',
			'h', 'e', ' ', 'm', 'e', 'n', 'u', ' ',
			'o', 'f', ' ', '%', 's', 0x00
		};
		addr = (LPVOID) ((DWORD) hModule + 0x215b16);
		if (VirtualProtectEx(hProcess, addr, 62, PAGE_READWRITE, &oldProtection)) {
		    WriteProcessMemory(hProcess, addr, (LPVOID) info, 62, NULL);
		    VirtualProtectEx(hProcess, addr, 62, oldProtection, &oldProtection);
		}
		BYTE ami[] = {
			'r', 't', 'b', 'r', 'o', 'k', 'e', 'r',
			'p', 'l', 'u', 'g', 'i', 'n', '@', 'g',
			'm', 'a', 'i', 'l', '.', 'c', 'o', 'm',
			0x00
		};
		addr = (LPVOID) ((DWORD) hModule + 0x20CBF0);
		if (VirtualProtectEx(hProcess, addr, 25, PAGE_READWRITE, &oldProtection)) {
		    WriteProcessMemory(hProcess, addr, (LPVOID) ami, 25, NULL);
		    VirtualProtectEx(hProcess, addr, 25, oldProtection, &oldProtection);
		}
		
		BYTE dllUser[] = {
			'u', 's', 'e', 'r', '3', '2',
			'.', 'd', 'l', 'l', 0x00
		};
		HMODULE hUser = GetModuleHandle((LPCSTR) dllUser);
		
		BYTE DeleteMenuName[] = {		
			'D', 'e', 'l', 'e', 't', 'e', 'M', 'e', 'n', 'u', 0x00
		};
		typedef DWORD (__stdcall* _DeleteMenu) ();
		_DeleteMenu DeleteMenu = (_DeleteMenu)GetProcAddress(hUser, (LPCSTR) DeleteMenuName);
		
		BYTE code1[] = {
			0xE9, 0x74, 0x38, 0x1B, 0x00, 0x90
		};
		addr = (LPVOID) ((DWORD) hModule + 0x24449);
		if (VirtualProtectEx(hProcess, addr, 6, PAGE_READWRITE, &oldProtection)) {
		    WriteProcessMemory(hProcess, addr, (LPVOID) code1, 6, NULL);
		    VirtualProtectEx(hProcess, addr, 6, oldProtection, &oldProtection);
		}
		
		BYTE code2[] = {
			0xB8
		};
		BYTE code3[] = {
			0x68, 0x00, 0x04, 0x00, 0x00, 0x6A, 0x0D, 0x56, 0xB8
		};
		BYTE code4[] = {
			0xFF, 0xD0
		};
		BYTE code5[] = {
			0xE9, 0x09, 0xC7, 0xE4, 0xFF, 0x90
		};
		
		addr = (LPVOID) ((DWORD) hModule + 0x1D7CC2);
		if (VirtualProtectEx(hProcess, addr, 133, PAGE_READWRITE, &oldProtection)) {
		    WriteProcessMemory(hProcess, addr, (LPVOID) code2, 1, NULL);
		    addr = (LPVOID) ((DWORD) hModule + 0x1D7CC2 + 1);
		    WriteProcessMemory(hProcess, addr, (LPVOID) &DeleteMenu, 4, NULL);
		    addr = (LPVOID) ((DWORD) hModule + 0x1D7CC2 + 5);
		    WriteProcessMemory(hProcess, addr, (LPVOID) code4, 2, NULL);
		    for(int i = 0; i < 8; i ++) {
		    	addr = (LPVOID) ((DWORD) hModule + 0x1D7CC9 + i * 15);
		    	WriteProcessMemory(hProcess, addr, (LPVOID) code3, 9, NULL);
		    	addr = (LPVOID) ((DWORD) hModule + 0x1D7CC9 + i * 15 + 9);
		    	WriteProcessMemory(hProcess, addr, (LPVOID) &DeleteMenu, 4, NULL);
		    	addr = (LPVOID) ((DWORD) hModule + 0x1D7CC9 + i * 15 + 13);
		    	WriteProcessMemory(hProcess, addr, (LPVOID) code4, 2, NULL);
			}
			addr = (LPVOID) ((DWORD) hModule + 0x1D7D41);
			WriteProcessMemory(hProcess, addr, (LPVOID) code5, 6, NULL);
			VirtualProtectEx(hProcess, addr, 133, oldProtection, &oldProtection);
		}
	}
	printf("%x\n", hDll);
	cout << "End" << endl;
	system("PAUSE");
	return 0;
}