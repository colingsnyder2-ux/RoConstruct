// from server: 100% by auto
// roc 2007-08 00429310  unit: ThreadLogManager  size: 494 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00429310
//
// 00429310  55                   push ebp
// 00429311  8bec                 mov ebp, esp
// 00429313  6aff                 push -1
// 00429315  68d9cc7300           push 0x73ccd9
// 0042931a  64a100000000         mov eax, dword ptr fs:[0]
// 00429320  50                   push eax
// 00429321  83ec38               sub esp, 0x38
// 00429324  a188518b00           mov eax, dword ptr [0x8b5188]
// 00429329  33c5                 xor eax, ebp
// 0042932b  8945ec               mov dword ptr [ebp - 0x14], eax
// 0042932e  53                   push ebx
// 0042932f  56                   push esi
// 00429330  57                   push edi
// 00429331  50                   push eax
// 00429332  8d45f4               lea eax, [ebp - 0xc]
// 00429335  64a300000000         mov dword ptr fs:[0], eax
// 0042933b  8965f0               mov dword ptr [ebp - 0x10], esp
// 0042933e  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00429341  8bf1                 mov esi, ecx
// 00429343  50                   push eax
// 00429344  8d4dd0               lea ecx, [ebp - 0x30]
// 00429347  8975bc               mov dword ptr [ebp - 0x44], esi
// 0042934a  ff159ce67700         call dword ptr [0x77e69c]
// 00429350  8b5e04               mov ebx, dword ptr [esi + 4]
// 00429353  33c0                 xor eax, eax
// 00429355  3bd8                 cmp ebx, eax
// 00429357  8945fc               mov dword ptr [ebp - 4], eax
// 0042935a  7418                 je 0x429374
// 0042935c  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0042935f  2bcb                 sub ecx, ebx
// 00429361  b893244992           mov eax, 0x92492493
// 00429366  f7e9                 imul ecx
// 00429368  03d1                 add edx, ecx
// 0042936a  c1fa04               sar edx, 4
// 0042936d  8bc2                 mov eax, edx
// 0042936f  c1e81f               shr eax, 0x1f
// 00429372  03c2                 add eax, edx
// 00429374  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00429377  85ff                 test edi, edi
// 00429379  8945cc               mov dword ptr [ebp - 0x34], eax
// 0042937c  0f849b020000         je 0x42961d
// 00429382  85db                 test ebx, ebx
// 00429384  7504                 jne 0x42938a
// 00429386  33c0                 xor eax, eax
// 00429388  eb18                 jmp 0x4293a2
// 0042938a  8b4e08               mov ecx, dword ptr [esi + 8]
// 0042938d  2bcb                 sub ecx, ebx
// 0042938f  b893244992           mov eax, 0x92492493
// 00429394  f7e9                 imul ecx
// 00429396  03d1                 add edx, ecx
// 00429398  c1fa04               sar edx, 4
// 0042939b  8bc2                 mov eax, edx
// 0042939d  c1e81f               shr eax, 0x1f
// 004293a0  03c2                 add eax, edx
// 004293a2  b949922409           mov ecx, 0x9249249
// 004293a7  2bc8                 sub ecx, eax
// 004293a9  3bcf                 cmp ecx, edi
// 004293ab  7305                 jae 0x4293b2
// 004293ad  e84ee4feff           call 0x417800
// 004293b2  85db                 test ebx, ebx
// 004293b4  7504                 jne 0x4293ba
// 004293b6  33c0                 xor eax, eax
// 004293b8  eb18                 jmp 0x4293d2
// 004293ba  8b4e08               mov ecx, dword ptr [esi + 8]
// 004293bd  2bcb                 sub ecx, ebx
// 004293bf  b893244992           mov eax, 0x92492493
// 004293c4  f7e9                 imul ecx
// 004293c6  03d1                 add edx, ecx
// 004293c8  c1fa04               sar edx, 4
// 004293cb  8bc2                 mov eax, edx
// 004293cd  c1e81f               shr eax, 0x1f
// 004293d0  03c2                 add eax, edx
// 004293d2  8b4dcc               mov ecx, dword ptr [ebp - 0x34]
// 004293d5  03c7                 add eax, edi
// 004293d7  3bc8                 cmp ecx, eax
// 004293d9  0f8341010000         jae 0x429520
// 004293df  8bc1                 mov eax, ecx
// 004293e1  d1e8                 shr eax, 1
// 004293e3  ba49922409           mov edx, 0x9249249
// 004293e8  2bd0                 sub edx, eax
// 004293ea  3bd1                 cmp edx, ecx
// 004293ec  7309                 jae 0x4293f7
// 004293ee  c745cc00000000       mov dword ptr [ebp - 0x34], 0
// 004293f5  eb05                 jmp 0x4293fc
// 004293f7  03c8                 add ecx, eax
// 004293f9  894dcc               mov dword ptr [ebp - 0x34], ecx
// 004293fc  85db                 test ebx, ebx
// 004293fe  7504                 jne 0x429404
// 00429400  33c0                 xor eax, eax
// 00429402  eb18                 jmp 0x42941c
// 00429404  8b4e08               mov ecx, dword ptr [esi + 8]
// 00429407  2bcb                 sub ecx, ebx
// 00429409  b893244992           mov eax, 0x92492493
// 0042940e  f7e9                 imul ecx
// 00429410  03d1                 add edx, ecx
// 00429412  c1fa04               sar edx, 4
// 00429415  8bc2                 mov eax, edx
// 00429417  c1e81f               shr eax, 0x1f
// 0042941a  03c2                 add eax, edx
// 0042941c  03c7                 add eax, edi
// 0042941e  3945cc               cmp dword ptr [ebp - 0x34], eax
// 00429421  730c                 jae 0x42942f
// 00429423  8bce                 mov ecx, esi
// 00429425  e80622ffff           call 0x41b630
// 0042942a  03c7                 add eax, edi
// 0042942c  8945cc               mov dword ptr [ebp - 0x34], eax
// 0042942f  8b45cc               mov eax, dword ptr [ebp - 0x34]
// 00429432  6a00                 push 0
// 00429434  50                   push eax
// 00429435  e82622ffff           call 0x41b660
// 0042943a  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 0042943d  8b4e04               mov ecx, dword ptr [esi + 4]
// 00429440  c645c400             mov byte ptr [ebp - 0x3c], 0
// 00429444  8b55c4               mov edx, dword ptr [ebp - 0x3c]
// 00429447  52                   push edx
// 00429448  8b55c4               mov edx, dword ptr [ebp - 0x3c]
// 0042944b  52                   push edx
// 0042944c  56                   push esi
// 0042944d  50                   push eax
// 0042944e  53                   push ebx
// 0042944f  51                   push ecx
// 00429450  8945c0               mov dword ptr [ebp - 0x40], eax
// 00429453  8945c8               mov dword ptr [ebp - 0x38], eax
// 00429456  c645fc01             mov byte ptr [ebp - 4], 1
// 0042945a  e8f1f4ffff           call 0x428950
// 0042945f  83c420               add esp, 0x20
// 00429462  8d4dd0               lea ecx, [ebp - 0x30]
// 00429465  51                   push ecx
// 00429466  57                   push edi
// 00429467  50                   push eax
// 00429468  8bce                 mov ecx, esi
// 0042946a  8945c8               mov dword ptr [ebp - 0x38], eax
// 0042946d  e85efeffff           call 0x4292d0
// 00429472  8b4e08               mov ecx, dword ptr [esi + 8]
// 00429475  c645c400             mov byte ptr [ebp - 0x3c], 0
// 00429479  8b55c4               mov edx, dword ptr [ebp - 0x3c]
// 0042947c  52                   push edx
// 0042947d  8b55c4               mov edx, dword ptr [ebp - 0x3c]
// 00429480  52                   push edx
// 00429481  56                   push esi
// 00429482  50                   push eax
// 00429483  51                   push ecx
// 00429484  53                   push ebx
// 00429485  8945c8               mov dword ptr [ebp - 0x38], eax
// 00429488  e8c3f4ffff           call 0x428950
// 0042948d  8b5e04               mov ebx, dword ptr [esi + 4]
// 00429490  33c0                 xor eax, eax
// 00429492  83c418               add esp, 0x18
// 00429495  3bd8                 cmp ebx, eax
// 00429497  8945fc               mov dword ptr [ebp - 4], eax
// 0042949a  7418                 je 0x4294b4
// 0042949c  8b4e08               mov ecx, dword ptr [esi + 8]
// 0042949f  2bcb                 sub ecx, ebx
// 004294a1  b893244992           mov eax, 0x92492493
// 004294a6  f7e9                 imul ecx
// 004294a8  03d1                 add edx, ecx
// 004294aa  c1fa04               sar edx, 4
// 004294ad  8bc2                 mov eax, edx
// 004294af  c1e81f               shr eax, 0x1f
// 004294b2  03c2                 add eax, edx
// 004294b4  03f8                 add edi, eax
// 004294b6  85db                 test ebx, ebx
// 004294b8  7418                 je 0x4294d2
// 004294ba  8b4608               mov eax, dword ptr [esi + 8]
// 004294bd  50                   push eax
// 004294be  53                   push ebx
// 004294bf  8bce                 mov ecx, esi
// 004294c1  e87a05feff           call 0x409a40
// 004294c6  8b4604               mov eax, dword ptr [esi + 4]
// 004294c9  50                   push eax
// 004294ca  e893672000           call 0x62fc62
// 004294cf  83c404               add esp, 4
// 004294d2  8b45cc               mov eax, dword ptr [ebp - 0x34]
// 004294d5  8d0cc500000000       lea ecx, [eax*8]
// 004294dc  2bc8                 sub ecx, eax
// 004294de  8b45c0               mov eax, dword ptr [ebp - 0x40]
// 004294e1  8d1488               lea edx, [eax + ecx*4]
// 004294e4  8d0cfd00000000       lea ecx, [edi*8]
// 004294eb  2bcf                 sub ecx, edi
// 004294ed  89560c               mov dword ptr [esi + 0xc], edx
// 004294f0  8d1488               lea edx, [eax + ecx*4]
// 004294f3  895608               mov dword ptr [esi + 8], edx
// 004294f6  894604               mov dword ptr [esi + 4], eax
// 004294f9  e91f010000           jmp 0x42961d
// standard library vector<string> (function ?_Insert_n@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXV?$_Vector_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@IABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
