// from server: 100% by colin
// from server: 69% by colin
// roc 2008-06 0063aca0  unit: RBX::N$1?sDoubleValue::V?$Value::?$SignalDesc  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063aca0
//
// 0063aca0  51                   push ecx
// 0063aca1  56                   push esi
// 0063aca2  85c9                 test ecx, ecx
// 0063aca4  7405                 je 0x63acab
// 0063aca6  8d7114               lea esi, [ecx + 0x14]
// 0063aca9  eb02                 jmp 0x63acad
// 0063acab  33f6                 xor esi, esi
// 0063acad  83ec1c               sub esp, 0x1c
// 0063acb0  8d8130010000         lea eax, [ecx + 0x130]
// 0063acb6  8bcc                 mov ecx, esp
// 0063acb8  89642420             mov dword ptr [esp + 0x20], esp
// 0063acbc  50                   push eax
// 0063acbd  ff155c248000         call dword ptr [0x80245c]
// 0063acc3  56                   push esi
// 0063acc4  b928d49700           mov ecx, 0x97d428
// 0063acc9  e88221dfff           call 0x42ce50
// 0063acce  5e                   pop esi
// 0063accf  59                   pop ecx
// 0063acd0  c20400               ret 4
#include <string>
struct Head { char padding[0x14]; };
struct Item { int value; };
struct Registry { int add(Item* item, std::string name); };
extern Registry registry;
struct S : Head, Item {
    char padding[0x130 - 0x18];
    std::string name;
    int f(std::string* arg);
};
int S::f(std::string*)
{
    return registry.add(this, name);
}
