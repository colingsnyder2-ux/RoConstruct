// from server: 100% by auto
// roc 2010-06 004032a0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 300 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004032a0
//
// 004032a0  56                   push esi
// 004032a1  8bf1                 mov esi, ecx
// 004032a3  e898ffffff           call 0x403240
// 004032a8  8b0e                 mov ecx, dword ptr [esi]
// 004032aa  8a01                 mov al, byte ptr [ecx]
// 004032ac  84c0                 test al, al
// 004032ae  7509                 jne 0x4032b9
// 004032b0  b809000280           mov eax, 0x80020009
// 004032b5  5e                   pop esi
// 004032b6  c20400               ret 4
// 004032b9  53                   push ebx
// 004032ba  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 004032be  55                   push ebp
// 004032bf  8b2d64ba9e00         mov ebp, dword ptr [0x9eba64]
// 004032c5  57                   push edi
// 004032c6  895c2414             mov dword ptr [esp + 0x14], ebx
// 004032ca  3c27                 cmp al, 0x27
// 004032cc  7574                 jne 0x403342
// 004032ce  51                   push ecx
// 004032cf  ffd5                 call ebp
// 004032d1  8906                 mov dword ptr [esi], eax
// 004032d3  803800               cmp byte ptr [eax], 0
// 004032d6  7450                 je 0x403328
// 004032d8  8b06                 mov eax, dword ptr [esi]
// 004032da  803827               cmp byte ptr [eax], 0x27
// 004032dd  7508                 jne 0x4032e7
// 004032df  50                   push eax
// 004032e0  ffd5                 call ebp
// 004032e2  803827               cmp byte ptr [eax], 0x27
// 004032e5  7541                 jne 0x403328
// 004032e7  8b06                 mov eax, dword ptr [esi]
// 004032e9  803827               cmp byte ptr [eax], 0x27
// 004032ec  7505                 jne 0x4032f3
// 004032ee  50                   push eax
// 004032ef  ffd5                 call ebp
// 004032f1  8906                 mov dword ptr [esi], eax
// 004032f3  8b3e                 mov edi, dword ptr [esi]
// 004032f5  57                   push edi
// 004032f6  ffd5                 call ebp
// 004032f8  8b542414             mov edx, dword ptr [esp + 0x14]
// 004032fc  8906                 mov dword ptr [esi], eax
// 004032fe  2bc7                 sub eax, edi
// 00403300  8d4c1801             lea ecx, [eax + ebx + 1]
// 00403304  81c200100000         add edx, 0x1000
// 0040330a  3bca                 cmp ecx, edx
// 0040330c  0f838c000000         jae 0x40339e
// 00403312  85c0                 test eax, eax
// 00403314  7e0b                 jle 0x403321
// 00403316  8a0f                 mov cl, byte ptr [edi]
// 00403318  880b                 mov byte ptr [ebx], cl
// 0040331a  43                   inc ebx
// 0040331b  47                   inc edi
// 0040331c  83e801               sub eax, 1
// 0040331f  75f5                 jne 0x403316
// 00403321  8b16                 mov edx, dword ptr [esi]
// 00403323  803a00               cmp byte ptr [edx], 0
// 00403326  75b0                 jne 0x4032d8
// 00403328  8b06                 mov eax, dword ptr [esi]
// 0040332a  803800               cmp byte ptr [eax], 0
// 0040332d  746f                 je 0x40339e
// 0040332f  c60300               mov byte ptr [ebx], 0
// 00403332  8b0e                 mov ecx, dword ptr [esi]
// 00403334  51                   push ecx
// 00403335  ffd5                 call ebp
// 00403337  5f                   pop edi
// 00403338  5d                   pop ebp
// 00403339  8906                 mov dword ptr [esi], eax
// 0040333b  5b                   pop ebx
// 0040333c  33c0                 xor eax, eax
// 0040333e  5e                   pop esi
// 0040333f  c20400               ret 4
// 00403342  8b3e                 mov edi, dword ptr [esi]
// 00403344  0fbe07               movsx eax, byte ptr [edi]
// 00403347  83c0f7               add eax, -9
// 0040334a  83f817               cmp eax, 0x17
// 0040334d  770e                 ja 0x40335d
// 0040334f  0fb690b4334000       movzx edx, byte ptr [eax + 0x4033b4]
// 00403356  ff2495ac334000       jmp dword ptr [edx*4 + 0x4033ac]
// 0040335d  57                   push edi
// 0040335e  ffd5                 call ebp
// 00403360  8b542414             mov edx, dword ptr [esp + 0x14]
// 00403364  8906                 mov dword ptr [esi], eax
// 00403366  2bc7                 sub eax, edi
// 00403368  8d4c1801             lea ecx, [eax + ebx + 1]
// 0040336c  81c200100000         add edx, 0x1000
// 00403372  3bca                 cmp ecx, edx
// 00403374  7328                 jae 0x40339e
// 00403376  85c0                 test eax, eax
// 00403378  7e11                 jle 0x40338b
// 0040337a  8d9b00000000         lea ebx, [ebx]
// 00403380  8a0f                 mov cl, byte ptr [edi]
// 00403382  880b                 mov byte ptr [ebx], cl
// 00403384  43                   inc ebx
// 00403385  47                   inc edi
// 00403386  83e801               sub eax, 1
// 00403389  75f5                 jne 0x403380
// 0040338b  8b16                 mov edx, dword ptr [esi]
// 0040338d  803a00               cmp byte ptr [edx], 0
// 00403390  75b0                 jne 0x403342
// 00403392  5f                   pop edi
// 00403393  5d                   pop ebp
// 00403394  c60300               mov byte ptr [ebx], 0
// 00403397  5b                   pop ebx
// 00403398  33c0                 xor eax, eax
// 0040339a  5e                   pop esi
// 0040339b  c20400               ret 4
// 0040339e  5f                   pop edi
// 0040339f  5d                   pop ebp
// 004033a0  5b                   pop ebx
// 004033a1  b809000280           mov eax, 0x80020009
// 004033a6  5e                   pop esi
// 004033a7  c20400               ret 4
// 004033aa  8bff                 mov edi, edi
// 004033ac  92                   xchg edx, eax
// 004033ad  334000               xor eax, dword ptr [eax]
// 004033b0  5d                   pop ebp
// 004033b1  334000               xor eax, dword ptr [eax]
// 004033b4  0000                 add byte ptr [eax], al
// 004033b6  0101                 add dword ptr [ecx], eax
// 004033b8  0001                 add byte ptr [ecx], al
// 004033ba  0101                 add dword ptr [ecx], eax
// 004033bc  0101                 add dword ptr [ecx], eax
// 004033be  0101                 add dword ptr [ecx], eax
// 004033c0  0101                 add dword ptr [ecx], eax
// 004033c2  0101                 add dword ptr [ecx], eax
// 004033c4  0101                 add dword ptr [ecx], eax
// 004033c6  0101                 add dword ptr [ecx], eax
// 004033c8  0101                 add dword ptr [ecx], eax
// 004033ca  0100                 add dword ptr [eax], eax
// library atl-9.0/atl.cpp (function ?NextToken@CRegParser@ATL@@IAEJPAD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
