// from server: 100% by nuck16
// roc 2009-12 0097f660  unit: seg_00970000  size: 55 bytes
//
// 0097f660  51                   push ecx
// 0097f661  68d0684f00           push 0x4f68d0
// 0097f666  6868deb700           push 0xb7de68
// 0097f66b  c705987fb10044a59b00 mov dword ptr [0xb17f98], 0x9ba544
// 0097f675  e8b61fa8ff           call 0x401630
// 0097f67a  83c408               add esp, 8
// 0097f67d  e83e63b7ff           call 0x4f59c0
// 0097f682  890424               mov dword ptr [esp], eax
// 0097f685  8d0424               lea eax, [esp]
// 0097f688  50                   push eax
// 0097f689  e8f222a8ff           call 0x401980
// 0097f68e  8bc8                 mov ecx, eax
// 0097f690  e8bb21a8ff           call 0x401850
// 0097f695  59                   pop ecx
// 0097f696  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de68;
extern const int data_009ba544[];
extern int global_b17f98;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f68d0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b17f98 = (int)data_009ba544;
    call_once(flag_b7de68, &callDoDeclare_4f68d0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
