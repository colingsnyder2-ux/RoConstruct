// from server: 100% by auto
// roc 2007-03 005bfe70  unit: seg_005b0000  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005bfe70
//
// 005bfe70  53                   push ebx
// 005bfe71  55                   push ebp
// 005bfe72  6a10                 push 0x10
// 005bfe74  57                   push edi
// 005bfe75  56                   push esi
// 005bfe76  e8a59b0300           call 0x5f9a20
// 005bfe7b  8bef                 mov ebp, edi
// 005bfe7d  2b6e20               sub ebp, dword ptr [esi + 0x20]
// 005bfe80  8bd8                 mov ebx, eax
// 005bfe82  83c40c               add esp, 0xc
// 005bfe85  837b0806             cmp dword ptr [ebx + 8], 6
// 005bfe89  740f                 je 0x5bfe9a
// 005bfe8b  6814977b00           push 0x7b9714
// 005bfe90  57                   push edi
// 005bfe91  56                   push esi
// 005bfe92  e849340000           call 0x5c32e0
// 005bfe97  83c40c               add esp, 0xc
// 005bfe9a  8b4e08               mov ecx, dword ptr [esi + 8]
// 005bfe9d  3bcf                 cmp ecx, edi
// 005bfe9f  761d                 jbe 0x5bfebe
// 005bfea1  8d41f0               lea eax, [ecx - 0x10]
// 005bfea4  8b10                 mov edx, dword ptr [eax]
// 005bfea6  8911                 mov dword ptr [ecx], edx
// 005bfea8  8b5004               mov edx, dword ptr [eax + 4]
// 005bfeab  895104               mov dword ptr [ecx + 4], edx
// 005bfeae  8b5008               mov edx, dword ptr [eax + 8]
// 005bfeb1  895018               mov dword ptr [eax + 0x18], edx
// 005bfeb4  83e910               sub ecx, 0x10
// 005bfeb7  83e810               sub eax, 0x10
// 005bfeba  3bcf                 cmp ecx, edi
// 005bfebc  77e6                 ja 0x5bfea4
// 005bfebe  8b461c               mov eax, dword ptr [esi + 0x1c]
// 005bfec1  2b4608               sub eax, dword ptr [esi + 8]
// 005bfec4  83f810               cmp eax, 0x10
// 005bfec7  7f1b                 jg 0x5bfee4
// 005bfec9  8b462c               mov eax, dword ptr [esi + 0x2c]
// 005bfecc  83f801               cmp eax, 1
// 005bfecf  7c06                 jl 0x5bfed7
// 005bfed1  8d0c00               lea ecx, [eax + eax]
// 005bfed4  51                   push ecx
// 005bfed5  eb04                 jmp 0x5bfedb
// 005bfed7  83c001               add eax, 1
// 005bfeda  50                   push eax
// 005bfedb  56                   push esi
// 005bfedc  e82ffdffff           call 0x5bfc10
// 005bfee1  83c408               add esp, 8
// 005bfee4  83460810             add dword ptr [esi + 8], 0x10
// 005bfee8  8b4620               mov eax, dword ptr [esi + 0x20]
// 005bfeeb  8b13                 mov edx, dword ptr [ebx]
// 005bfeed  03c5                 add eax, ebp
// 005bfeef  8910                 mov dword ptr [eax], edx
// 005bfef1  8b4b04               mov ecx, dword ptr [ebx + 4]
// 005bfef4  894804               mov dword ptr [eax + 4], ecx
// 005bfef7  8b5308               mov edx, dword ptr [ebx + 8]
// 005bfefa  5d                   pop ebp
// 005bfefb  895008               mov dword ptr [eax + 8], edx
// 005bfefe  5b                   pop ebx
// 005bfeff  c3                   ret 
// library lua-5.1.1/ldo.c (function _tryfuncTM)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
