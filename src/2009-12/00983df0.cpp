// from server: 100% by nuck16
// roc 2009-12 00983df0  unit: seg_00980000  size: 55 bytes
//
// 00983df0  51                   push ecx
// 00983df1  68e09a6400           push 0x649ae0
// 00983df6  684c60b800           push 0xb8604c
// 00983dfb  c705242bb30064d89c00 mov dword ptr [0xb32b24], 0x9cd864
// 00983e05  e826d8a7ff           call 0x401630
// 00983e0a  83c408               add esp, 8
// 00983e0d  e8ee51ccff           call 0x649000
// 00983e12  890424               mov dword ptr [esp], eax
// 00983e15  8d0424               lea eax, [esp]
// 00983e18  50                   push eax
// 00983e19  e862dba7ff           call 0x401980
// 00983e1e  8bc8                 mov ecx, eax
// 00983e20  e82bdaa7ff           call 0x401850
// 00983e25  59                   pop ecx
// 00983e26  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8604c;
extern const int data_009cd864[];
extern int global_b32b24;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649ae0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b24 = (int)data_009cd864;
    call_once(flag_b8604c, &callDoDeclare_649ae0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
