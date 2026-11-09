// from server: 100% by nuck16
// roc 2009-12 00971af0  unit: seg_00970000  size: 73 bytes
//
// 00971af0  51                   push ecx
// 00971af1  68309a6400           push 0x649a30
// 00971af6  682060b800           push 0xb86020
// 00971afb  e830fba8ff           call 0x401630
// 00971b00  83c408               add esp, 8
// 00971b03  e82870cdff           call 0x648b30
// 00971b08  890424               mov dword ptr [esp], eax
// 00971b0b  8d0424               lea eax, [esp]
// 00971b0e  50                   push eax
// 00971b0f  e86cfea8ff           call 0x401980
// 00971b14  8bc8                 mov ecx, eax
// 00971b16  e8053aadff           call 0x445520
// 00971b1b  c700f82ab300         mov dword ptr [eax], 0xb32af8
// 00971b21  68b0409800           push 0x9840b0
// 00971b26  c7054cfcb8009a020000 mov dword ptr [0xb8fc4c], 0x29a
// 00971b30  e8f42de8ff           call 0x7f4929
// 00971b35  83c408               add esp, 8
// 00971b38  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86020;
extern int global_b8fc4c;
extern ICreator creator_b32af8;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a30();
const Name &doDeclare();
void destroy_9840b0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86020, &callDoDeclare_649a30);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32af8;
    global_b8fc4c = 0x29a;
    atexit(&destroy_9840b0);
}
