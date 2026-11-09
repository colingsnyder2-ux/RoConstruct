// from server: 100% by nuck16
// roc 2009-12 00968180  unit: seg_00960000  size: 73 bytes
//
// 00968180  51                   push ecx
// 00968181  6870954000           push 0x409570
// 00968186  681096b700           push 0xb79610
// 0096818b  e8a094a9ff           call 0x401630
// 00968190  83c408               add esp, 8
// 00968193  e8d80faaff           call 0x409170
// 00968198  890424               mov dword ptr [esp], eax
// 0096819b  8d0424               lea eax, [esp]
// 0096819e  50                   push eax
// 0096819f  e8dc97a9ff           call 0x401980
// 009681a4  8bc8                 mov ecx, eax
// 009681a6  e875d3adff           call 0x445520
// 009681ab  c700541db000         mov dword ptr [eax], 0xb01d54
// 009681b1  6800da9700           push 0x97da00
// 009681b6  c7053c9db7009a020000 mov dword ptr [0xb79d3c], 0x29a
// 009681c0  e864c7e8ff           call 0x7f4929
// 009681c5  83c408               add esp, 8
// 009681c8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79610;
extern int global_b79d3c;
extern ICreator creator_b01d54;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_409570();
const Name &doDeclare();
void destroy_97da00();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b79610, &callDoDeclare_409570);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b01d54;
    global_b79d3c = 0x29a;
    atexit(&destroy_97da00);
}
