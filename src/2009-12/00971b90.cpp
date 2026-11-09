// from server: 100% by nuck16
// roc 2009-12 00971b90  unit: seg_00970000  size: 73 bytes
//
// 00971b90  51                   push ecx
// 00971b91  68509a6400           push 0x649a50
// 00971b96  682860b800           push 0xb86028
// 00971b9b  e890faa8ff           call 0x401630
// 00971ba0  83c408               add esp, 8
// 00971ba3  e86870cdff           call 0x648c10
// 00971ba8  890424               mov dword ptr [esp], eax
// 00971bab  8d0424               lea eax, [esp]
// 00971bae  50                   push eax
// 00971baf  e8ccfda8ff           call 0x401980
// 00971bb4  8bc8                 mov ecx, eax
// 00971bb6  e86539adff           call 0x445520
// 00971bbb  c700002bb300         mov dword ptr [eax], 0xb32b00
// 00971bc1  6830409800           push 0x984030
// 00971bc6  c70554fcb8009a020000 mov dword ptr [0xb8fc54], 0x29a
// 00971bd0  e8542de8ff           call 0x7f4929
// 00971bd5  83c408               add esp, 8
// 00971bd8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86028;
extern int global_b8fc54;
extern ICreator creator_b32b00;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a50();
const Name &doDeclare();
void destroy_984030();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86028, &callDoDeclare_649a50);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b00;
    global_b8fc54 = 0x29a;
    atexit(&destroy_984030);
}
