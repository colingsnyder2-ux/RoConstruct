// from server: 100% by nuck16
// roc 2009-12 0097dc70  unit: seg_00970000  size: 55 bytes
//
// 0097dc70  51                   push ecx
// 0097dc71  6800784100           push 0x417800
// 0097dc76  68cca1b700           push 0xb7a1cc
// 0097dc7b  c7052839b0004c259a00 mov dword ptr [0xb03928], 0x9a254c
// 0097dc85  e8a639a8ff           call 0x401630
// 0097dc8a  83c408               add esp, 8
// 0097dc8d  e8be9aa9ff           call 0x417750
// 0097dc92  890424               mov dword ptr [esp], eax
// 0097dc95  8d0424               lea eax, [esp]
// 0097dc98  50                   push eax
// 0097dc99  e8e23ca8ff           call 0x401980
// 0097dc9e  8bc8                 mov ecx, eax
// 0097dca0  e8ab3ba8ff           call 0x401850
// 0097dca5  59                   pop ecx
// 0097dca6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a1cc;
extern const int data_009a254c[];
extern int global_b03928;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_417800();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b03928 = (int)data_009a254c;
    call_once(flag_b7a1cc, &callDoDeclare_417800);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
