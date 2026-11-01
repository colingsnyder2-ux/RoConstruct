// from server: 100% by auto
// roc 2009-12 00809150  unit: CXTPCommandBar  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809150
//
// 00809150  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00809154  d9e8                 fld1 
// 00809156  dd442408             fld qword ptr [esp + 8]
// 0080915a  8bc1                 mov eax, ecx
// 0080915c  c1e810               shr eax, 0x10
// 0080915f  dce9                 fsub st(1), st(0)
// 00809161  dc0de0689a00         fmul qword ptr [0x9a68e0]
// 00809167  0fb6d0               movzx edx, al
// 0080916a  89542404             mov dword ptr [esp + 4], edx
// 0080916e  db442404             fild dword ptr [esp + 4]
// 00809172  d97c2404             fnstcw word ptr [esp + 4]
// 00809176  0fb7442404           movzx eax, word ptr [esp + 4]
// 0080917b  d8ca                 fmul st(2)
// 0080917d  0d000c0000           or eax, 0xc00
// 00809182  89442408             mov dword ptr [esp + 8], eax
// 00809186  d8c1                 fadd st(1)
// 00809188  d96c2408             fldcw word ptr [esp + 8]
// 0080918c  db5c2408             fistp dword ptr [esp + 8]
// 00809190  0fb6442408           movzx eax, byte ptr [esp + 8]
// 00809195  0fb6d0               movzx edx, al
// 00809198  d96c2404             fldcw word ptr [esp + 4]
// 0080919c  8bc1                 mov eax, ecx
// 0080919e  c1e808               shr eax, 8
// 008091a1  0fb6c0               movzx eax, al
// 008091a4  89442404             mov dword ptr [esp + 4], eax
// 008091a8  db442404             fild dword ptr [esp + 4]
// 008091ac  0fb6c9               movzx ecx, cl
// 008091af  d97c2404             fnstcw word ptr [esp + 4]
// 008091b3  0fb7442404           movzx eax, word ptr [esp + 4]
// 008091b8  d8ca                 fmul st(2)
// 008091ba  0d000c0000           or eax, 0xc00
// 008091bf  89442408             mov dword ptr [esp + 8], eax
// 008091c3  d8c1                 fadd st(1)
// 008091c5  c1e208               shl edx, 8
// 008091c8  d96c2408             fldcw word ptr [esp + 8]
// 008091cc  db5c2408             fistp dword ptr [esp + 8]
// 008091d0  0fb6442408           movzx eax, byte ptr [esp + 8]
// 008091d5  0bd0                 or edx, eax
// 008091d7  c1e208               shl edx, 8
// 008091da  d96c2404             fldcw word ptr [esp + 4]
// 008091de  894c2404             mov dword ptr [esp + 4], ecx
// 008091e2  db442404             fild dword ptr [esp + 4]
// 008091e6  d97c2404             fnstcw word ptr [esp + 4]
// 008091ea  deca                 fmulp st(2)
// 008091ec  0fb7442404           movzx eax, word ptr [esp + 4]
// 008091f1  0d000c0000           or eax, 0xc00
// 008091f6  89442408             mov dword ptr [esp + 8], eax
// 008091fa  dec1                 faddp st(1)
// 008091fc  d96c2408             fldcw word ptr [esp + 8]
// 00809200  db5c2408             fistp dword ptr [esp + 8]
// 00809204  0fb6442408           movzx eax, byte ptr [esp + 8]
// 00809209  0fb6c8               movzx ecx, al
// 0080920c  d96c2404             fldcw word ptr [esp + 4]
// 00809210  0bd1                 or edx, ecx
// 00809212  8bc2                 mov eax, edx
// 00809214  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?LightenColor@CXTPImageManagerIcon@@AAEKKN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
