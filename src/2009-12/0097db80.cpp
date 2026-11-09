// from server: 100% by nuck16
// roc 2009-12 0097db80  unit: seg_00970000  size: 55 bytes
//
// 0097db80  51                   push ecx
// 0097db81  68f03a4100           push 0x413af0
// 0097db86  6818a1b700           push 0xb7a118
// 0097db8b  c705a033b0003c239a00 mov dword ptr [0xb033a0], 0x9a233c
// 0097db95  e8963aa8ff           call 0x401630
// 0097db9a  83c408               add esp, 8
// 0097db9d  e8fe5ba9ff           call 0x4137a0
// 0097dba2  890424               mov dword ptr [esp], eax
// 0097dba5  8d0424               lea eax, [esp]
// 0097dba8  50                   push eax
// 0097dba9  e8d23da8ff           call 0x401980
// 0097dbae  8bc8                 mov ecx, eax
// 0097dbb0  e89b3ca8ff           call 0x401850
// 0097dbb5  59                   pop ecx
// 0097dbb6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a118;
extern const int data_009a233c[];
extern int global_b033a0;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_413af0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b033a0 = (int)data_009a233c;
    call_once(flag_b7a118, &callDoDeclare_413af0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
