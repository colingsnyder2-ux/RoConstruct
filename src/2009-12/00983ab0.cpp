// from server: 100% by nuck16
// roc 2009-12 00983ab0  unit: seg_00980000  size: 55 bytes
//
// 00983ab0  51                   push ecx
// 00983ab1  68b09b6400           push 0x649bb0
// 00983ab6  688060b800           push 0xb86080
// 00983abb  c705582bb30080db9c00 mov dword ptr [0xb32b58], 0x9cdb80
// 00983ac5  e866dba7ff           call 0x401630
// 00983aca  83c408               add esp, 8
// 00983acd  e8de5accff           call 0x6495b0
// 00983ad2  890424               mov dword ptr [esp], eax
// 00983ad5  8d0424               lea eax, [esp]
// 00983ad8  50                   push eax
// 00983ad9  e8a2dea7ff           call 0x401980
// 00983ade  8bc8                 mov ecx, eax
// 00983ae0  e86bdda7ff           call 0x401850
// 00983ae5  59                   pop ecx
// 00983ae6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86080;
extern const int data_009cdb80[];
extern int global_b32b58;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649bb0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b58 = (int)data_009cdb80;
    call_once(flag_b86080, &callDoDeclare_649bb0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
