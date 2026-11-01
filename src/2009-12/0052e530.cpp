// from server: 100% by auto
// roc 2009-12 0052e530  unit: RBX::Network::VGuidRegistryService::?$FactoryProduct  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052e530
//
// 0052e530  8b4904               mov ecx, dword ptr [ecx + 4]
// 0052e533  85c9                 test ecx, ecx
// 0052e535  7413                 je 0x52e54a
// 0052e537  8d4108               lea eax, [ecx + 8]
// 0052e53a  83caff               or edx, 0xffffffff
// 0052e53d  f00fc110             lock xadd dword ptr [eax], edx
// 0052e541  7507                 jne 0x52e54a
// 0052e543  8b01                 mov eax, dword ptr [ecx]
// 0052e545  8b5008               mov edx, dword ptr [eax + 8]
// 0052e548  ffe2                 jmp edx
// 0052e54a  c3                   ret 
// library templates-boost-1_34_1/deque_wp.cpp (function ??1?$weak_ptr@UT@@@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 deque_wp.cpp
