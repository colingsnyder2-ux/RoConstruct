// from server: 100% by nuck16
// roc 2009-12 0097d980  unit: seg_00970000  size: 55 bytes
//
// 0097d980  51                   push ecx
// 0097d981  6890954000           push 0x409590
// 0097d986  681896b700           push 0xb79618
// 0097d98b  c7055c1db00004039a00 mov dword ptr [0xb01d5c], 0x9a0304
// 0097d995  e8963ca8ff           call 0x401630
// 0097d99a  83c408               add esp, 8
// 0097d99d  e8aeb8a8ff           call 0x409250
// 0097d9a2  890424               mov dword ptr [esp], eax
// 0097d9a5  8d0424               lea eax, [esp]
// 0097d9a8  50                   push eax
// 0097d9a9  e8d23fa8ff           call 0x401980
// 0097d9ae  8bc8                 mov ecx, eax
// 0097d9b0  e89b3ea8ff           call 0x401850
// 0097d9b5  59                   pop ecx
// 0097d9b6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79618;
extern const int data_009a0304[];
extern int global_b01d5c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_409590();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b01d5c = (int)data_009a0304;
    call_once(flag_b79618, &callDoDeclare_409590);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
