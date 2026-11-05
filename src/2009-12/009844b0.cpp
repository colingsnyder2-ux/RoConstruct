// from server: 100% by nuck16
// roc 2009-12 009844b0  unit: seg_00980000  size: 55 bytes
//
// 009844b0  51                   push ecx
// 009844b1  6830996400           push 0x649930
// 009844b6  68e05fb800           push 0xb85fe0
// 009844bb  c705b82ab30070d09c00 mov dword ptr [0xb32ab8], 0x9cd070
// 009844c5  e866d1a7ff           call 0x401630
// 009844ca  83c408               add esp, 8
// 009844cd  e85e3fccff           call 0x648430
// 009844d2  890424               mov dword ptr [esp], eax
// 009844d5  8d0424               lea eax, [esp]
// 009844d8  50                   push eax
// 009844d9  e8a2d4a7ff           call 0x401980
// 009844de  8bc8                 mov ecx, eax
// 009844e0  e86bd3a7ff           call 0x401850
// 009844e5  59                   pop ecx
// 009844e6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fe0;
extern const int data_009cd070[];
extern int global_b32ab8;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649930();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32ab8 = (int)data_009cd070;
    call_once(flag_b85fe0, &callDoDeclare_649930);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
