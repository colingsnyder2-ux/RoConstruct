// from server: 100% by auto
// roc 2009-12 008c7090  unit: VCEdit::?$CXTMaskEditT  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c7090
//
// 008c7090  8b442404             mov eax, dword ptr [esp + 4]
// 008c7094  56                   push esi
// 008c7095  8bf1                 mov esi, ecx
// 008c7097  83f828               cmp eax, 0x28
// 008c709a  7405                 je 0x8c70a1
// 008c709c  83f826               cmp eax, 0x26
// 008c709f  752d                 jne 0x8c70ce
// 008c70a1  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 008c70a7  85c9                 test ecx, ecx
// 008c70a9  7423                 je 0x8c70ce
// 008c70ab  6a65                 push 0x65
// 008c70ad  e80ed8f9ff           call 0x8648c0
// 008c70b2  8bc8                 mov ecx, eax
// 008c70b4  e867f4ffff           call 0x8c6520
// 008c70b9  85c0                 test eax, eax
// 008c70bb  7411                 je 0x8c70ce
// 008c70bd  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 008c70c3  8b11                 mov edx, dword ptr [ecx]
// 008c70c5  50                   push eax
// 008c70c6  8b82d0000000         mov eax, dword ptr [edx + 0xd0]
// 008c70cc  ffd0                 call eax
// 008c70ce  8bce                 mov ecx, esi
// 008c70d0  e85bcdf2ff           call 0x7f3e30
// 008c70d5  5e                   pop esi
// 008c70d6  c20c00               ret 0xc
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?OnSysKeyDown@CXTPPropertyGridView@@IAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
