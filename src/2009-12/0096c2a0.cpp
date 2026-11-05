// from server: 100% by nuck16
// roc 2009-12 0096c2a0  unit: seg_00960000  size: 73 bytes
//
// 0096c2a0  51                   push ecx
// 0096c2a1  6800694f00           push 0x4f6900
// 0096c2a6  6874deb700           push 0xb7de74
// 0096c2ab  e88053a9ff           call 0x401630
// 0096c2b0  83c408               add esp, 8
// 0096c2b3  e85898b8ff           call 0x4f5b10
// 0096c2b8  890424               mov dword ptr [esp], eax
// 0096c2bb  8d0424               lea eax, [esp]
// 0096c2be  50                   push eax
// 0096c2bf  e8bc56a9ff           call 0x401980
// 0096c2c4  8bc8                 mov ecx, eax
// 0096c2c6  e85592adff           call 0x445520
// 0096c2cb  c700a47fb100         mov dword ptr [eax], 0xb17fa4
// 0096c2d1  68a0f59700           push 0x97f5a0
// 0096c2d6  c705d8e0b7009a020000 mov dword ptr [0xb7e0d8], 0x29a
// 0096c2e0  e84486e8ff           call 0x7f4929
// 0096c2e5  83c408               add esp, 8
// 0096c2e8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de74;
extern int global_b7e0d8;
extern ICreator creator_b17fa4;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6900();
const Name &doDeclare();
void destroy_97f5a0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7de74, &callDoDeclare_4f6900);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b17fa4;
    global_b7e0d8 = 0x29a;
    atexit(&destroy_97f5a0);
}
