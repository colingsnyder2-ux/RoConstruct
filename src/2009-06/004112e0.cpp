// from server: 100% by auto
// roc 2009-06 004112e0  unit: CChildFrame  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004112e0
//
// 004112e0  8b442408             mov eax, dword ptr [esp + 8]
// 004112e4  83f804               cmp eax, 4
// 004112e7  7733                 ja 0x41131c
// 004112e9  ff248528134100       jmp dword ptr [eax*4 + 0x411328]
// 004112f0  8b442404             mov eax, dword ptr [esp + 4]
// 004112f4  c70000000000         mov dword ptr [eax], 0
// 004112fa  c3                   ret 
// 004112fb  8b442404             mov eax, dword ptr [esp + 4]
// 004112ff  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 00411305  c3                   ret 
// 00411306  8b442404             mov eax, dword ptr [esp + 4]
// 0041130a  c700fdffffff         mov dword ptr [eax], 0xfffffffd
// 00411310  c3                   ret 
// 00411311  8b442404             mov eax, dword ptr [esp + 4]
// 00411315  c70001000000         mov dword ptr [eax], 1
// 0041131b  c3                   ret 
// 0041131c  8b442404             mov eax, dword ptr [esp + 4]
// 00411320  c700feffffff         mov dword ptr [eax], 0xfffffffe
// 00411326  c3                   ret 
// 00411327  90                   nop 
// 00411328  1c13                 sbb al, 0x13
// 0041132a  41                   inc ecx
// 0041132b  00f0                 add al, dh
// 0041132d  124100               adc al, byte ptr [ecx]
// 00411330  fb                   sti 
// 00411331  124100               adc al, byte ptr [ecx]
// 00411334  1113                 adc dword ptr [ebx], edx
// 00411336  41                   inc ecx
// 00411337  0006                 add byte ptr [esi], al
// 00411339  134100               adc eax, dword ptr [ecx]
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?from_special@?$int_adapter@K@date_time@boost@@SA?AV123@W4special_values@23@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
