// from server: 100% by nuck16
// roc 2009-12 00972400  unit: seg_00970000  size: 73 bytes
//
// 00972400  51                   push ecx
// 00972401  68009c6400           push 0x649c00
// 00972406  689460b800           push 0xb86094
// 0097240b  e820f2a8ff           call 0x401630
// 00972410  83c408               add esp, 8
// 00972413  e8c873cdff           call 0x6497e0
// 00972418  890424               mov dword ptr [esp], eax
// 0097241b  8d0424               lea eax, [esp]
// 0097241e  50                   push eax
// 0097241f  e85cf5a8ff           call 0x401980
// 00972424  8bc8                 mov ecx, eax
// 00972426  e8f530adff           call 0x445520
// 0097242b  c7006c2bb300         mov dword ptr [eax], 0xb32b6c
// 00972431  6870399800           push 0x983970
// 00972436  c705d0fcb8009a020000 mov dword ptr [0xb8fcd0], 0x29a
// 00972440  e8e424e8ff           call 0x7f4929
// 00972445  83c408               add esp, 8
// 00972448  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86094;
extern int global_b8fcd0;
extern ICreator creator_b32b6c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649c00();
const Name &doDeclare();
void destroy_983970();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86094, &callDoDeclare_649c00);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b6c;
    global_b8fcd0 = 0x29a;
    atexit(&destroy_983970);
}
