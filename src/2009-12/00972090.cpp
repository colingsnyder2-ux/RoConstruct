// from server: 100% by nuck16
// roc 2009-12 00972090  unit: seg_00970000  size: 73 bytes
//
// 00972090  51                   push ecx
// 00972091  68509b6400           push 0x649b50
// 00972096  686860b800           push 0xb86068
// 0097209b  e890f5a8ff           call 0x401630
// 009720a0  83c408               add esp, 8
// 009720a3  e86872cdff           call 0x649310
// 009720a8  890424               mov dword ptr [esp], eax
// 009720ab  8d0424               lea eax, [esp]
// 009720ae  50                   push eax
// 009720af  e8ccf8a8ff           call 0x401980
// 009720b4  8bc8                 mov ecx, eax
// 009720b6  e86534adff           call 0x445520
// 009720bb  c700402bb300         mov dword ptr [eax], 0xb32b40
// 009720c1  68303c9800           push 0x983c30
// 009720c6  c705a4fcb8009a020000 mov dword ptr [0xb8fca4], 0x29a
// 009720d0  e85428e8ff           call 0x7f4929
// 009720d5  83c408               add esp, 8
// 009720d8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86068;
extern int global_b8fca4;
extern ICreator creator_b32b40;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b50();
const Name &doDeclare();
void destroy_983c30();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86068, &callDoDeclare_649b50);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b40;
    global_b8fca4 = 0x29a;
    atexit(&destroy_983c30);
}
