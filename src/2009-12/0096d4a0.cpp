// from server: 100% by nuck16
// roc 2009-12 0096d4a0  unit: seg_00960000  size: 73 bytes
//
// 0096d4a0  51                   push ecx
// 0096d4a1  68c0be5200           push 0x52bec0
// 0096d4a6  686c01b800           push 0xb8016c
// 0096d4ab  e88041a9ff           call 0x401630
// 0096d4b0  83c408               add esp, 8
// 0096d4b3  e8c8e6bbff           call 0x52bb80
// 0096d4b8  890424               mov dword ptr [esp], eax
// 0096d4bb  8d0424               lea eax, [esp]
// 0096d4be  50                   push eax
// 0096d4bf  e8bc44a9ff           call 0x401980
// 0096d4c4  8bc8                 mov ecx, eax
// 0096d4c6  e85580adff           call 0x445520
// 0096d4cb  c70084cbb100         mov dword ptr [eax], 0xb1cb84
// 0096d4d1  6890049800           push 0x980490
// 0096d4d6  c7057401b8009a020000 mov dword ptr [0xb80174], 0x29a
// 0096d4e0  e84474e8ff           call 0x7f4929
// 0096d4e5  83c408               add esp, 8
// 0096d4e8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8016c;
extern int global_b80174;
extern ICreator creator_b1cb84;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_52bec0();
const Name &doDeclare();
void destroy_980490();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b8016c, &callDoDeclare_52bec0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b1cb84;
    global_b80174 = 0x29a;
    atexit(&destroy_980490);
}
