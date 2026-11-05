// from server: 100% by nuck16
// roc 2009-12 00984070  unit: seg_00980000  size: 55 bytes
//
// 00984070  51                   push ecx
// 00984071  68409a6400           push 0x649a40
// 00984076  682460b800           push 0xb86024
// 0098407b  c705fc2ab30000d39c00 mov dword ptr [0xb32afc], 0x9cd300
// 00984085  e8a6d5a7ff           call 0x401630
// 0098408a  83c408               add esp, 8
// 0098408d  e80e4bccff           call 0x648ba0
// 00984092  890424               mov dword ptr [esp], eax
// 00984095  8d0424               lea eax, [esp]
// 00984098  50                   push eax
// 00984099  e8e2d8a7ff           call 0x401980
// 0098409e  8bc8                 mov ecx, eax
// 009840a0  e8abd7a7ff           call 0x401850
// 009840a5  59                   pop ecx
// 009840a6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86024;
extern const int data_009cd300[];
extern int global_b32afc;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a40();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32afc = (int)data_009cd300;
    call_once(flag_b86024, &callDoDeclare_649a40);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
