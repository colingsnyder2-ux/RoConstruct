// from server: 100% by auto
// roc 2009-06 00440cd0  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 250 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00440cd0
//
// 00440cd0  6aff                 push -1
// 00440cd2  68f9788600           push 0x8678f9
// 00440cd7  64a100000000         mov eax, dword ptr fs:[0]
// 00440cdd  50                   push eax
// 00440cde  64892500000000       mov dword ptr fs:[0], esp
// 00440ce5  83ec10               sub esp, 0x10
// 00440ce8  53                   push ebx
// 00440ce9  55                   push ebp
// 00440cea  56                   push esi
// 00440ceb  57                   push edi
// 00440cec  8bf1                 mov esi, ecx
// 00440cee  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00440cf1  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 00440cf4  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00440cf8  8bcb                 mov ecx, ebx
// 00440cfa  2bcd                 sub ecx, ebp
// 00440cfc  b893244992           mov eax, 0x92492493
// 00440d01  f7e9                 imul ecx
// 00440d03  03d1                 add edx, ecx
// 00440d05  c1fa04               sar edx, 4
// 00440d08  8bc2                 mov eax, edx
// 00440d0a  c1e81f               shr eax, 0x1f
// 00440d0d  03c2                 add eax, edx
// 00440d0f  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00440d17  3bf8                 cmp edi, eax
// 00440d19  7638                 jbe 0x440d53
// 00440d1b  3beb                 cmp ebp, ebx
// 00440d1d  7606                 jbe 0x440d25
// 00440d1f  ff15ace98900         call dword ptr [0x89e9ac]
// 00440d25  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00440d28  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 00440d2b  8b2e                 mov ebp, dword ptr [esi]
// 00440d2d  8d442434             lea eax, [esp + 0x34]
// 00440d31  50                   push eax
// 00440d32  b893244992           mov eax, 0x92492493
// 00440d37  f7e9                 imul ecx
// 00440d39  03d1                 add edx, ecx
// 00440d3b  c1fa04               sar edx, 4
// 00440d3e  8bca                 mov ecx, edx
// 00440d40  c1e91f               shr ecx, 0x1f
// 00440d43  03ca                 add ecx, edx
// 00440d45  2bf9                 sub edi, ecx
// 00440d47  57                   push edi
// 00440d48  53                   push ebx
// 00440d49  55                   push ebp
// 00440d4a  8bce                 mov ecx, esi
// 00440d4c  e80f39feff           call 0x424660
// 00440d51  eb50                 jmp 0x440da3
// 00440d53  734e                 jae 0x440da3
// 00440d55  3beb                 cmp ebp, ebx
// 00440d57  7606                 jbe 0x440d5f
// 00440d59  ff15ace98900         call dword ptr [0x89e9ac]
// 00440d5f  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 00440d62  8b16                 mov edx, dword ptr [esi]
// 00440d64  89542418             mov dword ptr [esp + 0x18], edx
// 00440d68  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 00440d6b  7606                 jbe 0x440d73
// 00440d6d  ff15ace98900         call dword ptr [0x89e9ac]
// 00440d73  8b06                 mov eax, dword ptr [esi]
// 00440d75  57                   push edi
// 00440d76  8d4c2414             lea ecx, [esp + 0x14]
// 00440d7a  89442414             mov dword ptr [esp + 0x14], eax
// 00440d7e  896c2418             mov dword ptr [esp + 0x18], ebp
// 00440d82  e8594f2900           call 0x6d5ce0
// 00440d87  8b442418             mov eax, dword ptr [esp + 0x18]
// 00440d8b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00440d8f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00440d93  53                   push ebx
// 00440d94  50                   push eax
// 00440d95  51                   push ecx
// 00440d96  52                   push edx
// 00440d97  8d442428             lea eax, [esp + 0x28]
// 00440d9b  50                   push eax
// 00440d9c  8bce                 mov ecx, esi
// 00440d9e  e87dfdffff           call 0x440b20
// 00440da3  8d4c2434             lea ecx, [esp + 0x34]
// 00440da7  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00440daf  ff15c4e48900         call dword ptr [0x89e4c4]
// 00440db5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00440db9  5f                   pop edi
// 00440dba  5e                   pop esi
// 00440dbb  5d                   pop ebp
// 00440dbc  5b                   pop ebx
// 00440dbd  64890d00000000       mov dword ptr fs:[0], ecx
// 00440dc4  83c41c               add esp, 0x1c
// 00440dc7  c22000               ret 0x20
// standard library vector<string> (function ?resize@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
