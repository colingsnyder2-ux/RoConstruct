// from server: 100% by auto
// roc 2011-06 008e7690  unit: CXTColorHex  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e7690
//
// 008e7690  51                   push ecx
// 008e7691  53                   push ebx
// 008e7692  55                   push ebp
// 008e7693  894c2408             mov dword ptr [esp + 8], ecx
// 008e7697  8b4978               mov ecx, dword ptr [ecx + 0x78]
// 008e769a  56                   push esi
// 008e769b  57                   push edi
// 008e769c  85c9                 test ecx, ecx
// 008e769e  7440                 je 0x8e76e0
// 008e76a0  8b6908               mov ebp, dword ptr [ecx + 8]
// 008e76a3  85ed                 test ebp, ebp
// 008e76a5  7439                 je 0x8e76e0
// 008e76a7  8b4510               mov eax, dword ptr [ebp + 0x10]
// 008e76aa  f7d8                 neg eax
// 008e76ac  1bc0                 sbb eax, eax
// 008e76ae  25f5fdffff           and eax, 0xfffffdf5
// 008e76b3  05b3020000           add eax, 0x2b3
// 008e76b8  33f6                 xor esi, esi
// 008e76ba  85c0                 test eax, eax
// 008e76bc  7e1c                 jle 0x8e76da
// 008e76be  8b5514               mov edx, dword ptr [ebp + 0x14]
// 008e76c1  8b3a                 mov edi, dword ptr [edx]
// 008e76c3  8b5a04               mov ebx, dword ptr [edx + 4]
// 008e76c6  397c2418             cmp dword ptr [esp + 0x18], edi
// 008e76ca  7506                 jne 0x8e76d2
// 008e76cc  395c241c             cmp dword ptr [esp + 0x1c], ebx
// 008e76d0  7419                 je 0x8e76eb
// 008e76d2  46                   inc esi
// 008e76d3  83c208               add edx, 8
// 008e76d6  3bf0                 cmp esi, eax
// 008e76d8  7ce7                 jl 0x8e76c1
// 008e76da  8b09                 mov ecx, dword ptr [ecx]
// 008e76dc  85c9                 test ecx, ecx
// 008e76de  75c0                 jne 0x8e76a0
// 008e76e0  5f                   pop edi
// 008e76e1  5e                   pop esi
// 008e76e2  5d                   pop ebp
// 008e76e3  83c8ff               or eax, 0xffffffff
// 008e76e6  5b                   pop ebx
// 008e76e7  59                   pop ecx
// 008e76e8  c20800               ret 8
// 008e76eb  8b4514               mov eax, dword ptr [ebp + 0x14]
// 008e76ee  8b10                 mov edx, dword ptr [eax]
// 008e76f0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e76f4  895168               mov dword ptr [ecx + 0x68], edx
// 008e76f7  8b4004               mov eax, dword ptr [eax + 4]
// 008e76fa  89416c               mov dword ptr [ecx + 0x6c], eax
// 008e76fd  8b5510               mov edx, dword ptr [ebp + 0x10]
// 008e7700  5f                   pop edi
// 008e7701  5e                   pop esi
// 008e7702  895164               mov dword ptr [ecx + 0x64], edx
// 008e7705  8b4518               mov eax, dword ptr [ebp + 0x18]
// 008e7708  5d                   pop ebp
// 008e7709  5b                   pop ebx
// 008e770a  59                   pop ecx
// 008e770b  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?ColorFromPoint@CXTColorHex@@QAEKVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
