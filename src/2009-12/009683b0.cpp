// from server: 100% by nuck16
// roc 2009-12 009683b0  unit: seg_00960000  size: 73 bytes
//
// 009683b0  51                   push ecx
// 009683b1  68003b4100           push 0x413b00
// 009683b6  681ca1b700           push 0xb7a11c
// 009683bb  e87092a9ff           call 0x401630
// 009683c0  83c408               add esp, 8
// 009683c3  e848b4aaff           call 0x413810
// 009683c8  890424               mov dword ptr [esp], eax
// 009683cb  8d0424               lea eax, [esp]
// 009683ce  50                   push eax
// 009683cf  e8ac95a9ff           call 0x401980
// 009683d4  8bc8                 mov ecx, eax
// 009683d6  e845d1adff           call 0x445520
// 009683db  c700a433b000         mov dword ptr [eax], 0xb033a4
// 009683e1  6840db9700           push 0x97db40
// 009683e6  c70538a1b7009a020000 mov dword ptr [0xb7a138], 0x29a
// 009683f0  e834c5e8ff           call 0x7f4929
// 009683f5  83c408               add esp, 8
// 009683f8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a11c;
extern int global_b7a138;
extern ICreator creator_b033a4;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_413b00();
const Name &doDeclare();
void destroy_97db40();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a11c, &callDoDeclare_413b00);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b033a4;
    global_b7a138 = 0x29a;
    atexit(&destroy_97db40);
}
