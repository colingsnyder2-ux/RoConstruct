// from server: 100% by auto
// roc 2009-06 007541f0  unit: CXTPReportSelectedRows  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007541f0
//
// 007541f0  53                   push ebx
// 007541f1  55                   push ebp
// 007541f2  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 007541f6  56                   push esi
// 007541f7  8b742418             mov esi, dword ptr [esp + 0x18]
// 007541fb  33c9                 xor ecx, ecx
// 007541fd  83fe64               cmp esi, 0x64
// 00754200  0f9dc1               setge cl
// 00754203  57                   push edi
// 00754204  49                   dec ecx
// 00754205  81e17cfcffff         and ecx, 0xfffffc7c
// 0075420b  81c1e8030000         add ecx, 0x3e8
// 00754211  8bc1                 mov eax, ecx
// 00754213  99                   cdq 
// 00754214  2bc2                 sub eax, edx
// 00754216  8bd8                 mov ebx, eax
// 00754218  8bc5                 mov eax, ebp
// 0075421a  c1e810               shr eax, 0x10
// 0075421d  0fb6d0               movzx edx, al
// 00754220  8b442414             mov eax, dword ptr [esp + 0x14]
// 00754224  c1e810               shr eax, 0x10
// 00754227  0fb6c0               movzx eax, al
// 0075422a  0fafc6               imul eax, esi
// 0075422d  8bf9                 mov edi, ecx
// 0075422f  2bfe                 sub edi, esi
// 00754231  0fafd7               imul edx, edi
// 00754234  d1fb                 sar ebx, 1
// 00754236  03d3                 add edx, ebx
// 00754238  03c2                 add eax, edx
// 0075423a  99                   cdq 
// 0075423b  f7f9                 idiv ecx
// 0075423d  8bd5                 mov edx, ebp
// 0075423f  c1ea08               shr edx, 8
// 00754242  0fb6d2               movzx edx, dl
// 00754245  0fafd7               imul edx, edi
// 00754248  03d3                 add edx, ebx
// 0075424a  0fb66c2418           movzx ebp, byte ptr [esp + 0x18]
// 0075424f  0fafef               imul ebp, edi
// 00754252  0fb6c0               movzx eax, al
// 00754255  c1e008               shl eax, 8
// 00754258  8944241c             mov dword ptr [esp + 0x1c], eax
// 0075425c  8b442414             mov eax, dword ptr [esp + 0x14]
// 00754260  c1e808               shr eax, 8
// 00754263  0fb6c0               movzx eax, al
// 00754266  0fafc6               imul eax, esi
// 00754269  03c2                 add eax, edx
// 0075426b  99                   cdq 
// 0075426c  f7f9                 idiv ecx
// 0075426e  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00754272  03eb                 add ebp, ebx
// 00754274  5f                   pop edi
// 00754275  0fb6c0               movzx eax, al
// 00754278  0bd0                 or edx, eax
// 0075427a  0fb6442410           movzx eax, byte ptr [esp + 0x10]
// 0075427f  0fafc6               imul eax, esi
// 00754282  03c5                 add eax, ebp
// 00754284  c1e208               shl edx, 8
// 00754287  89542410             mov dword ptr [esp + 0x10], edx
// 0075428b  99                   cdq 
// 0075428c  f7f9                 idiv ecx
// 0075428e  5e                   pop esi
// 0075428f  5d                   pop ebp
// 00754290  5b                   pop ebx
// 00754291  0fb6c8               movzx ecx, al
// 00754294  8b442404             mov eax, dword ptr [esp + 4]
// 00754298  0bc1                 or eax, ecx
// 0075429a  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?LightColor@CXTPColorManager@@QBEKKKH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
