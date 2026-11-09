// from server: 100% by nuck16
// roc 2009-12 0096c160  unit: seg_00960000  size: 73 bytes
//
// 0096c160  51                   push ecx
// 0096c161  68c0684f00           push 0x4f68c0
// 0096c166  6864deb700           push 0xb7de64
// 0096c16b  e8c054a9ff           call 0x401630
// 0096c170  83c408               add esp, 8
// 0096c173  e8d897b8ff           call 0x4f5950
// 0096c178  890424               mov dword ptr [esp], eax
// 0096c17b  8d0424               lea eax, [esp]
// 0096c17e  50                   push eax
// 0096c17f  e8fc57a9ff           call 0x401980
// 0096c184  8bc8                 mov ecx, eax
// 0096c186  e89593adff           call 0x445520
// 0096c18b  c700947fb100         mov dword ptr [eax], 0xb17f94
// 0096c191  68a0f69700           push 0x97f6a0
// 0096c196  c705c8dfb7009a020000 mov dword ptr [0xb7dfc8], 0x29a
// 0096c1a0  e88487e8ff           call 0x7f4929
// 0096c1a5  83c408               add esp, 8
// 0096c1a8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de64;
extern int global_b7dfc8;
extern ICreator creator_b17f94;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f68c0();
const Name &doDeclare();
void destroy_97f6a0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7de64, &callDoDeclare_4f68c0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b17f94;
    global_b7dfc8 = 0x29a;
    atexit(&destroy_97f6a0);
}
