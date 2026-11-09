// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005444a0  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005444a0
//
// 005444a0  55                   push ebp
// 005444a1  8bec                 mov ebp, esp
// 005444a3  51                   push ecx
// 005444a4  894dfc               mov dword ptr [ebp - 4], ecx
// 005444a7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005444aa  e801020000           call 0x5446b0
// 005444af  837d0c00             cmp dword ptr [ebp + 0xc], 0
// 005444b3  7416                 je 0x5444cb
// 005444b5  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005444b8  8b480c               mov ecx, dword ptr [eax + 0xc]
// 005444bb  3b4d08               cmp ecx, dword ptr [ebp + 8]
// 005444be  770b                 ja 0x5444cb
// 005444c0  8b550c               mov edx, dword ptr [ebp + 0xc]
// 005444c3  8b4508               mov eax, dword ptr [ebp + 8]
// 005444c6  3b4210               cmp eax, dword ptr [edx + 0x10]
// 005444c9  7606                 jbe 0x5444d1
// 005444cb  ff1590288000         call dword ptr [0x802890]
// 005444d1  33c9                 xor ecx, ecx
// 005444d3  75fc                 jne 0x5444d1
// 005444d5  8b550c               mov edx, dword ptr [ebp + 0xc]
// 005444d8  52                   push edx
// 005444d9  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005444dc  e80fdfebff           call 0x4023f0
// 005444e1  8b45fc               mov eax, dword ptr [ebp - 4]
// 005444e4  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005444e7  894804               mov dword ptr [eax + 4], ecx
// 005444ea  8b45fc               mov eax, dword ptr [ebp - 4]
// 005444ed  8be5                 mov esp, ebp
// 005444ef  5d                   pop ebp
// 005444f0  c20800               ret 8

extern "C" void (__cdecl * _invalid_parameter_noinfo)();

struct Container {
    void *reserved[3];
    void **first;
    void **last;
};

struct IteratorBase {
    void *proxy;
    IteratorBase();
    void set_container(const Container *);
};

struct Iterator : IteratorBase {
    void **current;
    Iterator(void **p, const Container *container);
};

#pragma optimize("", off)

Iterator::Iterator(void **p, const Container *container)
{
    if (container == 0 || container->first > p || p > container->last)
        _invalid_parameter_noinfo();

    do {
    } while (0);

    set_container(container);
    current = p;
}
