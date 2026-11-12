// from server: 100% by EspClaude
// from server: 48% by colin
// roc 2007-08 00499230  unit: RBX::VNetworkSettings::?$FactoryProduct::Creator  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00499230
//
// 00499230  6aff                 push -1
// 00499232  680e8a7400           push 0x748a0e
// 00499237  64a100000000         mov eax, dword ptr fs:[0]
// 0049923d  50                   push eax
// 0049923e  a188518b00           mov eax, dword ptr [0x8b5188]
// 00499243  33c4                 xor eax, esp
// 00499245  50                   push eax
// 00499246  8d442404             lea eax, [esp + 4]
// 0049924a  64a300000000         mov dword ptr fs:[0], eax
// 00499250  b801000000           mov eax, 1
// 00499255  8405a8e48b00         test byte ptr [0x8be4a8], al
// 0049925b  7530                 jne 0x49928d
// 0049925d  0905a8e48b00         or dword ptr [0x8be4a8], eax
// 00499263  680c028900           push 0x89020c
// 00499268  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00499270  e80bfeffff           call 0x499080
// 00499275  50                   push eax
// 00499276  b920e48b00           mov ecx, 0x8be420
// 0049927b  e880790d00           call 0x570c00
// 00499280  68a0867700           push 0x7786a0
// 00499285  e8997a1900           call 0x630d23
// 0049928a  83c404               add esp, 4
// 0049928d  b820e48b00           mov eax, 0x8be420
// 00499292  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00499296  64890d00000000       mov dword ptr fs:[0], ecx
// 0049929d  59                   pop ecx
// 0049929e  83c40c               add esp, 0xc
// 004992a1  c3                   ret 

namespace RBX { namespace Reflection {
class ClassDescriptor {
public:
    ClassDescriptor(ClassDescriptor& base, const char* name);
    ~ClassDescriptor();
};
} }

RBX::Reflection::ClassDescriptor& baseClassDescriptor();

RBX::Reflection::ClassDescriptor& networkSettingsClassDescriptor()
{
    static RBX::Reflection::ClassDescriptor desc(baseClassDescriptor(), "NetworkServer");
    return desc;
}
