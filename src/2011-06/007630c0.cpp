// from server: 100% by auto
// roc 2011-06 007630c0  unit: seg_00760000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007630c0
//
// 007630c0  8b442408             mov eax, dword ptr [esp + 8]
// 007630c4  8b4804               mov ecx, dword ptr [eax + 4]
// 007630c7  8b10                 mov edx, dword ptr [eax]
// 007630c9  8b442404             mov eax, dword ptr [esp + 4]
// 007630cd  51                   push ecx
// 007630ce  52                   push edx
// 007630cf  50                   push eax
// 007630d0  e8cbb90100           call 0x77eaa0
// 007630d5  83c40c               add esp, 0xc
// 007630d8  c3                   ret 
// library lua-5.1/lapi.c (function _f_call)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
