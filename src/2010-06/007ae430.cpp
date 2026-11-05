// from server: 100% by auto
// roc 2010-06 007ae430  unit: CXTPPaintManager  size: 289 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ae430
//
// 007ae430  51                   push ecx
// 007ae431  d9ee                 fldz 
// 007ae433  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007ae437  dd44241c             fld qword ptr [esp + 0x1c]
// 007ae43b  d8d1                 fcom st(1)
// 007ae43d  dfe0                 fnstsw ax
// 007ae43f  ddd9                 fstp st(1)
// 007ae441  f6c405               test ah, 5
// 007ae444  7a04                 jp 0x7ae44a
// 007ae446  d9e0                 fchs 
// 007ae448  eb20                 jmp 0x7ae46a
// 007ae44a  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ae44e  ddd8                 fstp st(0)
// 007ae450  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007ae454  8b542408             mov edx, dword ptr [esp + 8]
// 007ae458  50                   push eax
// 007ae459  8b4204               mov eax, dword ptr [edx + 4]
// 007ae45c  51                   push ecx
// 007ae45d  50                   push eax
// 007ae45e  ff1560a19e00         call dword ptr [0x9ea160]
// 007ae464  dd44241c             fld qword ptr [esp + 0x1c]
// 007ae468  8bc8                 mov ecx, eax
// 007ae46a  8b442414             mov eax, dword ptr [esp + 0x14]
// 007ae46e  8bd0                 mov edx, eax
// 007ae470  56                   push esi
// 007ae471  c1ea10               shr edx, 0x10
// 007ae474  0fb6f2               movzx esi, dl
// 007ae477  8bd0                 mov edx, eax
// 007ae479  57                   push edi
// 007ae47a  0fb6f8               movzx edi, al
// 007ae47d  8bc1                 mov eax, ecx
// 007ae47f  c1e810               shr eax, 0x10
// 007ae482  0fb6c0               movzx eax, al
// 007ae485  2bc6                 sub eax, esi
// 007ae487  89442420             mov dword ptr [esp + 0x20], eax
// 007ae48b  8974241c             mov dword ptr [esp + 0x1c], esi
// 007ae48f  c1ea08               shr edx, 8
// 007ae492  db442420             fild dword ptr [esp + 0x20]
// 007ae496  0fb6d2               movzx edx, dl
// 007ae499  d97c2420             fnstcw word ptr [esp + 0x20]
// 007ae49d  d8c9                 fmul st(1)
// 007ae49f  0fb7442420           movzx eax, word ptr [esp + 0x20]
// 007ae4a4  da44241c             fiadd dword ptr [esp + 0x1c]
// 007ae4a8  0d000c0000           or eax, 0xc00
// 007ae4ad  8944241c             mov dword ptr [esp + 0x1c], eax
// 007ae4b1  d96c241c             fldcw word ptr [esp + 0x1c]
// 007ae4b5  89542424             mov dword ptr [esp + 0x24], edx
// 007ae4b9  897c2408             mov dword ptr [esp + 8], edi
// 007ae4bd  db5c241c             fistp dword ptr [esp + 0x1c]
// 007ae4c1  8a44241c             mov al, byte ptr [esp + 0x1c]
// 007ae4c5  0fb6f0               movzx esi, al
// 007ae4c8  8bc1                 mov eax, ecx
// 007ae4ca  d96c2420             fldcw word ptr [esp + 0x20]
// 007ae4ce  c1e808               shr eax, 8
// 007ae4d1  0fb6c0               movzx eax, al
// 007ae4d4  2bc2                 sub eax, edx
// 007ae4d6  89442420             mov dword ptr [esp + 0x20], eax
// 007ae4da  0fb6c9               movzx ecx, cl
// 007ae4dd  db442420             fild dword ptr [esp + 0x20]
// 007ae4e1  d97c2420             fnstcw word ptr [esp + 0x20]
// 007ae4e5  0fb7442420           movzx eax, word ptr [esp + 0x20]
// 007ae4ea  d8c9                 fmul st(1)
// 007ae4ec  0d000c0000           or eax, 0xc00
// 007ae4f1  8944241c             mov dword ptr [esp + 0x1c], eax
// 007ae4f5  2bcf                 sub ecx, edi
// 007ae4f7  da442424             fiadd dword ptr [esp + 0x24]
// 007ae4fb  c1e608               shl esi, 8
// 007ae4fe  5f                   pop edi
// 007ae4ff  d96c2418             fldcw word ptr [esp + 0x18]
// 007ae503  db5c2418             fistp dword ptr [esp + 0x18]
// 007ae507  0fb6542418           movzx edx, byte ptr [esp + 0x18]
// 007ae50c  0fb6c2               movzx eax, dl
// 007ae50f  d96c241c             fldcw word ptr [esp + 0x1c]
// 007ae513  0bf0                 or esi, eax
// 007ae515  894c241c             mov dword ptr [esp + 0x1c], ecx
// 007ae519  c1e608               shl esi, 8
// 007ae51c  db44241c             fild dword ptr [esp + 0x1c]
// 007ae520  d97c241c             fnstcw word ptr [esp + 0x1c]
// 007ae524  dec9                 fmulp st(1)
// 007ae526  0fb744241c           movzx eax, word ptr [esp + 0x1c]
// 007ae52b  0d000c0000           or eax, 0xc00
// 007ae530  89442418             mov dword ptr [esp + 0x18], eax
// 007ae534  da442404             fiadd dword ptr [esp + 4]
// 007ae538  d96c2418             fldcw word ptr [esp + 0x18]
// 007ae53c  db5c2418             fistp dword ptr [esp + 0x18]
// 007ae540  0fb6542418           movzx edx, byte ptr [esp + 0x18]
// 007ae545  0fb6c2               movzx eax, dl
// 007ae548  d96c241c             fldcw word ptr [esp + 0x1c]
// 007ae54c  0bc6                 or eax, esi
// 007ae54e  5e                   pop esi
// 007ae54f  59                   pop ecx
// 007ae550  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?Mix@@YAKPAVCDC@@HHKKN@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPaintManager.cpp
