// from server: 100% by auto
// roc 2008-06 0055c100  unit: RBX::VInstance::?$SignalDesc  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055c100
//
// 0055c100  837c240400           cmp dword ptr [esp + 4], 0
// 0055c105  7510                 jne 0x55c117
// 0055c107  817c240800000080     cmp dword ptr [esp + 8], 0x80000000
// 0055c10f  7506                 jne 0x55c117
// 0055c111  b801000000           mov eax, 1
// 0055c116  c3                   ret 
// 0055c117  33c0                 xor eax, eax
// 0055c119  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_neg_inf@?$int_adapter@_J@date_time@boost@@SA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
