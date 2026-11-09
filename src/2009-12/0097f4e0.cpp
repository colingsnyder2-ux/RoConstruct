// from server: 100% by nuck16
// roc 2009-12 0097f4e0  unit: seg_00970000  size: 55 bytes
//
// 0097f4e0  51                   push ecx
// 0097f4e1  6830694f00           push 0x4f6930
// 0097f4e6  6880deb700           push 0xb7de80
// 0097f4eb  c705b07fb100e8a69b00 mov dword ptr [0xb17fb0], 0x9ba6e8
// 0097f4f5  e83621a8ff           call 0x401630
// 0097f4fa  83c408               add esp, 8
// 0097f4fd  e85e67b7ff           call 0x4f5c60
// 0097f502  890424               mov dword ptr [esp], eax
// 0097f505  8d0424               lea eax, [esp]
// 0097f508  50                   push eax
// 0097f509  e87224a8ff           call 0x401980
// 0097f50e  8bc8                 mov ecx, eax
// 0097f510  e83b23a8ff           call 0x401850
// 0097f515  59                   pop ecx
// 0097f516  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de80;
extern const int data_009ba6e8[];
extern int global_b17fb0;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6930();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b17fb0 = (int)data_009ba6e8;
    call_once(flag_b7de80, &callDoDeclare_4f6930);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
