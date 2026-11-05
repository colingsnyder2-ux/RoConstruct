// from server: 100% by auto
// roc 2010-06 00446d40  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 250 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00446d40
//
// 00446d40  6aff                 push -1
// 00446d42  68a97e9900           push 0x997ea9
// 00446d47  64a100000000         mov eax, dword ptr fs:[0]
// 00446d4d  50                   push eax
// 00446d4e  64892500000000       mov dword ptr fs:[0], esp
// 00446d55  83ec10               sub esp, 0x10
// 00446d58  53                   push ebx
// 00446d59  55                   push ebp
// 00446d5a  56                   push esi
// 00446d5b  57                   push edi
// 00446d5c  8bf1                 mov esi, ecx
// 00446d5e  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00446d61  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 00446d64  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00446d68  8bcb                 mov ecx, ebx
// 00446d6a  2bcd                 sub ecx, ebp
// 00446d6c  b893244992           mov eax, 0x92492493
// 00446d71  f7e9                 imul ecx
// 00446d73  03d1                 add edx, ecx
// 00446d75  c1fa04               sar edx, 4
// 00446d78  8bc2                 mov eax, edx
// 00446d7a  c1e81f               shr eax, 0x1f
// 00446d7d  03c2                 add eax, edx
// 00446d7f  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00446d87  3bf8                 cmp edi, eax
// 00446d89  7638                 jbe 0x446dc3
// 00446d8b  3beb                 cmp ebp, ebx
// 00446d8d  7606                 jbe 0x446d95
// 00446d8f  ff150ca99e00         call dword ptr [0x9ea90c]
// 00446d95  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00446d98  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 00446d9b  8b2e                 mov ebp, dword ptr [esi]
// 00446d9d  8d442434             lea eax, [esp + 0x34]
// 00446da1  50                   push eax
// 00446da2  b893244992           mov eax, 0x92492493
// 00446da7  f7e9                 imul ecx
// 00446da9  03d1                 add edx, ecx
// 00446dab  c1fa04               sar edx, 4
// 00446dae  8bca                 mov ecx, edx
// 00446db0  c1e91f               shr ecx, 0x1f
// 00446db3  03ca                 add ecx, edx
// 00446db5  2bf9                 sub edi, ecx
// 00446db7  57                   push edi
// 00446db8  53                   push ebx
// 00446db9  55                   push ebp
// 00446dba  8bce                 mov ecx, esi
// 00446dbc  e89fe8fdff           call 0x425660
// 00446dc1  eb50                 jmp 0x446e13
// 00446dc3  734e                 jae 0x446e13
// 00446dc5  3beb                 cmp ebp, ebx
// 00446dc7  7606                 jbe 0x446dcf
// 00446dc9  ff150ca99e00         call dword ptr [0x9ea90c]
// 00446dcf  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 00446dd2  8b16                 mov edx, dword ptr [esi]
// 00446dd4  89542418             mov dword ptr [esp + 0x18], edx
// 00446dd8  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 00446ddb  7606                 jbe 0x446de3
// 00446ddd  ff150ca99e00         call dword ptr [0x9ea90c]
// 00446de3  8b06                 mov eax, dword ptr [esi]
// 00446de5  57                   push edi
// 00446de6  8d4c2414             lea ecx, [esp + 0x14]
// 00446dea  89442414             mov dword ptr [esp + 0x14], eax
// 00446dee  896c2418             mov dword ptr [esp + 0x18], ebp
// 00446df2  e879d0fdff           call 0x423e70
// 00446df7  8b442418             mov eax, dword ptr [esp + 0x18]
// 00446dfb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00446dff  8b542410             mov edx, dword ptr [esp + 0x10]
// 00446e03  53                   push ebx
// 00446e04  50                   push eax
// 00446e05  51                   push ecx
// 00446e06  52                   push edx
// 00446e07  8d442428             lea eax, [esp + 0x28]
// 00446e0b  50                   push eax
// 00446e0c  8bce                 mov ecx, esi
// 00446e0e  e8edf7ffff           call 0x446600
// 00446e13  8d4c2434             lea ecx, [esp + 0x34]
// 00446e17  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00446e1f  ff1500a49e00         call dword ptr [0x9ea400]
// 00446e25  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00446e29  5f                   pop edi
// 00446e2a  5e                   pop esi
// 00446e2b  5d                   pop ebp
// 00446e2c  5b                   pop ebx
// 00446e2d  64890d00000000       mov dword ptr fs:[0], ecx
// 00446e34  83c41c               add esp, 0x1c
// 00446e37  c22000               ret 0x20
// standard library vector<string> (function ?resize@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
