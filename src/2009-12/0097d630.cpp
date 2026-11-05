// from server: 100% by nuck16
// roc 2009-12 0097d630  unit: seg_00970000  size: 55 bytes
//
// 0097d630  51                   push ecx
// 0097d631  68f0164000           push 0x4016f0
// 0097d636  682094b700           push 0xb79420
// 0097d63b  c70574f4af0048f59900 mov dword ptr [0xaff474], 0x99f548
// 0097d645  e8e63fa8ff           call 0x401630
// 0097d64a  83c408               add esp, 8
// 0097d64d  e84e3da8ff           call 0x4013a0
// 0097d652  890424               mov dword ptr [esp], eax
// 0097d655  8d0424               lea eax, [esp]
// 0097d658  50                   push eax
// 0097d659  e82243a8ff           call 0x401980
// 0097d65e  8bc8                 mov ecx, eax
// 0097d660  e8eb41a8ff           call 0x401850
// 0097d665  59                   pop ecx
// 0097d666  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79420;
extern const int data_0099f548[];
extern int global_aff474;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4016f0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_aff474 = (int)data_0099f548;
    call_once(flag_b79420, &callDoDeclare_4016f0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
