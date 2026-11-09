// from server: 100% by nuck16
// roc 2009-12 0096a020  unit: seg_00960000  size: 73 bytes
//
// 0096a020  51                   push ecx
// 0096a021  68b0ac4900           push 0x49acb0
// 0096a026  68f0cdb700           push 0xb7cdf0
// 0096a02b  e80076a9ff           call 0x401630
// 0096a030  83c408               add esp, 8
// 0096a033  e88807b3ff           call 0x49a7c0
// 0096a038  890424               mov dword ptr [esp], eax
// 0096a03b  8d0424               lea eax, [esp]
// 0096a03e  50                   push eax
// 0096a03f  e83c79a9ff           call 0x401980
// 0096a044  8bc8                 mov ecx, eax
// 0096a046  e8d5b4adff           call 0x445520
// 0096a04b  c70014fdb000         mov dword ptr [eax], 0xb0fd14
// 0096a051  68b0ee9700           push 0x97eeb0
// 0096a056  c705f4cdb7009a020000 mov dword ptr [0xb7cdf4], 0x29a
// 0096a060  e8c4a8e8ff           call 0x7f4929
// 0096a065  83c408               add esp, 8
// 0096a068  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7cdf0;
extern int global_b7cdf4;
extern ICreator creator_b0fd14;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_49acb0();
const Name &doDeclare();
void destroy_97eeb0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7cdf0, &callDoDeclare_49acb0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b0fd14;
    global_b7cdf4 = 0x29a;
    atexit(&destroy_97eeb0);
}
