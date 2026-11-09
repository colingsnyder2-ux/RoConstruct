// from server: 100% by nuck16
// roc 2009-12 009721d0  unit: seg_00970000  size: 73 bytes
//
// 009721d0  51                   push ecx
// 009721d1  68909b6400           push 0x649b90
// 009721d6  687860b800           push 0xb86078
// 009721db  e850f4a8ff           call 0x401630
// 009721e0  83c408               add esp, 8
// 009721e3  e8e872cdff           call 0x6494d0
// 009721e8  890424               mov dword ptr [esp], eax
// 009721eb  8d0424               lea eax, [esp]
// 009721ee  50                   push eax
// 009721ef  e88cf7a8ff           call 0x401980
// 009721f4  8bc8                 mov ecx, eax
// 009721f6  e82533adff           call 0x445520
// 009721fb  c700502bb300         mov dword ptr [eax], 0xb32b50
// 00972201  68303b9800           push 0x983b30
// 00972206  c705b4fcb8009a020000 mov dword ptr [0xb8fcb4], 0x29a
// 00972210  e81427e8ff           call 0x7f4929
// 00972215  83c408               add esp, 8
// 00972218  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86078;
extern int global_b8fcb4;
extern ICreator creator_b32b50;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b90();
const Name &doDeclare();
void destroy_983b30();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86078, &callDoDeclare_649b90);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b50;
    global_b8fcb4 = 0x29a;
    atexit(&destroy_983b30);
}
