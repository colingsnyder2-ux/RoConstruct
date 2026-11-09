// from server: 100% by nuck16
// roc 2009-12 0097dac0  unit: seg_00970000  size: 55 bytes
//
// 0097dac0  51                   push ecx
// 0097dac1  6840954000           push 0x409540
// 0097dac6  680496b700           push 0xb79604
// 0097dacb  c705481db000f0ff9900 mov dword ptr [0xb01d48], 0x99fff0
// 0097dad5  e8563ba8ff           call 0x401630
// 0097dada  83c408               add esp, 8
// 0097dadd  e83eb5a8ff           call 0x409020
// 0097dae2  890424               mov dword ptr [esp], eax
// 0097dae5  8d0424               lea eax, [esp]
// 0097dae8  50                   push eax
// 0097dae9  e8923ea8ff           call 0x401980
// 0097daee  8bc8                 mov ecx, eax
// 0097daf0  e85b3da8ff           call 0x401850
// 0097daf5  59                   pop ecx
// 0097daf6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79604;
extern const int data_0099fff0[];
extern int global_b01d48;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_409540();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b01d48 = (int)data_0099fff0;
    call_once(flag_b79604, &callDoDeclare_409540);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
