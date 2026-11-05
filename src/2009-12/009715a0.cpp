// from server: 100% by nuck16
// roc 2009-12 009715a0  unit: seg_00970000  size: 73 bytes
//
// 009715a0  51                   push ecx
// 009715a1  6820996400           push 0x649920
// 009715a6  68dc5fb800           push 0xb85fdc
// 009715ab  e88000a9ff           call 0x401630
// 009715b0  83c408               add esp, 8
// 009715b3  e8086ecdff           call 0x6483c0
// 009715b8  890424               mov dword ptr [esp], eax
// 009715bb  8d0424               lea eax, [esp]
// 009715be  50                   push eax
// 009715bf  e8bc03a9ff           call 0x401980
// 009715c4  8bc8                 mov ecx, eax
// 009715c6  e8553fadff           call 0x445520
// 009715cb  c700b42ab300         mov dword ptr [eax], 0xb32ab4
// 009715d1  68f0449800           push 0x9844f0
// 009715d6  c70508fcb8009a020000 mov dword ptr [0xb8fc08], 0x29a
// 009715e0  e84433e8ff           call 0x7f4929
// 009715e5  83c408               add esp, 8
// 009715e8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fdc;
extern int global_b8fc08;
extern ICreator creator_b32ab4;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649920();
const Name &doDeclare();
void destroy_9844f0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b85fdc, &callDoDeclare_649920);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32ab4;
    global_b8fc08 = 0x29a;
    atexit(&destroy_9844f0);
}
