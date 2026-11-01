// from server: 100% by auto
// roc 2009-12 007fe920  unit: CXTPPaintManager  size: 289 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fe920
//
// 007fe920  51                   push ecx
// 007fe921  d9ee                 fldz 
// 007fe923  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007fe927  dd44241c             fld qword ptr [esp + 0x1c]
// 007fe92b  d8d1                 fcom st(1)
// 007fe92d  dfe0                 fnstsw ax
// 007fe92f  ddd9                 fstp st(1)
// 007fe931  f6c405               test ah, 5
// 007fe934  7a04                 jp 0x7fe93a
// 007fe936  d9e0                 fchs 
// 007fe938  eb20                 jmp 0x7fe95a
// 007fe93a  8b442410             mov eax, dword ptr [esp + 0x10]
// 007fe93e  ddd8                 fstp st(0)
// 007fe940  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007fe944  8b542408             mov edx, dword ptr [esp + 8]
// 007fe948  50                   push eax
// 007fe949  8b4204               mov eax, dword ptr [edx + 4]
// 007fe94c  51                   push ecx
// 007fe94d  50                   push eax
// 007fe94e  ff1518b19800         call dword ptr [0x98b118]
// 007fe954  dd44241c             fld qword ptr [esp + 0x1c]
// 007fe958  8bc8                 mov ecx, eax
// 007fe95a  8b442414             mov eax, dword ptr [esp + 0x14]
// 007fe95e  8bd0                 mov edx, eax
// 007fe960  56                   push esi
// 007fe961  c1ea10               shr edx, 0x10
// 007fe964  0fb6f2               movzx esi, dl
// 007fe967  8bd0                 mov edx, eax
// 007fe969  57                   push edi
// 007fe96a  0fb6f8               movzx edi, al
// 007fe96d  8bc1                 mov eax, ecx
// 007fe96f  c1e810               shr eax, 0x10
// 007fe972  0fb6c0               movzx eax, al
// 007fe975  2bc6                 sub eax, esi
// 007fe977  89442420             mov dword ptr [esp + 0x20], eax
// 007fe97b  8974241c             mov dword ptr [esp + 0x1c], esi
// 007fe97f  c1ea08               shr edx, 8
// 007fe982  db442420             fild dword ptr [esp + 0x20]
// 007fe986  0fb6d2               movzx edx, dl
// 007fe989  d97c2420             fnstcw word ptr [esp + 0x20]
// 007fe98d  d8c9                 fmul st(1)
// 007fe98f  0fb7442420           movzx eax, word ptr [esp + 0x20]
// 007fe994  da44241c             fiadd dword ptr [esp + 0x1c]
// 007fe998  0d000c0000           or eax, 0xc00
// 007fe99d  8944241c             mov dword ptr [esp + 0x1c], eax
// 007fe9a1  d96c241c             fldcw word ptr [esp + 0x1c]
// 007fe9a5  89542424             mov dword ptr [esp + 0x24], edx
// 007fe9a9  897c2408             mov dword ptr [esp + 8], edi
// 007fe9ad  db5c241c             fistp dword ptr [esp + 0x1c]
// 007fe9b1  8a44241c             mov al, byte ptr [esp + 0x1c]
// 007fe9b5  0fb6f0               movzx esi, al
// 007fe9b8  8bc1                 mov eax, ecx
// 007fe9ba  d96c2420             fldcw word ptr [esp + 0x20]
// 007fe9be  c1e808               shr eax, 8
// 007fe9c1  0fb6c0               movzx eax, al
// 007fe9c4  2bc2                 sub eax, edx
// 007fe9c6  89442420             mov dword ptr [esp + 0x20], eax
// 007fe9ca  0fb6c9               movzx ecx, cl
// 007fe9cd  db442420             fild dword ptr [esp + 0x20]
// 007fe9d1  d97c2420             fnstcw word ptr [esp + 0x20]
// 007fe9d5  0fb7442420           movzx eax, word ptr [esp + 0x20]
// 007fe9da  d8c9                 fmul st(1)
// 007fe9dc  0d000c0000           or eax, 0xc00
// 007fe9e1  8944241c             mov dword ptr [esp + 0x1c], eax
// 007fe9e5  2bcf                 sub ecx, edi
// 007fe9e7  da442424             fiadd dword ptr [esp + 0x24]
// 007fe9eb  c1e608               shl esi, 8
// 007fe9ee  5f                   pop edi
// 007fe9ef  d96c2418             fldcw word ptr [esp + 0x18]
// 007fe9f3  db5c2418             fistp dword ptr [esp + 0x18]
// 007fe9f7  0fb6542418           movzx edx, byte ptr [esp + 0x18]
// 007fe9fc  0fb6c2               movzx eax, dl
// 007fe9ff  d96c241c             fldcw word ptr [esp + 0x1c]
// 007fea03  0bf0                 or esi, eax
// 007fea05  894c241c             mov dword ptr [esp + 0x1c], ecx
// 007fea09  c1e608               shl esi, 8
// 007fea0c  db44241c             fild dword ptr [esp + 0x1c]
// 007fea10  d97c241c             fnstcw word ptr [esp + 0x1c]
// 007fea14  dec9                 fmulp st(1)
// 007fea16  0fb744241c           movzx eax, word ptr [esp + 0x1c]
// 007fea1b  0d000c0000           or eax, 0xc00
// 007fea20  89442418             mov dword ptr [esp + 0x18], eax
// 007fea24  da442404             fiadd dword ptr [esp + 4]
// 007fea28  d96c2418             fldcw word ptr [esp + 0x18]
// 007fea2c  db5c2418             fistp dword ptr [esp + 0x18]
// 007fea30  0fb6542418           movzx edx, byte ptr [esp + 0x18]
// 007fea35  0fb6c2               movzx eax, dl
// 007fea38  d96c241c             fldcw word ptr [esp + 0x1c]
// 007fea3c  0bc6                 or eax, esi
// 007fea3e  5e                   pop esi
// 007fea3f  59                   pop ecx
// 007fea40  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?Mix@@YAKPAVCDC@@HHKKN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
