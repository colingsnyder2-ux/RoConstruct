// from server: 100% by nuck16
// roc 2009-12 0097fd40  unit: seg_00970000  size: 55 bytes
//
// 0097fd40  51                   push ecx
// 0097fd41  68103a5100           push 0x513a10
// 0097fd46  682ce9b700           push 0xb7e92c
// 0097fd4b  c705609db10024b59b00 mov dword ptr [0xb19d60], 0x9bb524
// 0097fd55  e8d618a8ff           call 0x401630
// 0097fd5a  83c408               add esp, 8
// 0097fd5d  e86e2db9ff           call 0x512ad0
// 0097fd62  890424               mov dword ptr [esp], eax
// 0097fd65  8d0424               lea eax, [esp]
// 0097fd68  50                   push eax
// 0097fd69  e8121ca8ff           call 0x401980
// 0097fd6e  8bc8                 mov ecx, eax
// 0097fd70  e8db1aa8ff           call 0x401850
// 0097fd75  59                   pop ecx
// 0097fd76  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7e92c;
extern const int data_009bb524[];
extern int global_b19d60;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_513a10();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b19d60 = (int)data_009bb524;
    call_once(flag_b7e92c, &callDoDeclare_513a10);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
