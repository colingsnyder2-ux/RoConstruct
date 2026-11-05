// from server: 100% by nuck16
// roc 2009-12 009718c0  unit: seg_00970000  size: 73 bytes
//
// 009718c0  51                   push ecx
// 009718c1  68c0996400           push 0x6499c0
// 009718c6  680460b800           push 0xb86004
// 009718cb  e860fda8ff           call 0x401630
// 009718d0  83c408               add esp, 8
// 009718d3  e8486fcdff           call 0x648820
// 009718d8  890424               mov dword ptr [esp], eax
// 009718db  8d0424               lea eax, [esp]
// 009718de  50                   push eax
// 009718df  e89c00a9ff           call 0x401980
// 009718e4  8bc8                 mov ecx, eax
// 009718e6  e8353cadff           call 0x445520
// 009718eb  c700dc2ab300         mov dword ptr [eax], 0xb32adc
// 009718f1  6870429800           push 0x984270
// 009718f6  c70530fcb8009a020000 mov dword ptr [0xb8fc30], 0x29a
// 00971900  e82430e8ff           call 0x7f4929
// 00971905  83c408               add esp, 8
// 00971908  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86004;
extern int global_b8fc30;
extern ICreator creator_b32adc;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6499c0();
const Name &doDeclare();
void destroy_984270();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86004, &callDoDeclare_6499c0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32adc;
    global_b8fc30 = 0x29a;
    atexit(&destroy_984270);
}
