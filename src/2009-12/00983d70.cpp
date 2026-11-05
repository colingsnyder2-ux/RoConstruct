// from server: 100% by nuck16
// roc 2009-12 00983d70  unit: seg_00980000  size: 55 bytes
//
// 00983d70  51                   push ecx
// 00983d71  68009b6400           push 0x649b00
// 00983d76  685460b800           push 0xb86054
// 00983d7b  c7052c2bb3009cd89c00 mov dword ptr [0xb32b2c], 0x9cd89c
// 00983d85  e8a6d8a7ff           call 0x401630
// 00983d8a  83c408               add esp, 8
// 00983d8d  e84e53ccff           call 0x6490e0
// 00983d92  890424               mov dword ptr [esp], eax
// 00983d95  8d0424               lea eax, [esp]
// 00983d98  50                   push eax
// 00983d99  e8e2dba7ff           call 0x401980
// 00983d9e  8bc8                 mov ecx, eax
// 00983da0  e8abdaa7ff           call 0x401850
// 00983da5  59                   pop ecx
// 00983da6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86054;
extern const int data_009cd89c[];
extern int global_b32b2c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b00();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b2c = (int)data_009cd89c;
    call_once(flag_b86054, &callDoDeclare_649b00);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
