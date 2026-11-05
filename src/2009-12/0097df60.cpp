// from server: 100% by nuck16
// roc 2009-12 0097df60  unit: seg_00970000  size: 55 bytes
//
// 0097df60  51                   push ecx
// 0097df61  6820364300           push 0x433620
// 0097df66  6874a3b700           push 0xb7a374
// 0097df6b  c705b06bb000f07e9a00 mov dword ptr [0xb06bb0], 0x9a7ef0
// 0097df75  e8b636a8ff           call 0x401630
// 0097df7a  83c408               add esp, 8
// 0097df7d  e8fe4fabff           call 0x432f80
// 0097df82  890424               mov dword ptr [esp], eax
// 0097df85  8d0424               lea eax, [esp]
// 0097df88  50                   push eax
// 0097df89  e8f239a8ff           call 0x401980
// 0097df8e  8bc8                 mov ecx, eax
// 0097df90  e8bb38a8ff           call 0x401850
// 0097df95  59                   pop ecx
// 0097df96  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b7a374;
extern const int data_009a7ef0[];
extern int global_b06bb0;


void call_once(once_flag &flag, void (*f)());
void callDoDeclare_433620();
const Name &doDeclare();


struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    global_b06bb0 = (int)data_009a7ef0;
    call_once(flag_b7a374, &callDoDeclare_433620);
    const Name *key = &doDeclare();
    getCreators().add(key);
}
