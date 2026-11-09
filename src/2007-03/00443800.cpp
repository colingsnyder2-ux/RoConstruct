// from server: 100% by auto
// roc 2007-03 00443800  unit: seg_00440000  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00443800
//
// 00443800  51                   push ecx
// 00443801  53                   push ebx
// 00443802  55                   push ebp
// 00443803  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00443807  56                   push esi
// 00443808  8bf1                 mov esi, ecx
// 0044380a  57                   push edi
// 0044380b  8b7e04               mov edi, dword ptr [esi + 4]
// 0044380e  85ff                 test edi, edi
// 00443810  7419                 je 0x44382b
// 00443812  8b5e08               mov ebx, dword ptr [esi + 8]
// 00443815  8bcb                 mov ecx, ebx
// 00443817  2bcf                 sub ecx, edi
// 00443819  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044381e  f7e9                 imul ecx
// 00443820  d1fa                 sar edx, 1
// 00443822  8bc2                 mov eax, edx
// 00443824  c1e81f               shr eax, 0x1f
// 00443827  03c2                 add eax, edx
// 00443829  7508                 jne 0x443833
// 0044382b  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0044382f  33ff                 xor edi, edi
// 00443831  eb30                 jmp 0x443863
// 00443833  3bfb                 cmp edi, ebx
// 00443835  7606                 jbe 0x44383d
// 00443837  ff1544e97700         call dword ptr [0x77e944]
// 0044383d  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00443841  85db                 test ebx, ebx
// 00443843  7404                 je 0x443849
// 00443845  3bde                 cmp ebx, esi
// 00443847  7406                 je 0x44384f
// 00443849  ff1544e97700         call dword ptr [0x77e944]
// 0044384f  8bcd                 mov ecx, ebp
// 00443851  2bcf                 sub ecx, edi
// 00443853  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00443858  f7e9                 imul ecx
// 0044385a  d1fa                 sar edx, 1
// 0044385c  8bfa                 mov edi, edx
// 0044385e  c1ef1f               shr edi, 0x1f
// 00443861  03fa                 add edi, edx
// 00443863  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00443867  51                   push ecx
// 00443868  6a01                 push 1
// 0044386a  55                   push ebp
// 0044386b  53                   push ebx
// 0044386c  8bce                 mov ecx, esi
// 0044386e  e81dfbffff           call 0x443390
// 00443873  8b5e04               mov ebx, dword ptr [esi + 4]
// 00443876  3b5e08               cmp ebx, dword ptr [esi + 8]
// 00443879  7606                 jbe 0x443881
// 0044387b  ff1544e97700         call dword ptr [0x77e944]
// 00443881  8d147f               lea edx, [edi + edi*2]
// 00443884  8d3c93               lea edi, [ebx + edx*4]
// 00443887  3b7e08               cmp edi, dword ptr [esi + 8]
// 0044388a  895c2420             mov dword ptr [esp + 0x20], ebx
// 0044388e  7705                 ja 0x443895
// 00443890  3b7e04               cmp edi, dword ptr [esi + 4]
// 00443893  7306                 jae 0x44389b
// 00443895  ff1544e97700         call dword ptr [0x77e944]
// 0044389b  8b442418             mov eax, dword ptr [esp + 0x18]
// 0044389f  897804               mov dword ptr [eax + 4], edi
// 004438a2  5f                   pop edi
// 004438a3  8930                 mov dword ptr [eax], esi
// 004438a5  5e                   pop esi
// 004438a6  5d                   pop ebp
// 004438a7  5b                   pop ebx
// 004438a8  59                   pop ecx
// 004438a9  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V32@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
