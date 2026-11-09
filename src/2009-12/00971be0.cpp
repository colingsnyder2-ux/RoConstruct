// from server: 100% by nuck16
// roc 2009-12 00971be0  unit: seg_00970000  size: 73 bytes
//
// 00971be0  51                   push ecx
// 00971be1  68609a6400           push 0x649a60
// 00971be6  682c60b800           push 0xb8602c
// 00971beb  e840faa8ff           call 0x401630
// 00971bf0  83c408               add esp, 8
// 00971bf3  e88870cdff           call 0x648c80
// 00971bf8  890424               mov dword ptr [esp], eax
// 00971bfb  8d0424               lea eax, [esp]
// 00971bfe  50                   push eax
// 00971bff  e87cfda8ff           call 0x401980
// 00971c04  8bc8                 mov ecx, eax
// 00971c06  e81539adff           call 0x445520
// 00971c0b  c700042bb300         mov dword ptr [eax], 0xb32b04
// 00971c11  68f03f9800           push 0x983ff0
// 00971c16  c70558fcb8009a020000 mov dword ptr [0xb8fc58], 0x29a
// 00971c20  e8042de8ff           call 0x7f4929
// 00971c25  83c408               add esp, 8
// 00971c28  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8602c;
extern int global_b8fc58;
extern ICreator creator_b32b04;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a60();
const Name &doDeclare();
void destroy_983ff0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b8602c, &callDoDeclare_649a60);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b04;
    global_b8fc58 = 0x29a;
    atexit(&destroy_983ff0);
}
