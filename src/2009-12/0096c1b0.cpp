// from server: 100% by nuck16
// roc 2009-12 0096c1b0  unit: seg_00960000  size: 73 bytes
//
// 0096c1b0  51                   push ecx
// 0096c1b1  68d0684f00           push 0x4f68d0
// 0096c1b6  6868deb700           push 0xb7de68
// 0096c1bb  e87054a9ff           call 0x401630
// 0096c1c0  83c408               add esp, 8
// 0096c1c3  e8f897b8ff           call 0x4f59c0
// 0096c1c8  890424               mov dword ptr [esp], eax
// 0096c1cb  8d0424               lea eax, [esp]
// 0096c1ce  50                   push eax
// 0096c1cf  e8ac57a9ff           call 0x401980
// 0096c1d4  8bc8                 mov ecx, eax
// 0096c1d6  e84593adff           call 0x445520
// 0096c1db  c700987fb100         mov dword ptr [eax], 0xb17f98
// 0096c1e1  6860f69700           push 0x97f660
// 0096c1e6  c705ccdfb7009a020000 mov dword ptr [0xb7dfcc], 0x29a
// 0096c1f0  e83487e8ff           call 0x7f4929
// 0096c1f5  83c408               add esp, 8
// 0096c1f8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de68;
extern int global_b7dfcc;
extern ICreator creator_b17f98;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f68d0();
const Name &doDeclare();
void destroy_97f660();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7de68, &callDoDeclare_4f68d0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b17f98;
    global_b7dfcc = 0x29a;
    atexit(&destroy_97f660);
}
