#include <Windows.h>
//#include "User_Interface.h"

extern int UIMain(); //LOOK outside main for the User interface function

/*TODO: Find a way to overwrite a string in game in order to tell
the user whats up, E.G. UNLIM AMMO TURNED OFF AND ON*/

DWORD WINAPI Main_thread( LPVOID lpParam )
{
	UIMain();
    return S_OK;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  _reason,
                       LPVOID lpReserved
					  )
{
	//we only care if it attaches
	if (_reason == DLL_PROCESS_ATTACH)
	{
		CreateThread(0, 0x1000, &Main_thread, 0, 0, NULL);
	}
	return TRUE;
}
