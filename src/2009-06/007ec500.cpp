// from server: 100% by auto
// roc 2009-06 007ec500  unit: VCEdit::?$CXTMaskEditT  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ec500
//
// 007ec500  8b442404             mov eax, dword ptr [esp + 4]
// 007ec504  56                   push esi
// 007ec505  8bf1                 mov esi, ecx
// 007ec507  83f828               cmp eax, 0x28
// 007ec50a  7405                 je 0x7ec511
// 007ec50c  83f826               cmp eax, 0x26
// 007ec50f  752d                 jne 0x7ec53e
// 007ec511  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 007ec517  85c9                 test ecx, ecx
// 007ec519  7423                 je 0x7ec53e
// 007ec51b  6a65                 push 0x65
// 007ec51d  e88ed3f9ff           call 0x7898b0
// 007ec522  8bc8                 mov ecx, eax
// 007ec524  e857f4ffff           call 0x7eb980
// 007ec529  85c0                 test eax, eax
// 007ec52b  7411                 je 0x7ec53e
// 007ec52d  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 007ec533  8b11                 mov edx, dword ptr [ecx]
// 007ec535  50                   push eax
// 007ec536  8b82d0000000         mov eax, dword ptr [edx + 0xd0]
// 007ec53c  ffd0                 call eax
// 007ec53e  8bce                 mov ecx, esi
// 007ec540  e8c3caf2ff           call 0x719008
// 007ec545  5e                   pop esi
// 007ec546  c20c00               ret 0xc
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?OnSysKeyDown@CXTPPropertyGridView@@IAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
