// from server: 100% by nuck16
// roc 2009-12 0097f6a0  unit: seg_00970000  size: 55 bytes
//
// 0097f6a0  51                   push ecx
// 0097f6a1  68c0684f00           push 0x4f68c0
// 0097f6a6  6864deb700           push 0xb7de64
// 0097f6ab  c705947fb10028a59b00 mov dword ptr [0xb17f94], 0x9ba528
// 0097f6b5  e8761fa8ff           call 0x401630
// 0097f6ba  83c408               add esp, 8
// 0097f6bd  e88e62b7ff           call 0x4f5950
// 0097f6c2  890424               mov dword ptr [esp], eax
// 0097f6c5  8d0424               lea eax, [esp]
// 0097f6c8  50                   push eax
// 0097f6c9  e8b222a8ff           call 0x401980
// 0097f6ce  8bc8                 mov ecx, eax
// 0097f6d0  e87b21a8ff           call 0x401850
// 0097f6d5  59                   pop ecx
// 0097f6d6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de64;
extern const int data_009ba528[];
extern int global_b17f94;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f68c0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b17f94 = (int)data_009ba528;
    call_once(flag_b7de64, &callDoDeclare_4f68c0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
