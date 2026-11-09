// from server: 100% by nuck16
// roc 2009-12 00983c30  unit: seg_00980000  size: 55 bytes
//
// 00983c30  51                   push ecx
// 00983c31  68509b6400           push 0x649b50
// 00983c36  686860b800           push 0xb86068
// 00983c3b  c705402bb30028d99c00 mov dword ptr [0xb32b40], 0x9cd928
// 00983c45  e8e6d9a7ff           call 0x401630
// 00983c4a  83c408               add esp, 8
// 00983c4d  e8be56ccff           call 0x649310
// 00983c52  890424               mov dword ptr [esp], eax
// 00983c55  8d0424               lea eax, [esp]
// 00983c58  50                   push eax
// 00983c59  e822dda7ff           call 0x401980
// 00983c5e  8bc8                 mov ecx, eax
// 00983c60  e8ebdba7ff           call 0x401850
// 00983c65  59                   pop ecx
// 00983c66  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86068;
extern const int data_009cd928[];
extern int global_b32b40;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b50();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b40 = (int)data_009cd928;
    call_once(flag_b86068, &callDoDeclare_649b50);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
