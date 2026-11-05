// from server: 100% by nuck16
// roc 2009-12 00972040  unit: seg_00970000  size: 73 bytes
//
// 00972040  51                   push ecx
// 00972041  68409b6400           push 0x649b40
// 00972046  686460b800           push 0xb86064
// 0097204b  e8e0f5a8ff           call 0x401630
// 00972050  83c408               add esp, 8
// 00972053  e84872cdff           call 0x6492a0
// 00972058  890424               mov dword ptr [esp], eax
// 0097205b  8d0424               lea eax, [esp]
// 0097205e  50                   push eax
// 0097205f  e81cf9a8ff           call 0x401980
// 00972064  8bc8                 mov ecx, eax
// 00972066  e8b534adff           call 0x445520
// 0097206b  c7003c2bb300         mov dword ptr [eax], 0xb32b3c
// 00972071  68703c9800           push 0x983c70
// 00972076  c705a0fcb8009a020000 mov dword ptr [0xb8fca0], 0x29a
// 00972080  e8a428e8ff           call 0x7f4929
// 00972085  83c408               add esp, 8
// 00972088  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86064;
extern int global_b8fca0;
extern ICreator creator_b32b3c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b40();
const Name &doDeclare();
void destroy_983c70();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86064, &callDoDeclare_649b40);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b3c;
    global_b8fca0 = 0x29a;
    atexit(&destroy_983c70);
}
