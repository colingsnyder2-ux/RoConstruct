// from server: 100% by nuck16
// roc 2009-12 00984430  unit: seg_00980000  size: 55 bytes
//
// 00984430  51                   push ecx
// 00984431  6850996400           push 0x649950
// 00984436  68e85fb800           push 0xb85fe8
// 0098443b  c705c02ab300a8d09c00 mov dword ptr [0xb32ac0], 0x9cd0a8
// 00984445  e8e6d1a7ff           call 0x401630
// 0098444a  83c408               add esp, 8
// 0098444d  e8be40ccff           call 0x648510
// 00984452  890424               mov dword ptr [esp], eax
// 00984455  8d0424               lea eax, [esp]
// 00984458  50                   push eax
// 00984459  e822d5a7ff           call 0x401980
// 0098445e  8bc8                 mov ecx, eax
// 00984460  e8ebd3a7ff           call 0x401850
// 00984465  59                   pop ecx
// 00984466  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fe8;
extern const int data_009cd0a8[];
extern int global_b32ac0;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649950();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32ac0 = (int)data_009cd0a8;
    call_once(flag_b85fe8, &callDoDeclare_649950);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
