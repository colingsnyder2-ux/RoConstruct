// from server: 100% by nuck16
// roc 2009-12 0096c0c0  unit: seg_00960000  size: 73 bytes
//
// 0096c0c0  51                   push ecx
// 0096c0c1  68a0684f00           push 0x4f68a0
// 0096c0c6  685cdeb700           push 0xb7de5c
// 0096c0cb  e86055a9ff           call 0x401630
// 0096c0d0  83c408               add esp, 8
// 0096c0d3  e89897b8ff           call 0x4f5870
// 0096c0d8  890424               mov dword ptr [esp], eax
// 0096c0db  8d0424               lea eax, [esp]
// 0096c0de  50                   push eax
// 0096c0df  e89c58a9ff           call 0x401980
// 0096c0e4  8bc8                 mov ecx, eax
// 0096c0e6  e83594adff           call 0x445520
// 0096c0eb  c7008c7fb100         mov dword ptr [eax], 0xb17f8c
// 0096c0f1  6820f79700           push 0x97f720
// 0096c0f6  c705c0dfb7009a020000 mov dword ptr [0xb7dfc0], 0x29a
// 0096c100  e82488e8ff           call 0x7f4929
// 0096c105  83c408               add esp, 8
// 0096c108  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de5c;
extern int global_b7dfc0;
extern ICreator creator_b17f8c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f68a0();
const Name &doDeclare();
void destroy_97f720();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7de5c, &callDoDeclare_4f68a0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b17f8c;
    global_b7dfc0 = 0x29a;
    atexit(&destroy_97f720);
}
