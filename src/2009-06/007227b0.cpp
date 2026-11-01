// from server: 100% by auto
// roc 2009-06 007227b0  unit: CRobloxControlColorSelector  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007227b0
//
// 007227b0  57                   push edi
// 007227b1  8b7c2408             mov edi, dword ptr [esp + 8]
// 007227b5  85ff                 test edi, edi
// 007227b7  7e24                 jle 0x7227dd
// 007227b9  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007227bd  53                   push ebx
// 007227be  56                   push esi
// 007227bf  8b742418             mov esi, dword ptr [esp + 0x18]
// 007227c3  2bf2                 sub esi, edx
// 007227c5  8b02                 mov eax, dword ptr [edx]
// 007227c7  8b1c16               mov ebx, dword ptr [esi + edx]
// 007227ca  83c01e               add eax, 0x1e
// 007227cd  8d0440               lea eax, [eax + eax*2]
// 007227d0  83c204               add edx, 4
// 007227d3  83ef01               sub edi, 1
// 007227d6  891c81               mov dword ptr [ecx + eax*4], ebx
// 007227d9  75ea                 jne 0x7227c5
// 007227db  5e                   pop esi
// 007227dc  5b                   pop ebx
// 007227dd  5f                   pop edi
// 007227de  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?SetColors@CXTPPaintManager@@QAEXHPBHPBK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
