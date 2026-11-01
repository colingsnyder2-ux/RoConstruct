// from server: 100% by auto
// roc 2009-06 0077ee20  unit: CXTThemeManagerStyleFactory  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077ee20
//
// 0077ee20  83790400             cmp dword ptr [ecx + 4], 0
// 0077ee24  740a                 je 0x77ee30
// 0077ee26  8b4904               mov ecx, dword ptr [ecx + 4]
// 0077ee29  8b01                 mov eax, dword ptr [ecx]
// 0077ee2b  8b5004               mov edx, dword ptr [eax + 4]
// 0077ee2e  ffe2                 jmp edx
// 0077ee30  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTThemeManager.cpp (function ?RefreshMetrics@CXTThemeManagerStyleFactory@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTThemeManager.cpp
