// from server: 100% by nuck16
// roc 2009-12 0097d760  unit: seg_00970000  size: 55 bytes
//
// 0097d760  51                   push ecx
// 0097d761  6800214000           push 0x402100
// 0097d766  682495b700           push 0xb79524
// 0097d76b  c70534f6af0074f59900 mov dword ptr [0xaff634], 0x99f574
// 0097d775  e8b63ea8ff           call 0x401630
// 0097d77a  83c408               add esp, 8
// 0097d77d  e82e48a8ff           call 0x401fb0
// 0097d782  890424               mov dword ptr [esp], eax
// 0097d785  8d0424               lea eax, [esp]
// 0097d788  50                   push eax
// 0097d789  e8f241a8ff           call 0x401980
// 0097d78e  8bc8                 mov ecx, eax
// 0097d790  e8bb40a8ff           call 0x401850
// 0097d795  59                   pop ecx
// 0097d796  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b79524;
extern const int data_0099f574[];
extern int global_aff634;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_402100();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_aff634 = (int)data_0099f574;
    call_once(flag_b79524, &callDoDeclare_402100);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
