// from server: 100% by auto
// roc 2007-03 006e06a0  unit: seg_006e0000  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e06a0
//
// 006e06a0  8b442408             mov eax, dword ptr [esp + 8]
// 006e06a4  99                   cdq 
// 006e06a5  f7795c               idiv dword ptr [ecx + 0x5c]
// 006e06a8  56                   push esi
// 006e06a9  8b742408             mov esi, dword ptr [esp + 8]
// 006e06ad  8906                 mov dword ptr [esi], eax
// 006e06af  8b442410             mov eax, dword ptr [esp + 0x10]
// 006e06b3  99                   cdq 
// 006e06b4  f77960               idiv dword ptr [ecx + 0x60]
// 006e06b7  894604               mov dword ptr [esi + 4], eax
// 006e06ba  8bc6                 mov eax, esi
// 006e06bc  5e                   pop esi
// 006e06bd  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?ClientToPicture@CXTPImageEditorPicture@@QAE?AVCPoint@@V2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
