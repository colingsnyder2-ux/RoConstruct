// from server: 100% by auto
// roc 2010-06 0088e9e0  unit: CXTColorHex  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088e9e0
//
// 0088e9e0  51                   push ecx
// 0088e9e1  53                   push ebx
// 0088e9e2  55                   push ebp
// 0088e9e3  894c2408             mov dword ptr [esp + 8], ecx
// 0088e9e7  8b4978               mov ecx, dword ptr [ecx + 0x78]
// 0088e9ea  56                   push esi
// 0088e9eb  57                   push edi
// 0088e9ec  85c9                 test ecx, ecx
// 0088e9ee  7440                 je 0x88ea30
// 0088e9f0  8b6908               mov ebp, dword ptr [ecx + 8]
// 0088e9f3  85ed                 test ebp, ebp
// 0088e9f5  7439                 je 0x88ea30
// 0088e9f7  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0088e9fa  f7d8                 neg eax
// 0088e9fc  1bc0                 sbb eax, eax
// 0088e9fe  25f5fdffff           and eax, 0xfffffdf5
// 0088ea03  05b3020000           add eax, 0x2b3
// 0088ea08  33f6                 xor esi, esi
// 0088ea0a  85c0                 test eax, eax
// 0088ea0c  7e1c                 jle 0x88ea2a
// 0088ea0e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0088ea11  8b3a                 mov edi, dword ptr [edx]
// 0088ea13  8b5a04               mov ebx, dword ptr [edx + 4]
// 0088ea16  397c2418             cmp dword ptr [esp + 0x18], edi
// 0088ea1a  7506                 jne 0x88ea22
// 0088ea1c  395c241c             cmp dword ptr [esp + 0x1c], ebx
// 0088ea20  7419                 je 0x88ea3b
// 0088ea22  46                   inc esi
// 0088ea23  83c208               add edx, 8
// 0088ea26  3bf0                 cmp esi, eax
// 0088ea28  7ce7                 jl 0x88ea11
// 0088ea2a  8b09                 mov ecx, dword ptr [ecx]
// 0088ea2c  85c9                 test ecx, ecx
// 0088ea2e  75c0                 jne 0x88e9f0
// 0088ea30  5f                   pop edi
// 0088ea31  5e                   pop esi
// 0088ea32  5d                   pop ebp
// 0088ea33  83c8ff               or eax, 0xffffffff
// 0088ea36  5b                   pop ebx
// 0088ea37  59                   pop ecx
// 0088ea38  c20800               ret 8
// 0088ea3b  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0088ea3e  8b10                 mov edx, dword ptr [eax]
// 0088ea40  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0088ea44  895168               mov dword ptr [ecx + 0x68], edx
// 0088ea47  8b4004               mov eax, dword ptr [eax + 4]
// 0088ea4a  89416c               mov dword ptr [ecx + 0x6c], eax
// 0088ea4d  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0088ea50  5f                   pop edi
// 0088ea51  5e                   pop esi
// 0088ea52  895164               mov dword ptr [ecx + 0x64], edx
// 0088ea55  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0088ea58  5d                   pop ebp
// 0088ea59  5b                   pop ebx
// 0088ea5a  59                   pop ecx
// 0088ea5b  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?ColorFromPoint@CXTColorHex@@QAEKVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
