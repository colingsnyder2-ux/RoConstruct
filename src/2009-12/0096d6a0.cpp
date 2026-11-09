// from server: 100% by nuck16
// roc 2009-12 0096d6a0  unit: seg_00960000  size: 73 bytes
//
// 0096d6a0  51                   push ecx
// 0096d6a1  68b0885300           push 0x5388b0
// 0096d6a6  68cc05b800           push 0xb805cc
// 0096d6ab  e8803fa9ff           call 0x401630
// 0096d6b0  83c408               add esp, 8
// 0096d6b3  e8e8a0bcff           call 0x5377a0
// 0096d6b8  890424               mov dword ptr [esp], eax
// 0096d6bb  8d0424               lea eax, [esp]
// 0096d6be  50                   push eax
// 0096d6bf  e8bc42a9ff           call 0x401980
// 0096d6c4  8bc8                 mov ecx, eax
// 0096d6c6  e8557eadff           call 0x445520
// 0096d6cb  c70024f6b100         mov dword ptr [eax], 0xb1f624
// 0096d6d1  68d0089800           push 0x9808d0
// 0096d6d6  c705f805b8009a020000 mov dword ptr [0xb805f8], 0x29a
// 0096d6e0  e84472e8ff           call 0x7f4929
// 0096d6e5  83c408               add esp, 8
// 0096d6e8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805cc;
extern int global_b805f8;
extern ICreator creator_b1f624;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_5388b0();
const Name &doDeclare();
void destroy_9808d0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b805cc, &callDoDeclare_5388b0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b1f624;
    global_b805f8 = 0x29a;
    atexit(&destroy_9808d0);
}
