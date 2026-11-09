// from server: 100% by nuck16
// roc 2009-12 0096d790  unit: seg_00960000  size: 73 bytes
//
// 0096d790  51                   push ecx
// 0096d791  68e0885300           push 0x5388e0
// 0096d796  68d805b800           push 0xb805d8
// 0096d79b  e8903ea9ff           call 0x401630
// 0096d7a0  83c408               add esp, 8
// 0096d7a3  e848a1bcff           call 0x5378f0
// 0096d7a8  890424               mov dword ptr [esp], eax
// 0096d7ab  8d0424               lea eax, [esp]
// 0096d7ae  50                   push eax
// 0096d7af  e8cc41a9ff           call 0x401980
// 0096d7b4  8bc8                 mov ecx, eax
// 0096d7b6  e8657dadff           call 0x445520
// 0096d7bb  c70030f6b100         mov dword ptr [eax], 0xb1f630
// 0096d7c1  6810089800           push 0x980810
// 0096d7c6  c7050406b8009a020000 mov dword ptr [0xb80604], 0x29a
// 0096d7d0  e85471e8ff           call 0x7f4929
// 0096d7d5  83c408               add esp, 8
// 0096d7d8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805d8;
extern int global_b80604;
extern ICreator creator_b1f630;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_5388e0();
const Name &doDeclare();
void destroy_980810();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b805d8, &callDoDeclare_5388e0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b1f630;
    global_b80604 = 0x29a;
    atexit(&destroy_980810);
}
