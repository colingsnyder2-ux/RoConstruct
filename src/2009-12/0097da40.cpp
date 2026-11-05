// from server: 100% by nuck16
// roc 2009-12 0097da40  unit: seg_00970000  size: 55 bytes
//
// 0097da40  51                   push ecx
// 0097da41  6860954000           push 0x409560
// 0097da46  680c96b700           push 0xb7960c
// 0097da4b  c705501db0006c019a00 mov dword ptr [0xb01d50], 0x9a016c
// 0097da55  e8d63ba8ff           call 0x401630
// 0097da5a  83c408               add esp, 8
// 0097da5d  e89eb6a8ff           call 0x409100
// 0097da62  890424               mov dword ptr [esp], eax
// 0097da65  8d0424               lea eax, [esp]
// 0097da68  50                   push eax
// 0097da69  e8123fa8ff           call 0x401980
// 0097da6e  8bc8                 mov ecx, eax
// 0097da70  e8db3da8ff           call 0x401850
// 0097da75  59                   pop ecx
// 0097da76  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7960c;
extern const int data_009a016c[];
extern int global_b01d50;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_409560();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b01d50 = (int)data_009a016c;
    call_once(flag_b7960c, &callDoDeclare_409560);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
