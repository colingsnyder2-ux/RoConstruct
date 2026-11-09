// from server: 100% by nuck16
// roc 2009-12 0097ec10  unit: seg_00970000  size: 55 bytes
//
// 0097ec10  51                   push ecx
// 0097ec11  68402d4600           push 0x462d40
// 0097ec16  68ccb9b700           push 0xb7b9cc
// 0097ec1b  c705d0b4b000f8ea9a00 mov dword ptr [0xb0b4d0], 0x9aeaf8
// 0097ec25  e8062aa8ff           call 0x401630
// 0097ec2a  83c408               add esp, 8
// 0097ec2d  e8ae31aeff           call 0x461de0
// 0097ec32  890424               mov dword ptr [esp], eax
// 0097ec35  8d0424               lea eax, [esp]
// 0097ec38  50                   push eax
// 0097ec39  e8422da8ff           call 0x401980
// 0097ec3e  8bc8                 mov ecx, eax
// 0097ec40  e80b2ca8ff           call 0x401850
// 0097ec45  59                   pop ecx
// 0097ec46  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b9cc;
extern const int data_009aeaf8[];
extern int global_b0b4d0;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_462d40();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b0b4d0 = (int)data_009aeaf8;
    call_once(flag_b7b9cc, &callDoDeclare_462d40);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
