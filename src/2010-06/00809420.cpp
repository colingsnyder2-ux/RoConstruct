// from server: 100% by auto
// roc 2010-06 00809420  unit: PAUHWND__::?$CArray  size: 329 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00809420
//
// 00809420  53                   push ebx
// 00809421  56                   push esi
// 00809422  57                   push edi
// 00809423  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00809427  33db                 xor ebx, ebx
// 00809429  3bfb                 cmp edi, ebx
// 0080942b  8bf1                 mov esi, ecx
// 0080942d  7d05                 jge 0x809434
// 0080942f  e818e8f9ff           call 0x7a7c4c
// 00809434  8b442414             mov eax, dword ptr [esp + 0x14]
// 00809438  3bc3                 cmp eax, ebx
// 0080943a  7c03                 jl 0x80943f
// 0080943c  894610               mov dword ptr [esi + 0x10], eax
// 0080943f  3bfb                 cmp edi, ebx
// 00809441  751f                 jne 0x809462
// 00809443  8b4604               mov eax, dword ptr [esi + 4]
// 00809446  3bc3                 cmp eax, ebx
// 00809448  740c                 je 0x809456
// 0080944a  50                   push eax
// 0080944b  e8f6e7f9ff           call 0x7a7c46
// 00809450  83c404               add esp, 4
// 00809453  895e04               mov dword ptr [esi + 4], ebx
// 00809456  5f                   pop edi
// 00809457  895e0c               mov dword ptr [esi + 0xc], ebx
// 0080945a  895e08               mov dword ptr [esi + 8], ebx
// 0080945d  5e                   pop esi
// 0080945e  5b                   pop ebx
// 0080945f  c20800               ret 8
// 00809462  8b4e04               mov ecx, dword ptr [esi + 4]
// 00809465  55                   push ebp
// 00809466  3bcb                 cmp ecx, ebx
// 00809468  7530                 jne 0x80949a
// 0080946a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 0080946d  3bfd                 cmp edi, ebp
// 0080946f  7e02                 jle 0x809473
// 00809471  8bef                 mov ebp, edi
// 00809473  8bdd                 mov ebx, ebp
// 00809475  c1e304               shl ebx, 4
// 00809478  53                   push ebx
// 00809479  e804e8f9ff           call 0x7a7c82
// 0080947e  53                   push ebx
// 0080947f  6a00                 push 0
// 00809481  50                   push eax
// 00809482  894604               mov dword ptr [esi + 4], eax
// 00809485  e85af7f9ff           call 0x7a8be4
// 0080948a  83c410               add esp, 0x10
// 0080948d  896e0c               mov dword ptr [esi + 0xc], ebp
// 00809490  5d                   pop ebp
// 00809491  897e08               mov dword ptr [esi + 8], edi
// 00809494  5f                   pop edi
// 00809495  5e                   pop esi
// 00809496  5b                   pop ebx
// 00809497  c20800               ret 8
// 0080949a  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0080949d  3bfd                 cmp edi, ebp
// 0080949f  7f2c                 jg 0x8094cd
// 008094a1  8b4608               mov eax, dword ptr [esi + 8]
// 008094a4  3bf8                 cmp edi, eax
// 008094a6  0f8eb3000000         jle 0x80955f
// 008094ac  8bd7                 mov edx, edi
// 008094ae  2bd0                 sub edx, eax
// 008094b0  c1e204               shl edx, 4
// 008094b3  52                   push edx
// 008094b4  c1e004               shl eax, 4
// 008094b7  03c1                 add eax, ecx
// 008094b9  53                   push ebx
// 008094ba  50                   push eax
// 008094bb  e824f7f9ff           call 0x7a8be4
// 008094c0  83c40c               add esp, 0xc
// 008094c3  5d                   pop ebp
// 008094c4  897e08               mov dword ptr [esi + 8], edi
// 008094c7  5f                   pop edi
// 008094c8  5e                   pop esi
// 008094c9  5b                   pop ebx
// 008094ca  c20800               ret 8
// 008094cd  8b4610               mov eax, dword ptr [esi + 0x10]
// 008094d0  3bc3                 cmp eax, ebx
// 008094d2  7524                 jne 0x8094f8
// 008094d4  8b4608               mov eax, dword ptr [esi + 8]
// 008094d7  99                   cdq 
// 008094d8  83e207               and edx, 7
// 008094db  03c2                 add eax, edx
// 008094dd  c1f803               sar eax, 3
// 008094e0  83f804               cmp eax, 4
// 008094e3  7d07                 jge 0x8094ec
// 008094e5  b804000000           mov eax, 4
// 008094ea  eb0c                 jmp 0x8094f8
// 008094ec  3d00040000           cmp eax, 0x400
// 008094f1  7e05                 jle 0x8094f8
// 008094f3  b800040000           mov eax, 0x400
// 008094f8  8d1c28               lea ebx, [eax + ebp]
// 008094fb  3bfb                 cmp edi, ebx
// 008094fd  7d06                 jge 0x809505
// 008094ff  895c2414             mov dword ptr [esp + 0x14], ebx
// 00809503  eb06                 jmp 0x80950b
// 00809505  897c2414             mov dword ptr [esp + 0x14], edi
// 00809509  8bdf                 mov ebx, edi
// 0080950b  3bdd                 cmp ebx, ebp
// 0080950d  7d05                 jge 0x809514
// 0080950f  e838e7f9ff           call 0x7a7c4c
// 00809514  c1e304               shl ebx, 4
// 00809517  53                   push ebx
// 00809518  e865e7f9ff           call 0x7a7c82
// 0080951d  8b4e04               mov ecx, dword ptr [esi + 4]
// 00809520  8be8                 mov ebp, eax
// 00809522  8b4608               mov eax, dword ptr [esi + 8]
// 00809525  c1e004               shl eax, 4
// 00809528  50                   push eax
// 00809529  51                   push ecx
// 0080952a  53                   push ebx
// 0080952b  55                   push ebp
// 0080952c  e8bf96bfff           call 0x402bf0
// 00809531  8b4608               mov eax, dword ptr [esi + 8]
// 00809534  8bd7                 mov edx, edi
// 00809536  2bd0                 sub edx, eax
// 00809538  c1e204               shl edx, 4
// 0080953b  52                   push edx
// 0080953c  c1e004               shl eax, 4
// 0080953f  03c5                 add eax, ebp
// 00809541  6a00                 push 0
// 00809543  50                   push eax
// 00809544  e89bf6f9ff           call 0x7a8be4
// 00809549  8b4604               mov eax, dword ptr [esi + 4]
// 0080954c  50                   push eax
// 0080954d  e8f4e6f9ff           call 0x7a7c46
// 00809552  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00809556  83c424               add esp, 0x24
// 00809559  896e04               mov dword ptr [esi + 4], ebp
// 0080955c  894e0c               mov dword ptr [esi + 0xc], ecx
// 0080955f  5d                   pop ebp
// 00809560  897e08               mov dword ptr [esi + 8], edi
// 00809563  5f                   pop edi
// 00809564  5e                   pop esi
// 00809565  5b                   pop ebx
// 00809566  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ?SetSize@?$CArray@UtagRECT@@AAU1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
