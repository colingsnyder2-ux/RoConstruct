// from server: 100% by nuck16
// roc 2009-12 0096c250  unit: seg_00960000  size: 73 bytes
//
// 0096c250  51                   push ecx
// 0096c251  68f0684f00           push 0x4f68f0
// 0096c256  6870deb700           push 0xb7de70
// 0096c25b  e8d053a9ff           call 0x401630
// 0096c260  83c408               add esp, 8
// 0096c263  e83898b8ff           call 0x4f5aa0
// 0096c268  890424               mov dword ptr [esp], eax
// 0096c26b  8d0424               lea eax, [esp]
// 0096c26e  50                   push eax
// 0096c26f  e80c57a9ff           call 0x401980
// 0096c274  8bc8                 mov ecx, eax
// 0096c276  e8a592adff           call 0x445520
// 0096c27b  c700a07fb100         mov dword ptr [eax], 0xb17fa0
// 0096c281  68e0f59700           push 0x97f5e0
// 0096c286  c705d4e0b7009a020000 mov dword ptr [0xb7e0d4], 0x29a
// 0096c290  e89486e8ff           call 0x7f4929
// 0096c295  83c408               add esp, 8
// 0096c298  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de70;
extern int global_b7e0d4;
extern ICreator creator_b17fa0;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f68f0();
const Name &doDeclare();
void destroy_97f5e0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7de70, &callDoDeclare_4f68f0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b17fa0;
    global_b7e0d4 = 0x29a;
    atexit(&destroy_97f5e0);
}
