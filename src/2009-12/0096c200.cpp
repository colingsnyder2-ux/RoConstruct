// from server: 100% by nuck16
// roc 2009-12 0096c200  unit: seg_00960000  size: 73 bytes
//
// 0096c200  51                   push ecx
// 0096c201  68e0684f00           push 0x4f68e0
// 0096c206  686cdeb700           push 0xb7de6c
// 0096c20b  e82054a9ff           call 0x401630
// 0096c210  83c408               add esp, 8
// 0096c213  e81898b8ff           call 0x4f5a30
// 0096c218  890424               mov dword ptr [esp], eax
// 0096c21b  8d0424               lea eax, [esp]
// 0096c21e  50                   push eax
// 0096c21f  e85c57a9ff           call 0x401980
// 0096c224  8bc8                 mov ecx, eax
// 0096c226  e8f592adff           call 0x445520
// 0096c22b  c7009c7fb100         mov dword ptr [eax], 0xb17f9c
// 0096c231  6820f69700           push 0x97f620
// 0096c236  c705d0dfb7009a020000 mov dword ptr [0xb7dfd0], 0x29a
// 0096c240  e8e486e8ff           call 0x7f4929
// 0096c245  83c408               add esp, 8
// 0096c248  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de6c;
extern int global_b7dfd0;
extern ICreator creator_b17f9c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f68e0();
const Name &doDeclare();
void destroy_97f620();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7de6c, &callDoDeclare_4f68e0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b17f9c;
    global_b7dfd0 = 0x29a;
    atexit(&destroy_97f620);
}
