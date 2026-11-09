// from server: 100% by auto
// roc 2010-06 007e7840  unit: CRobloxTreeCtrl  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e7840
//
// 007e7840  56                   push esi
// 007e7841  57                   push edi
// 007e7842  8bf1                 mov esi, ecx
// 007e7844  33ff                 xor edi, edi
// 007e7846  e8d5eeffff           call 0x7e6720
// 007e784b  85c0                 test eax, eax
// 007e784d  740e                 je 0x7e785d
// 007e784f  90                   nop 
// 007e7850  50                   push eax
// 007e7851  8bce                 mov ecx, esi
// 007e7853  47                   inc edi
// 007e7854  e817efffff           call 0x7e6770
// 007e7859  85c0                 test eax, eax
// 007e785b  75f3                 jne 0x7e7850
// 007e785d  8bc7                 mov eax, edi
// 007e785f  5f                   pop edi
// 007e7860  5e                   pop esi
// 007e7861  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?GetSelectedCount@CXTTreeBase@@QBEIXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
