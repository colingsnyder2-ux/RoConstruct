// from server: 100% by nuck16
// roc 2009-12 00984170  unit: seg_00980000  size: 55 bytes
//
// 00984170  51                   push ecx
// 00984171  68009a6400           push 0x649a00
// 00984176  681460b800           push 0xb86014
// 0098417b  c705ec2ab300dcd19c00 mov dword ptr [0xb32aec], 0x9cd1dc
// 00984185  e8a6d4a7ff           call 0x401630
// 0098418a  83c408               add esp, 8
// 0098418d  e84e48ccff           call 0x6489e0
// 00984192  890424               mov dword ptr [esp], eax
// 00984195  8d0424               lea eax, [esp]
// 00984198  50                   push eax
// 00984199  e8e2d7a7ff           call 0x401980
// 0098419e  8bc8                 mov ecx, eax
// 009841a0  e8abd6a7ff           call 0x401850
// 009841a5  59                   pop ecx
// 009841a6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86014;
extern const int data_009cd1dc[];
extern int global_b32aec;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a00();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32aec = (int)data_009cd1dc;
    call_once(flag_b86014, &callDoDeclare_649a00);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
