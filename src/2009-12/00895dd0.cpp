// from server: 100% by auto
// roc 2009-12 00895dd0  unit: CXTPRibbonBar  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00895dd0
//
// 00895dd0  8b442404             mov eax, dword ptr [esp + 4]
// 00895dd4  8b5128               mov edx, dword ptr [ecx + 0x28]
// 00895dd7  8910                 mov dword ptr [eax], edx
// 00895dd9  8b512c               mov edx, dword ptr [ecx + 0x2c]
// 00895ddc  895004               mov dword ptr [eax + 4], edx
// 00895ddf  8b5130               mov edx, dword ptr [ecx + 0x30]
// 00895de2  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 00895de5  895008               mov dword ptr [eax + 8], edx
// 00895de8  89480c               mov dword ptr [eax + 0xc], ecx
// 00895deb  c20400               ret 4
// library xtp-15.2.1/Source\Chart\Diagram\Diagram2D\XTPChartDiagram2DPane.cpp (function ?GetBounds@CXTPChartDiagram2DPaneView@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/Diagram/Diagram2D/XTPChartDiagram2DPane.cpp
