// from server: 100% by EspClaude
// roc 2009-06 0043c620  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 295 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043c620
//
// 0043c620  64a100000000         mov eax, dword ptr fs:[0]
// 0043c626  6aff                 push -1
// 0043c628  6818008500           push 0x850018
// 0043c62d  50                   push eax
// 0043c62e  64892500000000       mov dword ptr fs:[0], esp
// 0043c635  83ec3c               sub esp, 0x3c
// 0043c638  55                   push ebp
// 0043c639  57                   push edi
// 0043c63a  8bf9                 mov edi, ecx
// 0043c63c  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0043c63f  8b4104               mov eax, dword ptr [ecx + 4]
// 0043c642  80782900             cmp byte ptr [eax + 0x29], 0
// 0043c646  8be9                 mov ebp, ecx
// 0043c648  751a                 jne 0x43c664
// 0043c64a  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0043c64e  8b09                 mov ecx, dword ptr [ecx]
// 0043c650  39480c               cmp dword ptr [eax + 0xc], ecx
// 0043c653  7305                 jae 0x43c65a
// 0043c655  8b4008               mov eax, dword ptr [eax + 8]
// 0043c658  eb04                 jmp 0x43c65e
// 0043c65a  8be8                 mov ebp, eax
// 0043c65c  8b00                 mov eax, dword ptr [eax]
// 0043c65e  80782900             cmp byte ptr [eax + 0x29], 0
// 0043c662  74ec                 je 0x43c650
// 0043c664  8b5718               mov edx, dword ptr [edi + 0x18]
// 0043c667  56                   push esi
// 0043c668  8b37                 mov esi, dword ptr [edi]
// 0043c66a  89542410             mov dword ptr [esp + 0x10], edx
// 0043c66e  85f6                 test esi, esi
// 0043c670  7404                 je 0x43c676
// 0043c672  3bf6                 cmp esi, esi
// 0043c674  7406                 je 0x43c67c
// 0043c676  ff15ace98900         call dword ptr [0x89e9ac]
// 0043c67c  3b6c2410             cmp ebp, dword ptr [esp + 0x10]
// 0043c680  740f                 je 0x43c691
// 0043c682  8b442458             mov eax, dword ptr [esp + 0x58]
// 0043c686  8b08                 mov ecx, dword ptr [eax]
// 0043c688  3b4d0c               cmp ecx, dword ptr [ebp + 0xc]
// 0043c68b  0f8386000000         jae 0x43c717
// 0043c691  6a04                 push 4
// 0043c693  e8a0c32d00           call 0x718a38
// 0043c698  33c9                 xor ecx, ecx
// 0043c69a  83c404               add esp, 4
// 0043c69d  3bc1                 cmp eax, ecx
// 0043c69f  7408                 je 0x43c6a9
// 0043c6a1  8d542414             lea edx, [esp + 0x14]
// 0043c6a5  8910                 mov dword ptr [eax], edx
// 0043c6a7  eb02                 jmp 0x43c6ab
// 0043c6a9  33c0                 xor eax, eax
// 0043c6ab  89442414             mov dword ptr [esp + 0x14], eax
// 0043c6af  894c2420             mov dword ptr [esp + 0x20], ecx
// 0043c6b3  894c2424             mov dword ptr [esp + 0x24], ecx
// 0043c6b7  894c2428             mov dword ptr [esp + 0x28], ecx
// 0043c6bb  8b442458             mov eax, dword ptr [esp + 0x58]
// 0043c6bf  8b08                 mov ecx, dword ptr [eax]
// 0043c6c1  8d542414             lea edx, [esp + 0x14]
// 0043c6c5  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0043c6c9  52                   push edx
// 0043c6ca  8d4c2434             lea ecx, [esp + 0x34]
// 0043c6ce  c744245401000000     mov dword ptr [esp + 0x54], 1
// 0043c6d6  e865b21f00           call 0x637940
// 0043c6db  8d44242c             lea eax, [esp + 0x2c]
// 0043c6df  50                   push eax
// 0043c6e0  55                   push ebp
// 0043c6e1  56                   push esi
// 0043c6e2  8d4c2418             lea ecx, [esp + 0x18]
// 0043c6e6  51                   push ecx
// 0043c6e7  8bcf                 mov ecx, edi
// 0043c6e9  c644246002           mov byte ptr [esp + 0x60], 2
// 0043c6ee  e80dfdffff           call 0x43c400
// 0043c6f3  8b30                 mov esi, dword ptr [eax]
// 0043c6f5  8b6804               mov ebp, dword ptr [eax + 4]
// 0043c6f8  8d4c2430             lea ecx, [esp + 0x30]
// 0043c6fc  c644245001           mov byte ptr [esp + 0x50], 1
// 0043c701  e8baf22c00           call 0x70b9c0
// 0043c706  8d4c2414             lea ecx, [esp + 0x14]
// 0043c70a  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 0043c712  e8a9f22c00           call 0x70b9c0
// 0043c717  85f6                 test esi, esi
// 0043c719  7528                 jne 0x43c743
// 0043c71b  ff15ace98900         call dword ptr [0x89e9ac]
// 0043c721  3b6e18               cmp ebp, dword ptr [esi + 0x18]
// 0043c724  5e                   pop esi
// 0043c725  7506                 jne 0x43c72d
// 0043c727  ff15ace98900         call dword ptr [0x89e9ac]
// 0043c72d  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0043c731  5f                   pop edi
// 0043c732  8d4510               lea eax, [ebp + 0x10]
// 0043c735  5d                   pop ebp
// 0043c736  64890d00000000       mov dword ptr fs:[0], ecx
// 0043c73d  83c448               add esp, 0x48
// 0043c740  c20400               ret 4
// 0043c743  8b36                 mov esi, dword ptr [esi]
// 0043c745  ebda                 jmp 0x43c721
// copied from an identical function in another client (function ??A?$map@IUValue@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUValue@@@std@@@3@@std@@QAEAAUValue@@ABI@Z)

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