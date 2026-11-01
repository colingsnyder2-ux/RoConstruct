// from server: 100% by auto
// roc 2009-12 0082f050  unit: CXTPReportSelectedRows  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082f050
//
// 0082f050  53                   push ebx
// 0082f051  55                   push ebp
// 0082f052  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0082f056  56                   push esi
// 0082f057  8b742418             mov esi, dword ptr [esp + 0x18]
// 0082f05b  33c9                 xor ecx, ecx
// 0082f05d  83fe64               cmp esi, 0x64
// 0082f060  0f9dc1               setge cl
// 0082f063  57                   push edi
// 0082f064  49                   dec ecx
// 0082f065  81e17cfcffff         and ecx, 0xfffffc7c
// 0082f06b  81c1e8030000         add ecx, 0x3e8
// 0082f071  8bc1                 mov eax, ecx
// 0082f073  99                   cdq 
// 0082f074  2bc2                 sub eax, edx
// 0082f076  8bd8                 mov ebx, eax
// 0082f078  8bc5                 mov eax, ebp
// 0082f07a  c1e810               shr eax, 0x10
// 0082f07d  0fb6d0               movzx edx, al
// 0082f080  8b442414             mov eax, dword ptr [esp + 0x14]
// 0082f084  c1e810               shr eax, 0x10
// 0082f087  0fb6c0               movzx eax, al
// 0082f08a  0fafc6               imul eax, esi
// 0082f08d  8bf9                 mov edi, ecx
// 0082f08f  2bfe                 sub edi, esi
// 0082f091  0fafd7               imul edx, edi
// 0082f094  d1fb                 sar ebx, 1
// 0082f096  03d3                 add edx, ebx
// 0082f098  03c2                 add eax, edx
// 0082f09a  99                   cdq 
// 0082f09b  f7f9                 idiv ecx
// 0082f09d  8bd5                 mov edx, ebp
// 0082f09f  c1ea08               shr edx, 8
// 0082f0a2  0fb6d2               movzx edx, dl
// 0082f0a5  0fafd7               imul edx, edi
// 0082f0a8  03d3                 add edx, ebx
// 0082f0aa  0fb66c2418           movzx ebp, byte ptr [esp + 0x18]
// 0082f0af  0fafef               imul ebp, edi
// 0082f0b2  0fb6c0               movzx eax, al
// 0082f0b5  c1e008               shl eax, 8
// 0082f0b8  8944241c             mov dword ptr [esp + 0x1c], eax
// 0082f0bc  8b442414             mov eax, dword ptr [esp + 0x14]
// 0082f0c0  c1e808               shr eax, 8
// 0082f0c3  0fb6c0               movzx eax, al
// 0082f0c6  0fafc6               imul eax, esi
// 0082f0c9  03c2                 add eax, edx
// 0082f0cb  99                   cdq 
// 0082f0cc  f7f9                 idiv ecx
// 0082f0ce  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0082f0d2  03eb                 add ebp, ebx
// 0082f0d4  5f                   pop edi
// 0082f0d5  0fb6c0               movzx eax, al
// 0082f0d8  0bd0                 or edx, eax
// 0082f0da  0fb6442410           movzx eax, byte ptr [esp + 0x10]
// 0082f0df  0fafc6               imul eax, esi
// 0082f0e2  03c5                 add eax, ebp
// 0082f0e4  c1e208               shl edx, 8
// 0082f0e7  89542410             mov dword ptr [esp + 0x10], edx
// 0082f0eb  99                   cdq 
// 0082f0ec  f7f9                 idiv ecx
// 0082f0ee  5e                   pop esi
// 0082f0ef  5d                   pop ebp
// 0082f0f0  5b                   pop ebx
// 0082f0f1  0fb6c8               movzx ecx, al
// 0082f0f4  8b442404             mov eax, dword ptr [esp + 4]
// 0082f0f8  0bc1                 or eax, ecx
// 0082f0fa  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?LightColor@CXTPColorManager@@QBEKKKH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
