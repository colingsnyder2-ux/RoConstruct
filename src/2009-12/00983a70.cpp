// from server: 100% by nuck16
// roc 2009-12 00983a70  unit: seg_00980000  size: 55 bytes
//
// 00983a70  51                   push ecx
// 00983a71  68c09b6400           push 0x649bc0
// 00983a76  688460b800           push 0xb86084
// 00983a7b  c7055c2bb30008dc9c00 mov dword ptr [0xb32b5c], 0x9cdc08
// 00983a85  e8a6dba7ff           call 0x401630
// 00983a8a  83c408               add esp, 8
// 00983a8d  e88e5bccff           call 0x649620
// 00983a92  890424               mov dword ptr [esp], eax
// 00983a95  8d0424               lea eax, [esp]
// 00983a98  50                   push eax
// 00983a99  e8e2dea7ff           call 0x401980
// 00983a9e  8bc8                 mov ecx, eax
// 00983aa0  e8abdda7ff           call 0x401850
// 00983aa5  59                   pop ecx
// 00983aa6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86084;
extern const int data_009cdc08[];
extern int global_b32b5c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649bc0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b5c = (int)data_009cdc08;
    call_once(flag_b86084, &callDoDeclare_649bc0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
