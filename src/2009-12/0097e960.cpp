// from server: 100% by nuck16
// roc 2009-12 0097e960  unit: seg_00970000  size: 55 bytes
//
// 0097e960  51                   push ecx
// 0097e961  6820cd4400           push 0x44cd20
// 0097e966  6894b4b700           push 0xb7b494
// 0097e96b  c705ec94b00088b69a00 mov dword ptr [0xb094ec], 0x9ab688
// 0097e975  e8b62ca8ff           call 0x401630
// 0097e97a  83c408               add esp, 8
// 0097e97d  e88ed3acff           call 0x44bd10
// 0097e982  890424               mov dword ptr [esp], eax
// 0097e985  8d0424               lea eax, [esp]
// 0097e988  50                   push eax
// 0097e989  e8f22fa8ff           call 0x401980
// 0097e98e  8bc8                 mov ecx, eax
// 0097e990  e8bb2ea8ff           call 0x401850
// 0097e995  59                   pop ecx
// 0097e996  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7b494;
extern const int data_009ab688[];
extern int global_b094ec;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_44cd20();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b094ec = (int)data_009ab688;
    call_once(flag_b7b494, &callDoDeclare_44cd20);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
