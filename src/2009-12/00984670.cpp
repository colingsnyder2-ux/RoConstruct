// from server: 100% by nuck16
// roc 2009-12 00984670  unit: seg_00980000  size: 55 bytes
//
// 00984670  51                   push ecx
// 00984671  68c0986400           push 0x6498c0
// 00984676  68c45fb800           push 0xb85fc4
// 0098467b  c7059c2ab300accf9c00 mov dword ptr [0xb32a9c], 0x9ccfac
// 00984685  e8a6cfa7ff           call 0x401630
// 0098468a  83c408               add esp, 8
// 0098468d  e88e3accff           call 0x648120
// 00984692  890424               mov dword ptr [esp], eax
// 00984695  8d0424               lea eax, [esp]
// 00984698  50                   push eax
// 00984699  e8e2d2a7ff           call 0x401980
// 0098469e  8bc8                 mov ecx, eax
// 009846a0  e8abd1a7ff           call 0x401850
// 009846a5  59                   pop ecx
// 009846a6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fc4;
extern const int data_009ccfac[];
extern int global_b32a9c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6498c0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32a9c = (int)data_009ccfac;
    call_once(flag_b85fc4, &callDoDeclare_6498c0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
