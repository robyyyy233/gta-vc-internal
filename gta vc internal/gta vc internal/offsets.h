#include <Windows.h>


#define STR_MERGE_IMPL(a, b) a##b
#define STR_MERGE(a, b) STR_MERGE_IMPL(a, b)
#define MAKE_PAD(size) STR_MERGE(_pad, __COUNTER__)[size]
#define DEFINE_MEMBER_N(type, name, offset) struct {unsigned char MAKE_PAD(offset); type name;}


class localEnt
{
public:

    union
    {
        //              Type     Name    Offset
        DEFINE_MEMBER_N(float, health, 0x354);
        DEFINE_MEMBER_N(float, armor, 0x358);


        DEFINE_MEMBER_N(int, pistolAmmo, 0x45C);
        DEFINE_MEMBER_N(int, smgAmmo, 0x48C);
        DEFINE_MEMBER_N(int, arAmmo, 0x4A4);
        DEFINE_MEMBER_N(int, heavyAmmo, 0x4BC);
        DEFINE_MEMBER_N(int, sniperAmmo, 0x4d4);
        DEFINE_MEMBER_N(int, shotgunAmmo, 0x474);
    };

};