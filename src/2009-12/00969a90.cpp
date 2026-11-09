// from server: 100% by nuck16
// roc 2009-12 00969a90  unit: seg_00960000  size: 73 bytes
//
// 00969a90  51                   push ecx
// 00969a91  68602d4600           push 0x462d60
// 00969a96  68d4b9b700           push 0xb7b9d4
// 00969a9b  e8907ba9ff           call 0x401630
// 00969aa0  83c408               add esp, 8
// 00969aa3  e81884afff           call 0x461ec0
// 00969aa8  890424               mov dword ptr [esp], eax
// 00969aab  8d0424               lea eax, [esp]
// 00969aae  50                   push eax
// 00969aaf  e8cc7ea9ff           call 0x401980
// 00969ab4  8bc8                 mov ecx, eax
// 00969ab6  e865baadff           call 0x445520
// 00969abb  c700d8b4b000         mov dword ptr [eax], 0xb0b4d8
// 00969ac1  6890eb9700           push 0x97eb90
// 00969ac6  c70500bbb7009a020000 mov dword ptr [0xb7bb00], 0x29a
// 00969ad0  e854aee8ff           call 0x7f4929
// 00969ad5  83c408               add esp, 8
// 00969ad8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9d4;
extern int global_b7bb00;
extern ICreator creator_b0b4d8;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d60();
const Name &doDeclare();
void destroy_97eb90();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7b9d4, &callDoDeclare_462d60);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b0b4d8;
    global_b7bb00 = 0x29a;
    atexit(&destroy_97eb90);
}
