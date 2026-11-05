// from server: 100% by auto
// roc 2010-06 007e3200  unit: CXTPReportSelectedRows  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e3200
//
// 007e3200  53                   push ebx
// 007e3201  55                   push ebp
// 007e3202  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 007e3206  56                   push esi
// 007e3207  8b742418             mov esi, dword ptr [esp + 0x18]
// 007e320b  33c9                 xor ecx, ecx
// 007e320d  83fe64               cmp esi, 0x64
// 007e3210  0f9dc1               setge cl
// 007e3213  57                   push edi
// 007e3214  49                   dec ecx
// 007e3215  81e17cfcffff         and ecx, 0xfffffc7c
// 007e321b  81c1e8030000         add ecx, 0x3e8
// 007e3221  8bc1                 mov eax, ecx
// 007e3223  99                   cdq 
// 007e3224  2bc2                 sub eax, edx
// 007e3226  8bd8                 mov ebx, eax
// 007e3228  8bc5                 mov eax, ebp
// 007e322a  c1e810               shr eax, 0x10
// 007e322d  0fb6d0               movzx edx, al
// 007e3230  8b442414             mov eax, dword ptr [esp + 0x14]
// 007e3234  c1e810               shr eax, 0x10
// 007e3237  0fb6c0               movzx eax, al
// 007e323a  0fafc6               imul eax, esi
// 007e323d  8bf9                 mov edi, ecx
// 007e323f  2bfe                 sub edi, esi
// 007e3241  0fafd7               imul edx, edi
// 007e3244  d1fb                 sar ebx, 1
// 007e3246  03d3                 add edx, ebx
// 007e3248  03c2                 add eax, edx
// 007e324a  99                   cdq 
// 007e324b  f7f9                 idiv ecx
// 007e324d  8bd5                 mov edx, ebp
// 007e324f  c1ea08               shr edx, 8
// 007e3252  0fb6d2               movzx edx, dl
// 007e3255  0fafd7               imul edx, edi
// 007e3258  03d3                 add edx, ebx
// 007e325a  0fb66c2418           movzx ebp, byte ptr [esp + 0x18]
// 007e325f  0fafef               imul ebp, edi
// 007e3262  0fb6c0               movzx eax, al
// 007e3265  c1e008               shl eax, 8
// 007e3268  8944241c             mov dword ptr [esp + 0x1c], eax
// 007e326c  8b442414             mov eax, dword ptr [esp + 0x14]
// 007e3270  c1e808               shr eax, 8
// 007e3273  0fb6c0               movzx eax, al
// 007e3276  0fafc6               imul eax, esi
// 007e3279  03c2                 add eax, edx
// 007e327b  99                   cdq 
// 007e327c  f7f9                 idiv ecx
// 007e327e  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007e3282  03eb                 add ebp, ebx
// 007e3284  5f                   pop edi
// 007e3285  0fb6c0               movzx eax, al
// 007e3288  0bd0                 or edx, eax
// 007e328a  0fb6442410           movzx eax, byte ptr [esp + 0x10]
// 007e328f  0fafc6               imul eax, esi
// 007e3292  03c5                 add eax, ebp
// 007e3294  c1e208               shl edx, 8
// 007e3297  89542410             mov dword ptr [esp + 0x10], edx
// 007e329b  99                   cdq 
// 007e329c  f7f9                 idiv ecx
// 007e329e  5e                   pop esi
// 007e329f  5d                   pop ebp
// 007e32a0  5b                   pop ebx
// 007e32a1  0fb6c8               movzx ecx, al
// 007e32a4  8b442404             mov eax, dword ptr [esp + 4]
// 007e32a8  0bc1                 or eax, ecx
// 007e32aa  c20c00               ret 0xc
// library xtp-13.2.1/Source\Common\XTPColorManager.cpp (function ?LightColor@CXTPColorManager@@QBEKKKH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPColorManager.cpp
