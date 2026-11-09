// from server: 100% by auto
// roc 2009-12 0079d600  unit: seg_00790000  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079d600
//
// 0079d600  57                   push edi
// 0079d601  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0079d604  83ff20               cmp edi, 0x20
// 0079d607  7c11                 jl 0x79d61a
// 0079d609  8b4608               mov eax, dword ptr [esi + 8]
// 0079d60c  6840b19e00           push 0x9eb140
// 0079d611  50                   push eax
// 0079d612  e8d9c6feff           call 0x789cf0
// 0079d617  83c408               add esp, 8
// 0079d61a  8b542408             mov edx, dword ptr [esp + 8]
// 0079d61e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0079d622  52                   push edx
// 0079d623  895cfe10             mov dword ptr [esi + edi*8 + 0x10], ebx
// 0079d627  894cfe14             mov dword ptr [esi + edi*8 + 0x14], ecx
// 0079d62b  53                   push ebx
// 0079d62c  47                   inc edi
// 0079d62d  56                   push esi
// 0079d62e  897e0c               mov dword ptr [esi + 0xc], edi
// 0079d631  e80a010000           call 0x79d740
// 0079d636  83c40c               add esp, 0xc
// 0079d639  5f                   pop edi
// 0079d63a  85c0                 test eax, eax
// 0079d63c  7503                 jne 0x79d641
// 0079d63e  ff4e0c               dec dword ptr [esi + 0xc]
// 0079d641  c3                   ret 
// library lua-5.1/lstrlib.c (function _start_capture)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
