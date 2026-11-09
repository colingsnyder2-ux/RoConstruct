// from server: 100% by nuck16
// roc 2009-12 0096c340  unit: seg_00960000  size: 73 bytes
//
// 0096c340  51                   push ecx
// 0096c341  6820694f00           push 0x4f6920
// 0096c346  687cdeb700           push 0xb7de7c
// 0096c34b  e8e052a9ff           call 0x401630
// 0096c350  83c408               add esp, 8
// 0096c353  e89898b8ff           call 0x4f5bf0
// 0096c358  890424               mov dword ptr [esp], eax
// 0096c35b  8d0424               lea eax, [esp]
// 0096c35e  50                   push eax
// 0096c35f  e81c56a9ff           call 0x401980
// 0096c364  8bc8                 mov ecx, eax
// 0096c366  e8b591adff           call 0x445520
// 0096c36b  c700ac7fb100         mov dword ptr [eax], 0xb17fac
// 0096c371  6820f59700           push 0x97f520
// 0096c376  c705e0e0b7009a020000 mov dword ptr [0xb7e0e0], 0x29a
// 0096c380  e8a485e8ff           call 0x7f4929
// 0096c385  83c408               add esp, 8
// 0096c388  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de7c;
extern int global_b7e0e0;
extern ICreator creator_b17fac;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6920();
const Name &doDeclare();
void destroy_97f520();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7de7c, &callDoDeclare_4f6920);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b17fac;
    global_b7e0e0 = 0x29a;
    atexit(&destroy_97f520);
}
