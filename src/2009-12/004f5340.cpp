// from server: 100% by auto
// roc 2009-12 004f5340  unit: RBX::GfxAttachement  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004f5340
//
// 004f5340  8bc1                 mov eax, ecx
// 004f5342  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004f5346  8b11                 mov edx, dword ptr [ecx]
// 004f5348  8910                 mov dword ptr [eax], edx
// 004f534a  8b4904               mov ecx, dword ptr [ecx + 4]
// 004f534d  894804               mov dword ptr [eax + 4], ecx
// 004f5350  85c9                 test ecx, ecx
// 004f5352  740c                 je 0x4f5360
// 004f5354  83c108               add ecx, 8
// 004f5357  ba01000000           mov edx, 1
// 004f535c  f00fc111             lock xadd dword ptr [ecx], edx
// 004f5360  c20400               ret 4
// library templates-boost-1_34_1/deque_wp.cpp (function ??0?$weak_ptr@UT@@@boost@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 deque_wp.cpp
