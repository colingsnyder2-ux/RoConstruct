// from server: 100% by Xemicl
// roc 2012-06 006d3540  unit: boost::io::Vbad_format_string::?$error_info_injector  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006d3540
//
// 006d3540  6aff                 push -1
// 006d3542  6888afab00           push 0xabaf88
// 006d3547  64a100000000         mov eax, dword ptr fs:[0]
// 006d354d  50                   push eax
// 006d354e  64892500000000       mov dword ptr fs:[0], esp
// 006d3555  51                   push ecx
// 006d3556  56                   push esi
// 006d3557  8bf1                 mov esi, ecx
// 006d3559  83ec1c               sub esp, 0x1c
// 006d355c  8d44243c             lea eax, [esp + 0x3c]
// 006d3560  89642420             mov dword ptr [esp + 0x20], esp
// 006d3564  8bcc                 mov ecx, esp
// 006d3566  50                   push eax
// 006d3567  c744243000000000     mov dword ptr [esp + 0x30], 0
// 006d356f  ff154426b200         call dword ptr [0xb22644]
// 006d3575  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 006d3579  8b542434             mov edx, dword ptr [esp + 0x34]
// 006d357d  51                   push ecx
// 006d357e  52                   push edx
// 006d357f  8bce                 mov ecx, esi
// 006d3581  e81ae7ffff           call 0x6d1ca0
// 006d3586  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 006d358a  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 006d358e  894e24               mov dword ptr [esi + 0x24], ecx
// 006d3591  8d4c2420             lea ecx, [esp + 0x20]
// 006d3595  894620               mov dword ptr [esi + 0x20], eax
// 006d3598  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006d35a0  ff153c26b200         call dword ptr [0xb2263c]
// 006d35a6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006d35aa  8bc6                 mov eax, esi
// 006d35ac  64890d00000000       mov dword ptr fs:[0], ecx
// 006d35b3  5e                   pop esi
// 006d35b4  83c410               add esp, 0x10
// 006d35b7  c22c00               ret 0x2c
// copied from an identical function in another client (function ??0Derived@RBX@@QAE@HUArg1@1@UStrValue@1@HH@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
struct StrValue { std::string t; };
struct Arg1 {};
class Base {
public:
    Base(int a, Arg1 b, StrValue name);
protected:
    int a;
    StrValue name;
};
class Derived : public Base {
public:
    Derived(int a, Arg1 b, StrValue name, int c, int d);
private:
    int c;
    int d;
};
Derived::Derived(int a, Arg1 b, StrValue name, int c, int d)
    : Base(a, b, name), c(c), d(d)
{
}
}