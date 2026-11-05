// from server: 100% by nuck16
// roc 2009-12 009845b0  unit: seg_00980000  size: 55 bytes
//
// 009845b0  51                   push ecx
// 009845b1  68f0986400           push 0x6498f0
// 009845b6  68d05fb800           push 0xb85fd0
// 009845bb  c705a82ab30000d09c00 mov dword ptr [0xb32aa8], 0x9cd000
// 009845c5  e866d0a7ff           call 0x401630
// 009845ca  83c408               add esp, 8
// 009845cd  e89e3cccff           call 0x648270
// 009845d2  890424               mov dword ptr [esp], eax
// 009845d5  8d0424               lea eax, [esp]
// 009845d8  50                   push eax
// 009845d9  e8a2d3a7ff           call 0x401980
// 009845de  8bc8                 mov ecx, eax
// 009845e0  e86bd2a7ff           call 0x401850
// 009845e5  59                   pop ecx
// 009845e6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fd0;
extern const int data_009cd000[];
extern int global_b32aa8;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6498f0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32aa8 = (int)data_009cd000;
    call_once(flag_b85fd0, &callDoDeclare_6498f0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
