// from server: 100% by nuck16
// roc 2009-12 0096a250  unit: seg_00960000  size: 73 bytes
//
// 0096a250  51                   push ecx
// 0096a251  6810054c00           push 0x4c0510
// 0096a256  6868cfb700           push 0xb7cf68
// 0096a25b  e8d073a9ff           call 0x401630
// 0096a260  83c408               add esp, 8
// 0096a263  e8785eb5ff           call 0x4c00e0
// 0096a268  890424               mov dword ptr [esp], eax
// 0096a26b  8d0424               lea eax, [esp]
// 0096a26e  50                   push eax
// 0096a26f  e80c77a9ff           call 0x401980
// 0096a274  8bc8                 mov ecx, eax
// 0096a276  e8a5b2adff           call 0x445520
// 0096a27b  c700bc09b100         mov dword ptr [eax], 0xb109bc
// 0096a281  6800ef9700           push 0x97ef00
// 0096a286  c7056ccfb7009a020000 mov dword ptr [0xb7cf6c], 0x29a
// 0096a290  e894a6e8ff           call 0x7f4929
// 0096a295  83c408               add esp, 8
// 0096a298  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7cf68;
extern int global_b7cf6c;
extern ICreator creator_b109bc;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4c0510();
const Name &doDeclare();
void destroy_97ef00();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7cf68, &callDoDeclare_4c0510);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b109bc;
    global_b7cf6c = 0x29a;
    atexit(&destroy_97ef00);
}
