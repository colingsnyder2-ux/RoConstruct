// from server: 100% by nuck16
// roc 2009-12 0097f520  unit: seg_00970000  size: 55 bytes
//
// 0097f520  51                   push ecx
// 0097f521  6820694f00           push 0x4f6920
// 0097f526  687cdeb700           push 0xb7de7c
// 0097f52b  c705ac7fb100cca69b00 mov dword ptr [0xb17fac], 0x9ba6cc
// 0097f535  e8f620a8ff           call 0x401630
// 0097f53a  83c408               add esp, 8
// 0097f53d  e8ae66b7ff           call 0x4f5bf0
// 0097f542  890424               mov dword ptr [esp], eax
// 0097f545  8d0424               lea eax, [esp]
// 0097f548  50                   push eax
// 0097f549  e83224a8ff           call 0x401980
// 0097f54e  8bc8                 mov ecx, eax
// 0097f550  e8fb22a8ff           call 0x401850
// 0097f555  59                   pop ecx
// 0097f556  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7de7c;
extern const int data_009ba6cc[];
extern int global_b17fac;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4f6920();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b17fac = (int)data_009ba6cc;
    call_once(flag_b7de7c, &callDoDeclare_4f6920);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
