// from server: 100% by nuck16
// roc 2009-12 0097f860  unit: seg_00970000  size: 55 bytes
//
// 0097f860  51                   push ecx
// 0097f861  6840684f00           push 0x4f6840
// 0097f866  6844deb700           push 0xb7de44
// 0097f86b  c705787fb1008ca49b00 mov dword ptr [0xb17f78], 0x9ba48c
// 0097f875  e8b61da8ff           call 0x401630
// 0097f87a  83c408               add esp, 8
// 0097f87d  e84e5db7ff           call 0x4f55d0
// 0097f882  890424               mov dword ptr [esp], eax
// 0097f885  8d0424               lea eax, [esp]
// 0097f888  50                   push eax
// 0097f889  e8f220a8ff           call 0x401980
// 0097f88e  8bc8                 mov ecx, eax
// 0097f890  e8bb1fa8ff           call 0x401850
// 0097f895  59                   pop ecx
// 0097f896  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de44;
extern const int data_009ba48c[];
extern int global_b17f78;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6840();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b17f78 = (int)data_009ba48c;
    call_once(flag_b7de44, &callDoDeclare_4f6840);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
