// from server: 100% by nuck16
// roc 2009-12 009687a0  unit: seg_00960000  size: 73 bytes
//
// 009687a0  51                   push ecx
// 009687a1  6810364300           push 0x433610
// 009687a6  6870a3b700           push 0xb7a370
// 009687ab  e8808ea9ff           call 0x401630
// 009687b0  83c408               add esp, 8
// 009687b3  e858a7acff           call 0x432f10
// 009687b8  890424               mov dword ptr [esp], eax
// 009687bb  8d0424               lea eax, [esp]
// 009687be  50                   push eax
// 009687bf  e8bc91a9ff           call 0x401980
// 009687c4  8bc8                 mov ecx, eax
// 009687c6  e855cdadff           call 0x445520
// 009687cb  c700ac6bb000         mov dword ptr [eax], 0xb06bac
// 009687d1  68a0df9700           push 0x97dfa0
// 009687d6  c70580a3b7009a020000 mov dword ptr [0xb7a380], 0x29a
// 009687e0  e844c1e8ff           call 0x7f4929
// 009687e5  83c408               add esp, 8
// 009687e8  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a370;
extern int global_b7a380;
extern ICreator creator_b06bac;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_433610();
const Name &doDeclare();
void destroy_97dfa0();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a370, &callDoDeclare_433610);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b06bac;
    global_b7a380 = 0x29a;
    atexit(&destroy_97dfa0);
}
