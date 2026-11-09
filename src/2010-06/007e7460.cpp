// from server: 100% by auto
// roc 2010-06 007e7460  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e7460
//
// 007e7460  53                   push ebx
// 007e7461  56                   push esi
// 007e7462  8bf1                 mov esi, ecx
// 007e7464  33db                 xor ebx, ebx
// 007e7466  6a0a                 push 0xa
// 007e7468  8d4e18               lea ecx, [esi + 0x18]
// 007e746b  c70694a8a500         mov dword ptr [esi], 0xa5a894
// 007e7471  895e04               mov dword ptr [esi + 4], ebx
// 007e7474  c7460801000000       mov dword ptr [esi + 8], 1
// 007e747b  895e0c               mov dword ptr [esi + 0xc], ebx
// 007e747e  895e10               mov dword ptr [esi + 0x10], ebx
// 007e7481  895e14               mov dword ptr [esi + 0x14], ebx
// 007e7484  e8e7fdffff           call 0x7e7270
// 007e7489  885e38               mov byte ptr [esi + 0x38], bl
// 007e748c  895e34               mov dword ptr [esi + 0x34], ebx
// 007e748f  c6463901             mov byte ptr [esi + 0x39], 1
// 007e7493  8bc6                 mov eax, esi
// 007e7495  5e                   pop esi
// 007e7496  5b                   pop ebx
// 007e7497  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ??0CXTTreeBase@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
