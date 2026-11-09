// from server: 100% by auto
// roc 2007-03 006089a0  unit: seg_00600000  size: 386 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006089a0
//
// 006089a0  55                   push ebp
// 006089a1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 006089a5  56                   push esi
// 006089a6  8bf1                 mov esi, ecx
// 006089a8  3bf5                 cmp esi, ebp
// 006089aa  0f846b010000         je 0x608b1b
// 006089b0  8b4504               mov eax, dword ptr [ebp + 4]
// 006089b3  85c0                 test eax, eax
// 006089b5  741a                 je 0x6089d1
// 006089b7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 006089ba  2bc8                 sub ecx, eax
// 006089bc  b893244992           mov eax, 0x92492493
// 006089c1  f7e9                 imul ecx
// 006089c3  03d1                 add edx, ecx
// 006089c5  c1fa04               sar edx, 4
// 006089c8  8bca                 mov ecx, edx
// 006089ca  c1e91f               shr ecx, 0x1f
// 006089cd  03ca                 add ecx, edx
// 006089cf  750e                 jne 0x6089df
// 006089d1  8bce                 mov ecx, esi
// 006089d3  e878ffffff           call 0x608950
// 006089d8  8bc6                 mov eax, esi
// 006089da  5e                   pop esi
// 006089db  5d                   pop ebp
// 006089dc  c20400               ret 4
// 006089df  53                   push ebx
// 006089e0  57                   push edi
// 006089e1  8b7e04               mov edi, dword ptr [esi + 4]
// 006089e4  85ff                 test edi, edi
// 006089e6  7504                 jne 0x6089ec
// 006089e8  33c0                 xor eax, eax
// 006089ea  eb18                 jmp 0x608a04
// 006089ec  8b5e08               mov ebx, dword ptr [esi + 8]
// 006089ef  2bdf                 sub ebx, edi
// 006089f1  b893244992           mov eax, 0x92492493
// 006089f6  f7eb                 imul ebx
// 006089f8  03d3                 add edx, ebx
// 006089fa  c1fa04               sar edx, 4
// 006089fd  8bc2                 mov eax, edx
// 006089ff  c1e81f               shr eax, 0x1f
// 00608a02  03c2                 add eax, edx
// 00608a04  3bc8                 cmp ecx, eax
// 00608a06  776b                 ja 0x608a73
// 00608a08  c644241400           mov byte ptr [esp + 0x14], 0
// 00608a0d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00608a11  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00608a15  8b542414             mov edx, dword ptr [esp + 0x14]
// 00608a19  50                   push eax
// 00608a1a  8b4508               mov eax, dword ptr [ebp + 8]
// 00608a1d  51                   push ecx
// 00608a1e  52                   push edx
// 00608a1f  57                   push edi
// 00608a20  50                   push eax
// 00608a21  8b4504               mov eax, dword ptr [ebp + 4]
// 00608a24  50                   push eax
// 00608a25  e856bce3ff           call 0x444680
// 00608a2a  8b4e08               mov ecx, dword ptr [esi + 8]
// 00608a2d  83c418               add esp, 0x18
// 00608a30  51                   push ecx
// 00608a31  50                   push eax
// 00608a32  8bce                 mov ecx, esi
// 00608a34  e8f712e0ff           call 0x409d30
// 00608a39  8b4504               mov eax, dword ptr [ebp + 4]
// 00608a3c  85c0                 test eax, eax
// 00608a3e  7418                 je 0x608a58
// 00608a40  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00608a43  2bc8                 sub ecx, eax
// 00608a45  b893244992           mov eax, 0x92492493
// 00608a4a  f7e9                 imul ecx
// 00608a4c  03d1                 add edx, ecx
// 00608a4e  c1fa04               sar edx, 4
// 00608a51  8bc2                 mov eax, edx
// 00608a53  c1e81f               shr eax, 0x1f
// 00608a56  03c2                 add eax, edx
// 00608a58  8d14c500000000       lea edx, [eax*8]
// 00608a5f  2bd0                 sub edx, eax
// 00608a61  8b4604               mov eax, dword ptr [esi + 4]
// 00608a64  5f                   pop edi
// 00608a65  8d0c90               lea ecx, [eax + edx*4]
// 00608a68  5b                   pop ebx
// 00608a69  894e08               mov dword ptr [esi + 8], ecx
// 00608a6c  8bc6                 mov eax, esi
// 00608a6e  5e                   pop esi
// 00608a6f  5d                   pop ebp
// 00608a70  c20400               ret 4
// 00608a73  85ff                 test edi, edi
// 00608a75  7504                 jne 0x608a7b
// 00608a77  33c0                 xor eax, eax
// 00608a79  eb18                 jmp 0x608a93
// 00608a7b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00608a7e  2bdf                 sub ebx, edi
// 00608a80  b893244992           mov eax, 0x92492493
// 00608a85  f7eb                 imul ebx
// 00608a87  03d3                 add edx, ebx
// 00608a89  c1fa04               sar edx, 4
// 00608a8c  8bc2                 mov eax, edx
// 00608a8e  c1e81f               shr eax, 0x1f
// 00608a91  03c2                 add eax, edx
// 00608a93  3bc8                 cmp ecx, eax
// 00608a95  773d                 ja 0x608ad4
// 00608a97  8bce                 mov ecx, esi
// 00608a99  e8a2f9dfff           call 0x408440
// 00608a9e  8d14c500000000       lea edx, [eax*8]
// 00608aa5  2bd0                 sub edx, eax
// 00608aa7  8b4504               mov eax, dword ptr [ebp + 4]
// 00608aaa  8d1c90               lea ebx, [eax + edx*4]
// 00608aad  57                   push edi
// 00608aae  53                   push ebx
// 00608aaf  50                   push eax
// 00608ab0  e85bbde3ff           call 0x444810
// 00608ab5  8b4608               mov eax, dword ptr [esi + 8]
// 00608ab8  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00608abb  83c40c               add esp, 0xc
// 00608abe  50                   push eax
// 00608abf  51                   push ecx
// 00608ac0  53                   push ebx
// 00608ac1  8bce                 mov ecx, esi
// 00608ac3  e858fcffff           call 0x608720
// 00608ac8  5f                   pop edi
// 00608ac9  894608               mov dword ptr [esi + 8], eax
// 00608acc  5b                   pop ebx
// 00608acd  8bc6                 mov eax, esi
// 00608acf  5e                   pop esi
// 00608ad0  5d                   pop ebp
// 00608ad1  c20400               ret 4
// 00608ad4  85ff                 test edi, edi
// 00608ad6  7418                 je 0x608af0
// 00608ad8  8b5608               mov edx, dword ptr [esi + 8]
// 00608adb  52                   push edx
// 00608adc  57                   push edi
// 00608add  8bce                 mov ecx, esi
// 00608adf  e84c12e0ff           call 0x409d30
// 00608ae4  8b4604               mov eax, dword ptr [esi + 4]
// 00608ae7  50                   push eax
// 00608ae8  e803560100           call 0x61e0f0
// 00608aed  83c404               add esp, 4
// 00608af0  8bcd                 mov ecx, ebp
// 00608af2  e849f9dfff           call 0x408440
// 00608af7  50                   push eax
// 00608af8  8bce                 mov ecx, esi
// 00608afa  e8811be2ff           call 0x42a680
// 00608aff  84c0                 test al, al
// 00608b01  7416                 je 0x608b19
// 00608b03  8b4e04               mov ecx, dword ptr [esi + 4]
// 00608b06  8b5508               mov edx, dword ptr [ebp + 8]
// 00608b09  8b4504               mov eax, dword ptr [ebp + 4]
// 00608b0c  51                   push ecx
// 00608b0d  52                   push edx
// 00608b0e  50                   push eax
// 00608b0f  8bce                 mov ecx, esi
// 00608b11  e80afcffff           call 0x608720
// 00608b16  894608               mov dword ptr [esi + 8], eax
// 00608b19  5f                   pop edi
// 00608b1a  5b                   pop ebx
// 00608b1b  8bc6                 mov eax, esi
// 00608b1d  5e                   pop esi
// 00608b1e  5d                   pop ebp
// 00608b1f  c20400               ret 4
// standard library vector<string> (function ??4?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEAAV01@ABV01@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
