// from server: 100% by auto
// roc 2009-12 007f6a90  unit: CRobloxControlColorSelector  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f6a90
//
// 007f6a90  83ec10               sub esp, 0x10
// 007f6a93  8b442418             mov eax, dword ptr [esp + 0x18]
// 007f6a97  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007f6a9b  890424               mov dword ptr [esp], eax
// 007f6a9e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007f6aa2  56                   push esi
// 007f6aa3  8b742418             mov esi, dword ptr [esp + 0x18]
// 007f6aa7  89442408             mov dword ptr [esp + 8], eax
// 007f6aab  57                   push edi
// 007f6aac  8b3da0ca9800         mov edi, dword ptr [0x98caa0]
// 007f6ab2  83c002               add eax, 2
// 007f6ab5  8d542408             lea edx, [esp + 8]
// 007f6ab9  89442414             mov dword ptr [esp + 0x14], eax
// 007f6abd  8b4604               mov eax, dword ptr [esi + 4]
// 007f6ac0  52                   push edx
// 007f6ac1  50                   push eax
// 007f6ac2  894c2418             mov dword ptr [esp + 0x18], ecx
// 007f6ac6  ffd7                 call edi
// 007f6ac8  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007f6acc  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007f6ad0  8d50fe               lea edx, [eax - 2]
// 007f6ad3  8954240c             mov dword ptr [esp + 0xc], edx
// 007f6ad7  8d542408             lea edx, [esp + 8]
// 007f6adb  89442414             mov dword ptr [esp + 0x14], eax
// 007f6adf  8b4604               mov eax, dword ptr [esi + 4]
// 007f6ae2  894c2408             mov dword ptr [esp + 8], ecx
// 007f6ae6  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007f6aea  52                   push edx
// 007f6aeb  50                   push eax
// 007f6aec  894c2418             mov dword ptr [esp + 0x18], ecx
// 007f6af0  ffd7                 call edi
// 007f6af2  8b442420             mov eax, dword ptr [esp + 0x20]
// 007f6af6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007f6afa  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007f6afe  89442408             mov dword ptr [esp + 8], eax
// 007f6b02  83c002               add eax, 2
// 007f6b05  83c102               add ecx, 2
// 007f6b08  89442410             mov dword ptr [esp + 0x10], eax
// 007f6b0c  8d442408             lea eax, [esp + 8]
// 007f6b10  894c240c             mov dword ptr [esp + 0xc], ecx
// 007f6b14  8b4e04               mov ecx, dword ptr [esi + 4]
// 007f6b17  50                   push eax
// 007f6b18  83c2fe               add edx, -2
// 007f6b1b  51                   push ecx
// 007f6b1c  8954241c             mov dword ptr [esp + 0x1c], edx
// 007f6b20  ffd7                 call edi
// 007f6b22  8b442428             mov eax, dword ptr [esp + 0x28]
// 007f6b26  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007f6b2a  8d50fe               lea edx, [eax - 2]
// 007f6b2d  83c102               add ecx, 2
// 007f6b30  89542408             mov dword ptr [esp + 8], edx
// 007f6b34  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007f6b38  89442410             mov dword ptr [esp + 0x10], eax
// 007f6b3c  8d442408             lea eax, [esp + 8]
// 007f6b40  894c240c             mov dword ptr [esp + 0xc], ecx
// 007f6b44  8b4e04               mov ecx, dword ptr [esi + 4]
// 007f6b47  50                   push eax
// 007f6b48  83c2fe               add edx, -2
// 007f6b4b  51                   push ecx
// 007f6b4c  8954241c             mov dword ptr [esp + 0x1c], edx
// 007f6b50  ffd7                 call edi
// 007f6b52  5f                   pop edi
// 007f6b53  5e                   pop esi
// 007f6b54  83c410               add esp, 0x10
// 007f6b57  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?OnInvertTracker@CXTPControl@@AAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
