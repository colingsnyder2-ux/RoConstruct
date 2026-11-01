// from server: 100% by auto
// roc 2009-06 00756840  unit: CRobloxTreeCtrl  size: 196 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00756840
//
// 00756840  51                   push ecx
// 00756841  56                   push esi
// 00756842  8bf1                 mov esi, ecx
// 00756844  837e0400             cmp dword ptr [esi + 4], 0
// 00756848  c744240400000000     mov dword ptr [esp + 4], 0
// 00756850  750a                 jne 0x75685c
// 00756852  b801000000           mov eax, 1
// 00756857  5e                   pop esi
// 00756858  59                   pop ecx
// 00756859  c21000               ret 0x10
// 0075685c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00756860  8b542414             mov edx, dword ptr [esp + 0x14]
// 00756864  55                   push ebp
// 00756865  57                   push edi
// 00756866  8d44240c             lea eax, [esp + 0xc]
// 0075686a  50                   push eax
// 0075686b  51                   push ecx
// 0075686c  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0075686f  52                   push edx
// 00756870  e8772bfcff           call 0x7193ec
// 00756875  8bf8                 mov edi, eax
// 00756877  85ff                 test edi, edi
// 00756879  7465                 je 0x7568e0
// 0075687b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0075687f  83e010               and eax, 0x10
// 00756882  7574                 jne 0x7568f8
// 00756884  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00756888  85ed                 test ebp, ebp
// 0075688a  7416                 je 0x7568a2
// 0075688c  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0075688f  e848560f00           call 0x84bedc
// 00756894  a900010000           test eax, 0x100
// 00756899  740b                 je 0x7568a6
// 0075689b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0075689f  83e040               and eax, 0x40
// 007568a2  85c0                 test eax, eax
// 007568a4  7552                 jne 0x7568f8
// 007568a6  f644240c29           test byte ptr [esp + 0xc], 0x29
// 007568ab  7533                 jne 0x7568e0
// 007568ad  8b06                 mov eax, dword ptr [esi]
// 007568af  8b5058               mov edx, dword ptr [eax + 0x58]
// 007568b2  53                   push ebx
// 007568b3  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 007568b7  53                   push ebx
// 007568b8  55                   push ebp
// 007568b9  57                   push edi
// 007568ba  8bce                 mov ecx, esi
// 007568bc  ffd2                 call edx
// 007568be  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007568c2  8b542420             mov edx, dword ptr [esp + 0x20]
// 007568c6  8b06                 mov eax, dword ptr [esi]
// 007568c8  8b405c               mov eax, dword ptr [eax + 0x5c]
// 007568cb  51                   push ecx
// 007568cc  52                   push edx
// 007568cd  53                   push ebx
// 007568ce  55                   push ebp
// 007568cf  57                   push edi
// 007568d0  8bce                 mov ecx, esi
// 007568d2  ffd0                 call eax
// 007568d4  0fb64638             movzx eax, byte ptr [esi + 0x38]
// 007568d8  5b                   pop ebx
// 007568d9  5f                   pop edi
// 007568da  5d                   pop ebp
// 007568db  5e                   pop esi
// 007568dc  59                   pop ecx
// 007568dd  c21000               ret 0x10
// 007568e0  8b442420             mov eax, dword ptr [esp + 0x20]
// 007568e4  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007568e8  8b16                 mov edx, dword ptr [esi]
// 007568ea  8b5260               mov edx, dword ptr [edx + 0x60]
// 007568ed  50                   push eax
// 007568ee  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007568f2  51                   push ecx
// 007568f3  50                   push eax
// 007568f4  8bce                 mov ecx, esi
// 007568f6  ffd2                 call edx
// 007568f8  5f                   pop edi
// 007568f9  5d                   pop ebp
// 007568fa  b801000000           mov eax, 1
// 007568ff  5e                   pop esi
// 00756900  59                   pop ecx
// 00756901  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnButtonDown@CXTPTreeBase@@MAEHHIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
