// from server: 100% by nuck16
// roc 2009-12 0097dbc0  unit: seg_00970000  size: 55 bytes
//
// 0097dbc0  51                   push ecx
// 0097dbc1  68e03a4100           push 0x413ae0
// 0097dbc6  6814a1b700           push 0xb7a114
// 0097dbcb  c7059c33b00020239a00 mov dword ptr [0xb0339c], 0x9a2320
// 0097dbd5  e8563aa8ff           call 0x401630
// 0097dbda  83c408               add esp, 8
// 0097dbdd  e84e5ba9ff           call 0x413730
// 0097dbe2  890424               mov dword ptr [esp], eax
// 0097dbe5  8d0424               lea eax, [esp]
// 0097dbe8  50                   push eax
// 0097dbe9  e8923da8ff           call 0x401980
// 0097dbee  8bc8                 mov ecx, eax
// 0097dbf0  e85b3ca8ff           call 0x401850
// 0097dbf5  59                   pop ecx
// 0097dbf6  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a114;
extern const int data_009a2320[];
extern int global_b0339c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_413ae0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b0339c = (int)data_009a2320;
    call_once(flag_b7a114, &callDoDeclare_413ae0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
