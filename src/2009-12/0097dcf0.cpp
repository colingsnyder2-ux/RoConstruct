// from server: 100% by nuck16
// roc 2009-12 0097dcf0  unit: seg_00970000  size: 55 bytes
//
// 0097dcf0  51                   push ecx
// 0097dcf1  68e0774100           push 0x4177e0
// 0097dcf6  68c4a1b700           push 0xb7a1c4
// 0097dcfb  c7052039b00014259a00 mov dword ptr [0xb03920], 0x9a2514
// 0097dd05  e82639a8ff           call 0x401630
// 0097dd0a  83c408               add esp, 8
// 0097dd0d  e85e99a9ff           call 0x417670
// 0097dd12  890424               mov dword ptr [esp], eax
// 0097dd15  8d0424               lea eax, [esp]
// 0097dd18  50                   push eax
// 0097dd19  e8623ca8ff           call 0x401980
// 0097dd1e  8bc8                 mov ecx, eax
// 0097dd20  e82b3ba8ff           call 0x401850
// 0097dd25  59                   pop ecx
// 0097dd26  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a1c4;
extern const int data_009a2514[];
extern int global_b03920;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4177e0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b03920 = (int)data_009a2514;
    call_once(flag_b7a1c4, &callDoDeclare_4177e0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
