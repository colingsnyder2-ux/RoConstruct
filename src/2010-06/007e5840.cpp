// from server: 100% by auto
// roc 2010-06 007e5840  unit: CRobloxTreeCtrl  size: 196 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5840
//
// 007e5840  51                   push ecx
// 007e5841  56                   push esi
// 007e5842  8bf1                 mov esi, ecx
// 007e5844  837e0400             cmp dword ptr [esi + 4], 0
// 007e5848  c744240400000000     mov dword ptr [esp + 4], 0
// 007e5850  750a                 jne 0x7e585c
// 007e5852  b801000000           mov eax, 1
// 007e5857  5e                   pop esi
// 007e5858  59                   pop ecx
// 007e5859  c21000               ret 0x10
// 007e585c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007e5860  8b542414             mov edx, dword ptr [esp + 0x14]
// 007e5864  55                   push ebp
// 007e5865  57                   push edi
// 007e5866  8d44240c             lea eax, [esp + 0xc]
// 007e586a  50                   push eax
// 007e586b  51                   push ecx
// 007e586c  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e586f  52                   push edx
// 007e5870  e8df2afcff           call 0x7a8354
// 007e5875  8bf8                 mov edi, eax
// 007e5877  85ff                 test edi, edi
// 007e5879  7465                 je 0x7e58e0
// 007e587b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e587f  83e010               and eax, 0x10
// 007e5882  7574                 jne 0x7e58f8
// 007e5884  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 007e5888  85ed                 test ebp, ebp
// 007e588a  7416                 je 0x7e58a2
// 007e588c  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e588f  e84a751900           call 0x97cdde
// 007e5894  a900010000           test eax, 0x100
// 007e5899  740b                 je 0x7e58a6
// 007e589b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e589f  83e040               and eax, 0x40
// 007e58a2  85c0                 test eax, eax
// 007e58a4  7552                 jne 0x7e58f8
// 007e58a6  f644240c29           test byte ptr [esp + 0xc], 0x29
// 007e58ab  7533                 jne 0x7e58e0
// 007e58ad  8b06                 mov eax, dword ptr [esi]
// 007e58af  8b5058               mov edx, dword ptr [eax + 0x58]
// 007e58b2  53                   push ebx
// 007e58b3  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 007e58b7  53                   push ebx
// 007e58b8  55                   push ebp
// 007e58b9  57                   push edi
// 007e58ba  8bce                 mov ecx, esi
// 007e58bc  ffd2                 call edx
// 007e58be  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007e58c2  8b542420             mov edx, dword ptr [esp + 0x20]
// 007e58c6  8b06                 mov eax, dword ptr [esi]
// 007e58c8  8b405c               mov eax, dword ptr [eax + 0x5c]
// 007e58cb  51                   push ecx
// 007e58cc  52                   push edx
// 007e58cd  53                   push ebx
// 007e58ce  55                   push ebp
// 007e58cf  57                   push edi
// 007e58d0  8bce                 mov ecx, esi
// 007e58d2  ffd0                 call eax
// 007e58d4  0fb64638             movzx eax, byte ptr [esi + 0x38]
// 007e58d8  5b                   pop ebx
// 007e58d9  5f                   pop edi
// 007e58da  5d                   pop ebp
// 007e58db  5e                   pop esi
// 007e58dc  59                   pop ecx
// 007e58dd  c21000               ret 0x10
// 007e58e0  8b442420             mov eax, dword ptr [esp + 0x20]
// 007e58e4  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007e58e8  8b16                 mov edx, dword ptr [esi]
// 007e58ea  8b5260               mov edx, dword ptr [edx + 0x60]
// 007e58ed  50                   push eax
// 007e58ee  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007e58f2  51                   push ecx
// 007e58f3  50                   push eax
// 007e58f4  8bce                 mov ecx, esi
// 007e58f6  ffd2                 call edx
// 007e58f8  5f                   pop edi
// 007e58f9  5d                   pop ebp
// 007e58fa  b801000000           mov eax, 1
// 007e58ff  5e                   pop esi
// 007e5900  59                   pop ecx
// 007e5901  c21000               ret 0x10
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?OnButtonDown@CXTTreeBase@@MAEHHIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
