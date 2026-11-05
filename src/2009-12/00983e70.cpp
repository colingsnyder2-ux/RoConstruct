// from server: 100% by nuck16
// roc 2009-12 00983e70  unit: seg_00980000  size: 55 bytes
//
// 00983e70  51                   push ecx
// 00983e71  68c09a6400           push 0x649ac0
// 00983e76  684460b800           push 0xb86044
// 00983e7b  c7051c2bb3002cd89c00 mov dword ptr [0xb32b1c], 0x9cd82c
// 00983e85  e8a6d7a7ff           call 0x401630
// 00983e8a  83c408               add esp, 8
// 00983e8d  e88e50ccff           call 0x648f20
// 00983e92  890424               mov dword ptr [esp], eax
// 00983e95  8d0424               lea eax, [esp]
// 00983e98  50                   push eax
// 00983e99  e8e2daa7ff           call 0x401980
// 00983e9e  8bc8                 mov ecx, eax
// 00983ea0  e8abd9a7ff           call 0x401850
// 00983ea5  59                   pop ecx
// 00983ea6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86044;
extern const int data_009cd82c[];
extern int global_b32b1c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649ac0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b1c = (int)data_009cd82c;
    call_once(flag_b86044, &callDoDeclare_649ac0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
