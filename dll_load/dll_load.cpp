#include "stdafx.h"
#include <stdio.h>


typedef void (*SV_GameSendServerCommand_t)(int clientNum, /*svscmd_type*/char type, const char *text);
typedef int (*Key_IsDown)(int ClientNum, int ButtonEnum);


DWORD WINAPI commands(LPVOID)
{
	SV_GameSendServerCommand_t SV_GameSendServerCommand = (SV_GameSendServerCommand_t)0x822548C8;
	Key_IsDown button_Pressed = (Key_IsDown)0x82141308;

        for(;;)
        {
		if(button_Pressed(0,0x06)) // Right Shoulder
                {
			SV_GameSendServerCommand(0,0, "s r_fullbright \"1\"");
			SV_GameSendServerCommand(0,0, "c \"RIGHT SHOULDER PRESSED\"");
			printf("Right Shoulder Pressed \n");
			Sleep(1000);
                }
	}
						
}

BOOL WINAPI DllMain(HANDLE hInstDLL, DWORD reason, LPVOID lpReserved)
{
	switch(reason)
  	{
		case DLL_PROCESS_ATTACH:
			CreateThread(0,0,commands,0,0,0);
      			printf("Proccess Attach \n");
     		 	break;
    		case DLL_THREAD_ATTACH:
      			printf("Thread Attach \n");
     			 break;
    		case DLL_THREAD_DETACH:
			printf("Thread Detach \n");
      			break;
    		case DLL_PROCESS_DETACH:
			printf("Process Detach \n");
     			 break;
 	}
 	return TRUE;
}

	
	
