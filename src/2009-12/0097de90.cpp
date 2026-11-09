// from server: 100% by nuck16
// roc 2009-12 0097de90  unit: seg_00970000  size: 55 bytes
//
// 0097de90  51                   push ecx
// 0097de91  68d0a44200           push 0x42a4d0
// 0097de96  6800a3b700           push 0xb7a300
// 0097de9b  c7058850b000084a9a00 mov dword ptr [0xb05088], 0x9a4a08
// 0097dea5  e88637a8ff           call 0x401630
// 0097deaa  83c408               add esp, 8
// 0097dead  e89eacaaff           call 0x428b50
// 0097deb2  890424               mov dword ptr [esp], eax
// 0097deb5  8d0424               lea eax, [esp]
// 0097deb8  50                   push eax
// 0097deb9  e8c23aa8ff           call 0x401980
// 0097debe  8bc8                 mov ecx, eax
// 0097dec0  e88b39a8ff           call 0x401850
// 0097dec5  59                   pop ecx
// 0097dec6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a300;
extern const int data_009a4a08[];
extern int global_b05088;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_42a4d0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b05088 = (int)data_009a4a08;
    call_once(flag_b7a300, &callDoDeclare_42a4d0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
