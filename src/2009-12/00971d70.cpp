// from server: 100% by nuck16
// roc 2009-12 00971d70  unit: seg_00970000  size: 73 bytes
//
// 00971d70  51                   push ecx
// 00971d71  68b09a6400           push 0x649ab0
// 00971d76  684060b800           push 0xb86040
// 00971d7b  e8b0f8a8ff           call 0x401630
// 00971d80  83c408               add esp, 8
// 00971d83  e82871cdff           call 0x648eb0
// 00971d88  890424               mov dword ptr [esp], eax
// 00971d8b  8d0424               lea eax, [esp]
// 00971d8e  50                   push eax
// 00971d8f  e8ecfba8ff           call 0x401980
// 00971d94  8bc8                 mov ecx, eax
// 00971d96  e88537adff           call 0x445520
// 00971d9b  c700182bb300         mov dword ptr [eax], 0xb32b18
// 00971da1  68b03e9800           push 0x983eb0
// 00971da6  c7057cfcb8009a020000 mov dword ptr [0xb8fc7c], 0x29a
// 00971db0  e8742be8ff           call 0x7f4929
// 00971db5  83c408               add esp, 8
// 00971db8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86040;
extern int global_b8fc7c;
extern ICreator creator_b32b18;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649ab0();
const Name &doDeclare();
void destroy_983eb0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86040, &callDoDeclare_649ab0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b18;
    global_b8fc7c = 0x29a;
    atexit(&destroy_983eb0);
}
