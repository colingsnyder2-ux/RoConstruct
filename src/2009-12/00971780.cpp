// from server: 100% by nuck16
// roc 2009-12 00971780  unit: seg_00970000  size: 73 bytes
//
// 00971780  51                   push ecx
// 00971781  6880996400           push 0x649980
// 00971786  68f45fb800           push 0xb85ff4
// 0097178b  e8a0fea8ff           call 0x401630
// 00971790  83c408               add esp, 8
// 00971793  e8c86ecdff           call 0x648660
// 00971798  890424               mov dword ptr [esp], eax
// 0097179b  8d0424               lea eax, [esp]
// 0097179e  50                   push eax
// 0097179f  e8dc01a9ff           call 0x401980
// 009717a4  8bc8                 mov ecx, eax
// 009717a6  e8753dadff           call 0x445520
// 009717ab  c700cc2ab300         mov dword ptr [eax], 0xb32acc
// 009717b1  6870439800           push 0x984370
// 009717b6  c70520fcb8009a020000 mov dword ptr [0xb8fc20], 0x29a
// 009717c0  e86431e8ff           call 0x7f4929
// 009717c5  83c408               add esp, 8
// 009717c8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85ff4;
extern int global_b8fc20;
extern ICreator creator_b32acc;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649980();
const Name &doDeclare();
void destroy_984370();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b85ff4, &callDoDeclare_649980);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32acc;
    global_b8fc20 = 0x29a;
    atexit(&destroy_984370);
}
