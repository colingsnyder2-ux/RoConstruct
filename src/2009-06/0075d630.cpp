// from server: 100% by auto
// roc 2009-06 0075d630  unit: CXTPControls  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075d630
//
// 0075d630  56                   push esi
// 0075d631  57                   push edi
// 0075d632  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0075d636  8b4720               mov eax, dword ptr [edi + 0x20]
// 0075d639  50                   push eax
// 0075d63a  8bf1                 mov esi, ecx
// 0075d63c  ff15e0ed8900         call dword ptr [0x89ede0]
// 0075d642  85c0                 test eax, eax
// 0075d644  7427                 je 0x75d66d
// 0075d646  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0075d64a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0075d64e  51                   push ecx
// 0075d64f  52                   push edx
// 0075d650  8bce                 mov ecx, esi
// 0075d652  e879feffff           call 0x75d4d0
// 0075d657  85c0                 test eax, eax
// 0075d659  7412                 je 0x75d66d
// 0075d65b  56                   push esi
// 0075d65c  8bcf                 mov ecx, edi
// 0075d65e  e8f1eb0e00           call 0x84c254
// 0075d663  5f                   pop edi
// 0075d664  b801000000           mov eax, 1
// 0075d669  5e                   pop esi
// 0075d66a  c20c00               ret 0xc
// 0075d66d  5f                   pop edi
// 0075d66e  33c0                 xor eax, eax
// 0075d670  5e                   pop esi
// 0075d671  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Util\XTPWindowPos.cpp (function ?LoadWindowPos@CXTPWindowPos@@QAEHPAVCWnd@@PBD1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPWindowPos.cpp
