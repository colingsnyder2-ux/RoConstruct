// from server: 100% by nuck16
// roc 2009-12 0097f760  unit: seg_00970000  size: 55 bytes
//
// 0097f760  51                   push ecx
// 0097f761  6890684f00           push 0x4f6890
// 0097f766  6858deb700           push 0xb7de58
// 0097f76b  c705887fb100e8a49b00 mov dword ptr [0xb17f88], 0x9ba4e8
// 0097f775  e8b61ea8ff           call 0x401630
// 0097f77a  83c408               add esp, 8
// 0097f77d  e87e60b7ff           call 0x4f5800
// 0097f782  890424               mov dword ptr [esp], eax
// 0097f785  8d0424               lea eax, [esp]
// 0097f788  50                   push eax
// 0097f789  e8f221a8ff           call 0x401980
// 0097f78e  8bc8                 mov ecx, eax
// 0097f790  e8bb20a8ff           call 0x401850
// 0097f795  59                   pop ecx
// 0097f796  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de58;
extern const int data_009ba4e8[];
extern int global_b17f88;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6890();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b17f88 = (int)data_009ba4e8;
    call_once(flag_b7de58, &callDoDeclare_4f6890);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
