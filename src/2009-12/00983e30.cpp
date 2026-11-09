// from server: 100% by nuck16
// roc 2009-12 00983e30  unit: seg_00980000  size: 55 bytes
//
// 00983e30  51                   push ecx
// 00983e31  68d09a6400           push 0x649ad0
// 00983e36  684860b800           push 0xb86048
// 00983e3b  c705202bb30048d89c00 mov dword ptr [0xb32b20], 0x9cd848
// 00983e45  e8e6d7a7ff           call 0x401630
// 00983e4a  83c408               add esp, 8
// 00983e4d  e83e51ccff           call 0x648f90
// 00983e52  890424               mov dword ptr [esp], eax
// 00983e55  8d0424               lea eax, [esp]
// 00983e58  50                   push eax
// 00983e59  e822dba7ff           call 0x401980
// 00983e5e  8bc8                 mov ecx, eax
// 00983e60  e8ebd9a7ff           call 0x401850
// 00983e65  59                   pop ecx
// 00983e66  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86048;
extern const int data_009cd848[];
extern int global_b32b20;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649ad0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b20 = (int)data_009cd848;
    call_once(flag_b86048, &callDoDeclare_649ad0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
