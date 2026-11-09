// from server: 100% by nuck16
// roc 2009-12 00968090  unit: seg_00960000  size: 73 bytes
//
// 00968090  51                   push ecx
// 00968091  6840954000           push 0x409540
// 00968096  680496b700           push 0xb79604
// 0096809b  e89095a9ff           call 0x401630
// 009680a0  83c408               add esp, 8
// 009680a3  e8780faaff           call 0x409020
// 009680a8  890424               mov dword ptr [esp], eax
// 009680ab  8d0424               lea eax, [esp]
// 009680ae  50                   push eax
// 009680af  e8cc98a9ff           call 0x401980
// 009680b4  8bc8                 mov ecx, eax
// 009680b6  e865d4adff           call 0x445520
// 009680bb  c700481db000         mov dword ptr [eax], 0xb01d48
// 009680c1  68c0da9700           push 0x97dac0
// 009680c6  c7052899b7009a020000 mov dword ptr [0xb79928], 0x29a
// 009680d0  e854c8e8ff           call 0x7f4929
// 009680d5  83c408               add esp, 8
// 009680d8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79604;
extern int global_b79928;
extern ICreator creator_b01d48;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_409540();
const Name &doDeclare();
void destroy_97dac0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b79604, &callDoDeclare_409540);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b01d48;
    global_b79928 = 0x29a;
    atexit(&destroy_97dac0);
}
