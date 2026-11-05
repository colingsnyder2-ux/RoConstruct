// from server: 100% by nuck16
// roc 2009-12 00980910  unit: seg_00980000  size: 55 bytes
//
// 00980910  51                   push ecx
// 00980911  68a0885300           push 0x5388a0
// 00980916  68c805b800           push 0xb805c8
// 0098091b  c70520f6b1000cd39b00 mov dword ptr [0xb1f620], 0x9bd30c
// 00980925  e8060da8ff           call 0x401630
// 0098092a  83c408               add esp, 8
// 0098092d  e8fe6dbbff           call 0x537730
// 00980932  890424               mov dword ptr [esp], eax
// 00980935  8d0424               lea eax, [esp]
// 00980938  50                   push eax
// 00980939  e84210a8ff           call 0x401980
// 0098093e  8bc8                 mov ecx, eax
// 00980940  e80b0fa8ff           call 0x401850
// 00980945  59                   pop ecx
// 00980946  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805c8;
extern const int data_009bd30c[];
extern int global_b1f620;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_5388a0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b1f620 = (int)data_009bd30c;
    call_once(flag_b805c8, &callDoDeclare_5388a0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
