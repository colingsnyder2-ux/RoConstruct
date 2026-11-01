// from server: 100% by auto
// roc 2007-03 0042b2a0  unit: seg_00420000  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0042b2a0
//
// 0042b2a0  83ec08               sub esp, 8
// 0042b2a3  53                   push ebx
// 0042b2a4  56                   push esi
// 0042b2a5  8bf1                 mov esi, ecx
// 0042b2a7  8b5e04               mov ebx, dword ptr [esi + 4]
// 0042b2aa  85db                 test ebx, ebx
// 0042b2ac  57                   push edi
// 0042b2ad  7504                 jne 0x42b2b3
// 0042b2af  33ff                 xor edi, edi
// 0042b2b1  eb18                 jmp 0x42b2cb
// 0042b2b3  8b4e08               mov ecx, dword ptr [esi + 8]
// 0042b2b6  2bcb                 sub ecx, ebx
// 0042b2b8  b893244992           mov eax, 0x92492493
// 0042b2bd  f7e9                 imul ecx
// 0042b2bf  03d1                 add edx, ecx
// 0042b2c1  c1fa04               sar edx, 4
// 0042b2c4  8bfa                 mov edi, edx
// 0042b2c6  c1ef1f               shr edi, 0x1f
// 0042b2c9  03fa                 add edi, edx
// 0042b2cb  85db                 test ebx, ebx
// 0042b2cd  744e                 je 0x42b31d
// 0042b2cf  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0042b2d2  2bcb                 sub ecx, ebx
// 0042b2d4  b893244992           mov eax, 0x92492493
// 0042b2d9  f7e9                 imul ecx
// 0042b2db  03d1                 add edx, ecx
// 0042b2dd  c1fa04               sar edx, 4
// 0042b2e0  8bc2                 mov eax, edx
// 0042b2e2  c1e81f               shr eax, 0x1f
// 0042b2e5  03c2                 add eax, edx
// 0042b2e7  3bf8                 cmp edi, eax
// 0042b2e9  7332                 jae 0x42b31d
// 0042b2eb  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0042b2ef  8b542418             mov edx, dword ptr [esp + 0x18]
// 0042b2f3  8b7e08               mov edi, dword ptr [esi + 8]
// 0042b2f6  c644240c00           mov byte ptr [esp + 0xc], 0
// 0042b2fb  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0042b2ff  50                   push eax
// 0042b300  51                   push ecx
// 0042b301  56                   push esi
// 0042b302  52                   push edx
// 0042b303  6a01                 push 1
// 0042b305  57                   push edi
// 0042b306  e865f4ffff           call 0x42a770
// 0042b30b  83c418               add esp, 0x18
// 0042b30e  83c71c               add edi, 0x1c
// 0042b311  897e08               mov dword ptr [esi + 8], edi
// 0042b314  5f                   pop edi
// 0042b315  5e                   pop esi
// 0042b316  5b                   pop ebx
// 0042b317  83c408               add esp, 8
// 0042b31a  c20400               ret 4
// 0042b31d  8b7e08               mov edi, dword ptr [esi + 8]
// 0042b320  3bdf                 cmp ebx, edi
// 0042b322  7606                 jbe 0x42b32a
// 0042b324  ff1544e97700         call dword ptr [0x77e944]
// 0042b32a  8b442418             mov eax, dword ptr [esp + 0x18]
// 0042b32e  50                   push eax
// 0042b32f  57                   push edi
// 0042b330  56                   push esi
// 0042b331  8d4c2418             lea ecx, [esp + 0x18]
// 0042b335  51                   push ecx
// 0042b336  8bce                 mov ecx, esi
// 0042b338  e833fbffff           call 0x42ae70
// 0042b33d  5f                   pop edi
// 0042b33e  5e                   pop esi
// 0042b33f  5b                   pop ebx
// 0042b340  83c408               add esp, 8
// 0042b343  c20400               ret 4
// standard library vector<string> (function ?push_back@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
