// from server: 100% by auto
// roc 2009-12 008554f0  unit: PAUHWND__::?$CArray  size: 329 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008554f0
//
// 008554f0  53                   push ebx
// 008554f1  56                   push esi
// 008554f2  57                   push edi
// 008554f3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008554f7  33db                 xor ebx, ebx
// 008554f9  3bfb                 cmp edi, ebx
// 008554fb  8bf1                 mov esi, ecx
// 008554fd  7d05                 jge 0x855504
// 008554ff  e808e6f9ff           call 0x7f3b0c
// 00855504  8b442414             mov eax, dword ptr [esp + 0x14]
// 00855508  3bc3                 cmp eax, ebx
// 0085550a  7c03                 jl 0x85550f
// 0085550c  894610               mov dword ptr [esi + 0x10], eax
// 0085550f  3bfb                 cmp edi, ebx
// 00855511  751f                 jne 0x855532
// 00855513  8b4604               mov eax, dword ptr [esi + 4]
// 00855516  3bc3                 cmp eax, ebx
// 00855518  740c                 je 0x855526
// 0085551a  50                   push eax
// 0085551b  e8e6e5f9ff           call 0x7f3b06
// 00855520  83c404               add esp, 4
// 00855523  895e04               mov dword ptr [esi + 4], ebx
// 00855526  5f                   pop edi
// 00855527  895e0c               mov dword ptr [esi + 0xc], ebx
// 0085552a  895e08               mov dword ptr [esi + 8], ebx
// 0085552d  5e                   pop esi
// 0085552e  5b                   pop ebx
// 0085552f  c20800               ret 8
// 00855532  8b4e04               mov ecx, dword ptr [esi + 4]
// 00855535  55                   push ebp
// 00855536  3bcb                 cmp ecx, ebx
// 00855538  7530                 jne 0x85556a
// 0085553a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 0085553d  3bfd                 cmp edi, ebp
// 0085553f  7e02                 jle 0x855543
// 00855541  8bef                 mov ebp, edi
// 00855543  8bdd                 mov ebx, ebp
// 00855545  c1e304               shl ebx, 4
// 00855548  53                   push ebx
// 00855549  e8f4e5f9ff           call 0x7f3b42
// 0085554e  53                   push ebx
// 0085554f  6a00                 push 0
// 00855551  50                   push eax
// 00855552  894604               mov dword ptr [esi + 4], eax
// 00855555  e84af5f9ff           call 0x7f4aa4
// 0085555a  83c410               add esp, 0x10
// 0085555d  896e0c               mov dword ptr [esi + 0xc], ebp
// 00855560  5d                   pop ebp
// 00855561  897e08               mov dword ptr [esi + 8], edi
// 00855564  5f                   pop edi
// 00855565  5e                   pop esi
// 00855566  5b                   pop ebx
// 00855567  c20800               ret 8
// 0085556a  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0085556d  3bfd                 cmp edi, ebp
// 0085556f  7f2c                 jg 0x85559d
// 00855571  8b4608               mov eax, dword ptr [esi + 8]
// 00855574  3bf8                 cmp edi, eax
// 00855576  0f8eb3000000         jle 0x85562f
// 0085557c  8bd7                 mov edx, edi
// 0085557e  2bd0                 sub edx, eax
// 00855580  c1e204               shl edx, 4
// 00855583  52                   push edx
// 00855584  c1e004               shl eax, 4
// 00855587  03c1                 add eax, ecx
// 00855589  53                   push ebx
// 0085558a  50                   push eax
// 0085558b  e814f5f9ff           call 0x7f4aa4
// 00855590  83c40c               add esp, 0xc
// 00855593  5d                   pop ebp
// 00855594  897e08               mov dword ptr [esi + 8], edi
// 00855597  5f                   pop edi
// 00855598  5e                   pop esi
// 00855599  5b                   pop ebx
// 0085559a  c20800               ret 8
// 0085559d  8b4610               mov eax, dword ptr [esi + 0x10]
// 008555a0  3bc3                 cmp eax, ebx
// 008555a2  7524                 jne 0x8555c8
// 008555a4  8b4608               mov eax, dword ptr [esi + 8]
// 008555a7  99                   cdq 
// 008555a8  83e207               and edx, 7
// 008555ab  03c2                 add eax, edx
// 008555ad  c1f803               sar eax, 3
// 008555b0  83f804               cmp eax, 4
// 008555b3  7d07                 jge 0x8555bc
// 008555b5  b804000000           mov eax, 4
// 008555ba  eb0c                 jmp 0x8555c8
// 008555bc  3d00040000           cmp eax, 0x400
// 008555c1  7e05                 jle 0x8555c8
// 008555c3  b800040000           mov eax, 0x400
// 008555c8  8d1c28               lea ebx, [eax + ebp]
// 008555cb  3bfb                 cmp edi, ebx
// 008555cd  7d06                 jge 0x8555d5
// 008555cf  895c2414             mov dword ptr [esp + 0x14], ebx
// 008555d3  eb06                 jmp 0x8555db
// 008555d5  897c2414             mov dword ptr [esp + 0x14], edi
// 008555d9  8bdf                 mov ebx, edi
// 008555db  3bdd                 cmp ebx, ebp
// 008555dd  7d05                 jge 0x8555e4
// 008555df  e828e5f9ff           call 0x7f3b0c
// 008555e4  c1e304               shl ebx, 4
// 008555e7  53                   push ebx
// 008555e8  e855e5f9ff           call 0x7f3b42
// 008555ed  8b4e04               mov ecx, dword ptr [esi + 4]
// 008555f0  8be8                 mov ebp, eax
// 008555f2  8b4608               mov eax, dword ptr [esi + 8]
// 008555f5  c1e004               shl eax, 4
// 008555f8  50                   push eax
// 008555f9  51                   push ecx
// 008555fa  53                   push ebx
// 008555fb  55                   push ebp
// 008555fc  e89fd5baff           call 0x402ba0
// 00855601  8b4608               mov eax, dword ptr [esi + 8]
// 00855604  8bd7                 mov edx, edi
// 00855606  2bd0                 sub edx, eax
// 00855608  c1e204               shl edx, 4
// 0085560b  52                   push edx
// 0085560c  c1e004               shl eax, 4
// 0085560f  03c5                 add eax, ebp
// 00855611  6a00                 push 0
// 00855613  50                   push eax
// 00855614  e88bf4f9ff           call 0x7f4aa4
// 00855619  8b4604               mov eax, dword ptr [esi + 4]
// 0085561c  50                   push eax
// 0085561d  e8e4e4f9ff           call 0x7f3b06
// 00855622  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00855626  83c424               add esp, 0x24
// 00855629  896e04               mov dword ptr [esi + 4], ebp
// 0085562c  894e0c               mov dword ptr [esi + 0xc], ecx
// 0085562f  5d                   pop ebp
// 00855630  897e08               mov dword ptr [esi + 8], edi
// 00855633  5f                   pop edi
// 00855634  5e                   pop esi
// 00855635  5b                   pop ebx
// 00855636  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ?SetSize@?$CArray@UtagRECT@@AAU1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
