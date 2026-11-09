// from server: 100% by nuck16
// roc 2009-12 00984530  unit: seg_00980000  size: 55 bytes
//
// 00984530  51                   push ecx
// 00984531  6810996400           push 0x649910
// 00984536  68d85fb800           push 0xb85fd8
// 0098453b  c705b02ab30038d09c00 mov dword ptr [0xb32ab0], 0x9cd038
// 00984545  e8e6d0a7ff           call 0x401630
// 0098454a  83c408               add esp, 8
// 0098454d  e8fe3dccff           call 0x648350
// 00984552  890424               mov dword ptr [esp], eax
// 00984555  8d0424               lea eax, [esp]
// 00984558  50                   push eax
// 00984559  e822d4a7ff           call 0x401980
// 0098455e  8bc8                 mov ecx, eax
// 00984560  e8ebd2a7ff           call 0x401850
// 00984565  59                   pop ecx
// 00984566  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fd8;
extern const int data_009cd038[];
extern int global_b32ab0;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649910();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32ab0 = (int)data_009cd038;
    call_once(flag_b85fd8, &callDoDeclare_649910);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
