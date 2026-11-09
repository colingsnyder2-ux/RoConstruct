// from server: 100% by nuck16
// roc 2009-12 00972450  unit: seg_00970000  size: 73 bytes
//
// 00972450  51                   push ecx
// 00972451  68109c6400           push 0x649c10
// 00972456  689860b800           push 0xb86098
// 0097245b  e8d0f1a8ff           call 0x401630
// 00972460  83c408               add esp, 8
// 00972463  e8e873cdff           call 0x649850
// 00972468  890424               mov dword ptr [esp], eax
// 0097246b  8d0424               lea eax, [esp]
// 0097246e  50                   push eax
// 0097246f  e80cf5a8ff           call 0x401980
// 00972474  8bc8                 mov ecx, eax
// 00972476  e8a530adff           call 0x445520
// 0097247b  c700702bb300         mov dword ptr [eax], 0xb32b70
// 00972481  6830399800           push 0x983930
// 00972486  c705d4fcb8009a020000 mov dword ptr [0xb8fcd4], 0x29a
// 00972490  e89424e8ff           call 0x7f4929
// 00972495  83c408               add esp, 8
// 00972498  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86098;
extern int global_b8fcd4;
extern ICreator creator_b32b70;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649c10();
const Name &doDeclare();
void destroy_983930();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86098, &callDoDeclare_649c10);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b70;
    global_b8fcd4 = 0x29a;
    atexit(&destroy_983930);
}
