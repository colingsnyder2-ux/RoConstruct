// from server: 100% by nuck16
// roc 2009-12 00980850  unit: seg_00980000  size: 55 bytes
//
// 00980850  51                   push ecx
// 00980851  68d0885300           push 0x5388d0
// 00980856  68d405b800           push 0xb805d4
// 0098085b  c7052cf6b1004cd39b00 mov dword ptr [0xb1f62c], 0x9bd34c
// 00980865  e8c60da8ff           call 0x401630
// 0098086a  83c408               add esp, 8
// 0098086d  e80e70bbff           call 0x537880
// 00980872  890424               mov dword ptr [esp], eax
// 00980875  8d0424               lea eax, [esp]
// 00980878  50                   push eax
// 00980879  e80211a8ff           call 0x401980
// 0098087e  8bc8                 mov ecx, eax
// 00980880  e8cb0fa8ff           call 0x401850
// 00980885  59                   pop ecx
// 00980886  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805d4;
extern const int data_009bd34c[];
extern int global_b1f62c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_5388d0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b1f62c = (int)data_009bd34c;
    call_once(flag_b805d4, &callDoDeclare_5388d0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
