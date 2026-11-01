// from server: 100% by colin
// roc 2007-03 006bfb80  unit: seg_006b0000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006bfb80
//
// 006bfb80  8b442408             mov eax, dword ptr [esp + 8]
// 006bfb84  85c0                 test eax, eax
// 006bfb86  7504                 jne 0x6bfb8c
// 006bfb88  33d2                 xor edx, edx
// 006bfb8a  eb03                 jmp 0x6bfb8f
// 006bfb8c  8b5004               mov edx, dword ptr [eax + 4]
// 006bfb8f  8b442404             mov eax, dword ptr [esp + 4]
// 006bfb93  85c0                 test eax, eax
// 006bfb95  7403                 je 0x6bfb9a
// 006bfb97  8b4004               mov eax, dword ptr [eax + 4]
// 006bfb9a  56                   push esi
// 006bfb9b  8b742410             mov esi, dword ptr [esp + 0x10]
// 006bfb9f  56                   push esi
// 006bfba0  52                   push edx
// 006bfba1  50                   push eax
// 006bfba2  8b4104               mov eax, dword ptr [ecx + 4]
// 006bfba5  50                   push eax
// 006bfba6  ff1578d17700         call dword ptr [0x77d178]
// 006bfbac  5e                   pop esi
// 006bfbad  c20c00               ret 0xc
// copied from an identical function in another client (function ?CombineRgn@CRgn@@QAEHPBV1@0H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp