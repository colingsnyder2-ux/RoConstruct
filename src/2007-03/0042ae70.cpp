// from server: 100% by auto
// roc 2007-03 0042ae70  unit: seg_00420000  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0042ae70
//
// 0042ae70  51                   push ecx
// 0042ae71  53                   push ebx
// 0042ae72  55                   push ebp
// 0042ae73  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0042ae77  56                   push esi
// 0042ae78  8bf1                 mov esi, ecx
// 0042ae7a  57                   push edi
// 0042ae7b  8b7e04               mov edi, dword ptr [esi + 4]
// 0042ae7e  85ff                 test edi, edi
// 0042ae80  741c                 je 0x42ae9e
// 0042ae82  8b5e08               mov ebx, dword ptr [esi + 8]
// 0042ae85  8bcb                 mov ecx, ebx
// 0042ae87  2bcf                 sub ecx, edi
// 0042ae89  b893244992           mov eax, 0x92492493
// 0042ae8e  f7e9                 imul ecx
// 0042ae90  03d1                 add edx, ecx
// 0042ae92  c1fa04               sar edx, 4
// 0042ae95  8bc2                 mov eax, edx
// 0042ae97  c1e81f               shr eax, 0x1f
// 0042ae9a  03c2                 add eax, edx
// 0042ae9c  7508                 jne 0x42aea6
// 0042ae9e  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0042aea2  33ff                 xor edi, edi
// 0042aea4  eb33                 jmp 0x42aed9
// 0042aea6  3bfb                 cmp edi, ebx
// 0042aea8  7606                 jbe 0x42aeb0
// 0042aeaa  ff1544e97700         call dword ptr [0x77e944]
// 0042aeb0  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0042aeb4  85db                 test ebx, ebx
// 0042aeb6  7404                 je 0x42aebc
// 0042aeb8  3bde                 cmp ebx, esi
// 0042aeba  7406                 je 0x42aec2
// 0042aebc  ff1544e97700         call dword ptr [0x77e944]
// 0042aec2  8bcd                 mov ecx, ebp
// 0042aec4  2bcf                 sub ecx, edi
// 0042aec6  b893244992           mov eax, 0x92492493
// 0042aecb  f7e9                 imul ecx
// 0042aecd  03d1                 add edx, ecx
// 0042aecf  c1fa04               sar edx, 4
// 0042aed2  8bfa                 mov edi, edx
// 0042aed4  c1ef1f               shr edi, 0x1f
// 0042aed7  03fa                 add edi, edx
// 0042aed9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0042aedd  51                   push ecx
// 0042aede  6a01                 push 1
// 0042aee0  55                   push ebp
// 0042aee1  53                   push ebx
// 0042aee2  8bce                 mov ecx, esi
// 0042aee4  e847fcffff           call 0x42ab30
// 0042aee9  8b5e04               mov ebx, dword ptr [esi + 4]
// 0042aeec  3b5e08               cmp ebx, dword ptr [esi + 8]
// 0042aeef  7606                 jbe 0x42aef7
// 0042aef1  ff1544e97700         call dword ptr [0x77e944]
// 0042aef7  8d14fd00000000       lea edx, [edi*8]
// 0042aefe  2bd7                 sub edx, edi
// 0042af00  8d3c93               lea edi, [ebx + edx*4]
// 0042af03  3b7e08               cmp edi, dword ptr [esi + 8]
// 0042af06  895c2420             mov dword ptr [esp + 0x20], ebx
// 0042af0a  7705                 ja 0x42af11
// 0042af0c  3b7e04               cmp edi, dword ptr [esi + 4]
// 0042af0f  7306                 jae 0x42af17
// 0042af11  ff1544e97700         call dword ptr [0x77e944]
// 0042af17  8b442418             mov eax, dword ptr [esp + 0x18]
// 0042af1b  897804               mov dword ptr [eax + 4], edi
// 0042af1e  5f                   pop edi
// 0042af1f  8930                 mov dword ptr [eax], esi
// 0042af21  5e                   pop esi
// 0042af22  5d                   pop ebp
// 0042af23  5b                   pop ebx
// 0042af24  59                   pop ecx
// 0042af25  c21000               ret 0x10
// standard library vector<string> (function ?insert@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Vector_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@V32@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
