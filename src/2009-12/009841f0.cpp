// from server: 100% by nuck16
// roc 2009-12 009841f0  unit: seg_00980000  size: 55 bytes
//
// 009841f0  51                   push ecx
// 009841f1  68e0996400           push 0x6499e0
// 009841f6  680c60b800           push 0xb8600c
// 009841fb  c705e42ab300a4d19c00 mov dword ptr [0xb32ae4], 0x9cd1a4
// 00984205  e826d4a7ff           call 0x401630
// 0098420a  83c408               add esp, 8
// 0098420d  e8ee46ccff           call 0x648900
// 00984212  890424               mov dword ptr [esp], eax
// 00984215  8d0424               lea eax, [esp]
// 00984218  50                   push eax
// 00984219  e862d7a7ff           call 0x401980
// 0098421e  8bc8                 mov ecx, eax
// 00984220  e82bd6a7ff           call 0x401850
// 00984225  59                   pop ecx
// 00984226  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8600c;
extern const int data_009cd1a4[];
extern int global_b32ae4;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6499e0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32ae4 = (int)data_009cd1a4;
    call_once(flag_b8600c, &callDoDeclare_6499e0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
