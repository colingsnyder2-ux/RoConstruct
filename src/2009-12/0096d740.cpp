// from server: 100% by nuck16
// roc 2009-12 0096d740  unit: seg_00960000  size: 73 bytes
//
// 0096d740  51                   push ecx
// 0096d741  68d0885300           push 0x5388d0
// 0096d746  68d405b800           push 0xb805d4
// 0096d74b  e8e03ea9ff           call 0x401630
// 0096d750  83c408               add esp, 8
// 0096d753  e828a1bcff           call 0x537880
// 0096d758  890424               mov dword ptr [esp], eax
// 0096d75b  8d0424               lea eax, [esp]
// 0096d75e  50                   push eax
// 0096d75f  e81c42a9ff           call 0x401980
// 0096d764  8bc8                 mov ecx, eax
// 0096d766  e8b57dadff           call 0x445520
// 0096d76b  c7002cf6b100         mov dword ptr [eax], 0xb1f62c
// 0096d771  6850089800           push 0x980850
// 0096d776  c7050006b8009a020000 mov dword ptr [0xb80600], 0x29a
// 0096d780  e8a471e8ff           call 0x7f4929
// 0096d785  83c408               add esp, 8
// 0096d788  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805d4;
extern int global_b80600;
extern ICreator creator_b1f62c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_5388d0();
const Name &doDeclare();
void destroy_980850();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b805d4, &callDoDeclare_5388d0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b1f62c;
    global_b80600 = 0x29a;
    atexit(&destroy_980850);
}
