#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <commctrl.h>
#include "resource.h"
#include "click.h"

void run(){
    char path[1024],cmd[1024];
    ExpandEnvironmentStringsA("%TEMP%\\click.cmd",path,1024);
    FILE *fp=fopen(path,"w");
    fwrite(data,1,strlen(data),fp);
    fclose(fp);
    //sprintf(cmd,"cmd /k \"%s\"",path);
    puts(path);
    system(path);
}

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
		
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg,0);
    }
    return TRUE;
	
    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
            case IDC_BUTTON1:
                run(); 
                break;
        }
    }
    return TRUE;
    }
    return FALSE;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    InitCommonControls();
    HINSTANCE hUser32 = LoadLibraryA("user32.dll");
    if(hUser32)
    {
        typedef BOOL(WINAPI * LPSetProcessDPIAware)(void);
        LPSetProcessDPIAware pSetProcessDPIAware = (LPSetProcessDPIAware)GetProcAddress(hUser32, "SetProcessDPIAware");
        if(pSetProcessDPIAware)
        {
            pSetProcessDPIAware();
        }
        FreeLibrary(hUser32);
    }
    return DialogBox(hInstance, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
