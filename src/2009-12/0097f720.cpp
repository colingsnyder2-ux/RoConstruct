// from server: 100% by nuck16
// roc 2009-12 0097f720  unit: seg_00970000  size: 55 bytes
//
// 0097f720  51                   push ecx
// 0097f721  68a0684f00           push 0x4f68a0
// 0097f726  685cdeb700           push 0xb7de5c
// 0097f72b  c7058c7fb100f0a49b00 mov dword ptr [0xb17f8c], 0x9ba4f0
// 0097f735  e8f61ea8ff           call 0x401630
// 0097f73a  83c408               add esp, 8
// 0097f73d  e82e61b7ff           call 0x4f5870
// 0097f742  890424               mov dword ptr [esp], eax
// 0097f745  8d0424               lea eax, [esp]
// 0097f748  50                   push eax
// 0097f749  e83222a8ff           call 0x401980
// 0097f74e  8bc8                 mov ecx, eax
// 0097f750  e8fb20a8ff           call 0x401850
// 0097f755  59                   pop ecx
// 0097f756  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de5c;
extern const int data_009ba4f0[];
extern int global_b17f8c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f68a0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b17f8c = (int)data_009ba4f0;
    call_once(flag_b7de5c, &callDoDeclare_4f68a0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
