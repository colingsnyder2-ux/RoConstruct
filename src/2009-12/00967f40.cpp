// from server: 100% by nuck16
// roc 2009-12 00967f40  unit: seg_00960000  size: 73 bytes
//
// 00967f40  51                   push ecx
// 00967f41  6810414000           push 0x404110
// 00967f46  688895b700           push 0xb79588
// 00967f4b  e8e096a9ff           call 0x401630
// 00967f50  83c408               add esp, 8
// 00967f53  e808baa9ff           call 0x403960
// 00967f58  890424               mov dword ptr [esp], eax
// 00967f5b  8d0424               lea eax, [esp]
// 00967f5e  50                   push eax
// 00967f5f  e81c9aa9ff           call 0x401980
// 00967f64  8bc8                 mov ecx, eax
// 00967f66  e8b5d5adff           call 0x445520
// 00967f6b  c7009cfdaf00         mov dword ptr [eax], 0xaffd9c
// 00967f71  68e0d79700           push 0x97d7e0
// 00967f76  c7059495b7009a020000 mov dword ptr [0xb79594], 0x29a
// 00967f80  e8a4c9e8ff           call 0x7f4929
// 00967f85  83c408               add esp, 8
// 00967f88  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79588;
extern int global_b79594;
extern ICreator creator_affd9c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_404110();
const Name &doDeclare();
void destroy_97d7e0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b79588, &callDoDeclare_404110);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_affd9c;
    global_b79594 = 0x29a;
    atexit(&destroy_97d7e0);
}
