// from server: 100% by nuck16
// roc 2009-12 009717d0  unit: seg_00970000  size: 73 bytes
//
// 009717d0  51                   push ecx
// 009717d1  6890996400           push 0x649990
// 009717d6  68f85fb800           push 0xb85ff8
// 009717db  e850fea8ff           call 0x401630
// 009717e0  83c408               add esp, 8
// 009717e3  e8e86ecdff           call 0x6486d0
// 009717e8  890424               mov dword ptr [esp], eax
// 009717eb  8d0424               lea eax, [esp]
// 009717ee  50                   push eax
// 009717ef  e88c01a9ff           call 0x401980
// 009717f4  8bc8                 mov ecx, eax
// 009717f6  e8253dadff           call 0x445520
// 009717fb  c700d02ab300         mov dword ptr [eax], 0xb32ad0
// 00971801  6830439800           push 0x984330
// 00971806  c70524fcb8009a020000 mov dword ptr [0xb8fc24], 0x29a
// 00971810  e81431e8ff           call 0x7f4929
// 00971815  83c408               add esp, 8
// 00971818  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85ff8;
extern int global_b8fc24;
extern ICreator creator_b32ad0;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649990();
const Name &doDeclare();
void destroy_984330();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b85ff8, &callDoDeclare_649990);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32ad0;
    global_b8fc24 = 0x29a;
    atexit(&destroy_984330);
}
