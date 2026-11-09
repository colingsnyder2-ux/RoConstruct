// from server: 100% by nuck16
// roc 2009-12 009680e0  unit: seg_00960000  size: 73 bytes
//
// 009680e0  51                   push ecx
// 009680e1  6850954000           push 0x409550
// 009680e6  680896b700           push 0xb79608
// 009680eb  e84095a9ff           call 0x401630
// 009680f0  83c408               add esp, 8
// 009680f3  e8980faaff           call 0x409090
// 009680f8  890424               mov dword ptr [esp], eax
// 009680fb  8d0424               lea eax, [esp]
// 009680fe  50                   push eax
// 009680ff  e87c98a9ff           call 0x401980
// 00968104  8bc8                 mov ecx, eax
// 00968106  e815d4adff           call 0x445520
// 0096810b  c7004c1db000         mov dword ptr [eax], 0xb01d4c
// 00968111  6880da9700           push 0x97da80
// 00968116  c7052c9ab7009a020000 mov dword ptr [0xb79a2c], 0x29a
// 00968120  e804c8e8ff           call 0x7f4929
// 00968125  83c408               add esp, 8
// 00968128  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79608;
extern int global_b79a2c;
extern ICreator creator_b01d4c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_409550();
const Name &doDeclare();
void destroy_97da80();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b79608, &callDoDeclare_409550);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b01d4c;
    global_b79a2c = 0x29a;
    atexit(&destroy_97da80);
}
