// from server: 100% by nuck16
// roc 2009-12 009699f0  unit: seg_00960000  size: 73 bytes
//
// 009699f0  51                   push ecx
// 009699f1  68402d4600           push 0x462d40
// 009699f6  68ccb9b700           push 0xb7b9cc
// 009699fb  e8307ca9ff           call 0x401630
// 00969a00  83c408               add esp, 8
// 00969a03  e8d883afff           call 0x461de0
// 00969a08  890424               mov dword ptr [esp], eax
// 00969a0b  8d0424               lea eax, [esp]
// 00969a0e  50                   push eax
// 00969a0f  e86c7fa9ff           call 0x401980
// 00969a14  8bc8                 mov ecx, eax
// 00969a16  e805bbadff           call 0x445520
// 00969a1b  c700d0b4b000         mov dword ptr [eax], 0xb0b4d0
// 00969a21  6810ec9700           push 0x97ec10
// 00969a26  c705f8bab7009a020000 mov dword ptr [0xb7baf8], 0x29a
// 00969a30  e8f4aee8ff           call 0x7f4929
// 00969a35  83c408               add esp, 8
// 00969a38  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9cc;
extern int global_b7baf8;
extern ICreator creator_b0b4d0;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d40();
const Name &doDeclare();
void destroy_97ec10();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7b9cc, &callDoDeclare_462d40);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b0b4d0;
    global_b7baf8 = 0x29a;
    atexit(&destroy_97ec10);
}
