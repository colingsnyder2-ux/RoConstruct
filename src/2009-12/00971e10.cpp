// from server: 100% by nuck16
// roc 2009-12 00971e10  unit: seg_00970000  size: 73 bytes
//
// 00971e10  51                   push ecx
// 00971e11  68d09a6400           push 0x649ad0
// 00971e16  684860b800           push 0xb86048
// 00971e1b  e810f8a8ff           call 0x401630
// 00971e20  83c408               add esp, 8
// 00971e23  e86871cdff           call 0x648f90
// 00971e28  890424               mov dword ptr [esp], eax
// 00971e2b  8d0424               lea eax, [esp]
// 00971e2e  50                   push eax
// 00971e2f  e84cfba8ff           call 0x401980
// 00971e34  8bc8                 mov ecx, eax
// 00971e36  e8e536adff           call 0x445520
// 00971e3b  c700202bb300         mov dword ptr [eax], 0xb32b20
// 00971e41  68303e9800           push 0x983e30
// 00971e46  c70584fcb8009a020000 mov dword ptr [0xb8fc84], 0x29a
// 00971e50  e8d42ae8ff           call 0x7f4929
// 00971e55  83c408               add esp, 8
// 00971e58  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86048;
extern int global_b8fc84;
extern ICreator creator_b32b20;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649ad0();
const Name &doDeclare();
void destroy_983e30();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86048, &callDoDeclare_649ad0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b20;
    global_b8fc84 = 0x29a;
    atexit(&destroy_983e30);
}
