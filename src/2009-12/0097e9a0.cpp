// from server: 100% by nuck16
// roc 2009-12 0097e9a0  unit: seg_00970000  size: 55 bytes
//
// 0097e9a0  51                   push ecx
// 0097e9a1  6810cd4400           push 0x44cd10
// 0097e9a6  6890b4b700           push 0xb7b490
// 0097e9ab  c705e894b00080b69a00 mov dword ptr [0xb094e8], 0x9ab680
// 0097e9b5  e8762ca8ff           call 0x401630
// 0097e9ba  83c408               add esp, 8
// 0097e9bd  e8ded2acff           call 0x44bca0
// 0097e9c2  890424               mov dword ptr [esp], eax
// 0097e9c5  8d0424               lea eax, [esp]
// 0097e9c8  50                   push eax
// 0097e9c9  e8b22fa8ff           call 0x401980
// 0097e9ce  8bc8                 mov ecx, eax
// 0097e9d0  e87b2ea8ff           call 0x401850
// 0097e9d5  59                   pop ecx
// 0097e9d6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b490;
extern const int data_009ab680[];
extern int global_b094e8;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_44cd10();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b094e8 = (int)data_009ab680;
    call_once(flag_b7b490, &callDoDeclare_44cd10);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
