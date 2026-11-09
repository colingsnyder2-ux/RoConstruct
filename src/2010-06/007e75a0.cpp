// from server: 100% by auto
// roc 2010-06 007e75a0  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e75a0
//
// 007e75a0  51                   push ecx
// 007e75a1  56                   push esi
// 007e75a2  8bf1                 mov esi, ecx
// 007e75a4  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e75a7  e832581900           call 0x97cdde
// 007e75ac  a900040000           test eax, 0x400
// 007e75b1  740d                 je 0x7e75c0
// 007e75b3  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e75b6  e8b509fcff           call 0x7a7f70
// 007e75bb  5e                   pop esi
// 007e75bc  59                   pop ecx
// 007e75bd  c20c00               ret 0xc
// 007e75c0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007e75c4  8b542410             mov edx, dword ptr [esp + 0x10]
// 007e75c8  57                   push edi
// 007e75c9  8d442408             lea eax, [esp + 8]
// 007e75cd  50                   push eax
// 007e75ce  51                   push ecx
// 007e75cf  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e75d2  52                   push edx
// 007e75d3  c744241400000000     mov dword ptr [esp + 0x14], 0
// 007e75db  e8740dfcff           call 0x7a8354
// 007e75e0  8bf8                 mov edi, eax
// 007e75e2  85ff                 test edi, edi
// 007e75e4  7437                 je 0x7e761d
// 007e75e6  f644240846           test byte ptr [esp + 8], 0x46
// 007e75eb  7430                 je 0x7e761d
// 007e75ed  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e75f0  6a02                 push 2
// 007e75f2  57                   push edi
// 007e75f3  e84a5a1900           call 0x97d042
// 007e75f8  a802                 test al, 2
// 007e75fa  752c                 jne 0x7e7628
// 007e75fc  6a00                 push 0
// 007e75fe  6a00                 push 0
// 007e7600  8bce                 mov ecx, esi
// 007e7602  e8c9f1ffff           call 0x7e67d0
// 007e7607  57                   push edi
// 007e7608  8bce                 mov ecx, esi
// 007e760a  e881f0ffff           call 0x7e6690
// 007e760f  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e7612  e85909fcff           call 0x7a7f70
// 007e7617  5f                   pop edi
// 007e7618  5e                   pop esi
// 007e7619  59                   pop ecx
// 007e761a  c20c00               ret 0xc
// 007e761d  6a00                 push 0
// 007e761f  6a00                 push 0
// 007e7621  8bce                 mov ecx, esi
// 007e7623  e8a8f1ffff           call 0x7e67d0
// 007e7628  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e762b  e84009fcff           call 0x7a7f70
// 007e7630  5f                   pop edi
// 007e7631  5e                   pop esi
// 007e7632  59                   pop ecx
// 007e7633  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?OnRButtonDown@CXTTreeBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
