// from server: 100% by nuck16
// roc 2009-12 009713c0  unit: seg_00970000  size: 73 bytes
//
// 009713c0  51                   push ecx
// 009713c1  68c0986400           push 0x6498c0
// 009713c6  68c45fb800           push 0xb85fc4
// 009713cb  e86002a9ff           call 0x401630
// 009713d0  83c408               add esp, 8
// 009713d3  e8486dcdff           call 0x648120
// 009713d8  890424               mov dword ptr [esp], eax
// 009713db  8d0424               lea eax, [esp]
// 009713de  50                   push eax
// 009713df  e89c05a9ff           call 0x401980
// 009713e4  8bc8                 mov ecx, eax
// 009713e6  e83541adff           call 0x445520
// 009713eb  c7009c2ab300         mov dword ptr [eax], 0xb32a9c
// 009713f1  6870469800           push 0x984670
// 009713f6  c705f0fbb8009a020000 mov dword ptr [0xb8fbf0], 0x29a
// 00971400  e82435e8ff           call 0x7f4929
// 00971405  83c408               add esp, 8
// 00971408  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b85fc4;
extern int global_b8fbf0;
extern ICreator creator_b32a9c;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6498c0();
const Name &doDeclare();
void destroy_984670();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b85fc4, &callDoDeclare_6498c0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32a9c;
    global_b8fbf0 = 0x29a;
    atexit(&destroy_984670);
}
