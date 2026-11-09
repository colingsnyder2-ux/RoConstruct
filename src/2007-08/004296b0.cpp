// from server: 100% by auto
// roc 2007-08 004296b0  unit: ThreadLogManager  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004296b0
//
// 004296b0  51                   push ecx
// 004296b1  53                   push ebx
// 004296b2  55                   push ebp
// 004296b3  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004296b7  56                   push esi
// 004296b8  8bf1                 mov esi, ecx
// 004296ba  57                   push edi
// 004296bb  8b7e04               mov edi, dword ptr [esi + 4]
// 004296be  85ff                 test edi, edi
// 004296c0  741c                 je 0x4296de
// 004296c2  8b5e08               mov ebx, dword ptr [esi + 8]
// 004296c5  8bcb                 mov ecx, ebx
// 004296c7  2bcf                 sub ecx, edi
// 004296c9  b893244992           mov eax, 0x92492493
// 004296ce  f7e9                 imul ecx
// 004296d0  03d1                 add edx, ecx
// 004296d2  c1fa04               sar edx, 4
// 004296d5  8bc2                 mov eax, edx
// 004296d7  c1e81f               shr eax, 0x1f
// 004296da  03c2                 add eax, edx
// 004296dc  7508                 jne 0x4296e6
// 004296de  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004296e2  33ff                 xor edi, edi
// 004296e4  eb33                 jmp 0x429719
// 004296e6  3bfb                 cmp edi, ebx
// 004296e8  7606                 jbe 0x4296f0
// 004296ea  ff15d8e67700         call dword ptr [0x77e6d8]
// 004296f0  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004296f4  85db                 test ebx, ebx
// 004296f6  7404                 je 0x4296fc
// 004296f8  3bde                 cmp ebx, esi
// 004296fa  7406                 je 0x429702
// 004296fc  ff15d8e67700         call dword ptr [0x77e6d8]
// 00429702  8bcd                 mov ecx, ebp
// 00429704  2bcf                 sub ecx, edi
// 00429706  b893244992           mov eax, 0x92492493
// 0042970b  f7e9                 imul ecx
// 0042970d  03d1                 add edx, ecx
// 0042970f  c1fa04               sar edx, 4
// 00429712  8bfa                 mov edi, edx
// 00429714  c1ef1f               shr edi, 0x1f
// 00429717  03fa                 add edi, edx
// 00429719  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0042971d  51                   push ecx
// 0042971e  6a01                 push 1
// 00429720  55                   push ebp
// 00429721  53                   push ebx
// 00429722  8bce                 mov ecx, esi
// 00429724  e8e7fbffff           call 0x429310
// 00429729  8b5e04               mov ebx, dword ptr [esi + 4]
// 0042972c  3b5e08               cmp ebx, dword ptr [esi + 8]
// 0042972f  7606                 jbe 0x429737
// 00429731  ff15d8e67700         call dword ptr [0x77e6d8]
// 00429737  8d14fd00000000       lea edx, [edi*8]
// 0042973e  2bd7                 sub edx, edi
// 00429740  8d3c93               lea edi, [ebx + edx*4]
// 00429743  3b7e08               cmp edi, dword ptr [esi + 8]
// 00429746  895c2420             mov dword ptr [esp + 0x20], ebx
// 0042974a  7705                 ja 0x429751
// 0042974c  3b7e04               cmp edi, dword ptr [esi + 4]
// 0042974f  7306                 jae 0x429757
// 00429751  ff15d8e67700         call dword ptr [0x77e6d8]
// 00429757  8b442418             mov eax, dword ptr [esp + 0x18]
// 0042975b  897804               mov dword ptr [eax + 4], edi
// 0042975e  5f                   pop edi
// 0042975f  8930                 mov dword ptr [eax], esi
// 00429761  5e                   pop esi
// 00429762  5d                   pop ebp
// 00429763  5b                   pop ebx
// 00429764  59                   pop ecx
// 00429765  c21000               ret 0x10
// standard library vector<string> (function ?insert@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Vector_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@V32@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
