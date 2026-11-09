// from server: 100% by nuck16
// roc 2009-12 0096d830  unit: seg_00960000  size: 73 bytes
//
// 0096d830  51                   push ecx
// 0096d831  6800895300           push 0x538900
// 0096d836  68e005b800           push 0xb805e0
// 0096d83b  e8f03da9ff           call 0x401630
// 0096d840  83c408               add esp, 8
// 0096d843  e888a1bcff           call 0x5379d0
// 0096d848  890424               mov dword ptr [esp], eax
// 0096d84b  8d0424               lea eax, [esp]
// 0096d84e  50                   push eax
// 0096d84f  e82c41a9ff           call 0x401980
// 0096d854  8bc8                 mov ecx, eax
// 0096d856  e8c57cadff           call 0x445520
// 0096d85b  c70038f6b100         mov dword ptr [eax], 0xb1f638
// 0096d861  6890079800           push 0x980790
// 0096d866  c7050c06b8009a020000 mov dword ptr [0xb8060c], 0x29a
// 0096d870  e8b470e8ff           call 0x7f4929
// 0096d875  83c408               add esp, 8
// 0096d878  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805e0;
extern int global_b8060c;
extern ICreator creator_b1f638;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_538900();
const Name &doDeclare();
void destroy_980790();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b805e0, &callDoDeclare_538900);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b1f638;
    global_b8060c = 0x29a;
    atexit(&destroy_980790);
}
