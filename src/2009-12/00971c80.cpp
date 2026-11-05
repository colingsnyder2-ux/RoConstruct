// from server: 100% by nuck16
// roc 2009-12 00971c80  unit: seg_00970000  size: 73 bytes
//
// 00971c80  51                   push ecx
// 00971c81  68809a6400           push 0x649a80
// 00971c86  683460b800           push 0xb86034
// 00971c8b  e8a0f9a8ff           call 0x401630
// 00971c90  83c408               add esp, 8
// 00971c93  e8c870cdff           call 0x648d60
// 00971c98  890424               mov dword ptr [esp], eax
// 00971c9b  8d0424               lea eax, [esp]
// 00971c9e  50                   push eax
// 00971c9f  e8dcfca8ff           call 0x401980
// 00971ca4  8bc8                 mov ecx, eax
// 00971ca6  e87538adff           call 0x445520
// 00971cab  c7000c2bb300         mov dword ptr [eax], 0xb32b0c
// 00971cb1  68703f9800           push 0x983f70
// 00971cb6  c70570fcb8009a020000 mov dword ptr [0xb8fc70], 0x29a
// 00971cc0  e8642ce8ff           call 0x7f4929
// 00971cc5  83c408               add esp, 8
// 00971cc8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86034;
extern int global_b8fc70;
extern ICreator creator_b32b0c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a80();
const Name &doDeclare();
void destroy_983f70();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86034, &callDoDeclare_649a80);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b0c;
    global_b8fc70 = 0x29a;
    atexit(&destroy_983f70);
}
