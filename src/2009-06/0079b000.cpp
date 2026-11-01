// from server: 100% by auto
// roc 2009-06 0079b000  unit: CXTPResourceManager  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079b000
//
// 0079b000  56                   push esi
// 0079b001  8b742414             mov esi, dword ptr [esp + 0x14]
// 0079b005  85f6                 test esi, esi
// 0079b007  7506                 jne 0x79b00f
// 0079b009  33c0                 xor eax, eax
// 0079b00b  5e                   pop esi
// 0079b00c  c21000               ret 0x10
// 0079b00f  8b442410             mov eax, dword ptr [esp + 0x10]
// 0079b013  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0079b017  8b542408             mov edx, dword ptr [esp + 8]
// 0079b01b  56                   push esi
// 0079b01c  6870a97900           push 0x79a970
// 0079b021  50                   push eax
// 0079b022  51                   push ecx
// 0079b023  52                   push edx
// 0079b024  ff1578e38900         call dword ptr [0x89e378]
// 0079b02a  0fb706               movzx eax, word ptr [esi]
// 0079b02d  6685c0               test ax, ax
// 0079b030  7509                 jne 0x79b03b
// 0079b032  b801000000           mov eax, 1
// 0079b037  5e                   pop esi
// 0079b038  c21000               ret 0x10
// 0079b03b  33d2                 xor edx, edx
// 0079b03d  b909040000           mov ecx, 0x409
// 0079b042  663bc1               cmp ax, cx
// 0079b045  0f94c2               sete dl
// 0079b048  5e                   pop esi
// 0079b049  8bc2                 mov eax, edx
// 0079b04b  c21000               ret 0x10
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?EnumResNameProc@CXTPResourceManager@@KGHPAUHINSTANCE__@@PBDPADJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
