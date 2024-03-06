#include <Windows.h>
#include <vector>

#include "mem.h"
#include "function.h"
#include "offsets.h"


uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"gta-vc.exe");
localEnt* localPlayerPtr = *(localEnt**)(moduleBase + 0x00549d30);

//inf ammo on all wepons
void func::InfAmmoFunction(bool InfAmmo)
{

	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"gta-vc.exe");

	uintptr_t destinationMag = moduleBase + 0x1d488e;
	uintptr_t destinationAll = moduleBase + 0x1d48c5;
	

	if (InfAmmo)
	{
		// mag
		mem::Nop((BYTE*)destinationMag, 3);
		
		//all
		mem::Nop((BYTE*)destinationAll, 3);
	}
	else
	{
		//mag
		mem::Patch((BYTE*)destinationMag, (BYTE*)"\xFF\x4E\x08", 3);

		//all
		mem::Patch((BYTE*)destinationAll, (BYTE*)"\xff\x4e\x0c", 3);
	}

}


//give 500 ammo on all wepons
void func::giveAmmo()
{
    //pistol
    localPlayerPtr->pistolAmmo += 500;

    //smg
    localPlayerPtr->smgAmmo += 500;

    //shotgun
    localPlayerPtr->shotgunAmmo += 500;

    //ar
    localPlayerPtr->arAmmo += 500;

    //heavy
    localPlayerPtr->heavyAmmo += 500;

    //sniper
    localPlayerPtr->sniperAmmo += 500;

}


//give 250k money
void func::giveMoney()
{

    uintptr_t moneyAddr = (uintptr_t)(moduleBase + 0x549DD0);
    uintptr_t* money = (uintptr_t*)moneyAddr;
    *money += 250000;

}


//money freez when buying house and wepons
void func::freezMoney(bool moneyFreez)
{

    if (moneyFreez)
    {   
        //weapons
        mem::Nop((BYTE*)(moduleBase + 0x45666), 6);

        //property
        mem::Nop((BYTE*)(moduleBase + 0x414CE), 6);
    }
    else
    {
        //weapons
        mem::Patch((BYTE*)(moduleBase + 0x45666), (BYTE*)"\x01\x99\xd0\xd9\x94\x00", 6);

        //property
        mem::Patch((BYTE*)(moduleBase + 0x414CE), (BYTE*)"\x29\x98\xD0\x9d\x94\x00", 6);
    }

}

//fly
void func::bFly(bool bFly)
{

    if (bFly)
    {
        mem::Nop((BYTE*)(moduleBase + 0xba831), 3);
    }
    else
    {
        mem::Patch((BYTE*)(moduleBase + 0xba831), (BYTE*)"\xd8\x69\x78", 3);
    }

}

//collect all packages
void func::collectAllPackages()
{
    uintptr_t packageAddr = (uintptr_t)(moduleBase + 0x549dd8);
    uintptr_t* package = (uintptr_t*)packageAddr;
    *package = 100;
}
