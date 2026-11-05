// from server: 100% by nuck16
// roc 2009-12 00971730  unit: seg_00970000  size: 73 bytes
//
// 00971730  51                   push ecx
// 00971731  6870996400           push 0x649970
// 00971736  68f05fb800           push 0xb85ff0
// 0097173b  e8f0fea8ff           call 0x401630
// 00971740  83c408               add esp, 8
// 00971743  e8a86ecdff           call 0x6485f0
// 00971748  890424               mov dword ptr [esp], eax
// 0097174b  8d0424               lea eax, [esp]
// 0097174e  50                   push eax
// 0097174f  e82c02a9ff           call 0x401980
// 00971754  8bc8                 mov ecx, eax
// 00971756  e8c53dadff           call 0x445520
// 0097175b  c700c82ab300         mov dword ptr [eax], 0xb32ac8
// 00971761  68b0439800           push 0x9843b0
// 00971766  c7051cfcb8009a020000 mov dword ptr [0xb8fc1c], 0x29a
// 00971770  e8b431e8ff           call 0x7f4929
// 00971775  83c408               add esp, 8
// 00971778  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85ff0;
extern int global_b8fc1c;
extern ICreator creator_b32ac8;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_649970();
const Name &doDeclare();
void destroy_9843b0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b85ff0, &callDoDeclare_649970);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32ac8;
    global_b8fc1c = 0x29a;
    atexit(&destroy_9843b0);
}
