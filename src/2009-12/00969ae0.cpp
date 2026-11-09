// from server: 100% by nuck16
// roc 2009-12 00969ae0  unit: seg_00960000  size: 73 bytes
//
// 00969ae0  51                   push ecx
// 00969ae1  68702d4600           push 0x462d70
// 00969ae6  68d8b9b700           push 0xb7b9d8
// 00969aeb  e8407ba9ff           call 0x401630
// 00969af0  83c408               add esp, 8
// 00969af3  e83884afff           call 0x461f30
// 00969af8  890424               mov dword ptr [esp], eax
// 00969afb  8d0424               lea eax, [esp]
// 00969afe  50                   push eax
// 00969aff  e87c7ea9ff           call 0x401980
// 00969b04  8bc8                 mov ecx, eax
// 00969b06  e815baadff           call 0x445520
// 00969b0b  c700dcb4b000         mov dword ptr [eax], 0xb0b4dc
// 00969b11  6850eb9700           push 0x97eb50
// 00969b16  c70504bbb7009a020000 mov dword ptr [0xb7bb04], 0x29a
// 00969b20  e804aee8ff           call 0x7f4929
// 00969b25  83c408               add esp, 8
// 00969b28  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9d8;
extern int global_b7bb04;
extern ICreator creator_b0b4dc;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d70();
const Name &doDeclare();
void destroy_97eb50();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7b9d8, &callDoDeclare_462d70);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b0b4dc;
    global_b7bb04 = 0x29a;
    atexit(&destroy_97eb50);
}
