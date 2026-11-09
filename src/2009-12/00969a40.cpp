// from server: 100% by nuck16
// roc 2009-12 00969a40  unit: seg_00960000  size: 73 bytes
//
// 00969a40  51                   push ecx
// 00969a41  68502d4600           push 0x462d50
// 00969a46  68d0b9b700           push 0xb7b9d0
// 00969a4b  e8e07ba9ff           call 0x401630
// 00969a50  83c408               add esp, 8
// 00969a53  e8f883afff           call 0x461e50
// 00969a58  890424               mov dword ptr [esp], eax
// 00969a5b  8d0424               lea eax, [esp]
// 00969a5e  50                   push eax
// 00969a5f  e81c7fa9ff           call 0x401980
// 00969a64  8bc8                 mov ecx, eax
// 00969a66  e8b5baadff           call 0x445520
// 00969a6b  c700d4b4b000         mov dword ptr [eax], 0xb0b4d4
// 00969a71  68d0eb9700           push 0x97ebd0
// 00969a76  c705fcbab7009a020000 mov dword ptr [0xb7bafc], 0x29a
// 00969a80  e8a4aee8ff           call 0x7f4929
// 00969a85  83c408               add esp, 8
// 00969a88  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9d0;
extern int global_b7bafc;
extern ICreator creator_b0b4d4;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d50();
const Name &doDeclare();
void destroy_97ebd0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7b9d0, &callDoDeclare_462d50);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b0b4d4;
    global_b7bafc = 0x29a;
    atexit(&destroy_97ebd0);
}
