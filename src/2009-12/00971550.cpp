// from server: 100% by nuck16
// roc 2009-12 00971550  unit: seg_00970000  size: 73 bytes
//
// 00971550  51                   push ecx
// 00971551  6810996400           push 0x649910
// 00971556  68d85fb800           push 0xb85fd8
// 0097155b  e8d000a9ff           call 0x401630
// 00971560  83c408               add esp, 8
// 00971563  e8e86dcdff           call 0x648350
// 00971568  890424               mov dword ptr [esp], eax
// 0097156b  8d0424               lea eax, [esp]
// 0097156e  50                   push eax
// 0097156f  e80c04a9ff           call 0x401980
// 00971574  8bc8                 mov ecx, eax
// 00971576  e8a53fadff           call 0x445520
// 0097157b  c700b02ab300         mov dword ptr [eax], 0xb32ab0
// 00971581  6830459800           push 0x984530
// 00971586  c70504fcb8009a020000 mov dword ptr [0xb8fc04], 0x29a
// 00971590  e89433e8ff           call 0x7f4929
// 00971595  83c408               add esp, 8
// 00971598  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fd8;
extern int global_b8fc04;
extern ICreator creator_b32ab0;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649910();
const Name &doDeclare();
void destroy_984530();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b85fd8, &callDoDeclare_649910);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32ab0;
    global_b8fc04 = 0x29a;
    atexit(&destroy_984530);
}
