// from server: 100% by nuck16
// roc 2009-12 0096d450  unit: seg_00960000  size: 73 bytes
//
// 0096d450  51                   push ecx
// 0096d451  68b0be5200           push 0x52beb0
// 0096d456  686801b800           push 0xb80168
// 0096d45b  e8d041a9ff           call 0x401630
// 0096d460  83c408               add esp, 8
// 0096d463  e8a8e6bbff           call 0x52bb10
// 0096d468  890424               mov dword ptr [esp], eax
// 0096d46b  8d0424               lea eax, [esp]
// 0096d46e  50                   push eax
// 0096d46f  e80c45a9ff           call 0x401980
// 0096d474  8bc8                 mov ecx, eax
// 0096d476  e8a580adff           call 0x445520
// 0096d47b  c70080cbb100         mov dword ptr [eax], 0xb1cb80
// 0096d481  68d0049800           push 0x9804d0
// 0096d486  c7057001b8009a020000 mov dword ptr [0xb80170], 0x29a
// 0096d490  e89474e8ff           call 0x7f4929
// 0096d495  83c408               add esp, 8
// 0096d498  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b80168;
extern int global_b80170;
extern ICreator creator_b1cb80;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_52beb0();
const Name &doDeclare();
void destroy_9804d0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b80168, &callDoDeclare_52beb0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b1cb80;
    global_b80170 = 0x29a;
    atexit(&destroy_9804d0);
}
