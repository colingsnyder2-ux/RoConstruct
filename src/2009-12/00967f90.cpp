// from server: 100% by nuck16
// roc 2009-12 00967f90  unit: seg_00960000  size: 73 bytes
//
// 00967f90  51                   push ecx
// 00967f91  6820414000           push 0x404120
// 00967f96  688c95b700           push 0xb7958c
// 00967f9b  e89096a9ff           call 0x401630
// 00967fa0  83c408               add esp, 8
// 00967fa3  e828baa9ff           call 0x4039d0
// 00967fa8  890424               mov dword ptr [esp], eax
// 00967fab  8d0424               lea eax, [esp]
// 00967fae  50                   push eax
// 00967faf  e8cc99a9ff           call 0x401980
// 00967fb4  8bc8                 mov ecx, eax
// 00967fb6  e865d5adff           call 0x445520
// 00967fbb  c700a0fdaf00         mov dword ptr [eax], 0xaffda0
// 00967fc1  68a0d79700           push 0x97d7a0
// 00967fc6  c7059895b7009a020000 mov dword ptr [0xb79598], 0x29a
// 00967fd0  e854c9e8ff           call 0x7f4929
// 00967fd5  83c408               add esp, 8
// 00967fd8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7958c;
extern int global_b79598;
extern ICreator creator_affda0;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_404120();
const Name &doDeclare();
void destroy_97d7a0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7958c, &callDoDeclare_404120);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_affda0;
    global_b79598 = 0x29a;
    atexit(&destroy_97d7a0);
}
