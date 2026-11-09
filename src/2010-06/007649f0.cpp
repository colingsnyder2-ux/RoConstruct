// from server: 100% by auto
// roc 2010-06 007649f0  unit: RBX::GuiLayerCollector  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007649f0
//
// 007649f0  83ec08               sub esp, 8
// 007649f3  53                   push ebx
// 007649f4  55                   push ebp
// 007649f5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 007649fb  56                   push esi
// 007649fc  8bf1                 mov esi, ecx
// 007649fe  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00764a01  57                   push edi
// 00764a02  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00764a05  8bcb                 mov ecx, ebx
// 00764a07  2bcf                 sub ecx, edi
// 00764a09  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00764a0e  f7e9                 imul ecx
// 00764a10  c1fa02               sar edx, 2
// 00764a13  8bc2                 mov eax, edx
// 00764a15  c1e81f               shr eax, 0x1f
// 00764a18  03c2                 add eax, edx
// 00764a1a  7504                 jne 0x764a20
// 00764a1c  33ff                 xor edi, edi
// 00764a1e  eb2d                 jmp 0x764a4d
// 00764a20  3bfb                 cmp edi, ebx
// 00764a22  7602                 jbe 0x764a26
// 00764a24  ffd5                 call ebp
// 00764a26  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00764a2a  8b06                 mov eax, dword ptr [esi]
// 00764a2c  85c9                 test ecx, ecx
// 00764a2e  7404                 je 0x764a34
// 00764a30  3bc8                 cmp ecx, eax
// 00764a32  7402                 je 0x764a36
// 00764a34  ffd5                 call ebp
// 00764a36  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00764a3a  2bcf                 sub ecx, edi
// 00764a3c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00764a41  f7e9                 imul ecx
// 00764a43  c1fa02               sar edx, 2
// 00764a46  8bfa                 mov edi, edx
// 00764a48  c1ef1f               shr edi, 0x1f
// 00764a4b  03fa                 add edi, edx
// 00764a4d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00764a51  8b542424             mov edx, dword ptr [esp + 0x24]
// 00764a55  8b442420             mov eax, dword ptr [esp + 0x20]
// 00764a59  51                   push ecx
// 00764a5a  6a01                 push 1
// 00764a5c  52                   push edx
// 00764a5d  50                   push eax
// 00764a5e  8bce                 mov ecx, esi
// 00764a60  e82bfcffff           call 0x764690
// 00764a65  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00764a68  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00764a6b  7602                 jbe 0x764a6f
// 00764a6d  ffd5                 call ebp
// 00764a6f  8b36                 mov esi, dword ptr [esi]
// 00764a71  57                   push edi
// 00764a72  8d4c2414             lea ecx, [esp + 0x14]
// 00764a76  89742414             mov dword ptr [esp + 0x14], esi
// 00764a7a  895c2418             mov dword ptr [esp + 0x18], ebx
// 00764a7e  e8fdbbfcff           call 0x730680
// 00764a83  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00764a87  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00764a8b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00764a8f  5f                   pop edi
// 00764a90  5e                   pop esi
// 00764a91  5d                   pop ebp
// 00764a92  8908                 mov dword ptr [eax], ecx
// 00764a94  895004               mov dword ptr [eax + 4], edx
// 00764a97  5b                   pop ebx
// 00764a98  83c408               add esp, 8
// 00764a9b  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
