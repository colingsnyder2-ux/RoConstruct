// from server: 100% by auto
// roc 2011-06 005b1fb0  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005b1fb0
//
// 005b1fb0  8b442404             mov eax, dword ptr [esp + 4]
// 005b1fb4  83f850               cmp eax, 0x50
// 005b1fb7  7722                 ja 0x5b1fdb
// 005b1fb9  0fb688f81f5b00       movzx ecx, byte ptr [eax + 0x5b1ff8]
// 005b1fc0  ff248de81f5b00       jmp dword ptr [ecx*4 + 0x5b1fe8]
// 005b1fc7  680e000780           push 0x8007000e
// 005b1fcc  e8cf15e5ff           call 0x4035a0
// 005b1fd1  6857000780           push 0x80070057
// 005b1fd6  e8c515e5ff           call 0x4035a0
// 005b1fdb  6805400080           push 0x80004005
// 005b1fe0  e8bb15e5ff           call 0x4035a0
// 005b1fe5  c3                   ret 
// 005b1fe6  8bff                 mov edi, edi
// 005b1fe8  e51f                 in eax, 0x1f
// 005b1fea  5b                   pop ebx
// 005b1feb  00c7                 add bh, al
// 005b1fed  1f                   pop ds
// 005b1fee  5b                   pop ebx
// 005b1fef  00d1                 add cl, dl
// 005b1ff1  1f                   pop ds
// 005b1ff2  5b                   pop ebx
// 005b1ff3  00db                 add bl, bl
// 005b1ff5  1f                   pop ds
// 005b1ff6  5b                   pop ebx
// 005b1ff7  0000                 add byte ptr [eax], al
// 005b1ff9  0303                 add eax, dword ptr [ebx]
// 005b1ffb  0303                 add eax, dword ptr [ebx]
// 005b1ffd  0303                 add eax, dword ptr [ebx]
// 005b1fff  0303                 add eax, dword ptr [ebx]
// 005b2001  0303                 add eax, dword ptr [ebx]
// 005b2003  0301                 add eax, dword ptr [ecx]
// 005b2005  0303                 add eax, dword ptr [ebx]
// 005b2007  0303                 add eax, dword ptr [ebx]
// 005b2009  0303                 add eax, dword ptr [ebx]
// 005b200b  0303                 add eax, dword ptr [ebx]
// 005b200d  0302                 add eax, dword ptr [edx]
// 005b200f  0303                 add eax, dword ptr [ebx]
// 005b2011  0303                 add eax, dword ptr [ebx]
// 005b2013  0303                 add eax, dword ptr [ebx]
// 005b2015  0303                 add eax, dword ptr [ebx]
// 005b2017  0303                 add eax, dword ptr [ebx]
// 005b2019  0302                 add eax, dword ptr [edx]
// 005b201b  0303                 add eax, dword ptr [ebx]
// 005b201d  0303                 add eax, dword ptr [ebx]
// 005b201f  0303                 add eax, dword ptr [ebx]
// 005b2021  0303                 add eax, dword ptr [ebx]
// 005b2023  0303                 add eax, dword ptr [ebx]
// 005b2025  0303                 add eax, dword ptr [ebx]
// 005b2027  0303                 add eax, dword ptr [ebx]
// 005b2029  0303                 add eax, dword ptr [ebx]
// 005b202b  0303                 add eax, dword ptr [ebx]
// 005b202d  0303                 add eax, dword ptr [ebx]
// 005b202f  0303                 add eax, dword ptr [ebx]
// 005b2031  0303                 add eax, dword ptr [ebx]
// 005b2033  0303                 add eax, dword ptr [ebx]
// 005b2035  0303                 add eax, dword ptr [ebx]
// 005b2037  0303                 add eax, dword ptr [ebx]
// 005b2039  0303                 add eax, dword ptr [ebx]
// 005b203b  0303                 add eax, dword ptr [ebx]
// 005b203d  0303                 add eax, dword ptr [ebx]
// 005b203f  0303                 add eax, dword ptr [ebx]
// 005b2041  0303                 add eax, dword ptr [ebx]
// 005b2043  0303                 add eax, dword ptr [ebx]
// 005b2045  0303                 add eax, dword ptr [ebx]
// 005b2047  0300                 add eax, dword ptr [eax]
// library mfc-9.0/atlmfc\src\mfc\appcore.cpp (function ?AtlCrtErrorCheck@ATL@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/appcore.cpp
