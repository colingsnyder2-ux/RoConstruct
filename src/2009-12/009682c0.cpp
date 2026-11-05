// from server: 100% by nuck16
// roc 2009-12 009682c0  unit: seg_00960000  size: 73 bytes
//
// 009682c0  51                   push ecx
// 009682c1  68d03a4100           push 0x413ad0
// 009682c6  6810a1b700           push 0xb7a110
// 009682cb  e86093a9ff           call 0x401630
// 009682d0  83c408               add esp, 8
// 009682d3  e8e8b3aaff           call 0x4136c0
// 009682d8  890424               mov dword ptr [esp], eax
// 009682db  8d0424               lea eax, [esp]
// 009682de  50                   push eax
// 009682df  e89c96a9ff           call 0x401980
// 009682e4  8bc8                 mov ecx, eax
// 009682e6  e835d2adff           call 0x445520
// 009682eb  c7009833b000         mov dword ptr [eax], 0xb03398
// 009682f1  6800dc9700           push 0x97dc00
// 009682f6  c7052ca1b7009a020000 mov dword ptr [0xb7a12c], 0x29a
// 00968300  e824c6e8ff           call 0x7f4929
// 00968305  83c408               add esp, 8
// 00968308  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a110;
extern int global_b7a12c;
extern ICreator creator_b03398;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_413ad0();
const Name &doDeclare();
void destroy_97dc00();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a110, &callDoDeclare_413ad0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b03398;
    global_b7a12c = 0x29a;
    atexit(&destroy_97dc00);
}
