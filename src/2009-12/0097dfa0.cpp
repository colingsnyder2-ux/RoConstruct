// from server: 100% by nuck16
// roc 2009-12 0097dfa0  unit: seg_00970000  size: 55 bytes
//
// 0097dfa0  51                   push ecx
// 0097dfa1  6810364300           push 0x433610
// 0097dfa6  6870a3b700           push 0xb7a370
// 0097dfab  c705ac6bb000d47e9a00 mov dword ptr [0xb06bac], 0x9a7ed4
// 0097dfb5  e87636a8ff           call 0x401630
// 0097dfba  83c408               add esp, 8
// 0097dfbd  e84e4fabff           call 0x432f10
// 0097dfc2  890424               mov dword ptr [esp], eax
// 0097dfc5  8d0424               lea eax, [esp]
// 0097dfc8  50                   push eax
// 0097dfc9  e8b239a8ff           call 0x401980
// 0097dfce  8bc8                 mov ecx, eax
// 0097dfd0  e87b38a8ff           call 0x401850
// 0097dfd5  59                   pop ecx
// 0097dfd6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a370;
extern const int data_009a7ed4[];
extern int global_b06bac;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_433610();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b06bac = (int)data_009a7ed4;
    call_once(flag_b7a370, &callDoDeclare_433610);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
