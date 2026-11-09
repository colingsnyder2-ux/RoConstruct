// from server: 100% by nuck16
// roc 2009-12 009715f0  unit: seg_00970000  size: 73 bytes
//
// 009715f0  51                   push ecx
// 009715f1  6830996400           push 0x649930
// 009715f6  68e05fb800           push 0xb85fe0
// 009715fb  e83000a9ff           call 0x401630
// 00971600  83c408               add esp, 8
// 00971603  e8286ecdff           call 0x648430
// 00971608  890424               mov dword ptr [esp], eax
// 0097160b  8d0424               lea eax, [esp]
// 0097160e  50                   push eax
// 0097160f  e86c03a9ff           call 0x401980
// 00971614  8bc8                 mov ecx, eax
// 00971616  e8053fadff           call 0x445520
// 0097161b  c700b82ab300         mov dword ptr [eax], 0xb32ab8
// 00971621  68b0449800           push 0x9844b0
// 00971626  c7050cfcb8009a020000 mov dword ptr [0xb8fc0c], 0x29a
// 00971630  e8f432e8ff           call 0x7f4929
// 00971635  83c408               add esp, 8
// 00971638  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fe0;
extern int global_b8fc0c;
extern ICreator creator_b32ab8;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649930();
const Name &doDeclare();
void destroy_9844b0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b85fe0, &callDoDeclare_649930);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32ab8;
    global_b8fc0c = 0x29a;
    atexit(&destroy_9844b0);
}
