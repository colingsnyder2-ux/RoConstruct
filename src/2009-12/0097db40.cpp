// from server: 100% by nuck16
// roc 2009-12 0097db40  unit: seg_00970000  size: 55 bytes
//
// 0097db40  51                   push ecx
// 0097db41  68003b4100           push 0x413b00
// 0097db46  681ca1b700           push 0xb7a11c
// 0097db4b  c705a433b00058239a00 mov dword ptr [0xb033a4], 0x9a2358
// 0097db55  e8d63aa8ff           call 0x401630
// 0097db5a  83c408               add esp, 8
// 0097db5d  e8ae5ca9ff           call 0x413810
// 0097db62  890424               mov dword ptr [esp], eax
// 0097db65  8d0424               lea eax, [esp]
// 0097db68  50                   push eax
// 0097db69  e8123ea8ff           call 0x401980
// 0097db6e  8bc8                 mov ecx, eax
// 0097db70  e8db3ca8ff           call 0x401850
// 0097db75  59                   pop ecx
// 0097db76  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a11c;
extern const int data_009a2358[];
extern int global_b033a4;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_413b00();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b033a4 = (int)data_009a2358;
    call_once(flag_b7a11c, &callDoDeclare_413b00);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
