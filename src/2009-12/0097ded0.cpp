// from server: 100% by nuck16
// roc 2009-12 0097ded0  unit: seg_00970000  size: 55 bytes
//
// 0097ded0  51                   push ecx
// 0097ded1  68c0a44200           push 0x42a4c0
// 0097ded6  68fca2b700           push 0xb7a2fc
// 0097dedb  c7058450b000ec499a00 mov dword ptr [0xb05084], 0x9a49ec
// 0097dee5  e84637a8ff           call 0x401630
// 0097deea  83c408               add esp, 8
// 0097deed  e8eeabaaff           call 0x428ae0
// 0097def2  890424               mov dword ptr [esp], eax
// 0097def5  8d0424               lea eax, [esp]
// 0097def8  50                   push eax
// 0097def9  e8823aa8ff           call 0x401980
// 0097defe  8bc8                 mov ecx, eax
// 0097df00  e84b39a8ff           call 0x401850
// 0097df05  59                   pop ecx
// 0097df06  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a2fc;
extern const int data_009a49ec[];
extern int global_b05084;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_42a4c0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b05084 = (int)data_009a49ec;
    call_once(flag_b7a2fc, &callDoDeclare_42a4c0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
