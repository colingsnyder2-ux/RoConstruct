// from server: 100% by nuck16
// roc 2009-12 009844f0  unit: seg_00980000  size: 55 bytes
//
// 009844f0  51                   push ecx
// 009844f1  6820996400           push 0x649920
// 009844f6  68dc5fb800           push 0xb85fdc
// 009844fb  c705b42ab30054d09c00 mov dword ptr [0xb32ab4], 0x9cd054
// 00984505  e826d1a7ff           call 0x401630
// 0098450a  83c408               add esp, 8
// 0098450d  e8ae3eccff           call 0x6483c0
// 00984512  890424               mov dword ptr [esp], eax
// 00984515  8d0424               lea eax, [esp]
// 00984518  50                   push eax
// 00984519  e862d4a7ff           call 0x401980
// 0098451e  8bc8                 mov ecx, eax
// 00984520  e82bd3a7ff           call 0x401850
// 00984525  59                   pop ecx
// 00984526  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fdc;
extern const int data_009cd054[];
extern int global_b32ab4;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649920();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32ab4 = (int)data_009cd054;
    call_once(flag_b85fdc, &callDoDeclare_649920);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
