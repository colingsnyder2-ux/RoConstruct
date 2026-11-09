// from server: 100% by nuck16
// roc 2009-12 009857d0  unit: seg_00980000  size: 55 bytes
//
// 009857d0  51                   push ecx
// 009857d1  6810416b00           push 0x6b4110
// 009857d6  68a01cb900           push 0xb91ca0
// 009857db  c705f4b8b300dc5f9d00 mov dword ptr [0xb3b8f4], 0x9d5fdc
// 009857e5  e846bea7ff           call 0x401630
// 009857ea  83c408               add esp, 8
// 009857ed  e8eee3d2ff           call 0x6b3be0
// 009857f2  890424               mov dword ptr [esp], eax
// 009857f5  8d0424               lea eax, [esp]
// 009857f8  50                   push eax
// 009857f9  e882c1a7ff           call 0x401980
// 009857fe  8bc8                 mov ecx, eax
// 00985800  e84bc0a7ff           call 0x401850
// 00985805  59                   pop ecx
// 00985806  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b91ca0;
extern const int data_009d5fdc[];
extern int global_b3b8f4;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6b4110();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b3b8f4 = (int)data_009d5fdc;
    call_once(flag_b91ca0, &callDoDeclare_6b4110);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
