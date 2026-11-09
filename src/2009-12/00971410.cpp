// from server: 100% by nuck16
// roc 2009-12 00971410  unit: seg_00970000  size: 73 bytes
//
// 00971410  51                   push ecx
// 00971411  68d0986400           push 0x6498d0
// 00971416  68c85fb800           push 0xb85fc8
// 0097141b  e81002a9ff           call 0x401630
// 00971420  83c408               add esp, 8
// 00971423  e8686dcdff           call 0x648190
// 00971428  890424               mov dword ptr [esp], eax
// 0097142b  8d0424               lea eax, [esp]
// 0097142e  50                   push eax
// 0097142f  e84c05a9ff           call 0x401980
// 00971434  8bc8                 mov ecx, eax
// 00971436  e8e540adff           call 0x445520
// 0097143b  c700a02ab300         mov dword ptr [eax], 0xb32aa0
// 00971441  6830469800           push 0x984630
// 00971446  c705f4fbb8009a020000 mov dword ptr [0xb8fbf4], 0x29a
// 00971450  e8d434e8ff           call 0x7f4929
// 00971455  83c408               add esp, 8
// 00971458  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fc8;
extern int global_b8fbf4;
extern ICreator creator_b32aa0;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6498d0();
const Name &doDeclare();
void destroy_984630();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b85fc8, &callDoDeclare_6498d0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32aa0;
    global_b8fbf4 = 0x29a;
    atexit(&destroy_984630);
}
