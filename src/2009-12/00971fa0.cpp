// from server: 100% by nuck16
// roc 2009-12 00971fa0  unit: seg_00970000  size: 73 bytes
//
// 00971fa0  51                   push ecx
// 00971fa1  68209b6400           push 0x649b20
// 00971fa6  685c60b800           push 0xb8605c
// 00971fab  e880f6a8ff           call 0x401630
// 00971fb0  83c408               add esp, 8
// 00971fb3  e80872cdff           call 0x6491c0
// 00971fb8  890424               mov dword ptr [esp], eax
// 00971fbb  8d0424               lea eax, [esp]
// 00971fbe  50                   push eax
// 00971fbf  e8bcf9a8ff           call 0x401980
// 00971fc4  8bc8                 mov ecx, eax
// 00971fc6  e85535adff           call 0x445520
// 00971fcb  c700342bb300         mov dword ptr [eax], 0xb32b34
// 00971fd1  68f03c9800           push 0x983cf0
// 00971fd6  c70598fcb8009a020000 mov dword ptr [0xb8fc98], 0x29a
// 00971fe0  e84429e8ff           call 0x7f4929
// 00971fe5  83c408               add esp, 8
// 00971fe8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8605c;
extern int global_b8fc98;
extern ICreator creator_b32b34;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b20();
const Name &doDeclare();
void destroy_983cf0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b8605c, &callDoDeclare_649b20);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b34;
    global_b8fc98 = 0x29a;
    atexit(&destroy_983cf0);
}
