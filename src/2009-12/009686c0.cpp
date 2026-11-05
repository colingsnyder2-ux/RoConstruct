// from server: 100% by nuck16
// roc 2009-12 009686c0  unit: seg_00960000  size: 73 bytes
//
// 009686c0  51                   push ecx
// 009686c1  68d0a44200           push 0x42a4d0
// 009686c6  6800a3b700           push 0xb7a300
// 009686cb  e8608fa9ff           call 0x401630
// 009686d0  83c408               add esp, 8
// 009686d3  e87804acff           call 0x428b50
// 009686d8  890424               mov dword ptr [esp], eax
// 009686db  8d0424               lea eax, [esp]
// 009686de  50                   push eax
// 009686df  e89c92a9ff           call 0x401980
// 009686e4  8bc8                 mov ecx, eax
// 009686e6  e835ceadff           call 0x445520
// 009686eb  c7008850b000         mov dword ptr [eax], 0xb05088
// 009686f1  6890de9700           push 0x97de90
// 009686f6  c70510a3b7009a020000 mov dword ptr [0xb7a310], 0x29a
// 00968700  e824c2e8ff           call 0x7f4929
// 00968705  83c408               add esp, 8
// 00968708  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a300;
extern int global_b7a310;
extern ICreator creator_b05088;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_42a4d0();
const Name &doDeclare();
void destroy_97de90();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a300, &callDoDeclare_42a4d0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b05088;
    global_b7a310 = 0x29a;
    atexit(&destroy_97de90);
}
