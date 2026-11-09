// from server: 100% by nuck16
// roc 2009-12 0096a2a0  unit: seg_00960000  size: 73 bytes
//
// 0096a2a0  51                   push ecx
// 0096a2a1  68c02d4c00           push 0x4c2dc0
// 0096a2a6  6894cfb700           push 0xb7cf94
// 0096a2ab  e88073a9ff           call 0x401630
// 0096a2b0  83c408               add esp, 8
// 0096a2b3  e8587fb5ff           call 0x4c2210
// 0096a2b8  890424               mov dword ptr [esp], eax
// 0096a2bb  8d0424               lea eax, [esp]
// 0096a2be  50                   push eax
// 0096a2bf  e8bc76a9ff           call 0x401980
// 0096a2c4  8bc8                 mov ecx, eax
// 0096a2c6  e855b2adff           call 0x445520
// 0096a2cb  c7007c0eb100         mov dword ptr [eax], 0xb10e7c
// 0096a2d1  6840ef9700           push 0x97ef40
// 0096a2d6  c7059ccfb7009a020000 mov dword ptr [0xb7cf9c], 0x29a
// 0096a2e0  e844a6e8ff           call 0x7f4929
// 0096a2e5  83c408               add esp, 8
// 0096a2e8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7cf94;
extern int global_b7cf9c;
extern ICreator creator_b10e7c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4c2dc0();
const Name &doDeclare();
void destroy_97ef40();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7cf94, &callDoDeclare_4c2dc0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b10e7c;
    global_b7cf9c = 0x29a;
    atexit(&destroy_97ef40);
}
