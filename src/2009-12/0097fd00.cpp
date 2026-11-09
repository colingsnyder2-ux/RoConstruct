// from server: 100% by nuck16
// roc 2009-12 0097fd00  unit: seg_00970000  size: 55 bytes
//
// 0097fd00  51                   push ecx
// 0097fd01  68203a5100           push 0x513a20
// 0097fd06  6830e9b700           push 0xb7e930
// 0097fd0b  c705649db1002cb59b00 mov dword ptr [0xb19d64], 0x9bb52c
// 0097fd15  e81619a8ff           call 0x401630
// 0097fd1a  83c408               add esp, 8
// 0097fd1d  e81e2eb9ff           call 0x512b40
// 0097fd22  890424               mov dword ptr [esp], eax
// 0097fd25  8d0424               lea eax, [esp]
// 0097fd28  50                   push eax
// 0097fd29  e8521ca8ff           call 0x401980
// 0097fd2e  8bc8                 mov ecx, eax
// 0097fd30  e81b1ba8ff           call 0x401850
// 0097fd35  59                   pop ecx
// 0097fd36  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7e930;
extern const int data_009bb52c[];
extern int global_b19d64;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_513a20();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b19d64 = (int)data_009bb52c;
    call_once(flag_b7e930, &callDoDeclare_513a20);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
