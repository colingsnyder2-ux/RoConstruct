// from server: 100% by colin
// roc 2007-08 0054b210  unit: boost::iostreams::Uinput::V?$chain::?$chain_client  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054b210
//
// 0054b210  6aff                 push -1
// 0054b212  6892247500           push 0x752492
// 0054b217  64a100000000         mov eax, dword ptr fs:[0]
// 0054b21d  50                   push eax
// 0054b21e  64892500000000       mov dword ptr fs:[0], esp
// 0054b225  83ec20               sub esp, 0x20
// 0054b228  56                   push esi
// 0054b229  68c4787a00           push 0x7a78c4
// 0054b22e  8d4c240c             lea ecx, [esp + 0xc]
// 0054b232  c744240800000000     mov dword ptr [esp + 8], 0
// 0054b23a  ff1598e67700         call dword ptr [0x77e698]
// 0054b240  8b742434             mov esi, dword ptr [esp + 0x34]
// 0054b244  8d442408             lea eax, [esp + 8]
// 0054b248  50                   push eax
// 0054b249  8bce                 mov ecx, esi
// 0054b24b  c744243001000000     mov dword ptr [esp + 0x30], 1
// 0054b253  e8687becff           call 0x412dc0
// 0054b258  c7063c787a00         mov dword ptr [esi], 0x7a783c
// 0054b25e  8d4c2408             lea ecx, [esp + 8]
// 0054b262  c744240401000000     mov dword ptr [esp + 4], 1
// 0054b26a  c644242c00           mov byte ptr [esp + 0x2c], 0
// 0054b26f  ff15ace67700         call dword ptr [0x77e6ac]
// 0054b275  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0054b279  8bc6                 mov eax, esi
// 0054b27b  5e                   pop esi
// 0054b27c  64890d00000000       mov dword ptr fs:[0], ecx
// 0054b283  83c42c               add esp, 0x2c
// 0054b286  c3                   ret 
// copied from an identical function in another client (function ?cant_read@detail@iostreams@boost@@YA?AVfailure@ios_base@std@@XZ)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp