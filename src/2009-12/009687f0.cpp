// from server: 100% by nuck16
// roc 2009-12 009687f0  unit: seg_00960000  size: 73 bytes
//
// 009687f0  51                   push ecx
// 009687f1  6820364300           push 0x433620
// 009687f6  6874a3b700           push 0xb7a374
// 009687fb  e8308ea9ff           call 0x401630
// 00968800  83c408               add esp, 8
// 00968803  e878a7acff           call 0x432f80
// 00968808  890424               mov dword ptr [esp], eax
// 0096880b  8d0424               lea eax, [esp]
// 0096880e  50                   push eax
// 0096880f  e86c91a9ff           call 0x401980
// 00968814  8bc8                 mov ecx, eax
// 00968816  e805cdadff           call 0x445520
// 0096881b  c700b06bb000         mov dword ptr [eax], 0xb06bb0
// 00968821  6860df9700           push 0x97df60
// 00968826  c70584a3b7009a020000 mov dword ptr [0xb7a384], 0x29a
// 00968830  e8f4c0e8ff           call 0x7f4929
// 00968835  83c408               add esp, 8
// 00968838  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a374;
extern int global_b7a384;
extern ICreator creator_b06bb0;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_433620();
const Name &doDeclare();
void destroy_97df60();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b7a374, &callDoDeclare_433620);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b06bb0;
    global_b7a384 = 0x29a;
    atexit(&destroy_97df60);
}
