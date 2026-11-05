// from server: 100% by nuck16
// roc 2009-12 0096d650  unit: seg_00960000  size: 73 bytes
//
// 0096d650  51                   push ecx
// 0096d651  68a0885300           push 0x5388a0
// 0096d656  68c805b800           push 0xb805c8
// 0096d65b  e8d03fa9ff           call 0x401630
// 0096d660  83c408               add esp, 8
// 0096d663  e8c8a0bcff           call 0x537730
// 0096d668  890424               mov dword ptr [esp], eax
// 0096d66b  8d0424               lea eax, [esp]
// 0096d66e  50                   push eax
// 0096d66f  e80c43a9ff           call 0x401980
// 0096d674  8bc8                 mov ecx, eax
// 0096d676  e8a57eadff           call 0x445520
// 0096d67b  c70020f6b100         mov dword ptr [eax], 0xb1f620
// 0096d681  6810099800           push 0x980910
// 0096d686  c705f405b8009a020000 mov dword ptr [0xb805f4], 0x29a
// 0096d690  e89472e8ff           call 0x7f4929
// 0096d695  83c408               add esp, 8
// 0096d698  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b805c8;
extern int global_b805f4;
extern ICreator creator_b1f620;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_5388a0();
const Name &doDeclare();
void destroy_980910();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b805c8, &callDoDeclare_5388a0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b1f620;
    global_b805f4 = 0x29a;
    atexit(&destroy_980910);
}
