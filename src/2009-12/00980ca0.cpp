// from server: 100% by nuck16
// roc 2009-12 00980ca0  unit: seg_00980000  size: 55 bytes
//
// 00980ca0  51                   push ecx
// 00980ca1  68507c5700           push 0x577c50
// 00980ca6  687427b800           push 0xb82774
// 00980cab  c705f84eb200200b9c00 mov dword ptr [0xb24ef8], 0x9c0b20
// 00980cb5  e87609a8ff           call 0x401630
// 00980cba  83c408               add esp, 8
// 00980cbd  e85e6bbfff           call 0x577820
// 00980cc2  890424               mov dword ptr [esp], eax
// 00980cc5  8d0424               lea eax, [esp]
// 00980cc8  50                   push eax
// 00980cc9  e8b20ca8ff           call 0x401980
// 00980cce  8bc8                 mov ecx, eax
// 00980cd0  e87b0ba8ff           call 0x401850
// 00980cd5  59                   pop ecx
// 00980cd6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b82774;
extern const int data_009c0b20[];
extern int global_b24ef8;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_577c50();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b24ef8 = (int)data_009c0b20;
    call_once(flag_b82774, &callDoDeclare_577c50);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
