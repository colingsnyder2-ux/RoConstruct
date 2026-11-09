// from server: 100% by auto
// roc 2009-06 005d9150  unit: VAuthoringSettings::?$BoundPropGetSet  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d9150
//
// 005d9150  56                   push esi
// 005d9151  8bf1                 mov esi, ecx
// 005d9153  8b0e                 mov ecx, dword ptr [esi]
// 005d9155  8379f400             cmp dword ptr [ecx - 0xc], 0
// 005d9159  8d41f0               lea eax, [ecx - 0x10]
// 005d915c  57                   push edi
// 005d915d  8b38                 mov edi, dword ptr [eax]
// 005d915f  744c                 je 0x5d91ad
// 005d9161  83780c00             cmp dword ptr [eax + 0xc], 0
// 005d9165  8d500c               lea edx, [eax + 0xc]
// 005d9168  7d1f                 jge 0x5d9189
// 005d916a  8379f800             cmp dword ptr [ecx - 8], 0
// 005d916e  7d0a                 jge 0x5d917a
// 005d9170  6857000780           push 0x80070057
// 005d9175  e8369de2ff           call 0x402eb0
// 005d917a  c741f400000000       mov dword ptr [ecx - 0xc], 0
// 005d9181  8b06                 mov eax, dword ptr [esi]
// 005d9183  5f                   pop edi
// 005d9184  c60000               mov byte ptr [eax], 0
// 005d9187  5e                   pop esi
// 005d9188  c3                   ret 
// 005d9189  83c9ff               or ecx, 0xffffffff
// 005d918c  f00fc10a             lock xadd dword ptr [edx], ecx
// 005d9190  49                   dec ecx
// 005d9191  85c9                 test ecx, ecx
// 005d9193  7f0a                 jg 0x5d919f
// 005d9195  8b08                 mov ecx, dword ptr [eax]
// 005d9197  8b11                 mov edx, dword ptr [ecx]
// 005d9199  50                   push eax
// 005d919a  8b4204               mov eax, dword ptr [edx + 4]
// 005d919d  ffd0                 call eax
// 005d919f  8b17                 mov edx, dword ptr [edi]
// 005d91a1  8b420c               mov eax, dword ptr [edx + 0xc]
// 005d91a4  8bcf                 mov ecx, edi
// 005d91a6  ffd0                 call eax
// 005d91a8  83c010               add eax, 0x10
// 005d91ab  8906                 mov dword ptr [esi], eax
// 005d91ad  5f                   pop edi
// 005d91ae  5e                   pop esi
// 005d91af  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ?Empty@?$CSimpleStringT@D$0A@@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
