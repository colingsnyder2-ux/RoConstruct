// from server: 100% by auto
// roc 2007-08 00545930  unit: RBX::MD5HasherImpl  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00545930
//
// 00545930  56                   push esi
// 00545931  8bf1                 mov esi, ecx
// 00545933  8b0e                 mov ecx, dword ptr [esi]
// 00545935  8379f400             cmp dword ptr [ecx - 0xc], 0
// 00545939  8d41f0               lea eax, [ecx - 0x10]
// 0054593c  57                   push edi
// 0054593d  8b38                 mov edi, dword ptr [eax]
// 0054593f  744c                 je 0x54598d
// 00545941  83780c00             cmp dword ptr [eax + 0xc], 0
// 00545945  8d500c               lea edx, [eax + 0xc]
// 00545948  7d1f                 jge 0x545969
// 0054594a  8379f800             cmp dword ptr [ecx - 8], 0
// 0054594e  7d0a                 jge 0x54595a
// 00545950  6857000780           push 0x80070057
// 00545955  e8a6b6ebff           call 0x401000
// 0054595a  c741f400000000       mov dword ptr [ecx - 0xc], 0
// 00545961  8b06                 mov eax, dword ptr [esi]
// 00545963  5f                   pop edi
// 00545964  c60000               mov byte ptr [eax], 0
// 00545967  5e                   pop esi
// 00545968  c3                   ret 
// 00545969  83c9ff               or ecx, 0xffffffff
// 0054596c  f00fc10a             lock xadd dword ptr [edx], ecx
// 00545970  49                   dec ecx
// 00545971  85c9                 test ecx, ecx
// 00545973  7f0a                 jg 0x54597f
// 00545975  8b08                 mov ecx, dword ptr [eax]
// 00545977  8b11                 mov edx, dword ptr [ecx]
// 00545979  50                   push eax
// 0054597a  8b4204               mov eax, dword ptr [edx + 4]
// 0054597d  ffd0                 call eax
// 0054597f  8b17                 mov edx, dword ptr [edi]
// 00545981  8b420c               mov eax, dword ptr [edx + 0xc]
// 00545984  8bcf                 mov ecx, edi
// 00545986  ffd0                 call eax
// 00545988  83c010               add eax, 0x10
// 0054598b  8906                 mov dword ptr [esi], eax
// 0054598d  5f                   pop edi
// 0054598e  5e                   pop esi
// 0054598f  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?Empty@?$CSimpleStringT@D$0A@@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
