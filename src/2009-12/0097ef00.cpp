// from server: 100% by nuck16
// roc 2009-12 0097ef00  unit: seg_00970000  size: 55 bytes
//
// 0097ef00  51                   push ecx
// 0097ef01  6810054c00           push 0x4c0510
// 0097ef06  6868cfb700           push 0xb7cf68
// 0097ef0b  c705bc09b1009c519b00 mov dword ptr [0xb109bc], 0x9b519c
// 0097ef15  e81627a8ff           call 0x401630
// 0097ef1a  83c408               add esp, 8
// 0097ef1d  e8be11b4ff           call 0x4c00e0
// 0097ef22  890424               mov dword ptr [esp], eax
// 0097ef25  8d0424               lea eax, [esp]
// 0097ef28  50                   push eax
// 0097ef29  e8522aa8ff           call 0x401980
// 0097ef2e  8bc8                 mov ecx, eax
// 0097ef30  e81b29a8ff           call 0x401850
// 0097ef35  59                   pop ecx
// 0097ef36  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7cf68;
extern const int data_009b519c[];
extern int global_b109bc;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_4c0510();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b109bc = (int)data_009b519c;
    call_once(flag_b7cf68, &callDoDeclare_4c0510);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
