// from server: 100% by nuck16
// roc 2009-12 0097ec90  unit: seg_00970000  size: 55 bytes
//
// 0097ec90  51                   push ecx
// 0097ec91  68102d4600           push 0x462d10
// 0097ec96  68c0b9b700           push 0xb7b9c0
// 0097ec9b  c705c8b4b000c0ea9a00 mov dword ptr [0xb0b4c8], 0x9aeac0
// 0097eca5  e88629a8ff           call 0x401630
// 0097ecaa  83c408               add esp, 8
// 0097ecad  e8de2faeff           call 0x461c90
// 0097ecb2  890424               mov dword ptr [esp], eax
// 0097ecb5  8d0424               lea eax, [esp]
// 0097ecb8  50                   push eax
// 0097ecb9  e8c22ca8ff           call 0x401980
// 0097ecbe  8bc8                 mov ecx, eax
// 0097ecc0  e88b2ba8ff           call 0x401850
// 0097ecc5  59                   pop ecx
// 0097ecc6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9c0;
extern const int data_009aeac0[];
extern int global_b0b4c8;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d10();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b0b4c8 = (int)data_009aeac0;
    call_once(flag_b7b9c0, &callDoDeclare_462d10);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
