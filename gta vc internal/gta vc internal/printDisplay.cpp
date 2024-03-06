#include <iostream>
#include "printDisplay.h"

#define GREEN_TEXT "\033[32m"
#define RED_TEXT "\033[31m"
#define RESET_TEXT "\033[0m"


void prntDis::printDisplay(bool bGodMode, bool bInfAmmo, bool MoneyFreez, bool bFly)
{
    system("cls");
    std::cout << "[NUMPAD1] GodMode                  ->  [" << (bGodMode ? GREEN_TEXT "ON" RESET_TEXT : RED_TEXT "OFF" RESET_TEXT) << "]\n";
    std::cout << "[NUMPAD2] INF ammo                 ->  [" << (bInfAmmo ? GREEN_TEXT "ON" RESET_TEXT : RED_TEXT "OFF" RESET_TEXT) << "]\n";
    std::cout << "[NUMPAD3] Add 500 ammo             ->  [" << GREEN_TEXT << "Press" << RESET_TEXT << "]\n";
    std::cout << "[NUMPAD4] Add 250K Money           ->  [" << GREEN_TEXT << "Press" << RESET_TEXT << "]\n";
    std::cout << "[NUMPAD5] MoneyFreez               ->  [" << (MoneyFreez ? GREEN_TEXT "ON" RESET_TEXT : RED_TEXT "OFF" RESET_TEXT) << "]\n";
    std::cout << "[NUMPAD6] Fly                      ->  [" << (bFly ? GREEN_TEXT "ON" RESET_TEXT : RED_TEXT "OFF" RESET_TEXT) << "]\n";
    std::cout << "[NUMPAD7] Set all packages to 100  ->  [" << GREEN_TEXT << "Press" << RESET_TEXT << "]\n";

}