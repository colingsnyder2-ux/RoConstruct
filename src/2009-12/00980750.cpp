// from server: 100% by nuck16
// roc 2009-12 00980750  unit: seg_00980000  size: 55 bytes
//
// 00980750  51                   push ecx
// 00980751  6810895300           push 0x538910
// 00980756  68e405b800           push 0xb805e4
// 0098075b  c7053cf6b100bcd39b00 mov dword ptr [0xb1f63c], 0x9bd3bc
// 00980765  e8c60ea8ff           call 0x401630
// 0098076a  83c408               add esp, 8
// 0098076d  e8ce72bbff           call 0x537a40
// 00980772  890424               mov dword ptr [esp], eax
// 00980775  8d0424               lea eax, [esp]
// 00980778  50                   push eax
// 00980779  e80212a8ff           call 0x401980
// 0098077e  8bc8                 mov ecx, eax
// 00980780  e8cb10a8ff           call 0x401850
// 00980785  59                   pop ecx
// 00980786  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805e4;
extern const int data_009bd3bc[];
extern int global_b1f63c;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_538910();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b1f63c = (int)data_009bd3bc;
    call_once(flag_b805e4, &callDoDeclare_538910);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
