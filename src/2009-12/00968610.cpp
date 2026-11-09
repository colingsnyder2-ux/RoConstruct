// from server: 100% by nuck16
// roc 2009-12 00968610  unit: seg_00960000  size: 73 bytes
//
// 00968610  51                   push ecx
// 00968611  68a0684200           push 0x4268a0
// 00968616  68a0a2b700           push 0xb7a2a0
// 0096861b  e81090a9ff           call 0x401630
// 00968620  83c408               add esp, 8
// 00968623  e8f8e0abff           call 0x426720
// 00968628  890424               mov dword ptr [esp], eax
// 0096862b  8d0424               lea eax, [esp]
// 0096862e  50                   push eax
// 0096862f  e84c93a9ff           call 0x401980
// 00968634  8bc8                 mov ecx, eax
// 00968636  e8e5ceadff           call 0x445520
// 0096863b  c700484ab000         mov dword ptr [eax], 0xb04a48
// 00968641  6810de9700           push 0x97de10
// 00968646  c705b4a2b7009a020000 mov dword ptr [0xb7a2b4], 0x29a
// 00968650  e8d4c2e8ff           call 0x7f4929
// 00968655  83c408               add esp, 8
// 00968658  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a2a0;
extern int global_b7a2b4;
extern ICreator creator_b04a48;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4268a0();
const Name &doDeclare();
void destroy_97de10();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a2a0, &callDoDeclare_4268a0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b04a48;
    global_b7a2b4 = 0x29a;
    atexit(&destroy_97de10);
}
