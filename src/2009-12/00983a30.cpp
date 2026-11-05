// from server: 100% by nuck16
// roc 2009-12 00983a30  unit: seg_00980000  size: 55 bytes
//
// 00983a30  51                   push ecx
// 00983a31  68d09b6400           push 0x649bd0
// 00983a36  688860b800           push 0xb86088
// 00983a3b  c705602bb30090dc9c00 mov dword ptr [0xb32b60], 0x9cdc90
// 00983a45  e8e6dba7ff           call 0x401630
// 00983a4a  83c408               add esp, 8
// 00983a4d  e83e5cccff           call 0x649690
// 00983a52  890424               mov dword ptr [esp], eax
// 00983a55  8d0424               lea eax, [esp]
// 00983a58  50                   push eax
// 00983a59  e822dfa7ff           call 0x401980
// 00983a5e  8bc8                 mov ecx, eax
// 00983a60  e8ebdda7ff           call 0x401850
// 00983a65  59                   pop ecx
// 00983a66  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86088;
extern const int data_009cdc90[];
extern int global_b32b60;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649bd0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b60 = (int)data_009cdc90;
    call_once(flag_b86088, &callDoDeclare_649bd0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
