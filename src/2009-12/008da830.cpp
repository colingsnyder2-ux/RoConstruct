// from server: 100% by auto
// roc 2009-12 008da830  unit: CXTColorHex  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008da830
//
// 008da830  51                   push ecx
// 008da831  53                   push ebx
// 008da832  55                   push ebp
// 008da833  894c2408             mov dword ptr [esp + 8], ecx
// 008da837  8b4978               mov ecx, dword ptr [ecx + 0x78]
// 008da83a  56                   push esi
// 008da83b  57                   push edi
// 008da83c  85c9                 test ecx, ecx
// 008da83e  7440                 je 0x8da880
// 008da840  8b6908               mov ebp, dword ptr [ecx + 8]
// 008da843  85ed                 test ebp, ebp
// 008da845  7439                 je 0x8da880
// 008da847  8b4510               mov eax, dword ptr [ebp + 0x10]
// 008da84a  f7d8                 neg eax
// 008da84c  1bc0                 sbb eax, eax
// 008da84e  25f5fdffff           and eax, 0xfffffdf5
// 008da853  05b3020000           add eax, 0x2b3
// 008da858  33f6                 xor esi, esi
// 008da85a  85c0                 test eax, eax
// 008da85c  7e1c                 jle 0x8da87a
// 008da85e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 008da861  8b3a                 mov edi, dword ptr [edx]
// 008da863  8b5a04               mov ebx, dword ptr [edx + 4]
// 008da866  397c2418             cmp dword ptr [esp + 0x18], edi
// 008da86a  7506                 jne 0x8da872
// 008da86c  395c241c             cmp dword ptr [esp + 0x1c], ebx
// 008da870  7419                 je 0x8da88b
// 008da872  46                   inc esi
// 008da873  83c208               add edx, 8
// 008da876  3bf0                 cmp esi, eax
// 008da878  7ce7                 jl 0x8da861
// 008da87a  8b09                 mov ecx, dword ptr [ecx]
// 008da87c  85c9                 test ecx, ecx
// 008da87e  75c0                 jne 0x8da840
// 008da880  5f                   pop edi
// 008da881  5e                   pop esi
// 008da882  5d                   pop ebp
// 008da883  83c8ff               or eax, 0xffffffff
// 008da886  5b                   pop ebx
// 008da887  59                   pop ecx
// 008da888  c20800               ret 8
// 008da88b  8b4514               mov eax, dword ptr [ebp + 0x14]
// 008da88e  8b10                 mov edx, dword ptr [eax]
// 008da890  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008da894  895168               mov dword ptr [ecx + 0x68], edx
// 008da897  8b4004               mov eax, dword ptr [eax + 4]
// 008da89a  89416c               mov dword ptr [ecx + 0x6c], eax
// 008da89d  8b5510               mov edx, dword ptr [ebp + 0x10]
// 008da8a0  5f                   pop edi
// 008da8a1  5e                   pop esi
// 008da8a2  895164               mov dword ptr [ecx + 0x64], edx
// 008da8a5  8b4518               mov eax, dword ptr [ebp + 0x18]
// 008da8a8  5d                   pop ebp
// 008da8a9  5b                   pop ebx
// 008da8aa  59                   pop ecx
// 008da8ab  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?ColorFromPoint@CXTColorHex@@QAEKVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
