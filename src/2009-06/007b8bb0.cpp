// from server: 100% by auto
// roc 2009-06 007b8bb0  unit: CXTPRibbonBar  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b8bb0
//
// 007b8bb0  8b442404             mov eax, dword ptr [esp + 4]
// 007b8bb4  8b5128               mov edx, dword ptr [ecx + 0x28]
// 007b8bb7  8910                 mov dword ptr [eax], edx
// 007b8bb9  8b512c               mov edx, dword ptr [ecx + 0x2c]
// 007b8bbc  895004               mov dword ptr [eax + 4], edx
// 007b8bbf  8b5130               mov edx, dword ptr [ecx + 0x30]
// 007b8bc2  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 007b8bc5  895008               mov dword ptr [eax + 8], edx
// 007b8bc8  89480c               mov dword ptr [eax + 0xc], ecx
// 007b8bcb  c20400               ret 4
// library xtp-15.2.1/Source\Chart\Diagram\Diagram2D\XTPChartDiagram2DPane.cpp (function ?GetBounds@CXTPChartDiagram2DPaneView@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/Diagram/Diagram2D/XTPChartDiagram2DPane.cpp
