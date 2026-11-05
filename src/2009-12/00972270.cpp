// from server: 100% by nuck16
// roc 2009-12 00972270  unit: seg_00970000  size: 73 bytes
//
// 00972270  51                   push ecx
// 00972271  68b09b6400           push 0x649bb0
// 00972276  688060b800           push 0xb86080
// 0097227b  e8b0f3a8ff           call 0x401630
// 00972280  83c408               add esp, 8
// 00972283  e82873cdff           call 0x6495b0
// 00972288  890424               mov dword ptr [esp], eax
// 0097228b  8d0424               lea eax, [esp]
// 0097228e  50                   push eax
// 0097228f  e8ecf6a8ff           call 0x401980
// 00972294  8bc8                 mov ecx, eax
// 00972296  e88532adff           call 0x445520
// 0097229b  c700582bb300         mov dword ptr [eax], 0xb32b58
// 009722a1  68b03a9800           push 0x983ab0
// 009722a6  c705bcfcb8009a020000 mov dword ptr [0xb8fcbc], 0x29a
// 009722b0  e87426e8ff           call 0x7f4929
// 009722b5  83c408               add esp, 8
// 009722b8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86080;
extern int global_b8fcbc;
extern ICreator creator_b32b58;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649bb0();
const Name &doDeclare();
void destroy_983ab0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86080, &callDoDeclare_649bb0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b58;
    global_b8fcbc = 0x29a;
    atexit(&destroy_983ab0);
}
