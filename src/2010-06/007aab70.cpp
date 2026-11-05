// from server: 100% by auto
// roc 2010-06 007aab70  unit: CRobloxControlColorSelector  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007aab70
//
// 007aab70  83ec10               sub esp, 0x10
// 007aab73  8b442418             mov eax, dword ptr [esp + 0x18]
// 007aab77  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007aab7b  890424               mov dword ptr [esp], eax
// 007aab7e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007aab82  56                   push esi
// 007aab83  8b742418             mov esi, dword ptr [esp + 0x18]
// 007aab87  89442408             mov dword ptr [esp + 8], eax
// 007aab8b  57                   push edi
// 007aab8c  8b3ddcba9e00         mov edi, dword ptr [0x9ebadc]
// 007aab92  83c002               add eax, 2
// 007aab95  8d542408             lea edx, [esp + 8]
// 007aab99  89442414             mov dword ptr [esp + 0x14], eax
// 007aab9d  8b4604               mov eax, dword ptr [esi + 4]
// 007aaba0  52                   push edx
// 007aaba1  50                   push eax
// 007aaba2  894c2418             mov dword ptr [esp + 0x18], ecx
// 007aaba6  ffd7                 call edi
// 007aaba8  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007aabac  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007aabb0  8d50fe               lea edx, [eax - 2]
// 007aabb3  8954240c             mov dword ptr [esp + 0xc], edx
// 007aabb7  8d542408             lea edx, [esp + 8]
// 007aabbb  89442414             mov dword ptr [esp + 0x14], eax
// 007aabbf  8b4604               mov eax, dword ptr [esi + 4]
// 007aabc2  894c2408             mov dword ptr [esp + 8], ecx
// 007aabc6  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007aabca  52                   push edx
// 007aabcb  50                   push eax
// 007aabcc  894c2418             mov dword ptr [esp + 0x18], ecx
// 007aabd0  ffd7                 call edi
// 007aabd2  8b442420             mov eax, dword ptr [esp + 0x20]
// 007aabd6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007aabda  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007aabde  89442408             mov dword ptr [esp + 8], eax
// 007aabe2  83c002               add eax, 2
// 007aabe5  83c102               add ecx, 2
// 007aabe8  89442410             mov dword ptr [esp + 0x10], eax
// 007aabec  8d442408             lea eax, [esp + 8]
// 007aabf0  894c240c             mov dword ptr [esp + 0xc], ecx
// 007aabf4  8b4e04               mov ecx, dword ptr [esi + 4]
// 007aabf7  50                   push eax
// 007aabf8  83c2fe               add edx, -2
// 007aabfb  51                   push ecx
// 007aabfc  8954241c             mov dword ptr [esp + 0x1c], edx
// 007aac00  ffd7                 call edi
// 007aac02  8b442428             mov eax, dword ptr [esp + 0x28]
// 007aac06  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007aac0a  8d50fe               lea edx, [eax - 2]
// 007aac0d  83c102               add ecx, 2
// 007aac10  89542408             mov dword ptr [esp + 8], edx
// 007aac14  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007aac18  89442410             mov dword ptr [esp + 0x10], eax
// 007aac1c  8d442408             lea eax, [esp + 8]
// 007aac20  894c240c             mov dword ptr [esp + 0xc], ecx
// 007aac24  8b4e04               mov ecx, dword ptr [esi + 4]
// 007aac27  50                   push eax
// 007aac28  83c2fe               add edx, -2
// 007aac2b  51                   push ecx
// 007aac2c  8954241c             mov dword ptr [esp + 0x1c], edx
// 007aac30  ffd7                 call edi
// 007aac32  5f                   pop edi
// 007aac33  5e                   pop esi
// 007aac34  83c410               add esp, 0x10
// 007aac37  c21400               ret 0x14
// library xtp-13.2.1/Source\CommandBars\XTPControl.cpp (function ?OnInvertTracker@CXTPControl@@AAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControl.cpp
