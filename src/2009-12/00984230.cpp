// from server: 100% by nuck16
// roc 2009-12 00984230  unit: seg_00980000  size: 55 bytes
//
// 00984230  51                   push ecx
// 00984231  68d0996400           push 0x6499d0
// 00984236  680860b800           push 0xb86008
// 0098423b  c705e02ab30088d19c00 mov dword ptr [0xb32ae0], 0x9cd188
// 00984245  e8e6d3a7ff           call 0x401630
// 0098424a  83c408               add esp, 8
// 0098424d  e83e46ccff           call 0x648890
// 00984252  890424               mov dword ptr [esp], eax
// 00984255  8d0424               lea eax, [esp]
// 00984258  50                   push eax
// 00984259  e822d7a7ff           call 0x401980
// 0098425e  8bc8                 mov ecx, eax
// 00984260  e8ebd5a7ff           call 0x401850
// 00984265  59                   pop ecx
// 00984266  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86008;
extern const int data_009cd188[];
extern int global_b32ae0;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6499d0();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b32ae0 = (int)data_009cd188;
    call_once(flag_b86008, &callDoDeclare_6499d0);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
