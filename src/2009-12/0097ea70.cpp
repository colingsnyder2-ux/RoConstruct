// from server: 100% by nuck16
// roc 2009-12 0097ea70  unit: seg_00970000  size: 55 bytes
//
// 0097ea70  51                   push ecx
// 0097ea71  6810674500           push 0x456710
// 0097ea76  68f0b7b700           push 0xb7b7f0
// 0097ea7b  c705c89cb000d0cd9a00 mov dword ptr [0xb09cc8], 0x9acdd0
// 0097ea85  e8a62ba8ff           call 0x401630
// 0097ea8a  83c408               add esp, 8
// 0097ea8d  e8fe63adff           call 0x454e90
// 0097ea92  890424               mov dword ptr [esp], eax
// 0097ea95  8d0424               lea eax, [esp]
// 0097ea98  50                   push eax
// 0097ea99  e8e22ea8ff           call 0x401980
// 0097ea9e  8bc8                 mov ecx, eax
// 0097eaa0  e8ab2da8ff           call 0x401850
// 0097eaa5  59                   pop ecx
// 0097eaa6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b7f0;
extern const int data_009acdd0[];
extern int global_b09cc8;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_456710();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b09cc8 = (int)data_009acdd0;
    call_once(flag_b7b7f0, &callDoDeclare_456710);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
