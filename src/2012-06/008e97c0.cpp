// from server: 100% by auto
// roc 2012-06 008e97c0  unit: RBX::FloorWire  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008e97c0
//
// 008e97c0  6aff                 push -1
// 008e97c2  6819fea900           push 0xa9fe19
// 008e97c7  64a100000000         mov eax, dword ptr fs:[0]
// 008e97cd  50                   push eax
// 008e97ce  64892500000000       mov dword ptr fs:[0], esp
// 008e97d5  51                   push ecx
// 008e97d6  33c9                 xor ecx, ecx
// 008e97d8  890c24               mov dword ptr [esp], ecx
// 008e97db  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e97df  57                   push edi
// 008e97e0  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 008e97e4  8907                 mov dword ptr [edi], eax
// 008e97e6  8b442420             mov eax, dword ptr [esp + 0x20]
// 008e97ea  894704               mov dword ptr [edi + 4], eax
// 008e97ed  3bc1                 cmp eax, ecx
// 008e97ef  7410                 je 0x8e9801
// 008e97f1  83c004               add eax, 4
// 008e97f4  ba01000000           mov edx, 1
// 008e97f9  f00fc110             lock xadd dword ptr [eax], edx
// 008e97fd  8b442420             mov eax, dword ptr [esp + 0x20]
// 008e9801  894c2410             mov dword ptr [esp + 0x10], ecx
// 008e9805  c744240401000000     mov dword ptr [esp + 4], 1
// 008e980d  3bc1                 cmp eax, ecx
// 008e980f  7440                 je 0x8e9851
// 008e9811  56                   push esi
// 008e9812  8bf0                 mov esi, eax
// 008e9814  83c004               add eax, 4
// 008e9817  83c9ff               or ecx, 0xffffffff
// 008e981a  f00fc108             lock xadd dword ptr [eax], ecx
// 008e981e  751e                 jne 0x8e983e
// 008e9820  8b16                 mov edx, dword ptr [esi]
// 008e9822  8b4204               mov eax, dword ptr [edx + 4]
// 008e9825  8bce                 mov ecx, esi
// 008e9827  ffd0                 call eax
// 008e9829  8d4e08               lea ecx, [esi + 8]
// 008e982c  83caff               or edx, 0xffffffff
// 008e982f  f00fc111             lock xadd dword ptr [ecx], edx
// 008e9833  7509                 jne 0x8e983e
// 008e9835  8b06                 mov eax, dword ptr [esi]
// 008e9837  8b5008               mov edx, dword ptr [eax + 8]
// 008e983a  8bce                 mov ecx, esi
// 008e983c  ffd2                 call edx
// 008e983e  5e                   pop esi
// 008e983f  8bc7                 mov eax, edi
// 008e9841  5f                   pop edi
// 008e9842  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008e9846  64890d00000000       mov dword ptr fs:[0], ecx
// 008e984d  83c410               add esp, 0x10
// 008e9850  c3                   ret 
// 008e9851  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008e9855  8bc7                 mov eax, edi
// 008e9857  5f                   pop edi
// 008e9858  64890d00000000       mov dword ptr fs:[0], ecx
// 008e985f  83c410               add esp, 0x10
// 008e9862  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??$convert_to_named_subs_imp@D@re_detail@boost@@YA?AV?$shared_ptr@V?$named_subexpressions_base@D@re_detail@boost@@@1@V?$shared_ptr@V?$named_subexpressions@D@re_detail@boost@@@1@ABU?$integral_constant@_N$00@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
