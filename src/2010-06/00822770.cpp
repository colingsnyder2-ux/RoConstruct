// from server: 100% by auto
// roc 2010-06 00822770  unit: CXTPResourceManager  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00822770
//
// 00822770  56                   push esi
// 00822771  8b742414             mov esi, dword ptr [esp + 0x14]
// 00822775  85f6                 test esi, esi
// 00822777  7506                 jne 0x82277f
// 00822779  33c0                 xor eax, eax
// 0082277b  5e                   pop esi
// 0082277c  c21000               ret 0x10
// 0082277f  8b442410             mov eax, dword ptr [esp + 0x10]
// 00822783  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00822787  8b542408             mov edx, dword ptr [esp + 8]
// 0082278b  56                   push esi
// 0082278c  68e0208200           push 0x8220e0
// 00822791  50                   push eax
// 00822792  51                   push ecx
// 00822793  52                   push edx
// 00822794  ff1558a29e00         call dword ptr [0x9ea258]
// 0082279a  0fb706               movzx eax, word ptr [esi]
// 0082279d  6685c0               test ax, ax
// 008227a0  7509                 jne 0x8227ab
// 008227a2  b801000000           mov eax, 1
// 008227a7  5e                   pop esi
// 008227a8  c21000               ret 0x10
// 008227ab  33d2                 xor edx, edx
// 008227ad  b909040000           mov ecx, 0x409
// 008227b2  663bc1               cmp ax, cx
// 008227b5  0f94c2               sete dl
// 008227b8  5e                   pop esi
// 008227b9  8bc2                 mov eax, edx
// 008227bb  c21000               ret 0x10
// library xtp-13.2.1/Source\Common\XTPResourceManager.cpp (function ?EnumResNameProc@CXTPResourceManager@@KGHPAUHINSTANCE__@@PBDPADJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPResourceManager.cpp
