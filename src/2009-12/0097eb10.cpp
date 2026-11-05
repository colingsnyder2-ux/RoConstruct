// from server: 100% by nuck16
// roc 2009-12 0097eb10  unit: seg_00970000  size: 55 bytes
//
// 0097eb10  51                   push ecx
// 0097eb11  68802d4600           push 0x462d80
// 0097eb16  68dcb9b700           push 0xb7b9dc
// 0097eb1b  c705e0b4b00068eb9a00 mov dword ptr [0xb0b4e0], 0x9aeb68
// 0097eb25  e8062ba8ff           call 0x401630
// 0097eb2a  83c408               add esp, 8
// 0097eb2d  e86e34aeff           call 0x461fa0
// 0097eb32  890424               mov dword ptr [esp], eax
// 0097eb35  8d0424               lea eax, [esp]
// 0097eb38  50                   push eax
// 0097eb39  e8422ea8ff           call 0x401980
// 0097eb3e  8bc8                 mov ecx, eax
// 0097eb40  e80b2da8ff           call 0x401850
// 0097eb45  59                   pop ecx
// 0097eb46  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9dc;
extern const int data_009aeb68[];
extern int global_b0b4e0;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d80();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b0b4e0 = (int)data_009aeb68;
    call_once(flag_b7b9dc, &callDoDeclare_462d80);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
