// from server: 100% by nuck16
// roc 2009-12 0097dd30  unit: seg_00970000  size: 55 bytes
//
// 0097dd30  51                   push ecx
// 0097dd31  68d0774100           push 0x4177d0
// 0097dd36  68c0a1b700           push 0xb7a1c0
// 0097dd3b  c7051c39b000f8249a00 mov dword ptr [0xb0391c], 0x9a24f8
// 0097dd45  e8e638a8ff           call 0x401630
// 0097dd4a  83c408               add esp, 8
// 0097dd4d  e8ae98a9ff           call 0x417600
// 0097dd52  890424               mov dword ptr [esp], eax
// 0097dd55  8d0424               lea eax, [esp]
// 0097dd58  50                   push eax
// 0097dd59  e8223ca8ff           call 0x401980
// 0097dd5e  8bc8                 mov ecx, eax
// 0097dd60  e8eb3aa8ff           call 0x401850
// 0097dd65  59                   pop ecx
// 0097dd66  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a1c0;
extern const int data_009a24f8[];
extern int global_b0391c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4177d0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b0391c = (int)data_009a24f8;
    call_once(flag_b7a1c0, &callDoDeclare_4177d0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
