// from server: 100% by nuck16
// roc 2009-12 00971d20  unit: seg_00970000  size: 73 bytes
//
// 00971d20  51                   push ecx
// 00971d21  68a09a6400           push 0x649aa0
// 00971d26  683c60b800           push 0xb8603c
// 00971d2b  e800f9a8ff           call 0x401630
// 00971d30  83c408               add esp, 8
// 00971d33  e80871cdff           call 0x648e40
// 00971d38  890424               mov dword ptr [esp], eax
// 00971d3b  8d0424               lea eax, [esp]
// 00971d3e  50                   push eax
// 00971d3f  e83cfca8ff           call 0x401980
// 00971d44  8bc8                 mov ecx, eax
// 00971d46  e8d537adff           call 0x445520
// 00971d4b  c700142bb300         mov dword ptr [eax], 0xb32b14
// 00971d51  68f03e9800           push 0x983ef0
// 00971d56  c70578fcb8009a020000 mov dword ptr [0xb8fc78], 0x29a
// 00971d60  e8c42be8ff           call 0x7f4929
// 00971d65  83c408               add esp, 8
// 00971d68  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8603c;
extern int global_b8fc78;
extern ICreator creator_b32b14;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649aa0();
const Name &doDeclare();
void destroy_983ef0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b8603c, &callDoDeclare_649aa0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b14;
    global_b8fc78 = 0x29a;
    atexit(&destroy_983ef0);
}
