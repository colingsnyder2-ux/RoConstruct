// from server: 100% by auto
// roc 2008-06 00429870  unit: ThreadLogManager  size: 178 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00429870
//
// 00429870  83ec08               sub esp, 8
// 00429873  53                   push ebx
// 00429874  55                   push ebp
// 00429875  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0042987b  56                   push esi
// 0042987c  8bf1                 mov esi, ecx
// 0042987e  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00429881  57                   push edi
// 00429882  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00429885  8bcb                 mov ecx, ebx
// 00429887  2bcf                 sub ecx, edi
// 00429889  b893244992           mov eax, 0x92492493
// 0042988e  f7e9                 imul ecx
// 00429890  03d1                 add edx, ecx
// 00429892  c1fa04               sar edx, 4
// 00429895  8bc2                 mov eax, edx
// 00429897  c1e81f               shr eax, 0x1f
// 0042989a  03c2                 add eax, edx
// 0042989c  7504                 jne 0x4298a2
// 0042989e  33ff                 xor edi, edi
// 004298a0  eb2f                 jmp 0x4298d1
// 004298a2  3bfb                 cmp edi, ebx
// 004298a4  7602                 jbe 0x4298a8
// 004298a6  ffd5                 call ebp
// 004298a8  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004298ac  8b06                 mov eax, dword ptr [esi]
// 004298ae  85c9                 test ecx, ecx
// 004298b0  7404                 je 0x4298b6
// 004298b2  3bc8                 cmp ecx, eax
// 004298b4  7402                 je 0x4298b8
// 004298b6  ffd5                 call ebp
// 004298b8  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004298bc  2bcf                 sub ecx, edi
// 004298be  b893244992           mov eax, 0x92492493
// 004298c3  f7e9                 imul ecx
// 004298c5  03d1                 add edx, ecx
// 004298c7  c1fa04               sar edx, 4
// 004298ca  8bfa                 mov edi, edx
// 004298cc  c1ef1f               shr edi, 0x1f
// 004298cf  03fa                 add edi, edx
// 004298d1  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004298d5  8b542424             mov edx, dword ptr [esp + 0x24]
// 004298d9  8b442420             mov eax, dword ptr [esp + 0x20]
// 004298dd  51                   push ecx
// 004298de  6a01                 push 1
// 004298e0  52                   push edx
// 004298e1  50                   push eax
// 004298e2  8bce                 mov ecx, esi
// 004298e4  e897fbffff           call 0x429480
// 004298e9  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004298ec  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 004298ef  7602                 jbe 0x4298f3
// 004298f1  ffd5                 call ebp
// 004298f3  8b36                 mov esi, dword ptr [esi]
// 004298f5  57                   push edi
// 004298f6  8d4c2414             lea ecx, [esp + 0x14]
// 004298fa  89742414             mov dword ptr [esp + 0x14], esi
// 004298fe  895c2418             mov dword ptr [esp + 0x18], ebx
// 00429902  e849e5ffff           call 0x427e50
// 00429907  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0042990b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042990f  8b542414             mov edx, dword ptr [esp + 0x14]
// 00429913  5f                   pop edi
// 00429914  5e                   pop esi
// 00429915  5d                   pop ebp
// 00429916  8908                 mov dword ptr [eax], ecx
// 00429918  895004               mov dword ptr [eax + 4], edx
// 0042991b  5b                   pop ebx
// 0042991c  83c408               add esp, 8
// 0042991f  c21000               ret 0x10
// standard library vector<string> (function ?insert@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Vector_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@V?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
