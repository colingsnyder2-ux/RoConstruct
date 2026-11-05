// from server: 100% by auto
// roc 2008-06 004449f0  unit: 1RBX::Metadata::VReflection::?$FactoryProduct  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004449f0
//
// 004449f0  83ec08               sub esp, 8
// 004449f3  56                   push esi
// 004449f4  8bf1                 mov esi, ecx
// 004449f6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004449f9  57                   push edi
// 004449fa  85c9                 test ecx, ecx
// 004449fc  7504                 jne 0x444a02
// 004449fe  33c0                 xor eax, eax
// 00444a00  eb08                 jmp 0x444a0a
// 00444a02  8b4614               mov eax, dword ptr [esi + 0x14]
// 00444a05  2bc1                 sub eax, ecx
// 00444a07  c1f804               sar eax, 4
// 00444a0a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00444a0d  8bd7                 mov edx, edi
// 00444a0f  2bd1                 sub edx, ecx
// 00444a11  c1fa04               sar edx, 4
// 00444a14  3bd0                 cmp edx, eax
// 00444a16  7331                 jae 0x444a49
// 00444a18  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00444a1c  c644240800           mov byte ptr [esp + 8], 0
// 00444a21  8b442408             mov eax, dword ptr [esp + 8]
// 00444a25  50                   push eax
// 00444a26  8b442418             mov eax, dword ptr [esp + 0x18]
// 00444a2a  51                   push ecx
// 00444a2b  8d5608               lea edx, [esi + 8]
// 00444a2e  52                   push edx
// 00444a2f  50                   push eax
// 00444a30  6a01                 push 1
// 00444a32  57                   push edi
// 00444a33  e818f6ffff           call 0x444050
// 00444a38  83c418               add esp, 0x18
// 00444a3b  83c710               add edi, 0x10
// 00444a3e  897e10               mov dword ptr [esi + 0x10], edi
// 00444a41  5f                   pop edi
// 00444a42  5e                   pop esi
// 00444a43  83c408               add esp, 8
// 00444a46  c20400               ret 4
// 00444a49  3bcf                 cmp ecx, edi
// 00444a4b  7606                 jbe 0x444a53
// 00444a4d  ff1590288000         call dword ptr [0x802890]
// 00444a53  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00444a57  8b06                 mov eax, dword ptr [esi]
// 00444a59  51                   push ecx
// 00444a5a  57                   push edi
// 00444a5b  50                   push eax
// 00444a5c  8d542414             lea edx, [esp + 0x14]
// 00444a60  52                   push edx
// 00444a61  8bce                 mov ecx, esi
// 00444a63  e858fbffff           call 0x4445c0
// 00444a68  5f                   pop edi
// 00444a69  5e                   pop esi
// 00444a6a  83c408               add esp, 8
// 00444a6d  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
