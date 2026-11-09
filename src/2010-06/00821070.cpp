// from server: 100% by auto
// roc 2010-06 00821070  unit: CSelectionCaption  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00821070
//
// 00821070  57                   push edi
// 00821071  8bf9                 mov edi, ecx
// 00821073  e870bf1500           call 0x97cfe8
// 00821078  80bf8000000000       cmp byte ptr [edi + 0x80], 0
// 0082107f  756b                 jne 0x8210ec
// 00821081  53                   push ebx
// 00821082  8b1d04ba9e00         mov ebx, dword ptr [0x9eba04]
// 00821088  6a12                 push 0x12
// 0082108a  ffd3                 call ebx
// 0082108c  6a0f                 push 0xf
// 0082108e  894778               mov dword ptr [edi + 0x78], eax
// 00821091  ffd3                 call ebx
// 00821093  6a0f                 push 0xf
// 00821095  894770               mov dword ptr [edi + 0x70], eax
// 00821098  ffd3                 call ebx
// 0082109a  894774               mov dword ptr [edi + 0x74], eax
// 0082109d  8b87fc000000         mov eax, dword ptr [edi + 0xfc]
// 008210a3  50                   push eax
// 008210a4  ff1528bc9e00         call dword ptr [0x9ebc28]
// 008210aa  85c0                 test eax, eax
// 008210ac  743d                 je 0x8210eb
// 008210ae  8b97dc000000         mov edx, dword ptr [edi + 0xdc]
// 008210b4  8b4774               mov eax, dword ptr [edi + 0x74]
// 008210b7  8b9274010000         mov edx, dword ptr [edx + 0x174]
// 008210bd  56                   push esi
// 008210be  8db7dc000000         lea esi, [edi + 0xdc]
// 008210c4  50                   push eax
// 008210c5  8bce                 mov ecx, esi
// 008210c7  ffd2                 call edx
// 008210c9  8b4f78               mov ecx, dword ptr [edi + 0x78]
// 008210cc  8b06                 mov eax, dword ptr [esi]
// 008210ce  8b9084010000         mov edx, dword ptr [eax + 0x184]
// 008210d4  51                   push ecx
// 008210d5  8bce                 mov ecx, esi
// 008210d7  ffd2                 call edx
// 008210d9  8b3e                 mov edi, dword ptr [esi]
// 008210db  6a15                 push 0x15
// 008210dd  ffd3                 call ebx
// 008210df  50                   push eax
// 008210e0  8b8780010000         mov eax, dword ptr [edi + 0x180]
// 008210e6  8bce                 mov ecx, esi
// 008210e8  ffd0                 call eax
// 008210ea  5e                   pop esi
// 008210eb  5b                   pop ebx
// 008210ec  5f                   pop edi
// 008210ed  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Controls\XTCaption.cpp (function ?OnSysColorChange@CXTCaption@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTCaption.cpp
