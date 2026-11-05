// from server: 100% by nuck16
// roc 2009-12 0097d7a0  unit: seg_00970000  size: 55 bytes
//
// 0097d7a0  51                   push ecx
// 0097d7a1  6820414000           push 0x404120
// 0097d7a6  688c95b700           push 0xb7958c
// 0097d7ab  c705a0fdaf0008fd9900 mov dword ptr [0xaffda0], 0x99fd08
// 0097d7b5  e8763ea8ff           call 0x401630
// 0097d7ba  83c408               add esp, 8
// 0097d7bd  e80e62a8ff           call 0x4039d0
// 0097d7c2  890424               mov dword ptr [esp], eax
// 0097d7c5  8d0424               lea eax, [esp]
// 0097d7c8  50                   push eax
// 0097d7c9  e8b241a8ff           call 0x401980
// 0097d7ce  8bc8                 mov ecx, eax
// 0097d7d0  e87b40a8ff           call 0x401850
// 0097d7d5  59                   pop ecx
// 0097d7d6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7958c;
extern const int data_0099fd08[];
extern int global_affda0;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_404120();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_affda0 = (int)data_0099fd08;
    call_once(flag_b7958c, &callDoDeclare_404120);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
