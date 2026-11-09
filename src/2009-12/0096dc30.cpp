// from server: 100% by nuck16
// roc 2009-12 0096dc30  unit: seg_00960000  size: 73 bytes
//
// 0096dc30  51                   push ecx
// 0096dc31  68507c5700           push 0x577c50
// 0096dc36  687427b800           push 0xb82774
// 0096dc3b  e8f039a9ff           call 0x401630
// 0096dc40  83c408               add esp, 8
// 0096dc43  e8d89bc0ff           call 0x577820
// 0096dc48  890424               mov dword ptr [esp], eax
// 0096dc4b  8d0424               lea eax, [esp]
// 0096dc4e  50                   push eax
// 0096dc4f  e82c3da9ff           call 0x401980
// 0096dc54  8bc8                 mov ecx, eax
// 0096dc56  e8c578adff           call 0x445520
// 0096dc5b  c700f84eb200         mov dword ptr [eax], 0xb24ef8
// 0096dc61  68a00c9800           push 0x980ca0
// 0096dc66  c7057c27b8009a020000 mov dword ptr [0xb8277c], 0x29a
// 0096dc70  e8b46ce8ff           call 0x7f4929
// 0096dc75  83c408               add esp, 8
// 0096dc78  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b82774;
extern int global_b8277c;
extern ICreator creator_b24ef8;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_577c50();
const Name &doDeclare();
void destroy_980ca0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b82774, &callDoDeclare_577c50);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b24ef8;
    global_b8277c = 0x29a;
    atexit(&destroy_980ca0);
}
