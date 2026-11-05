// from server: 100% by nuck16
// roc 2009-12 009839f0  unit: seg_00980000  size: 55 bytes
//
// 009839f0  51                   push ecx
// 009839f1  68e09b6400           push 0x649be0
// 009839f6  688c60b800           push 0xb8608c
// 009839fb  c705642bb30018dd9c00 mov dword ptr [0xb32b64], 0x9cdd18
// 00983a05  e826dca7ff           call 0x401630
// 00983a0a  83c408               add esp, 8
// 00983a0d  e8ee5cccff           call 0x649700
// 00983a12  890424               mov dword ptr [esp], eax
// 00983a15  8d0424               lea eax, [esp]
// 00983a18  50                   push eax
// 00983a19  e862dfa7ff           call 0x401980
// 00983a1e  8bc8                 mov ecx, eax
// 00983a20  e82bdea7ff           call 0x401850
// 00983a25  59                   pop ecx
// 00983a26  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b8608c;
extern const int data_009cdd18[];
extern int global_b32b64;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649be0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32b64 = (int)data_009cdd18;
    call_once(flag_b8608c, &callDoDeclare_649be0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
