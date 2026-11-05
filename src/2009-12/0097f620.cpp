// from server: 100% by nuck16
// roc 2009-12 0097f620  unit: seg_00970000  size: 55 bytes
//
// 0097f620  51                   push ecx
// 0097f621  68e0684f00           push 0x4f68e0
// 0097f626  686cdeb700           push 0xb7de6c
// 0097f62b  c7059c7fb10060a59b00 mov dword ptr [0xb17f9c], 0x9ba560
// 0097f635  e8f61fa8ff           call 0x401630
// 0097f63a  83c408               add esp, 8
// 0097f63d  e8ee63b7ff           call 0x4f5a30
// 0097f642  890424               mov dword ptr [esp], eax
// 0097f645  8d0424               lea eax, [esp]
// 0097f648  50                   push eax
// 0097f649  e83223a8ff           call 0x401980
// 0097f64e  8bc8                 mov ecx, eax
// 0097f650  e8fb21a8ff           call 0x401850
// 0097f655  59                   pop ecx
// 0097f656  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de6c;
extern const int data_009ba560[];
extern int global_b17f9c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f68e0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b17f9c = (int)data_009ba560;
    call_once(flag_b7de6c, &callDoDeclare_4f68e0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
