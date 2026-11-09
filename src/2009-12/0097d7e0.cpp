// from server: 100% by nuck16
// roc 2009-12 0097d7e0  unit: seg_00970000  size: 55 bytes
//
// 0097d7e0  51                   push ecx
// 0097d7e1  6810414000           push 0x404110
// 0097d7e6  688895b700           push 0xb79588
// 0097d7eb  c7059cfdaf00ecfc9900 mov dword ptr [0xaffd9c], 0x99fcec
// 0097d7f5  e8363ea8ff           call 0x401630
// 0097d7fa  83c408               add esp, 8
// 0097d7fd  e85e61a8ff           call 0x403960
// 0097d802  890424               mov dword ptr [esp], eax
// 0097d805  8d0424               lea eax, [esp]
// 0097d808  50                   push eax
// 0097d809  e87241a8ff           call 0x401980
// 0097d80e  8bc8                 mov ecx, eax
// 0097d810  e83b40a8ff           call 0x401850
// 0097d815  59                   pop ecx
// 0097d816  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79588;
extern const int data_0099fcec[];
extern int global_affd9c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_404110();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_affd9c = (int)data_0099fcec;
    call_once(flag_b79588, &callDoDeclare_404110);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
