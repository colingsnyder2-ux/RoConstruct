// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 00429480  unit: ThreadLogManager  size: 391 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00429480
//
// 00429480  55                   push ebp
// 00429481  8bec                 mov ebp, esp
// 00429483  6aff                 push -1
// 00429485  68d2f27b00           push 0x7bf2d2
// 0042948a  64a100000000         mov eax, dword ptr fs:[0]
// 00429490  50                   push eax
// 00429491  64892500000000       mov dword ptr fs:[0], esp
// 00429498  83ec48               sub esp, 0x48
// 0042949b  53                   push ebx
// 0042949c  56                   push esi
// 0042949d  8bf1                 mov esi, ecx
// 0042949f  8b460c               mov eax, dword ptr [esi + 0xc]
// 004294a2  57                   push edi
// 004294a3  8965f0               mov dword ptr [ebp - 0x10], esp
// 004294a6  8975e8               mov dword ptr [ebp - 0x18], esi
// 004294a9  85c0                 test eax, eax
// 004294ab  7504                 jne 0x4294b1
// 004294ad  33db                 xor ebx, ebx
// 004294af  eb18                 jmp 0x4294c9
// 004294b1  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004294b4  2bc8                 sub ecx, eax
// 004294b6  b893244992           mov eax, 0x92492493
// 004294bb  f7e9                 imul ecx
// 004294bd  03d1                 add edx, ecx
// 004294bf  c1fa04               sar edx, 4
// 004294c2  8bda                 mov ebx, edx
// 004294c4  c1eb1f               shr ebx, 0x1f
// 004294c7  03da                 add ebx, edx
// 004294c9  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004294cc  85ff                 test edi, edi
// 004294ce  0f8497020000         je 0x42976b
// 004294d4  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004294d7  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 004294da  b893244992           mov eax, 0x92492493
// 004294df  f7e9                 imul ecx
// 004294e1  03d1                 add edx, ecx
// 004294e3  c1fa04               sar edx, 4
// 004294e6  8bc2                 mov eax, edx
// 004294e8  c1e81f               shr eax, 0x1f
// 004294eb  03c2                 add eax, edx
// 004294ed  b949922409           mov ecx, 0x9249249
// 004294f2  2bc8                 sub ecx, eax
// 004294f4  3bcf                 cmp ecx, edi
// 004294f6  7305                 jae 0x4294fd
// 004294f8  e843d80900           call 0x4c6d40
// 004294fd  8d0c38               lea ecx, [eax + edi]
// 00429500  3bd9                 cmp ebx, ecx
// 00429502  0f8321010000         jae 0x429629
// 00429508  8bc3                 mov eax, ebx
// 0042950a  d1e8                 shr eax, 1
// 0042950c  ba49922409           mov edx, 0x9249249
// 00429511  2bd0                 sub edx, eax
// 00429513  3bd3                 cmp edx, ebx
// 00429515  7304                 jae 0x42951b
// 00429517  33db                 xor ebx, ebx
// 00429519  eb02                 jmp 0x42951d
// 0042951b  03d8                 add ebx, eax
// 0042951d  3bd9                 cmp ebx, ecx
// 0042951f  7302                 jae 0x429523
// 00429521  8bd9                 mov ebx, ecx
// 00429523  6a00                 push 0
// 00429525  53                   push ebx
// 00429526  e8d53fffff           call 0x41d500
// 0042952b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0042952e  c645e400             mov byte ptr [ebp - 0x1c], 0
// 00429532  8b55e4               mov edx, dword ptr [ebp - 0x1c]
// 00429535  52                   push edx
// 00429536  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00429539  52                   push edx
// 0042953a  8d5608               lea edx, [esi + 8]
// 0042953d  52                   push edx
// 0042953e  50                   push eax
// 0042953f  8945ec               mov dword ptr [ebp - 0x14], eax
// 00429542  894510               mov dword ptr [ebp + 0x10], eax
// 00429545  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00429548  50                   push eax
// 00429549  51                   push ecx
// 0042954a  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00429551  e8caf4ffff           call 0x428a20
// 00429556  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00429559  83c420               add esp, 0x20
// 0042955c  51                   push ecx
// 0042955d  57                   push edi
// 0042955e  50                   push eax
// 0042955f  8bce                 mov ecx, esi
// 00429561  894510               mov dword ptr [ebp + 0x10], eax
// 00429564  e8d7feffff           call 0x429440
// 00429569  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0042956c  c6451400             mov byte ptr [ebp + 0x14], 0
// 00429570  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00429573  52                   push edx
// 00429574  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00429577  52                   push edx
// 00429578  8d5608               lea edx, [esi + 8]
// 0042957b  52                   push edx
// 0042957c  50                   push eax
// 0042957d  894510               mov dword ptr [ebp + 0x10], eax
// 00429580  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00429583  51                   push ecx
// 00429584  50                   push eax
// 00429585  e896f4ffff           call 0x428a20
// 0042958a  8b460c               mov eax, dword ptr [esi + 0xc]
// 0042958d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00429590  2bc8                 sub ecx, eax
// 00429592  b893244992           mov eax, 0x92492493
// 00429597  f7e9                 imul ecx
// 00429599  8b460c               mov eax, dword ptr [esi + 0xc]
// 0042959c  03d1                 add edx, ecx
// 0042959e  c1fa04               sar edx, 4
// 004295a1  8bca                 mov ecx, edx
// 004295a3  c1e91f               shr ecx, 0x1f
// 004295a6  03ca                 add ecx, edx
// 004295a8  83c418               add esp, 0x18
// 004295ab  03f9                 add edi, ecx
// 004295ad  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 004295b4  85c0                 test eax, eax
// 004295b6  7418                 je 0x4295d0
// 004295b8  8b5610               mov edx, dword ptr [esi + 0x10]
// 004295bb  52                   push edx
// 004295bc  50                   push eax
// 004295bd  8bce                 mov ecx, esi
// 004295bf  e8dce1fdff           call 0x4077a0
// 004295c4  8b460c               mov eax, dword ptr [esi + 0xc]
// 004295c7  50                   push eax
// 004295c8  e8ad702700           call 0x6a067a
// 004295cd  83c404               add esp, 4
// 004295d0  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004295d3  8d0cdd00000000       lea ecx, [ebx*8]
// 004295da  2bcb                 sub ecx, ebx
// 004295dc  8d1488               lea edx, [eax + ecx*4]
// 004295df  8d0cfd00000000       lea ecx, [edi*8]
// 004295e6  2bcf                 sub ecx, edi
// 004295e8  895614               mov dword ptr [esi + 0x14], edx
// 004295eb  8d1488               lea edx, [eax + ecx*4]
// 004295ee  895610               mov dword ptr [esi + 0x10], edx
// 004295f1  89460c               mov dword ptr [esi + 0xc], eax
// 004295f4  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004295f7  64890d00000000       mov dword ptr fs:[0], ecx
// 004295fe  5f                   pop edi
// 004295ff  5e                   pop esi
// 00429600  5b                   pop ebx
// 00429601  8be5                 mov esp, ebp
// 00429603  5d                   pop ebp
// 00429604  c21000               ret 0x10
// standard library vector<string> (function ?_Insert_n@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXV?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@IABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
