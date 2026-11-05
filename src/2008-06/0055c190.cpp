// from server: 100% by auto
// roc 2008-06 0055c190  unit: RBX::VInstance::?$SignalDesc  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055c190
//
// 0055c190  56                   push esi
// 0055c191  8bf1                 mov esi, ecx
// 0055c193  8b0e                 mov ecx, dword ptr [esi]
// 0055c195  8379f400             cmp dword ptr [ecx - 0xc], 0
// 0055c199  8d41f0               lea eax, [ecx - 0x10]
// 0055c19c  57                   push edi
// 0055c19d  8b38                 mov edi, dword ptr [eax]
// 0055c19f  744c                 je 0x55c1ed
// 0055c1a1  83780c00             cmp dword ptr [eax + 0xc], 0
// 0055c1a5  8d500c               lea edx, [eax + 0xc]
// 0055c1a8  7d1f                 jge 0x55c1c9
// 0055c1aa  8379f800             cmp dword ptr [ecx - 8], 0
// 0055c1ae  7d0a                 jge 0x55c1ba
// 0055c1b0  6857000780           push 0x80070057
// 0055c1b5  e8464eeaff           call 0x401000
// 0055c1ba  c741f400000000       mov dword ptr [ecx - 0xc], 0
// 0055c1c1  8b06                 mov eax, dword ptr [esi]
// 0055c1c3  5f                   pop edi
// 0055c1c4  c60000               mov byte ptr [eax], 0
// 0055c1c7  5e                   pop esi
// 0055c1c8  c3                   ret 
// 0055c1c9  83c9ff               or ecx, 0xffffffff
// 0055c1cc  f00fc10a             lock xadd dword ptr [edx], ecx
// 0055c1d0  49                   dec ecx
// 0055c1d1  85c9                 test ecx, ecx
// 0055c1d3  7f0a                 jg 0x55c1df
// 0055c1d5  8b08                 mov ecx, dword ptr [eax]
// 0055c1d7  8b11                 mov edx, dword ptr [ecx]
// 0055c1d9  50                   push eax
// 0055c1da  8b4204               mov eax, dword ptr [edx + 4]
// 0055c1dd  ffd0                 call eax
// 0055c1df  8b17                 mov edx, dword ptr [edi]
// 0055c1e1  8b420c               mov eax, dword ptr [edx + 0xc]
// 0055c1e4  8bcf                 mov ecx, edi
// 0055c1e6  ffd0                 call eax
// 0055c1e8  83c010               add eax, 0x10
// 0055c1eb  8906                 mov dword ptr [esi], eax
// 0055c1ed  5f                   pop edi
// 0055c1ee  5e                   pop esi
// 0055c1ef  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ?Empty@?$CSimpleStringT@D$0A@@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
