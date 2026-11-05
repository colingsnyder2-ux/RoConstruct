// from server: 100% by auto
// roc 2010-06 005a0e90  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005a0e90
//
// 005a0e90  56                   push esi
// 005a0e91  8bf1                 mov esi, ecx
// 005a0e93  8b0e                 mov ecx, dword ptr [esi]
// 005a0e95  8379f400             cmp dword ptr [ecx - 0xc], 0
// 005a0e99  8d41f0               lea eax, [ecx - 0x10]
// 005a0e9c  57                   push edi
// 005a0e9d  8b38                 mov edi, dword ptr [eax]
// 005a0e9f  744c                 je 0x5a0eed
// 005a0ea1  83780c00             cmp dword ptr [eax + 0xc], 0
// 005a0ea5  8d500c               lea edx, [eax + 0xc]
// 005a0ea8  7d1f                 jge 0x5a0ec9
// 005a0eaa  8379f800             cmp dword ptr [ecx - 8], 0
// 005a0eae  7d0a                 jge 0x5a0eba
// 005a0eb0  6857000780           push 0x80070057
// 005a0eb5  e8161de6ff           call 0x402bd0
// 005a0eba  c741f400000000       mov dword ptr [ecx - 0xc], 0
// 005a0ec1  8b06                 mov eax, dword ptr [esi]
// 005a0ec3  5f                   pop edi
// 005a0ec4  c60000               mov byte ptr [eax], 0
// 005a0ec7  5e                   pop esi
// 005a0ec8  c3                   ret 
// 005a0ec9  83c9ff               or ecx, 0xffffffff
// 005a0ecc  f00fc10a             lock xadd dword ptr [edx], ecx
// 005a0ed0  49                   dec ecx
// 005a0ed1  85c9                 test ecx, ecx
// 005a0ed3  7f0a                 jg 0x5a0edf
// 005a0ed5  8b08                 mov ecx, dword ptr [eax]
// 005a0ed7  8b11                 mov edx, dword ptr [ecx]
// 005a0ed9  50                   push eax
// 005a0eda  8b4204               mov eax, dword ptr [edx + 4]
// 005a0edd  ffd0                 call eax
// 005a0edf  8b17                 mov edx, dword ptr [edi]
// 005a0ee1  8b420c               mov eax, dword ptr [edx + 0xc]
// 005a0ee4  8bcf                 mov ecx, edi
// 005a0ee6  ffd0                 call eax
// 005a0ee8  83c010               add eax, 0x10
// 005a0eeb  8906                 mov dword ptr [esi], eax
// 005a0eed  5f                   pop edi
// 005a0eee  5e                   pop esi
// 005a0eef  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ?Empty@?$CSimpleStringT@D$0A@@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
