// from server: 100% by auto
// roc 2011-06 00881310  unit: CXTPMouseManager  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00881310
//
// 00881310  56                   push esi
// 00881311  8bf1                 mov esi, ecx
// 00881313  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00881316  85c9                 test ecx, ecx
// 00881318  7506                 jne 0x881320
// 0088131a  33c0                 xor eax, eax
// 0088131c  5e                   pop esi
// 0088131d  c20800               ret 8
// 00881320  8b4614               mov eax, dword ptr [esi + 0x14]
// 00881323  85c0                 test eax, eax
// 00881325  750a                 jne 0x881331
// 00881327  8b81a0000000         mov eax, dword ptr [ecx + 0xa0]
// 0088132d  85c0                 test eax, eax
// 0088132f  74e9                 je 0x88131a
// 00881331  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00881335  894e04               mov dword ptr [esi + 4], ecx
// 00881338  8b4020               mov eax, dword ptr [eax + 0x20]
// 0088133b  57                   push edi
// 0088133c  50                   push eax
// 0088133d  8906                 mov dword ptr [esi], eax
// 0088133f  ff15341ba400         call dword ptr [0xa41b34]
// 00881345  8b542410             mov edx, dword ptr [esp + 0x10]
// 00881349  8d4618               lea eax, [esi + 0x18]
// 0088134c  50                   push eax
// 0088134d  c7460800000000       mov dword ptr [esi + 8], 0
// 00881354  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0088135b  89560c               mov dword ptr [esi + 0xc], edx
// 0088135e  ff15c819a400         call dword ptr [0xa419c8]
// 00881364  8bce                 mov ecx, esi
// 00881366  e845fdffff           call 0x8810b0
// 0088136b  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0088136e  8bf8                 mov edi, eax
// 00881370  85c9                 test ecx, ecx
// 00881372  740a                 je 0x88137e
// 00881374  8b11                 mov edx, dword ptr [ecx]
// 00881376  8b8274010000         mov eax, dword ptr [edx + 0x174]
// 0088137c  ffd0                 call eax
// 0088137e  ff15401ba400         call dword ptr [0xa41b40]
// 00881384  e8938ff8ff           call 0x80a31c
// 00881389  68007f0000           push 0x7f00
// 0088138e  6a00                 push 0
// 00881390  ff15081aa400         call dword ptr [0xa41a08]
// 00881396  50                   push eax
// 00881397  ff15f41ba400         call dword ptr [0xa41bf4]
// 0088139d  8bc7                 mov eax, edi
// 0088139f  5f                   pop edi
// 008813a0  5e                   pop esi
// 008813a1  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCustomizeTools.cpp (function ?DoDragDrop@CXTPCustomizeDropSource@@QAEKPAVCXTPControl@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCustomizeTools.cpp
