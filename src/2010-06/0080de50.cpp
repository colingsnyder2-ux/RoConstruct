// from server: 100% by auto
// roc 2010-06 0080de50  unit: CXTThemeManagerStyleFactory  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080de50
//
// 0080de50  83790400             cmp dword ptr [ecx + 4], 0
// 0080de54  740a                 je 0x80de60
// 0080de56  8b4904               mov ecx, dword ptr [ecx + 4]
// 0080de59  8b01                 mov eax, dword ptr [ecx]
// 0080de5b  8b5004               mov edx, dword ptr [eax + 4]
// 0080de5e  ffe2                 jmp edx
// 0080de60  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ?RefreshMetrics@CXTThemeManagerStyleFactory@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
