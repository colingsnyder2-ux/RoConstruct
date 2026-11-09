// roc 2008-06 00682350  unit: Ogre::RbxSceneNode  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00682350
//
// 00682350  83ec20               sub esp, 0x20
// 00682353  53                   push ebx
// 00682354  55                   push ebp
// 00682355  56                   push esi
// 00682356  57                   push edi
// 00682357  e884ffffff           call 0x6822e0
// 0068235c  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 00682360  8d442434             lea eax, [esp + 0x34]
// 00682364  50                   push eax
// 00682365  8d4c2414             lea ecx, [esp + 0x14]
// 00682369  51                   push ecx
// 0068236a  8b0dc4db9700         mov ecx, dword ptr [0x97dbc4]
// 00682370  895c243c             mov dword ptr [esp + 0x3c], ebx
// 00682374  e887fbffff           call 0x681f00
// 00682379  8b0dc4db9700         mov ecx, dword ptr [0x97dbc4]
// 0068237f  8b742410             mov esi, dword ptr [esp + 0x10]
// 00682383  8b6918               mov ebp, dword ptr [ecx + 0x18]
// 00682386  8b01                 mov eax, dword ptr [ecx]
// 00682388  85f6                 test esi, esi
// 0068238a  7404                 je 0x682390
// 0068238c  3bf0                 cmp esi, eax
// 0068238e  740c                 je 0x68239c
// 00682390  ff1590288000         call dword ptr [0x802890]
// 00682396  8b0dc4db9700         mov ecx, dword ptr [0x97dbc4]
// 0068239c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006823a0  3bfd                 cmp edi, ebp
// 006823a2  7542                 jne 0x6823e6
// 006823a4  a188448000           mov eax, dword ptr [0x804488]
// 006823a9  d900                 fld dword ptr [eax]
// 006823ab  8d54241c             lea edx, [esp + 0x1c]
// 006823af  d94004               fld dword ptr [eax + 4]
// 006823b2  52                   push edx
// 006823b3  d94008               fld dword ptr [eax + 8]
// 006823b6  8d442414             lea eax, [esp + 0x14]
// 006823ba  d9e8                 fld1 
// 006823bc  50                   push eax
// 006823bd  d95c2428             fstp dword ptr [esp + 0x28]
// 006823c1  895c2424             mov dword ptr [esp + 0x24], ebx
// 006823c5  d9ca                 fxch st(2)
// 006823c7  d95c242c             fstp dword ptr [esp + 0x2c]
// 006823cb  d95c2430             fstp dword ptr [esp + 0x30]
// 006823cf  d95c2434             fstp dword ptr [esp + 0x34]
// 006823d3  e868f7ffff           call 0x681b40
// 006823d8  8b4804               mov ecx, dword ptr [eax + 4]
// 006823db  8b5008               mov edx, dword ptr [eax + 8]
// 006823de  8b30                 mov esi, dword ptr [eax]
// 006823e0  89542418             mov dword ptr [esp + 0x18], edx
// 006823e4  8bf9                 mov edi, ecx
// 006823e6  85f6                 test esi, esi
// 006823e8  7536                 jne 0x682420
// 006823ea  ff1590288000         call dword ptr [0x802890]
// 006823f0  3b7e18               cmp edi, dword ptr [esi + 0x18]
// 006823f3  7506                 jne 0x6823fb
// 006823f5  ff1590288000         call dword ptr [0x802890]
// 006823fb  8b442438             mov eax, dword ptr [esp + 0x38]
// 006823ff  d900                 fld dword ptr [eax]
// 00682401  d95f10               fstp dword ptr [edi + 0x10]
// 00682404  d94004               fld dword ptr [eax + 4]
// 00682407  d95f14               fstp dword ptr [edi + 0x14]
// 0068240a  d94008               fld dword ptr [eax + 8]
// 0068240d  d95f18               fstp dword ptr [edi + 0x18]
// 00682410  d9400c               fld dword ptr [eax + 0xc]
// 00682413  d95f1c               fstp dword ptr [edi + 0x1c]
// 00682416  5f                   pop edi
// 00682417  5e                   pop esi
// 00682418  5d                   pop ebp
// 00682419  5b                   pop ebx
// 0068241a  83c420               add esp, 0x20
// 0068241d  c20800               ret 8

void func_00682350()
{
}
