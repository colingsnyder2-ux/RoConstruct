// from server: 100% by nuck16
// roc 2009-12 009696a0  unit: seg_00960000  size: 73 bytes
//
// 009696a0  51                   push ecx
// 009696a1  6810cd4400           push 0x44cd10
// 009696a6  6890b4b700           push 0xb7b490
// 009696ab  e8807fa9ff           call 0x401630
// 009696b0  83c408               add esp, 8
// 009696b3  e8e825aeff           call 0x44bca0
// 009696b8  890424               mov dword ptr [esp], eax
// 009696bb  8d0424               lea eax, [esp]
// 009696be  50                   push eax
// 009696bf  e8bc82a9ff           call 0x401980
// 009696c4  8bc8                 mov ecx, eax
// 009696c6  e855beadff           call 0x445520
// 009696cb  c700e894b000         mov dword ptr [eax], 0xb094e8
// 009696d1  68a0e99700           push 0x97e9a0
// 009696d6  c70514b6b7009a020000 mov dword ptr [0xb7b614], 0x29a
// 009696e0  e844b2e8ff           call 0x7f4929
// 009696e5  83c408               add esp, 8
// 009696e8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b490;
extern int global_b7b614;
extern ICreator creator_b094e8;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_44cd10();
const Name &doDeclare();
void destroy_97e9a0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7b490, &callDoDeclare_44cd10);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b094e8;
    global_b7b614 = 0x29a;
    atexit(&destroy_97e9a0);
}
