// from server: 100% by auto
// roc 2009-12 008d47c0  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d47c0
//
// 008d47c0  8b442418             mov eax, dword ptr [esp + 0x18]
// 008d47c4  83f803               cmp eax, 3
// 008d47c7  0f87a8000000         ja 0x8d4875
// 008d47cd  ff248578488d00       jmp dword ptr [eax*4 + 0x8d4878]
// 008d47d4  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d47d8  83f8ff               cmp eax, -1
// 008d47db  0f8494000000         je 0x8d4875
// 008d47e1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d47e5  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008d47e9  50                   push eax
// 008d47ea  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008d47ee  6a01                 push 1
// 008d47f0  2bc8                 sub ecx, eax
// 008d47f2  51                   push ecx
// 008d47f3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d47f7  52                   push edx
// 008d47f8  50                   push eax
// 008d47f9  e8981c0500           call 0x926496
// 008d47fe  c3                   ret 
// 008d47ff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d4803  83f8ff               cmp eax, -1
// 008d4806  746d                 je 0x8d4875
// 008d4808  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d480c  8b542408             mov edx, dword ptr [esp + 8]
// 008d4810  50                   push eax
// 008d4811  8b442410             mov eax, dword ptr [esp + 0x10]
// 008d4815  2bc8                 sub ecx, eax
// 008d4817  51                   push ecx
// 008d4818  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008d481c  6a01                 push 1
// 008d481e  50                   push eax
// 008d481f  52                   push edx
// 008d4820  e8711c0500           call 0x926496
// 008d4825  c3                   ret 
// 008d4826  8b442420             mov eax, dword ptr [esp + 0x20]
// 008d482a  83f8ff               cmp eax, -1
// 008d482d  7446                 je 0x8d4875
// 008d482f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d4833  8b542414             mov edx, dword ptr [esp + 0x14]
// 008d4837  50                   push eax
// 008d4838  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008d483c  6a01                 push 1
// 008d483e  2bc8                 sub ecx, eax
// 008d4840  51                   push ecx
// 008d4841  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d4845  4a                   dec edx
// 008d4846  52                   push edx
// 008d4847  50                   push eax
// 008d4848  e8491c0500           call 0x926496
// 008d484d  c3                   ret 
// 008d484e  8b442420             mov eax, dword ptr [esp + 0x20]
// 008d4852  83f8ff               cmp eax, -1
// 008d4855  741e                 je 0x8d4875
// 008d4857  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d485b  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d485f  50                   push eax
// 008d4860  8b442410             mov eax, dword ptr [esp + 0x10]
// 008d4864  2bc8                 sub ecx, eax
// 008d4866  51                   push ecx
// 008d4867  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008d486b  6a01                 push 1
// 008d486d  4a                   dec edx
// 008d486e  50                   push eax
// 008d486f  52                   push edx
// 008d4870  e8211c0500           call 0x926496
// 008d4875  c3                   ret 
// 008d4876  8bff                 mov edi, edi
// 008d4878  d447                 aam 0x47
// 008d487a  8d00                 lea eax, [eax]
// 008d487c  ff478d               inc dword ptr [edi - 0x73]
// 008d487f  0026                 add byte ptr [esi], ah
// 008d4881  48                   dec eax
// 008d4882  8d00                 lea eax, [eax]
// 008d4884  4e                   dec esi
// 008d4885  48                   dec eax
// 008d4886  8d00                 lea eax, [eax]
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?DrawSingleLineBorder@CXTPTabPaintManagerAppearanceSet@@SAXPAVCDC@@VCRect@@W4XTPTabPosition@@KK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
