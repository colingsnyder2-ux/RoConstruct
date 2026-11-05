// from server: 100% by auto
// roc 2007-03 00544f40  unit: seg_00540000  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00544f40
//
// 00544f40  56                   push esi
// 00544f41  8bf1                 mov esi, ecx
// 00544f43  8b0e                 mov ecx, dword ptr [esi]
// 00544f45  8379f400             cmp dword ptr [ecx - 0xc], 0
// 00544f49  8d41f0               lea eax, [ecx - 0x10]
// 00544f4c  57                   push edi
// 00544f4d  8b38                 mov edi, dword ptr [eax]
// 00544f4f  744c                 je 0x544f9d
// 00544f51  83780c00             cmp dword ptr [eax + 0xc], 0
// 00544f55  8d500c               lea edx, [eax + 0xc]
// 00544f58  7d1f                 jge 0x544f79
// 00544f5a  8379f800             cmp dword ptr [ecx - 8], 0
// 00544f5e  7d0a                 jge 0x544f6a
// 00544f60  6857000780           push 0x80070057
// 00544f65  e896c0ebff           call 0x401000
// 00544f6a  c741f400000000       mov dword ptr [ecx - 0xc], 0
// 00544f71  8b06                 mov eax, dword ptr [esi]
// 00544f73  5f                   pop edi
// 00544f74  c60000               mov byte ptr [eax], 0
// 00544f77  5e                   pop esi
// 00544f78  c3                   ret 
// 00544f79  83c9ff               or ecx, 0xffffffff
// 00544f7c  f00fc10a             lock xadd dword ptr [edx], ecx
// 00544f80  49                   dec ecx
// 00544f81  85c9                 test ecx, ecx
// 00544f83  7f0a                 jg 0x544f8f
// 00544f85  8b08                 mov ecx, dword ptr [eax]
// 00544f87  8b11                 mov edx, dword ptr [ecx]
// 00544f89  50                   push eax
// 00544f8a  8b4204               mov eax, dword ptr [edx + 4]
// 00544f8d  ffd0                 call eax
// 00544f8f  8b17                 mov edx, dword ptr [edi]
// 00544f91  8b420c               mov eax, dword ptr [edx + 0xc]
// 00544f94  8bcf                 mov ecx, edi
// 00544f96  ffd0                 call eax
// 00544f98  83c010               add eax, 0x10
// 00544f9b  8906                 mov dword ptr [esi], eax
// 00544f9d  5f                   pop edi
// 00544f9e  5e                   pop esi
// 00544f9f  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?Empty@?$CSimpleStringT@D$0A@@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
