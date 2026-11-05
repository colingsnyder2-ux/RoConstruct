// from server: 100% by nuck16
// roc 2009-12 0097de10  unit: seg_00970000  size: 55 bytes
//
// 0097de10  51                   push ecx
// 0097de11  68a0684200           push 0x4268a0
// 0097de16  68a0a2b700           push 0xb7a2a0
// 0097de1b  c705484ab000c0399a00 mov dword ptr [0xb04a48], 0x9a39c0
// 0097de25  e80638a8ff           call 0x401630
// 0097de2a  83c408               add esp, 8
// 0097de2d  e8ee88aaff           call 0x426720
// 0097de32  890424               mov dword ptr [esp], eax
// 0097de35  8d0424               lea eax, [esp]
// 0097de38  50                   push eax
// 0097de39  e8423ba8ff           call 0x401980
// 0097de3e  8bc8                 mov ecx, eax
// 0097de40  e80b3aa8ff           call 0x401850
// 0097de45  59                   pop ecx
// 0097de46  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a2a0;
extern const int data_009a39c0[];
extern int global_b04a48;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4268a0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b04a48 = (int)data_009a39c0;
    call_once(flag_b7a2a0, &callDoDeclare_4268a0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
