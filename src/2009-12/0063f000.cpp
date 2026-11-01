// from server: 100% by auto
// roc 2009-12 0063f000  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0063f000
//
// 0063f000  56                   push esi
// 0063f001  8bf1                 mov esi, ecx
// 0063f003  8b0e                 mov ecx, dword ptr [esi]
// 0063f005  8379f400             cmp dword ptr [ecx - 0xc], 0
// 0063f009  8d41f0               lea eax, [ecx - 0x10]
// 0063f00c  57                   push edi
// 0063f00d  8b38                 mov edi, dword ptr [eax]
// 0063f00f  744c                 je 0x63f05d
// 0063f011  83780c00             cmp dword ptr [eax + 0xc], 0
// 0063f015  8d500c               lea edx, [eax + 0xc]
// 0063f018  7d1f                 jge 0x63f039
// 0063f01a  8379f800             cmp dword ptr [ecx - 8], 0
// 0063f01e  7d0a                 jge 0x63f02a
// 0063f020  6857000780           push 0x80070057
// 0063f025  e8563bdcff           call 0x402b80
// 0063f02a  c741f400000000       mov dword ptr [ecx - 0xc], 0
// 0063f031  8b06                 mov eax, dword ptr [esi]
// 0063f033  5f                   pop edi
// 0063f034  c60000               mov byte ptr [eax], 0
// 0063f037  5e                   pop esi
// 0063f038  c3                   ret 
// 0063f039  83c9ff               or ecx, 0xffffffff
// 0063f03c  f00fc10a             lock xadd dword ptr [edx], ecx
// 0063f040  49                   dec ecx
// 0063f041  85c9                 test ecx, ecx
// 0063f043  7f0a                 jg 0x63f04f
// 0063f045  8b08                 mov ecx, dword ptr [eax]
// 0063f047  8b11                 mov edx, dword ptr [ecx]
// 0063f049  50                   push eax
// 0063f04a  8b4204               mov eax, dword ptr [edx + 4]
// 0063f04d  ffd0                 call eax
// 0063f04f  8b17                 mov edx, dword ptr [edi]
// 0063f051  8b420c               mov eax, dword ptr [edx + 0xc]
// 0063f054  8bcf                 mov ecx, edi
// 0063f056  ffd0                 call eax
// 0063f058  83c010               add eax, 0x10
// 0063f05b  8906                 mov dword ptr [esi], eax
// 0063f05d  5f                   pop edi
// 0063f05e  5e                   pop esi
// 0063f05f  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?Empty@?$CSimpleStringT@D$0A@@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
