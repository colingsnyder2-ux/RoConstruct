// from server: 100% by nuck16
// roc 2009-12 00984130  unit: seg_00980000  size: 55 bytes
//
// 00984130  51                   push ecx
// 00984131  68109a6400           push 0x649a10
// 00984136  681860b800           push 0xb86018
// 0098413b  c705f02ab300f8d19c00 mov dword ptr [0xb32af0], 0x9cd1f8
// 00984145  e8e6d4a7ff           call 0x401630
// 0098414a  83c408               add esp, 8
// 0098414d  e8fe48ccff           call 0x648a50
// 00984152  890424               mov dword ptr [esp], eax
// 00984155  8d0424               lea eax, [esp]
// 00984158  50                   push eax
// 00984159  e822d8a7ff           call 0x401980
// 0098415e  8bc8                 mov ecx, eax
// 00984160  e8ebd6a7ff           call 0x401850
// 00984165  59                   pop ecx
// 00984166  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86018;
extern const int data_009cd1f8[];
extern int global_b32af0;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649a10();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32af0 = (int)data_009cd1f8;
    call_once(flag_b86018, &callDoDeclare_649a10);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
