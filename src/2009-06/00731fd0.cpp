// from server: 100% by auto
// roc 2009-06 00731fd0  unit: CXTPCommandBar  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00731fd0
//
// 00731fd0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00731fd4  d9e8                 fld1 
// 00731fd6  dd442408             fld qword ptr [esp + 8]
// 00731fda  8bc1                 mov eax, ecx
// 00731fdc  c1e810               shr eax, 0x10
// 00731fdf  dce9                 fsub st(1), st(0)
// 00731fe1  dc0d703b8b00         fmul qword ptr [0x8b3b70]
// 00731fe7  0fb6d0               movzx edx, al
// 00731fea  89542404             mov dword ptr [esp + 4], edx
// 00731fee  db442404             fild dword ptr [esp + 4]
// 00731ff2  d97c2404             fnstcw word ptr [esp + 4]
// 00731ff6  0fb7442404           movzx eax, word ptr [esp + 4]
// 00731ffb  d8ca                 fmul st(2)
// 00731ffd  0d000c0000           or eax, 0xc00
// 00732002  89442408             mov dword ptr [esp + 8], eax
// 00732006  d8c1                 fadd st(1)
// 00732008  d96c2408             fldcw word ptr [esp + 8]
// 0073200c  db5c2408             fistp dword ptr [esp + 8]
// 00732010  0fb6442408           movzx eax, byte ptr [esp + 8]
// 00732015  0fb6d0               movzx edx, al
// 00732018  d96c2404             fldcw word ptr [esp + 4]
// 0073201c  8bc1                 mov eax, ecx
// 0073201e  c1e808               shr eax, 8
// 00732021  0fb6c0               movzx eax, al
// 00732024  89442404             mov dword ptr [esp + 4], eax
// 00732028  db442404             fild dword ptr [esp + 4]
// 0073202c  0fb6c9               movzx ecx, cl
// 0073202f  d97c2404             fnstcw word ptr [esp + 4]
// 00732033  0fb7442404           movzx eax, word ptr [esp + 4]
// 00732038  d8ca                 fmul st(2)
// 0073203a  0d000c0000           or eax, 0xc00
// 0073203f  89442408             mov dword ptr [esp + 8], eax
// 00732043  d8c1                 fadd st(1)
// 00732045  c1e208               shl edx, 8
// 00732048  d96c2408             fldcw word ptr [esp + 8]
// 0073204c  db5c2408             fistp dword ptr [esp + 8]
// 00732050  0fb6442408           movzx eax, byte ptr [esp + 8]
// 00732055  0bd0                 or edx, eax
// 00732057  c1e208               shl edx, 8
// 0073205a  d96c2404             fldcw word ptr [esp + 4]
// 0073205e  894c2404             mov dword ptr [esp + 4], ecx
// 00732062  db442404             fild dword ptr [esp + 4]
// 00732066  d97c2404             fnstcw word ptr [esp + 4]
// 0073206a  deca                 fmulp st(2)
// 0073206c  0fb7442404           movzx eax, word ptr [esp + 4]
// 00732071  0d000c0000           or eax, 0xc00
// 00732076  89442408             mov dword ptr [esp + 8], eax
// 0073207a  dec1                 faddp st(1)
// 0073207c  d96c2408             fldcw word ptr [esp + 8]
// 00732080  db5c2408             fistp dword ptr [esp + 8]
// 00732084  0fb6442408           movzx eax, byte ptr [esp + 8]
// 00732089  0fb6c8               movzx ecx, al
// 0073208c  d96c2404             fldcw word ptr [esp + 4]
// 00732090  0bd1                 or edx, ecx
// 00732092  8bc2                 mov eax, edx
// 00732094  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?LightenColor@CXTPImageManagerIcon@@AAEKKN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
