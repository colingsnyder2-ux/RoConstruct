// from server: 100% by nuck16
// roc 2009-12 00984630  unit: seg_00980000  size: 55 bytes
//
// 00984630  51                   push ecx
// 00984631  68d0986400           push 0x6498d0
// 00984636  68c85fb800           push 0xb85fc8
// 0098463b  c705a02ab300c8cf9c00 mov dword ptr [0xb32aa0], 0x9ccfc8
// 00984645  e8e6cfa7ff           call 0x401630
// 0098464a  83c408               add esp, 8
// 0098464d  e83e3bccff           call 0x648190
// 00984652  890424               mov dword ptr [esp], eax
// 00984655  8d0424               lea eax, [esp]
// 00984658  50                   push eax
// 00984659  e822d3a7ff           call 0x401980
// 0098465e  8bc8                 mov ecx, eax
// 00984660  e8ebd1a7ff           call 0x401850
// 00984665  59                   pop ecx
// 00984666  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fc8;
extern const int data_009ccfc8[];
extern int global_b32aa0;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6498d0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32aa0 = (int)data_009ccfc8;
    call_once(flag_b85fc8, &callDoDeclare_6498d0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
