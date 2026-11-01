// from server: 100% by auto
// roc 2009-06 00720380  unit: CRobloxControlColorSelector  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00720380
//
// 00720380  83ec10               sub esp, 0x10
// 00720383  8b442418             mov eax, dword ptr [esp + 0x18]
// 00720387  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0072038b  890424               mov dword ptr [esp], eax
// 0072038e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00720392  56                   push esi
// 00720393  8b742418             mov esi, dword ptr [esp + 0x18]
// 00720397  89442408             mov dword ptr [esp + 8], eax
// 0072039b  57                   push edi
// 0072039c  8b3dccee8900         mov edi, dword ptr [0x89eecc]
// 007203a2  83c002               add eax, 2
// 007203a5  8d542408             lea edx, [esp + 8]
// 007203a9  89442414             mov dword ptr [esp + 0x14], eax
// 007203ad  8b4604               mov eax, dword ptr [esi + 4]
// 007203b0  52                   push edx
// 007203b1  50                   push eax
// 007203b2  894c2418             mov dword ptr [esp + 0x18], ecx
// 007203b6  ffd7                 call edi
// 007203b8  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007203bc  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007203c0  8d50fe               lea edx, [eax - 2]
// 007203c3  8954240c             mov dword ptr [esp + 0xc], edx
// 007203c7  8d542408             lea edx, [esp + 8]
// 007203cb  89442414             mov dword ptr [esp + 0x14], eax
// 007203cf  8b4604               mov eax, dword ptr [esi + 4]
// 007203d2  894c2408             mov dword ptr [esp + 8], ecx
// 007203d6  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007203da  52                   push edx
// 007203db  50                   push eax
// 007203dc  894c2418             mov dword ptr [esp + 0x18], ecx
// 007203e0  ffd7                 call edi
// 007203e2  8b442420             mov eax, dword ptr [esp + 0x20]
// 007203e6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007203ea  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007203ee  89442408             mov dword ptr [esp + 8], eax
// 007203f2  83c002               add eax, 2
// 007203f5  83c102               add ecx, 2
// 007203f8  89442410             mov dword ptr [esp + 0x10], eax
// 007203fc  8d442408             lea eax, [esp + 8]
// 00720400  894c240c             mov dword ptr [esp + 0xc], ecx
// 00720404  8b4e04               mov ecx, dword ptr [esi + 4]
// 00720407  50                   push eax
// 00720408  83c2fe               add edx, -2
// 0072040b  51                   push ecx
// 0072040c  8954241c             mov dword ptr [esp + 0x1c], edx
// 00720410  ffd7                 call edi
// 00720412  8b442428             mov eax, dword ptr [esp + 0x28]
// 00720416  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0072041a  8d50fe               lea edx, [eax - 2]
// 0072041d  83c102               add ecx, 2
// 00720420  89542408             mov dword ptr [esp + 8], edx
// 00720424  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00720428  89442410             mov dword ptr [esp + 0x10], eax
// 0072042c  8d442408             lea eax, [esp + 8]
// 00720430  894c240c             mov dword ptr [esp + 0xc], ecx
// 00720434  8b4e04               mov ecx, dword ptr [esi + 4]
// 00720437  50                   push eax
// 00720438  83c2fe               add edx, -2
// 0072043b  51                   push ecx
// 0072043c  8954241c             mov dword ptr [esp + 0x1c], edx
// 00720440  ffd7                 call edi
// 00720442  5f                   pop edi
// 00720443  5e                   pop esi
// 00720444  83c410               add esp, 0x10
// 00720447  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?OnInvertTracker@CXTPControl@@AAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
