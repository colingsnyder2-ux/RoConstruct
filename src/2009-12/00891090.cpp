// from server: 100% by auto
// roc 2009-12 00891090  unit: ATL::CRegObject  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00891090
//
// 00891090  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00891094  8bc1                 mov eax, ecx
// 00891096  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0089109a  56                   push esi
// 0089109b  8b742414             mov esi, dword ptr [esp + 0x14]
// 0089109f  8908                 mov dword ptr [eax], ecx
// 008910a1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008910a5  894804               mov dword ptr [eax + 4], ecx
// 008910a8  894814               mov dword ptr [eax + 0x14], ecx
// 008910ab  57                   push edi
// 008910ac  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 008910b0  895008               mov dword ptr [eax + 8], edx
// 008910b3  895018               mov dword ptr [eax + 0x18], edx
// 008910b6  8b542420             mov edx, dword ptr [esp + 0x20]
// 008910ba  89700c               mov dword ptr [eax + 0xc], esi
// 008910bd  89701c               mov dword ptr [eax + 0x1c], esi
// 008910c0  897810               mov dword ptr [eax + 0x10], edi
// 008910c3  897820               mov dword ptr [eax + 0x20], edi
// 008910c6  33c9                 xor ecx, ecx
// 008910c8  5f                   pop edi
// 008910c9  895024               mov dword ptr [eax + 0x24], edx
// 008910cc  894828               mov dword ptr [eax + 0x28], ecx
// 008910cf  89482c               mov dword ptr [eax + 0x2c], ecx
// 008910d2  5e                   pop esi
// 008910d3  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ??0DOCK_INFO@CXTPDockBar@@QAE@PAVCXTPToolBar@@VCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp
