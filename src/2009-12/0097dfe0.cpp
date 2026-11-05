// from server: 100% by nuck16
// roc 2009-12 0097dfe0  unit: seg_00970000  size: 55 bytes
//
// 0097dfe0  51                   push ecx
// 0097dfe1  6800364300           push 0x433600
// 0097dfe6  686ca3b700           push 0xb7a36c
// 0097dfeb  c705a86bb000b87e9a00 mov dword ptr [0xb06ba8], 0x9a7eb8
// 0097dff5  e83636a8ff           call 0x401630
// 0097dffa  83c408               add esp, 8
// 0097dffd  e89e4eabff           call 0x432ea0
// 0097e002  890424               mov dword ptr [esp], eax
// 0097e005  8d0424               lea eax, [esp]
// 0097e008  50                   push eax
// 0097e009  e87239a8ff           call 0x401980
// 0097e00e  8bc8                 mov ecx, eax
// 0097e010  e83b38a8ff           call 0x401850
// 0097e015  59                   pop ecx
// 0097e016  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a36c;
extern const int data_009a7eb8[];
extern int global_b06ba8;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_433600();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b06ba8 = (int)data_009a7eb8;
    call_once(flag_b7a36c, &callDoDeclare_433600);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
