// from server: 100% by nuck16
// roc 2009-12 00971910  unit: seg_00970000  size: 73 bytes
//
// 00971910  51                   push ecx
// 00971911  68d0996400           push 0x6499d0
// 00971916  680860b800           push 0xb86008
// 0097191b  e810fda8ff           call 0x401630
// 00971920  83c408               add esp, 8
// 00971923  e8686fcdff           call 0x648890
// 00971928  890424               mov dword ptr [esp], eax
// 0097192b  8d0424               lea eax, [esp]
// 0097192e  50                   push eax
// 0097192f  e84c00a9ff           call 0x401980
// 00971934  8bc8                 mov ecx, eax
// 00971936  e8e53badff           call 0x445520
// 0097193b  c700e02ab300         mov dword ptr [eax], 0xb32ae0
// 00971941  6830429800           push 0x984230
// 00971946  c70534fcb8009a020000 mov dword ptr [0xb8fc34], 0x29a
// 00971950  e8d42fe8ff           call 0x7f4929
// 00971955  83c408               add esp, 8
// 00971958  c3                   ret 

// FactoryProduct<...>::creator registration: Name::declare<ClassName>() (call_once + doDeclare), getCreators()
#include <stdlib.h>

struct Name;
struct ICreator;
struct once_flag { long v; };

extern once_flag flag_b86008;
extern int global_b8fc34;
extern ICreator creator_b32ae0;

void call_once(once_flag &flag, void (*f)());
void callDoDeclare_6499d0();
const Name &doDeclare();
void destroy_984230();

struct CreatorMap
{
    const ICreator *&operator[](const Name *const &key);
    void add(const Name *const &key);
};
CreatorMap &getCreators();

void init()
{
    call_once(flag_b86008, &callDoDeclare_6499d0);
    const Name *key = &doDeclare();
    getCreators()[key] = &creator_b32ae0;
    global_b8fc34 = 0x29a;
    atexit(&destroy_984230);
}
