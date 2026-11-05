// from server: 100% by nuck16
// roc 2009-12 0097d9c0  unit: seg_00970000  size: 55 bytes
//
// 0097d9c0  51                   push ecx
// 0097d9c1  6880954000           push 0x409580
// 0097d9c6  681496b700           push 0xb79614
// 0097d9cb  c705581db0007c029a00 mov dword ptr [0xb01d58], 0x9a027c
// 0097d9d5  e8563ca8ff           call 0x401630
// 0097d9da  83c408               add esp, 8
// 0097d9dd  e8feb7a8ff           call 0x4091e0
// 0097d9e2  890424               mov dword ptr [esp], eax
// 0097d9e5  8d0424               lea eax, [esp]
// 0097d9e8  50                   push eax
// 0097d9e9  e8923fa8ff           call 0x401980
// 0097d9ee  8bc8                 mov ecx, eax
// 0097d9f0  e85b3ea8ff           call 0x401850
// 0097d9f5  59                   pop ecx
// 0097d9f6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79614;
extern const int data_009a027c[];
extern int global_b01d58;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_409580();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b01d58 = (int)data_009a027c;
    call_once(flag_b79614, &callDoDeclare_409580);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
