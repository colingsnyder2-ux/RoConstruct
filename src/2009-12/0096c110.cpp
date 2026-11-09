// from server: 100% by nuck16
// roc 2009-12 0096c110  unit: seg_00960000  size: 73 bytes
//
// 0096c110  51                   push ecx
// 0096c111  68b0684f00           push 0x4f68b0
// 0096c116  6860deb700           push 0xb7de60
// 0096c11b  e81055a9ff           call 0x401630
// 0096c120  83c408               add esp, 8
// 0096c123  e8b897b8ff           call 0x4f58e0
// 0096c128  890424               mov dword ptr [esp], eax
// 0096c12b  8d0424               lea eax, [esp]
// 0096c12e  50                   push eax
// 0096c12f  e84c58a9ff           call 0x401980
// 0096c134  8bc8                 mov ecx, eax
// 0096c136  e8e593adff           call 0x445520
// 0096c13b  c700907fb100         mov dword ptr [eax], 0xb17f90
// 0096c141  68e0f69700           push 0x97f6e0
// 0096c146  c705c4dfb7009a020000 mov dword ptr [0xb7dfc4], 0x29a
// 0096c150  e8d487e8ff           call 0x7f4929
// 0096c155  83c408               add esp, 8
// 0096c158  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de60;
extern int global_b7dfc4;
extern ICreator creator_b17f90;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f68b0();
const Name &doDeclare();
void destroy_97f6e0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7de60, &callDoDeclare_4f68b0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b17f90;
    global_b7dfc4 = 0x29a;
    atexit(&destroy_97f6e0);
}
