// from server: 100% by auto
// roc 2010-06 007bd2f0  unit: CXTPCommandBar  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bd2f0
//
// 007bd2f0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007bd2f4  d9e8                 fld1 
// 007bd2f6  dd442408             fld qword ptr [esp + 8]
// 007bd2fa  8bc1                 mov eax, ecx
// 007bd2fc  c1e810               shr eax, 0x10
// 007bd2ff  dce9                 fsub st(1), st(0)
// 007bd301  dc0d8076a000         fmul qword ptr [0xa07680]
// 007bd307  0fb6d0               movzx edx, al
// 007bd30a  89542404             mov dword ptr [esp + 4], edx
// 007bd30e  db442404             fild dword ptr [esp + 4]
// 007bd312  d97c2404             fnstcw word ptr [esp + 4]
// 007bd316  0fb7442404           movzx eax, word ptr [esp + 4]
// 007bd31b  d8ca                 fmul st(2)
// 007bd31d  0d000c0000           or eax, 0xc00
// 007bd322  89442408             mov dword ptr [esp + 8], eax
// 007bd326  d8c1                 fadd st(1)
// 007bd328  d96c2408             fldcw word ptr [esp + 8]
// 007bd32c  db5c2408             fistp dword ptr [esp + 8]
// 007bd330  0fb6442408           movzx eax, byte ptr [esp + 8]
// 007bd335  0fb6d0               movzx edx, al
// 007bd338  d96c2404             fldcw word ptr [esp + 4]
// 007bd33c  8bc1                 mov eax, ecx
// 007bd33e  c1e808               shr eax, 8
// 007bd341  0fb6c0               movzx eax, al
// 007bd344  89442404             mov dword ptr [esp + 4], eax
// 007bd348  db442404             fild dword ptr [esp + 4]
// 007bd34c  0fb6c9               movzx ecx, cl
// 007bd34f  d97c2404             fnstcw word ptr [esp + 4]
// 007bd353  0fb7442404           movzx eax, word ptr [esp + 4]
// 007bd358  d8ca                 fmul st(2)
// 007bd35a  0d000c0000           or eax, 0xc00
// 007bd35f  89442408             mov dword ptr [esp + 8], eax
// 007bd363  d8c1                 fadd st(1)
// 007bd365  c1e208               shl edx, 8
// 007bd368  d96c2408             fldcw word ptr [esp + 8]
// 007bd36c  db5c2408             fistp dword ptr [esp + 8]
// 007bd370  0fb6442408           movzx eax, byte ptr [esp + 8]
// 007bd375  0bd0                 or edx, eax
// 007bd377  c1e208               shl edx, 8
// 007bd37a  d96c2404             fldcw word ptr [esp + 4]
// 007bd37e  894c2404             mov dword ptr [esp + 4], ecx
// 007bd382  db442404             fild dword ptr [esp + 4]
// 007bd386  d97c2404             fnstcw word ptr [esp + 4]
// 007bd38a  deca                 fmulp st(2)
// 007bd38c  0fb7442404           movzx eax, word ptr [esp + 4]
// 007bd391  0d000c0000           or eax, 0xc00
// 007bd396  89442408             mov dword ptr [esp + 8], eax
// 007bd39a  dec1                 faddp st(1)
// 007bd39c  d96c2408             fldcw word ptr [esp + 8]
// 007bd3a0  db5c2408             fistp dword ptr [esp + 8]
// 007bd3a4  0fb6442408           movzx eax, byte ptr [esp + 8]
// 007bd3a9  0fb6c8               movzx ecx, al
// 007bd3ac  d96c2404             fldcw word ptr [esp + 4]
// 007bd3b0  0bd1                 or edx, ecx
// 007bd3b2  8bc2                 mov eax, edx
// 007bd3b4  c20c00               ret 0xc
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?LightenColor@CXTPImageManagerIcon@@AAEKKN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
