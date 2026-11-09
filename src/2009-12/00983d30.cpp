// from server: 100% by nuck16
// roc 2009-12 00983d30  unit: seg_00980000  size: 55 bytes
//
// 00983d30  51                   push ecx
// 00983d31  68109b6400           push 0x649b10
// 00983d36  685860b800           push 0xb86058
// 00983d3b  c705302bb300b8d89c00 mov dword ptr [0xb32b30], 0x9cd8b8
// 00983d45  e8e6d8a7ff           call 0x401630
// 00983d4a  83c408               add esp, 8
// 00983d4d  e8fe53ccff           call 0x649150
// 00983d52  890424               mov dword ptr [esp], eax
// 00983d55  8d0424               lea eax, [esp]
// 00983d58  50                   push eax
// 00983d59  e822dca7ff           call 0x401980
// 00983d5e  8bc8                 mov ecx, eax
// 00983d60  e8ebdaa7ff           call 0x401850
// 00983d65  59                   pop ecx
// 00983d66  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86058;
extern const int data_009cd8b8[];
extern int global_b32b30;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b10();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b30 = (int)data_009cd8b8;
    call_once(flag_b86058, &callDoDeclare_649b10);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
