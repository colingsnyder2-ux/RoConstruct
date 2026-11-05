// from server: 100% by nuck16
// roc 2009-12 00967d00  unit: seg_00960000  size: 73 bytes
//
// 00967d00  51                   push ecx
// 00967d01  68e0164000           push 0x4016e0
// 00967d06  681c94b700           push 0xb7941c
// 00967d0b  e82099a9ff           call 0x401630
// 00967d10  83c408               add esp, 8
// 00967d13  e81896a9ff           call 0x401330
// 00967d18  890424               mov dword ptr [esp], eax
// 00967d1b  8d0424               lea eax, [esp]
// 00967d1e  50                   push eax
// 00967d1f  e85c9ca9ff           call 0x401980
// 00967d24  8bc8                 mov ecx, eax
// 00967d26  e8f5d7adff           call 0x445520
// 00967d2b  c70070f4af00         mov dword ptr [eax], 0xaff470
// 00967d31  6870d69700           push 0x97d670
// 00967d36  c705b094b7009a020000 mov dword ptr [0xb794b0], 0x29a
// 00967d40  e8e4cbe8ff           call 0x7f4929
// 00967d45  83c408               add esp, 8
// 00967d48  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7941c;
extern int global_b794b0;
extern ICreator creator_aff470;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4016e0();
const Name &doDeclare();
void destroy_97d670();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7941c, &callDoDeclare_4016e0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_aff470;
    global_b794b0 = 0x29a;
    atexit(&destroy_97d670);
}
