// from server: 100% by Yeetserama
// roc 2010-06 004420b0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 295 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004420b0
//
// 004420b0  64a100000000         mov eax, dword ptr fs:[0]
// 004420b6  6aff                 push -1
// 004420b8  68d8119800           push 0x9811d8
// 004420bd  50                   push eax
// 004420be  64892500000000       mov dword ptr fs:[0], esp
// 004420c5  83ec3c               sub esp, 0x3c
// 004420c8  55                   push ebp
// 004420c9  57                   push edi
// 004420ca  8bf9                 mov edi, ecx
// 004420cc  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004420cf  8b4104               mov eax, dword ptr [ecx + 4]
// 004420d2  80782900             cmp byte ptr [eax + 0x29], 0
// 004420d6  8be9                 mov ebp, ecx
// 004420d8  751a                 jne 0x4420f4
// 004420da  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004420de  8b09                 mov ecx, dword ptr [ecx]
// 004420e0  39480c               cmp dword ptr [eax + 0xc], ecx
// 004420e3  7305                 jae 0x4420ea
// 004420e5  8b4008               mov eax, dword ptr [eax + 8]
// 004420e8  eb04                 jmp 0x4420ee
// 004420ea  8be8                 mov ebp, eax
// 004420ec  8b00                 mov eax, dword ptr [eax]
// 004420ee  80782900             cmp byte ptr [eax + 0x29], 0
// 004420f2  74ec                 je 0x4420e0
// 004420f4  8b5718               mov edx, dword ptr [edi + 0x18]
// 004420f7  56                   push esi
// 004420f8  8b37                 mov esi, dword ptr [edi]
// 004420fa  89542410             mov dword ptr [esp + 0x10], edx
// 004420fe  85f6                 test esi, esi
// 00442100  7404                 je 0x442106
// 00442102  3bf6                 cmp esi, esi
// 00442104  7406                 je 0x44210c
// 00442106  ff150ca99e00         call dword ptr [0x9ea90c]
// 0044210c  3b6c2410             cmp ebp, dword ptr [esp + 0x10]
// 00442110  740f                 je 0x442121
// 00442112  8b442458             mov eax, dword ptr [esp + 0x58]
// 00442116  8b08                 mov ecx, dword ptr [eax]
// 00442118  3b4d0c               cmp ecx, dword ptr [ebp + 0xc]
// 0044211b  0f8386000000         jae 0x4421a7
// 00442121  6a04                 push 4
// 00442123  e878583600           call 0x7a79a0
// 00442128  33c9                 xor ecx, ecx
// 0044212a  83c404               add esp, 4
// 0044212d  3bc1                 cmp eax, ecx
// 0044212f  7408                 je 0x442139
// 00442131  8d542414             lea edx, [esp + 0x14]
// 00442135  8910                 mov dword ptr [eax], edx
// 00442137  eb02                 jmp 0x44213b
// 00442139  33c0                 xor eax, eax
// 0044213b  89442414             mov dword ptr [esp + 0x14], eax
// 0044213f  894c2420             mov dword ptr [esp + 0x20], ecx
// 00442143  894c2424             mov dword ptr [esp + 0x24], ecx
// 00442147  894c2428             mov dword ptr [esp + 0x28], ecx
// 0044214b  8b442458             mov eax, dword ptr [esp + 0x58]
// 0044214f  8b08                 mov ecx, dword ptr [eax]
// 00442151  8d542414             lea edx, [esp + 0x14]
// 00442155  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00442159  52                   push edx
// 0044215a  8d4c2434             lea ecx, [esp + 0x34]
// 0044215e  c744245401000000     mov dword ptr [esp + 0x54], 1
// 00442166  e89546ffff           call 0x436800
// 0044216b  8d44242c             lea eax, [esp + 0x2c]
// 0044216f  50                   push eax
// 00442170  55                   push ebp
// 00442171  56                   push esi
// 00442172  8d4c2418             lea ecx, [esp + 0x18]
// 00442176  51                   push ecx
// 00442177  8bcf                 mov ecx, edi
// 00442179  c644246002           mov byte ptr [esp + 0x60], 2
// 0044217e  e80dfdffff           call 0x441e90
// 00442183  8b30                 mov esi, dword ptr [eax]
// 00442185  8b6804               mov ebp, dword ptr [eax + 4]
// 00442188  8d4c2430             lea ecx, [esp + 0x30]
// 0044218c  c644245001           mov byte ptr [esp + 0x50], 1
// 00442191  e83aa23500           call 0x79c3d0
// 00442196  8d4c2414             lea ecx, [esp + 0x14]
// 0044219a  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 004421a2  e829a23500           call 0x79c3d0
// 004421a7  85f6                 test esi, esi
// 004421a9  7528                 jne 0x4421d3
// 004421ab  ff150ca99e00         call dword ptr [0x9ea90c]
// 004421b1  3b6e18               cmp ebp, dword ptr [esi + 0x18]
// 004421b4  5e                   pop esi
// 004421b5  7506                 jne 0x4421bd
// 004421b7  ff150ca99e00         call dword ptr [0x9ea90c]
// 004421bd  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 004421c1  5f                   pop edi
// 004421c2  8d4510               lea eax, [ebp + 0x10]
// 004421c5  5d                   pop ebp
// 004421c6  64890d00000000       mov dword ptr fs:[0], ecx
// 004421cd  83c448               add esp, 0x48
// 004421d0  c20400               ret 4
// 004421d3  8b36                 mov esi, dword ptr [esi]
// 004421d5  ebda                 jmp 0x4421b1
// copied from an identical function in another client (function ??A?$map@IUValue@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUValue@@@std@@@3@@std@@QAEAAUValue@@ABI@Z)

// from server: 100% by EspClaude
// from server: 69% by colin
// roc 2008-06 00442140  unit: TextureItem  size: 295 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00442140
//
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <map>
#include <vector>
struct Elem { int x; };
struct Value : std::vector<Elem> {
    Value() {}
    Value(const Value&);
    ~Value();
};

Value& lookup(std::map<unsigned int, Value>& m, const unsigned int& k)
{
    return m[k];
}