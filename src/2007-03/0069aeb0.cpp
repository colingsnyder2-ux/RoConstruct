// from server: 100% by auto
// roc 2007-03 0069aeb0  unit: seg_00690000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0069aeb0
//
// 0069aeb0  8b442404             mov eax, dword ptr [esp + 4]
// 0069aeb4  8b5124               mov edx, dword ptr [ecx + 0x24]
// 0069aeb7  8910                 mov dword ptr [eax], edx
// 0069aeb9  8b5128               mov edx, dword ptr [ecx + 0x28]
// 0069aebc  895004               mov dword ptr [eax + 4], edx
// 0069aebf  8b512c               mov edx, dword ptr [ecx + 0x2c]
// 0069aec2  8b4930               mov ecx, dword ptr [ecx + 0x30]
// 0069aec5  895008               mov dword ptr [eax + 8], edx
// 0069aec8  89480c               mov dword ptr [eax + 0xc], ecx
// 0069aecb  c20400               ret 4
// library xtp-15.2.1/Source\Chart\Styles\Funnel\XTPChartFunnelDiagram.cpp (function ?GetBounds@CXTPChartDiagramView@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/Styles/Funnel/XTPChartFunnelDiagram.cpp
