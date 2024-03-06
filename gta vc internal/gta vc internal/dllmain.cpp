#include <Windows.h>
#include <iostream>

#include "mem.h"
#include "function.h"
#include "printDisplay.h"
#include "offsets.h"


DWORD WINAPI HackThread(HMODULE hModule)
{

    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    std::cout << "Hack injected sucesfully!";
    Sleep(2000);
    system("cls");

    //get module base addr
    uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"gta-vc.exe");

    localEnt* localPlayerPtr = *(localEnt**)(moduleBase + 0x00549d30);

    bool bGodMode = false,
         bInfAmmo = false,
         bAddAmmo = false,
         bMoneyFreez = false,
         bFly = false;



    prntDis::printDisplay(bGodMode, bInfAmmo, bMoneyFreez, bFly);

    while (true)
    {

        //cheat exit
        if (GetAsyncKeyState(VK_END) & 1)
        {
            //health
            bGodMode = false;
            localPlayerPtr->health = 100.00f;
            localPlayerPtr->armor = 0.00f;

            //Inf Ammo
            bInfAmmo = false;
            func::InfAmmoFunction(bInfAmmo);

            //FreezMoney
            bMoneyFreez = false;
            func::freezMoney(bMoneyFreez);

            //Fly
            bFly = false;
            func::bFly(bFly);

            prntDis::printDisplay(bGodMode, bInfAmmo,bMoneyFreez,bFly);
            std::cout << "\n\nCheat closing...";
            Sleep(1000);


            break;
        }


        //Godmode
        if (GetAsyncKeyState(VK_NUMPAD1) & 1)
        {

            bGodMode = !bGodMode;

            prntDis::printDisplay(bGodMode, bInfAmmo,bMoneyFreez,bFly);

            if (!bGodMode)
            {
                localPlayerPtr->health = 100.00f;
                localPlayerPtr->armor = 0.00f;
            }

        }

        if (bGodMode)
        {
            localPlayerPtr->health = 999.00f;
            localPlayerPtr->armor = 999.00f;
        }


        //freez ammo
        if (GetAsyncKeyState(VK_NUMPAD2) & 1)
        {
            bInfAmmo = !bInfAmmo;

            prntDis::printDisplay(bGodMode, bInfAmmo,bMoneyFreez,bFly);

            func::InfAmmoFunction(bInfAmmo);

        }


        //Give 500 ammo
        if (GetAsyncKeyState(VK_NUMPAD3) & 1)
        {
            func::giveAmmo();
        }


        //give 250k
        if(GetAsyncKeyState(VK_NUMPAD4) & 1)
        {
            func::giveMoney();
        }


        //freez money
        if (GetAsyncKeyState(VK_NUMPAD5) & 1)
        {

            bMoneyFreez = !bMoneyFreez;

            prntDis::printDisplay(bGodMode, bInfAmmo, bMoneyFreez,bFly);

            func::freezMoney(bMoneyFreez);
        }

        
        //Fly
        if (GetAsyncKeyState(VK_NUMPAD6) & 1)
        {

            bFly = !bFly;

            prntDis::printDisplay(bGodMode, bInfAmmo, bMoneyFreez, bFly);

            func::bFly(bFly);

        }


        //get all pachete
        if (GetAsyncKeyState(VK_NUMPAD7) & 1)
        {
            prntDis::printDisplay(bGodMode, bInfAmmo, bMoneyFreez, bFly);

            func::collectAllPackages();
        }


        


        Sleep(5);

    }


    fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;

}




BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

