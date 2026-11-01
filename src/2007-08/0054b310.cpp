// from server: 100% by colin
// roc 2007-08 0054b310  unit: boost::iostreams::Uinput::V?$chain::?$chain_client  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054b310
//
// 0054b310  6aff                 push -1
// 0054b312  6892247500           push 0x752492
// 0054b317  64a100000000         mov eax, dword ptr fs:[0]
// 0054b31d  50                   push eax
// 0054b31e  64892500000000       mov dword ptr fs:[0], esp
// 0054b325  83ec20               sub esp, 0x20
// 0054b328  56                   push esi
// 0054b329  68e8787a00           push 0x7a78e8
// 0054b32e  8d4c240c             lea ecx, [esp + 0xc]
// 0054b332  c744240800000000     mov dword ptr [esp + 8], 0
// 0054b33a  ff1598e67700         call dword ptr [0x77e698]
// 0054b340  8b742434             mov esi, dword ptr [esp + 0x34]
// 0054b344  8d442408             lea eax, [esp + 8]
// 0054b348  50                   push eax
// 0054b349  8bce                 mov ecx, esi
// 0054b34b  c744243001000000     mov dword ptr [esp + 0x30], 1
// 0054b353  e8687aecff           call 0x412dc0
// 0054b358  c7063c787a00         mov dword ptr [esi], 0x7a783c
// 0054b35e  8d4c2408             lea ecx, [esp + 8]
// 0054b362  c744240401000000     mov dword ptr [esp + 4], 1
// 0054b36a  c644242c00           mov byte ptr [esp + 0x2c], 0
// 0054b36f  ff15ace67700         call dword ptr [0x77e6ac]
// 0054b375  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0054b379  8bc6                 mov eax, esi
// 0054b37b  5e                   pop esi
// 0054b37c  64890d00000000       mov dword ptr fs:[0], ecx
// 0054b383  83c42c               add esp, 0x2c
// 0054b386  c3                   ret 
// copied from an identical function in another client (function ?bad_putback@detail@iostreams@boost@@YA?AVfailure@ios_base@std@@XZ)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp