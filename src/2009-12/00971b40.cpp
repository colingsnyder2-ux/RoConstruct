// from server: 100% by nuck16
// roc 2009-12 00971b40  unit: seg_00970000  size: 73 bytes
//
// 00971b40  51                   push ecx
// 00971b41  68409a6400           push 0x649a40
// 00971b46  682460b800           push 0xb86024
// 00971b4b  e8e0faa8ff           call 0x401630
// 00971b50  83c408               add esp, 8
// 00971b53  e84870cdff           call 0x648ba0
// 00971b58  890424               mov dword ptr [esp], eax
// 00971b5b  8d0424               lea eax, [esp]
// 00971b5e  50                   push eax
// 00971b5f  e81cfea8ff           call 0x401980
// 00971b64  8bc8                 mov ecx, eax
// 00971b66  e8b539adff           call 0x445520
// 00971b6b  c700fc2ab300         mov dword ptr [eax], 0xb32afc
// 00971b71  6870409800           push 0x984070
// 00971b76  c70550fcb8009a020000 mov dword ptr [0xb8fc50], 0x29a
// 00971b80  e8a42de8ff           call 0x7f4929
// 00971b85  83c408               add esp, 8
// 00971b88  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86024;
extern int global_b8fc50;
extern ICreator creator_b32afc;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a40();
const Name &doDeclare();
void destroy_984070();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86024, &callDoDeclare_649a40);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32afc;
    global_b8fc50 = 0x29a;
    atexit(&destroy_984070);
}
