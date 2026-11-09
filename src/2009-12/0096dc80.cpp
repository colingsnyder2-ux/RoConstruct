// from server: 100% by nuck16
// roc 2009-12 0096dc80  unit: seg_00960000  size: 73 bytes
//
// 0096dc80  51                   push ecx
// 0096dc81  68607c5700           push 0x577c60
// 0096dc86  687827b800           push 0xb82778
// 0096dc8b  e8a039a9ff           call 0x401630
// 0096dc90  83c408               add esp, 8
// 0096dc93  e8f89bc0ff           call 0x577890
// 0096dc98  890424               mov dword ptr [esp], eax
// 0096dc9b  8d0424               lea eax, [esp]
// 0096dc9e  50                   push eax
// 0096dc9f  e8dc3ca9ff           call 0x401980
// 0096dca4  8bc8                 mov ecx, eax
// 0096dca6  e87578adff           call 0x445520
// 0096dcab  c700fc4eb200         mov dword ptr [eax], 0xb24efc
// 0096dcb1  68600c9800           push 0x980c60
// 0096dcb6  c7057c29b8009a020000 mov dword ptr [0xb8297c], 0x29a
// 0096dcc0  e8646ce8ff           call 0x7f4929
// 0096dcc5  83c408               add esp, 8
// 0096dcc8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b82778;
extern int global_b8297c;
extern ICreator creator_b24efc;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_577c60();
const Name &doDeclare();
void destroy_980c60();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b82778, &callDoDeclare_577c60);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b24efc;
    global_b8297c = 0x29a;
    atexit(&destroy_980c60);
}
