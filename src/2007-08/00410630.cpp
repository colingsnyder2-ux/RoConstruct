// from server: 100% by auto
// roc 2007-08 00410630  unit: CopyVerb  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00410630
//
// 00410630  51                   push ecx
// 00410631  53                   push ebx
// 00410632  55                   push ebp
// 00410633  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00410637  56                   push esi
// 00410638  8bf1                 mov esi, ecx
// 0041063a  57                   push edi
// 0041063b  8b7e04               mov edi, dword ptr [esi + 4]
// 0041063e  85ff                 test edi, edi
// 00410640  741a                 je 0x41065c
// 00410642  8b5e08               mov ebx, dword ptr [esi + 8]
// 00410645  8bcb                 mov ecx, ebx
// 00410647  2bcf                 sub ecx, edi
// 00410649  b8398ee338           mov eax, 0x38e38e39
// 0041064e  f7e9                 imul ecx
// 00410650  c1fa03               sar edx, 3
// 00410653  8bc2                 mov eax, edx
// 00410655  c1e81f               shr eax, 0x1f
// 00410658  03c2                 add eax, edx
// 0041065a  7508                 jne 0x410664
// 0041065c  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00410660  33ff                 xor edi, edi
// 00410662  eb31                 jmp 0x410695
// 00410664  3bfb                 cmp edi, ebx
// 00410666  7606                 jbe 0x41066e
// 00410668  ff15d8e67700         call dword ptr [0x77e6d8]
// 0041066e  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00410672  85db                 test ebx, ebx
// 00410674  7404                 je 0x41067a
// 00410676  3bde                 cmp ebx, esi
// 00410678  7406                 je 0x410680
// 0041067a  ff15d8e67700         call dword ptr [0x77e6d8]
// 00410680  8bcd                 mov ecx, ebp
// 00410682  2bcf                 sub ecx, edi
// 00410684  b8398ee338           mov eax, 0x38e38e39
// 00410689  f7e9                 imul ecx
// 0041068b  c1fa03               sar edx, 3
// 0041068e  8bfa                 mov edi, edx
// 00410690  c1ef1f               shr edi, 0x1f
// 00410693  03fa                 add edi, edx
// 00410695  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00410699  51                   push ecx
// 0041069a  6a01                 push 1
// 0041069c  55                   push ebp
// 0041069d  53                   push ebx
// 0041069e  8bce                 mov ecx, esi
// 004106a0  e87bfcffff           call 0x410320
// 004106a5  8b5e04               mov ebx, dword ptr [esi + 4]
// 004106a8  3b5e08               cmp ebx, dword ptr [esi + 8]
// 004106ab  7606                 jbe 0x4106b3
// 004106ad  ff15d8e67700         call dword ptr [0x77e6d8]
// 004106b3  8d14ff               lea edx, [edi + edi*8]
// 004106b6  8d3c93               lea edi, [ebx + edx*4]
// 004106b9  3b7e08               cmp edi, dword ptr [esi + 8]
// 004106bc  895c2420             mov dword ptr [esp + 0x20], ebx
// 004106c0  7705                 ja 0x4106c7
// 004106c2  3b7e04               cmp edi, dword ptr [esi + 4]
// 004106c5  7306                 jae 0x4106cd
// 004106c7  ff15d8e67700         call dword ptr [0x77e6d8]
// 004106cd  8b442418             mov eax, dword ptr [esp + 0x18]
// 004106d1  897804               mov dword ptr [eax + 4], edi
// 004106d4  5f                   pop edi
// 004106d5  8930                 mov dword ptr [eax], esi
// 004106d7  5e                   pop esi
// 004106d8  5d                   pop ebp
// 004106d9  5b                   pop ebx
// 004106da  59                   pop ecx
// 004106db  c21000               ret 0x10
// standard library vector<pod36> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V32@ABUE@@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
