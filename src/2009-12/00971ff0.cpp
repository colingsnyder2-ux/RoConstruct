// from server: 100% by nuck16
// roc 2009-12 00971ff0  unit: seg_00970000  size: 73 bytes
//
// 00971ff0  51                   push ecx
// 00971ff1  68309b6400           push 0x649b30
// 00971ff6  686060b800           push 0xb86060
// 00971ffb  e830f6a8ff           call 0x401630
// 00972000  83c408               add esp, 8
// 00972003  e82872cdff           call 0x649230
// 00972008  890424               mov dword ptr [esp], eax
// 0097200b  8d0424               lea eax, [esp]
// 0097200e  50                   push eax
// 0097200f  e86cf9a8ff           call 0x401980
// 00972014  8bc8                 mov ecx, eax
// 00972016  e80535adff           call 0x445520
// 0097201b  c700382bb300         mov dword ptr [eax], 0xb32b38
// 00972021  68b03c9800           push 0x983cb0
// 00972026  c7059cfcb8009a020000 mov dword ptr [0xb8fc9c], 0x29a
// 00972030  e8f428e8ff           call 0x7f4929
// 00972035  83c408               add esp, 8
// 00972038  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86060;
extern int global_b8fc9c;
extern ICreator creator_b32b38;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b30();
const Name &doDeclare();
void destroy_983cb0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86060, &callDoDeclare_649b30);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b38;
    global_b8fc9c = 0x29a;
    atexit(&destroy_983cb0);
}
