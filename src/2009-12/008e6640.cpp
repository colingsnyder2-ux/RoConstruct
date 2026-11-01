// from server: 100% by auto
// roc 2009-12 008e6640  unit: CXTCaptionPopupWnd  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e6640
//
// 008e6640  83ec28               sub esp, 0x28
// 008e6643  56                   push esi
// 008e6644  e8d5d4f0ff           call 0x7f3b1e
// 008e6649  8b7008               mov esi, dword ptr [eax + 8]
// 008e664c  8d442404             lea eax, [esp + 4]
// 008e6650  50                   push eax
// 008e6651  6818cba000           push 0xa0cb18
// 008e6656  56                   push esi
// 008e6657  ff1588ca9800         call dword ptr [0x98ca88]
// 008e665d  85c0                 test eax, eax
// 008e665f  756d                 jne 0x8e66ce
// 008e6661  8b0ddcc99800         mov ecx, dword ptr [0x98c9dc]
// 008e6667  57                   push edi
// 008e6668  33ff                 xor edi, edi
// 008e666a  c744240803000000     mov dword ptr [esp + 8], 3
// 008e6672  894c240c             mov dword ptr [esp + 0xc], ecx
// 008e6676  897c2410             mov dword ptr [esp + 0x10], edi
// 008e667a  897c2414             mov dword ptr [esp + 0x14], edi
// 008e667e  89742418             mov dword ptr [esp + 0x18], esi
// 008e6682  897c241c             mov dword ptr [esp + 0x1c], edi
// 008e6686  e893d4f0ff           call 0x7f3b1e
// 008e668b  68007f0000           push 0x7f00
// 008e6690  57                   push edi
// 008e6691  ff1548ca9800         call dword ptr [0x98ca48]
// 008e6697  6a0f                 push 0xf
// 008e6699  89442424             mov dword ptr [esp + 0x24], eax
// 008e669d  ff1564cb9800         call dword ptr [0x98cb64]
// 008e66a3  8d542408             lea edx, [esp + 8]
// 008e66a7  52                   push edx
// 008e66a8  89442428             mov dword ptr [esp + 0x28], eax
// 008e66ac  897c242c             mov dword ptr [esp + 0x2c], edi
// 008e66b0  c744243018cba000     mov dword ptr [esp + 0x30], 0xa0cb18
// 008e66b8  e8c5020400           call 0x926982
// 008e66bd  5f                   pop edi
// 008e66be  85c0                 test eax, eax
// 008e66c0  750c                 jne 0x8e66ce
// 008e66c2  e807ff0300           call 0x9265ce
// 008e66c7  33c0                 xor eax, eax
// 008e66c9  5e                   pop esi
// 008e66ca  83c428               add esp, 0x28
// 008e66cd  c3                   ret 
// 008e66ce  b801000000           mov eax, 1
// 008e66d3  5e                   pop esi
// 008e66d4  83c428               add esp, 0x28
// 008e66d7  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?RegisterWindowClass@CXTCaptionPopupWnd@@IAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
