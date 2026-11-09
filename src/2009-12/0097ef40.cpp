// from server: 100% by nuck16
// roc 2009-12 0097ef40  unit: seg_00970000  size: 55 bytes
//
// 0097ef40  51                   push ecx
// 0097ef41  68c02d4c00           push 0x4c2dc0
// 0097ef46  6894cfb700           push 0xb7cf94
// 0097ef4b  c7057c0eb10034549b00 mov dword ptr [0xb10e7c], 0x9b5434
// 0097ef55  e8d626a8ff           call 0x401630
// 0097ef5a  83c408               add esp, 8
// 0097ef5d  e8ae32b4ff           call 0x4c2210
// 0097ef62  890424               mov dword ptr [esp], eax
// 0097ef65  8d0424               lea eax, [esp]
// 0097ef68  50                   push eax
// 0097ef69  e8122aa8ff           call 0x401980
// 0097ef6e  8bc8                 mov ecx, eax
// 0097ef70  e8db28a8ff           call 0x401850
// 0097ef75  59                   pop ecx
// 0097ef76  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7cf94;
extern const int data_009b5434[];
extern int global_b10e7c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4c2dc0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b10e7c = (int)data_009b5434;
    call_once(flag_b7cf94, &callDoDeclare_4c2dc0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
