// from server: 100% by nuck16
// roc 2009-12 00971cd0  unit: seg_00970000  size: 73 bytes
//
// 00971cd0  51                   push ecx
// 00971cd1  68909a6400           push 0x649a90
// 00971cd6  683860b800           push 0xb86038
// 00971cdb  e850f9a8ff           call 0x401630
// 00971ce0  83c408               add esp, 8
// 00971ce3  e8e870cdff           call 0x648dd0
// 00971ce8  890424               mov dword ptr [esp], eax
// 00971ceb  8d0424               lea eax, [esp]
// 00971cee  50                   push eax
// 00971cef  e88cfca8ff           call 0x401980
// 00971cf4  8bc8                 mov ecx, eax
// 00971cf6  e82538adff           call 0x445520
// 00971cfb  c700102bb300         mov dword ptr [eax], 0xb32b10
// 00971d01  68303f9800           push 0x983f30
// 00971d06  c70574fcb8009a020000 mov dword ptr [0xb8fc74], 0x29a
// 00971d10  e8142ce8ff           call 0x7f4929
// 00971d15  83c408               add esp, 8
// 00971d18  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86038;
extern int global_b8fc74;
extern ICreator creator_b32b10;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a90();
const Name &doDeclare();
void destroy_983f30();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86038, &callDoDeclare_649a90);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b10;
    global_b8fc74 = 0x29a;
    atexit(&destroy_983f30);
}
