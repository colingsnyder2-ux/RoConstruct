// from server: 100% by nuck16
// roc 2009-12 009843f0  unit: seg_00980000  size: 55 bytes
//
// 009843f0  51                   push ecx
// 009843f1  6860996400           push 0x649960
// 009843f6  68ec5fb800           push 0xb85fec
// 009843fb  c705c42ab300c4d09c00 mov dword ptr [0xb32ac4], 0x9cd0c4
// 00984405  e826d2a7ff           call 0x401630
// 0098440a  83c408               add esp, 8
// 0098440d  e86e41ccff           call 0x648580
// 00984412  890424               mov dword ptr [esp], eax
// 00984415  8d0424               lea eax, [esp]
// 00984418  50                   push eax
// 00984419  e862d5a7ff           call 0x401980
// 0098441e  8bc8                 mov ecx, eax
// 00984420  e82bd4a7ff           call 0x401850
// 00984425  59                   pop ecx
// 00984426  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fec;
extern const int data_009cd0c4[];
extern int global_b32ac4;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649960();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32ac4 = (int)data_009cd0c4;
    call_once(flag_b85fec, &callDoDeclare_649960);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
