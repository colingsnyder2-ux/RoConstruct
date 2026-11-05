// from server: 100% by nuck16
// roc 2009-12 0097da00  unit: seg_00970000  size: 55 bytes
//
// 0097da00  51                   push ecx
// 0097da01  6870954000           push 0x409570
// 0097da06  681096b700           push 0xb79610
// 0097da0b  c705541db000f4019a00 mov dword ptr [0xb01d54], 0x9a01f4
// 0097da15  e8163ca8ff           call 0x401630
// 0097da1a  83c408               add esp, 8
// 0097da1d  e84eb7a8ff           call 0x409170
// 0097da22  890424               mov dword ptr [esp], eax
// 0097da25  8d0424               lea eax, [esp]
// 0097da28  50                   push eax
// 0097da29  e8523fa8ff           call 0x401980
// 0097da2e  8bc8                 mov ecx, eax
// 0097da30  e81b3ea8ff           call 0x401850
// 0097da35  59                   pop ecx
// 0097da36  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79610;
extern const int data_009a01f4[];
extern int global_b01d54;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_409570();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b01d54 = (int)data_009a01f4;
    call_once(flag_b79610, &callDoDeclare_409570);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
