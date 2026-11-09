// from server: 100% by nuck16
// roc 2009-12 009845f0  unit: seg_00980000  size: 55 bytes
//
// 009845f0  51                   push ecx
// 009845f1  68e0986400           push 0x6498e0
// 009845f6  68cc5fb800           push 0xb85fcc
// 009845fb  c705a42ab300e4cf9c00 mov dword ptr [0xb32aa4], 0x9ccfe4
// 00984605  e826d0a7ff           call 0x401630
// 0098460a  83c408               add esp, 8
// 0098460d  e8ee3bccff           call 0x648200
// 00984612  890424               mov dword ptr [esp], eax
// 00984615  8d0424               lea eax, [esp]
// 00984618  50                   push eax
// 00984619  e862d3a7ff           call 0x401980
// 0098461e  8bc8                 mov ecx, eax
// 00984620  e82bd2a7ff           call 0x401850
// 00984625  59                   pop ecx
// 00984626  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fcc;
extern const int data_009ccfe4[];
extern int global_b32aa4;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6498e0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32aa4 = (int)data_009ccfe4;
    call_once(flag_b85fcc, &callDoDeclare_6498e0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
