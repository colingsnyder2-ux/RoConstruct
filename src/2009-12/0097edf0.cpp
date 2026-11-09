// from server: 100% by nuck16
// roc 2009-12 0097edf0  unit: seg_00970000  size: 55 bytes
//
// 0097edf0  51                   push ecx
// 0097edf1  6890b44800           push 0x48b490
// 0097edf6  68d8ccb700           push 0xb7ccd8
// 0097edfb  c70510c8b000242e9b00 mov dword ptr [0xb0c810], 0x9b2e24
// 0097ee05  e82628a8ff           call 0x401630
// 0097ee0a  83c408               add esp, 8
// 0097ee0d  e8eec5b0ff           call 0x48b400
// 0097ee12  890424               mov dword ptr [esp], eax
// 0097ee15  8d0424               lea eax, [esp]
// 0097ee18  50                   push eax
// 0097ee19  e8622ba8ff           call 0x401980
// 0097ee1e  8bc8                 mov ecx, eax
// 0097ee20  e82b2aa8ff           call 0x401850
// 0097ee25  59                   pop ecx
// 0097ee26  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7ccd8;
extern const int data_009b2e24[];
extern int global_b0c810;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_48b490();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b0c810 = (int)data_009b2e24;
    call_once(flag_b7ccd8, &callDoDeclare_48b490);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
