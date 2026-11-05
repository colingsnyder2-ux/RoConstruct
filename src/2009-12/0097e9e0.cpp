// from server: 100% by nuck16
// roc 2009-12 0097e9e0  unit: seg_00970000  size: 55 bytes
//
// 0097e9e0  51                   push ecx
// 0097e9e1  6800cd4400           push 0x44cd00
// 0097e9e6  688cb4b700           push 0xb7b48c
// 0097e9eb  c705e494b00078b69a00 mov dword ptr [0xb094e4], 0x9ab678
// 0097e9f5  e8362ca8ff           call 0x401630
// 0097e9fa  83c408               add esp, 8
// 0097e9fd  e82ed2acff           call 0x44bc30
// 0097ea02  890424               mov dword ptr [esp], eax
// 0097ea05  8d0424               lea eax, [esp]
// 0097ea08  50                   push eax
// 0097ea09  e8722fa8ff           call 0x401980
// 0097ea0e  8bc8                 mov ecx, eax
// 0097ea10  e83b2ea8ff           call 0x401850
// 0097ea15  59                   pop ecx
// 0097ea16  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b48c;
extern const int data_009ab678[];
extern int global_b094e4;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_44cd00();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b094e4 = (int)data_009ab678;
    call_once(flag_b7b48c, &callDoDeclare_44cd00);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
