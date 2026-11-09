// from server: 100% by nuck16
// roc 2009-12 00971500  unit: seg_00970000  size: 73 bytes
//
// 00971500  51                   push ecx
// 00971501  6800996400           push 0x649900
// 00971506  68d45fb800           push 0xb85fd4
// 0097150b  e82001a9ff           call 0x401630
// 00971510  83c408               add esp, 8
// 00971513  e8c86dcdff           call 0x6482e0
// 00971518  890424               mov dword ptr [esp], eax
// 0097151b  8d0424               lea eax, [esp]
// 0097151e  50                   push eax
// 0097151f  e85c04a9ff           call 0x401980
// 00971524  8bc8                 mov ecx, eax
// 00971526  e8f53fadff           call 0x445520
// 0097152b  c700ac2ab300         mov dword ptr [eax], 0xb32aac
// 00971531  6870459800           push 0x984570
// 00971536  c70500fcb8009a020000 mov dword ptr [0xb8fc00], 0x29a
// 00971540  e8e433e8ff           call 0x7f4929
// 00971545  83c408               add esp, 8
// 00971548  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fd4;
extern int global_b8fc00;
extern ICreator creator_b32aac;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649900();
const Name &doDeclare();
void destroy_984570();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b85fd4, &callDoDeclare_649900);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32aac;
    global_b8fc00 = 0x29a;
    atexit(&destroy_984570);
}
