// from server: 100% by EspClaude
// from server: 52% by colin
// roc 2007-08 004a95c0  unit: RBX::Network::VClient::?$FactoryProduct  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a95c0
//
// 004a95c0  8b442404             mov eax, dword ptr [esp + 4]
// 004a95c4  83ec08               sub esp, 8
// 004a95c7  53                   push ebx
// 004a95c8  55                   push ebp
// 004a95c9  8ba8bc000000         mov ebp, dword ptr [eax + 0xbc]
// 004a95cf  85ed                 test ebp, ebp
// 004a95d1  56                   push esi
// 004a95d2  57                   push edi
// 004a95d3  896c241c             mov dword ptr [esp + 0x1c], ebp
// 004a95d7  7440                 je 0x4a9619
// 004a95d9  8db9a81d0000         lea edi, [ecx + 0x1da8]
// 004a95df  90                   nop 
// 004a95e0  8b5f04               mov ebx, dword ptr [edi + 4]
// 004a95e3  8d4c241c             lea ecx, [esp + 0x1c]
// 004a95e7  51                   push ecx
// 004a95e8  8d542414             lea edx, [esp + 0x14]
// 004a95ec  52                   push edx
// 004a95ed  8bcf                 mov ecx, edi
// 004a95ef  e85cbf1500           call 0x605550
// 004a95f4  8bf0                 mov esi, eax
// 004a95f6  8b06                 mov eax, dword ptr [esi]
// 004a95f8  85c0                 test eax, eax
// 004a95fa  7404                 je 0x4a9600
// 004a95fc  3bc7                 cmp eax, edi
// 004a95fe  7406                 je 0x4a9606
// 004a9600  ff15d8e67700         call dword ptr [0x77e6d8]
// 004a9606  395e04               cmp dword ptr [esi + 4], ebx
// 004a9609  751a                 jne 0x4a9625
// 004a960b  8badbc000000         mov ebp, dword ptr [ebp + 0xbc]
// 004a9611  85ed                 test ebp, ebp
// 004a9613  896c241c             mov dword ptr [esp + 0x1c], ebp
// 004a9617  75c7                 jne 0x4a95e0
// 004a9619  5f                   pop edi
// 004a961a  5e                   pop esi
// 004a961b  5d                   pop ebp
// 004a961c  32c0                 xor al, al
// 004a961e  5b                   pop ebx
// 004a961f  83c408               add esp, 8
// 004a9622  c20400               ret 4
// 004a9625  5f                   pop edi
// 004a9626  5e                   pop esi
// 004a9627  5d                   pop ebp
// 004a9628  b001                 mov al, 1
// 004a962a  5b                   pop ebx
// 004a962b  83c408               add esp, 8
// 004a962e  c20400               ret 4
#include <map>

class Instance {
    char pad[0xbc];
public:
    Instance* parent;          // +0xbc (target: mov ebp, [eax + 0xbc])
};

class VClient {
    char pad[0x1da8];
    std::map<Instance*, int> products;   // +0x1da8 (target: lea edi, [ecx + 0x1da8]; _Myhead at +4)
public:
    bool hasProductAncestor(Instance* instance);
};

bool VClient::hasProductAncestor(Instance* instance)
{
    instance = instance->parent;
    while (instance) {
        if (products.find(instance) != products.end())
            return true;
        instance = instance->parent;
    }
    return false;
}
