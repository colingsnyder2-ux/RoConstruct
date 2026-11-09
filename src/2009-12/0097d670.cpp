// from server: 100% by nuck16
// roc 2009-12 0097d670  unit: seg_00970000  size: 55 bytes
//
// 0097d670  51                   push ecx
// 0097d671  68e0164000           push 0x4016e0
// 0097d676  681c94b700           push 0xb7941c
// 0097d67b  c70570f4af0018f59900 mov dword ptr [0xaff470], 0x99f518
// 0097d685  e8a63fa8ff           call 0x401630
// 0097d68a  83c408               add esp, 8
// 0097d68d  e89e3ca8ff           call 0x401330
// 0097d692  890424               mov dword ptr [esp], eax
// 0097d695  8d0424               lea eax, [esp]
// 0097d698  50                   push eax
// 0097d699  e8e242a8ff           call 0x401980
// 0097d69e  8bc8                 mov ecx, eax
// 0097d6a0  e8ab41a8ff           call 0x401850
// 0097d6a5  59                   pop ecx
// 0097d6a6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7941c;
extern const int data_0099f518[];
extern int global_aff470;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4016e0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_aff470 = (int)data_0099f518;
    call_once(flag_b7941c, &callDoDeclare_4016e0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
