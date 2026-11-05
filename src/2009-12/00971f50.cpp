// from server: 100% by nuck16
// roc 2009-12 00971f50  unit: seg_00970000  size: 73 bytes
//
// 00971f50  51                   push ecx
// 00971f51  68109b6400           push 0x649b10
// 00971f56  685860b800           push 0xb86058
// 00971f5b  e8d0f6a8ff           call 0x401630
// 00971f60  83c408               add esp, 8
// 00971f63  e8e871cdff           call 0x649150
// 00971f68  890424               mov dword ptr [esp], eax
// 00971f6b  8d0424               lea eax, [esp]
// 00971f6e  50                   push eax
// 00971f6f  e80cfaa8ff           call 0x401980
// 00971f74  8bc8                 mov ecx, eax
// 00971f76  e8a535adff           call 0x445520
// 00971f7b  c700302bb300         mov dword ptr [eax], 0xb32b30
// 00971f81  68303d9800           push 0x983d30
// 00971f86  c70594fcb8009a020000 mov dword ptr [0xb8fc94], 0x29a
// 00971f90  e89429e8ff           call 0x7f4929
// 00971f95  83c408               add esp, 8
// 00971f98  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86058;
extern int global_b8fc94;
extern ICreator creator_b32b30;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649b10();
const Name &doDeclare();
void destroy_983d30();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86058, &callDoDeclare_649b10);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32b30;
    global_b8fc94 = 0x29a;
    atexit(&destroy_983d30);
}
