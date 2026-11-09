// from server: 100% by nuck16
// roc 2009-12 0097f7e0  unit: seg_00970000  size: 55 bytes
//
// 0097f7e0  51                   push ecx
// 0097f7e1  6870684f00           push 0x4f6870
// 0097f7e6  6850deb700           push 0xb7de50
// 0097f7eb  c705807fb100c4a49b00 mov dword ptr [0xb17f80], 0x9ba4c4
// 0097f7f5  e8361ea8ff           call 0x401630
// 0097f7fa  83c408               add esp, 8
// 0097f7fd  e81e5fb7ff           call 0x4f5720
// 0097f802  890424               mov dword ptr [esp], eax
// 0097f805  8d0424               lea eax, [esp]
// 0097f808  50                   push eax
// 0097f809  e87221a8ff           call 0x401980
// 0097f80e  8bc8                 mov ecx, eax
// 0097f810  e83b20a8ff           call 0x401850
// 0097f815  59                   pop ecx
// 0097f816  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de50;
extern const int data_009ba4c4[];
extern int global_b17f80;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6870();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b17f80 = (int)data_009ba4c4;
    call_once(flag_b7de50, &callDoDeclare_4f6870);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
