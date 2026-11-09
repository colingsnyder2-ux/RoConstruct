// from server: 100% by nuck16
// roc 2009-12 0097f560  unit: seg_00970000  size: 55 bytes
//
// 0097f560  51                   push ecx
// 0097f561  6810694f00           push 0x4f6910
// 0097f566  6878deb700           push 0xb7de78
// 0097f56b  c705a87fb100b0a69b00 mov dword ptr [0xb17fa8], 0x9ba6b0
// 0097f575  e8b620a8ff           call 0x401630
// 0097f57a  83c408               add esp, 8
// 0097f57d  e8fe65b7ff           call 0x4f5b80
// 0097f582  890424               mov dword ptr [esp], eax
// 0097f585  8d0424               lea eax, [esp]
// 0097f588  50                   push eax
// 0097f589  e8f223a8ff           call 0x401980
// 0097f58e  8bc8                 mov ecx, eax
// 0097f590  e8bb22a8ff           call 0x401850
// 0097f595  59                   pop ecx
// 0097f596  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de78;
extern const int data_009ba6b0[];
extern int global_b17fa8;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6910();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b17fa8 = (int)data_009ba6b0;
    call_once(flag_b7de78, &callDoDeclare_4f6910);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
