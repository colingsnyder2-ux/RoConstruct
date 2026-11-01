// from server: 100% by auto
// roc 2009-12 00859ee0  unit: CXTThemeManagerStyleFactory  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00859ee0
//
// 00859ee0  83790400             cmp dword ptr [ecx + 4], 0
// 00859ee4  740a                 je 0x859ef0
// 00859ee6  8b4904               mov ecx, dword ptr [ecx + 4]
// 00859ee9  8b01                 mov eax, dword ptr [ecx]
// 00859eeb  8b5004               mov edx, dword ptr [eax + 4]
// 00859eee  ffe2                 jmp edx
// 00859ef0  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTThemeManager.cpp (function ?RefreshMetrics@CXTThemeManagerStyleFactory@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTThemeManager.cpp
