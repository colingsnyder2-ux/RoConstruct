// from server: 100% by nuck16
// roc 2009-12 0097df20  unit: seg_00970000  size: 55 bytes
//
// 0097df20  51                   push ecx
// 0097df21  6830364300           push 0x433630
// 0097df26  6878a3b700           push 0xb7a378
// 0097df2b  c705b46bb0000c7f9a00 mov dword ptr [0xb06bb4], 0x9a7f0c
// 0097df35  e8f636a8ff           call 0x401630
// 0097df3a  83c408               add esp, 8
// 0097df3d  e8ae50abff           call 0x432ff0
// 0097df42  890424               mov dword ptr [esp], eax
// 0097df45  8d0424               lea eax, [esp]
// 0097df48  50                   push eax
// 0097df49  e8323aa8ff           call 0x401980
// 0097df4e  8bc8                 mov ecx, eax
// 0097df50  e8fb38a8ff           call 0x401850
// 0097df55  59                   pop ecx
// 0097df56  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a378;
extern const int data_009a7f0c[];
extern int global_b06bb4;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_433630();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b06bb4 = (int)data_009a7f0c;
    call_once(flag_b7a378, &callDoDeclare_433630);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
