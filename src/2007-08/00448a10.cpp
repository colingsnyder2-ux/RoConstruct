// from server: 100% by EspClaude
// from server: 50% by colin
// roc 2007-08 00448a10  unit: CRbxDocTemplate  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00448a10
//
// 00448a10  6aff                 push -1
// 00448a12  6879fb7300           push 0x73fb79
// 00448a17  64a100000000         mov eax, dword ptr fs:[0]
// 00448a1d  50                   push eax
// 00448a1e  51                   push ecx
// 00448a1f  56                   push esi
// 00448a20  a188518b00           mov eax, dword ptr [0x8b5188]
// 00448a25  33c4                 xor eax, esp
// 00448a27  50                   push eax
// 00448a28  8d44240c             lea eax, [esp + 0xc]
// 00448a2c  64a300000000         mov dword ptr fs:[0], eax
// 00448a32  8bf1                 mov esi, ecx
// 00448a34  83ec1c               sub esp, 0x1c
// 00448a37  8d442438             lea eax, [esp + 0x38]
// 00448a3b  8bcc                 mov ecx, esp
// 00448a3d  89642424             mov dword ptr [esp + 0x24], esp
// 00448a41  50                   push eax
// 00448a42  c744243400000000     mov dword ptr [esp + 0x34], 0
// 00448a4a  ff159ce67700         call dword ptr [0x77e69c]
// 00448a50  8bce                 mov ecx, esi
// 00448a52  e859fdffff           call 0x4487b0
// 00448a57  33c9                 xor ecx, ecx
// 00448a59  85c0                 test eax, eax
// 00448a5b  0f94c1               sete cl
// 00448a5e  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00448a66  8bf1                 mov esi, ecx
// 00448a68  8d4c241c             lea ecx, [esp + 0x1c]
// 00448a6c  ff15ace67700         call dword ptr [0x77e6ac]
// 00448a72  8bc6                 mov eax, esi
// 00448a74  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00448a78  64890d00000000       mov dword ptr fs:[0], ecx
// 00448a7f  59                   pop ecx

#include <string>

class CRbxDocTemplate {
public:
    void* sub_4487B0(std::string name);
    int func(std::string name);
};

int CRbxDocTemplate::func(std::string name)
{
    return sub_4487B0(name) == 0;
}
