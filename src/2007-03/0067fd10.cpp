// from server: 100% by auto
// roc 2007-03 0067fd10  unit: seg_00670000  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067fd10
//
// 0067fd10  8b442404             mov eax, dword ptr [esp + 4]
// 0067fd14  83ec24               sub esp, 0x24
// 0067fd17  85c0                 test eax, eax
// 0067fd19  757c                 jne 0x67fd97
// 0067fd1b  8b0d981e8c00         mov ecx, dword ptr [0x8c1e98]
// 0067fd21  85c9                 test ecx, ecx
// 0067fd23  7472                 je 0x67fd97
// 0067fd25  398190000000         cmp dword ptr [ecx + 0x90], eax
// 0067fd2b  746a                 je 0x67fd97
// 0067fd2d  56                   push esi
// 0067fd2e  8b742434             mov esi, dword ptr [esp + 0x34]
// 0067fd32  8b06                 mov eax, dword ptr [esi]
// 0067fd34  8b5604               mov edx, dword ptr [esi + 4]
// 0067fd37  89442404             mov dword ptr [esp + 4], eax
// 0067fd3b  8d442404             lea eax, [esp + 4]
// 0067fd3f  50                   push eax
// 0067fd40  6a00                 push 0
// 0067fd42  89542410             mov dword ptr [esp + 0x10], edx
// 0067fd46  e805daffff           call 0x67d750
// 0067fd4b  8b0d981e8c00         mov ecx, dword ptr [0x8c1e98]
// 0067fd51  3b8190000000         cmp eax, dword ptr [ecx + 0x90]
// 0067fd57  7422                 je 0x67fd7b
// 0067fd59  8b542404             mov edx, dword ptr [esp + 4]
// 0067fd5d  8b442408             mov eax, dword ptr [esp + 8]
// 0067fd61  89542420             mov dword ptr [esp + 0x20], edx
// 0067fd65  8d54240c             lea edx, [esp + 0xc]
// 0067fd69  52                   push edx
// 0067fd6a  89442428             mov dword ptr [esp + 0x28], eax
// 0067fd6e  c744241400020000     mov dword ptr [esp + 0x14], 0x200
// 0067fd76  e885f4ffff           call 0x67f200
// 0067fd7b  8b442430             mov eax, dword ptr [esp + 0x30]
// 0067fd7f  8b0d941e8c00         mov ecx, dword ptr [0x8c1e94]
// 0067fd85  56                   push esi
// 0067fd86  50                   push eax
// 0067fd87  6a00                 push 0
// 0067fd89  51                   push ecx
// 0067fd8a  ff15e4ee7700         call dword ptr [0x77eee4]
// 0067fd90  5e                   pop esi
// 0067fd91  83c424               add esp, 0x24
// 0067fd94  c20c00               ret 0xc
// 0067fd97  8b542430             mov edx, dword ptr [esp + 0x30]
// 0067fd9b  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0067fd9f  52                   push edx
// 0067fda0  8b15941e8c00         mov edx, dword ptr [0x8c1e94]
// 0067fda6  51                   push ecx
// 0067fda7  50                   push eax
// 0067fda8  52                   push edx
// 0067fda9  ff15e4ee7700         call dword ptr [0x77eee4]
// 0067fdaf  83c424               add esp, 0x24
// 0067fdb2  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?MouseProc@CXTPToolTipContextToolTip@@KGJHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
