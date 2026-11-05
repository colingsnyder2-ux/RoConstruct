// from server: 100% by EspClaude
// from server: 82% by EspClaude
// roc 2009-06 005af0c0  unit: RBX::Mesh  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005af0c0
//
// 005af0c0  55                   push ebp
// 005af0c1  8bec                 mov ebp, esp
// 005af0c3  6aff                 push -1
// 005af0c5  687b108600           push 0x86107b
// 005af0ca  64a100000000         mov eax, dword ptr fs:[0]
// 005af0d0  50                   push eax
// 005af0d1  64892500000000       mov dword ptr fs:[0], esp
// 005af0d8  83ec28               sub esp, 0x28
// 005af0db  833d6ccb9f0000       cmp dword ptr [0x9fcb6c], 0
// 005af0e2  754f                 jne 0x5af133
// 005af0e4  6a68                 push 0x68
// 005af0e6  e84d991600           call 0x718a38
// 005af0eb  83c404               add esp, 4
// 005af0ee  8945ec               mov dword ptr [ebp - 0x14], eax
// 005af0f1  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005af0f8  837dec00             cmp dword ptr [ebp - 0x14], 0
// 005af0fc  741a                 je 0x5af118
// 005af0fe  0fb64510             movzx eax, byte ptr [ebp + 0x10]
// 005af102  50                   push eax
// 005af103  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005af106  51                   push ecx
// 005af107  8b5508               mov edx, dword ptr [ebp + 8]
// 005af10a  52                   push edx
// 005af10b  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 005af10e  e89d040000           call 0x5af5b0
// 005af113  8945d0               mov dword ptr [ebp - 0x30], eax
// 005af116  eb07                 jmp 0x5af11f
// 005af118  c745d000000000       mov dword ptr [ebp - 0x30], 0
// 005af11f  8b45d0               mov eax, dword ptr [ebp - 0x30]
// 005af122  8945f0               mov dword ptr [ebp - 0x10], eax
// 005af125  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 005af12c  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 005af12f  eb7c                 jmp 0x5af1ad
// 005af131  eb7a                 jmp 0x5af1ad
// 005af133  833d6ccb9f0001       cmp dword ptr [0x9fcb6c], 1
// 005af13a  754f                 jne 0x5af18b
// 005af13c  6a54                 push 0x54
// 005af13e  e8f5981600           call 0x718a38
// 005af143  83c404               add esp, 4
// 005af146  8945e4               mov dword ptr [ebp - 0x1c], eax
// 005af149  c745fc01000000       mov dword ptr [ebp - 4], 1
// 005af150  837de400             cmp dword ptr [ebp - 0x1c], 0
// 005af154  741a                 je 0x5af170
// 005af156  0fb64d10             movzx ecx, byte ptr [ebp + 0x10]
// 005af15a  51                   push ecx
// 005af15b  8b550c               mov edx, dword ptr [ebp + 0xc]
// 005af15e  52                   push edx
// 005af15f  8b4508               mov eax, dword ptr [ebp + 8]
// 005af162  50                   push eax
// 005af163  8b4de4               mov ecx, dword ptr [ebp - 0x1c]
// 005af166  e855010000           call 0x5af2c0
// 005af16b  8945cc               mov dword ptr [ebp - 0x34], eax
// 005af16e  eb07                 jmp 0x5af177
// 005af170  c745cc00000000       mov dword ptr [ebp - 0x34], 0
// 005af177  8b4dcc               mov ecx, dword ptr [ebp - 0x34]
// 005af17a  894de8               mov dword ptr [ebp - 0x18], ecx
// 005af17d  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 005af184  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 005af187  eb24                 jmp 0x5af1ad
// 005af189  eb22                 jmp 0x5af1ad
// 005af18b  c745d4503e8d00       mov dword ptr [ebp - 0x2c], 0x8d3e50
// 005af192  8d55d4               lea edx, [ebp - 0x2c]
// 005af195  52                   push edx
// 005af196  8d4dd8               lea ecx, [ebp - 0x28]
// 005af199  ff15c4e98900         call dword ptr [0x89e9c4]
// 005af19f  683c1b9800           push 0x981b3c
// 005af1a4  8d45d8               lea eax, [ebp - 0x28]
// 005af1a7  50                   push eax
// 005af1a8  e89da81600           call 0x719a4a
// 005af1ad  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005af1b0  64890d00000000       mov dword ptr fs:[0], ecx
// 005af1b7  8be5                 mov esp, ebp
// 005af1b9  5d                   pop ebp
// 005af1ba  c3                   ret 

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
// Factory analog for 00551920: selector 00942ec4 picks a 0x60-byte object
// (ctor 00551e30) or a 0x54-byte object (ctor 00551b30); otherwise throws.
#include <string>
#include <exception>

class ProxyBase {
public:
    virtual ~ProxyBase();
};

class ProxyA : public ProxyBase { public: ProxyA(int owner, const std::string& name, bool flag); char data[0x64]; };
class ProxyB : public ProxyBase { public: ProxyB(int owner, const std::string& name, bool flag); char data[0x50]; };

extern int materialFactoryType;

ProxyBase* createProxy(int owner, const std::string& name, bool flag)
{
    if (materialFactoryType == 0)
        return new ProxyA(owner, name, flag);
    else if (materialFactoryType == 1)
        return new ProxyB(owner, name, flag);
    else
        throw std::exception("Invalid factory type");
}
