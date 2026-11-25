// from server: 100% by Xemicl
﻿// from server: 100% by tajop
// roc 2012-06 00428ec0  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00428ec0
//
// 00428ec0  53                   push ebx
// 00428ec1  56                   push esi
// 00428ec2  8bf1                 mov esi, ecx
// 00428ec4  33db                 xor ebx, ebx
// 00428ec6  57                   push edi
// 00428ec7  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 00428eca  7463                 je 0x428f2f
// 00428ecc  8d642400             lea esp, [esp]
// 00428ed0  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00428ed3  3bc3                 cmp eax, ebx
// 00428ed5  7453                 je 0x428f2a
// 00428ed7  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00428eda  8d4408ff             lea eax, [eax + ecx - 1]
// 00428ede  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00428ee1  3bc8                 cmp ecx, eax
// 00428ee3  7702                 ja 0x428ee7
// 00428ee5  2bc1                 sub eax, ecx
// 00428ee7  8b5610               mov edx, dword ptr [esi + 0x10]
// 00428eea  8b0482               mov eax, dword ptr [edx + eax*4]
// 00428eed  8b7808               mov edi, dword ptr [eax + 8]
// 00428ef0  83c008               add eax, 8
// 00428ef3  3bfb                 cmp edi, ebx
// 00428ef5  742a                 je 0x428f21
// 00428ef7  8d4704               lea eax, [edi + 4]
// 00428efa  83c9ff               or ecx, 0xffffffff
// 00428efd  f00fc108             lock xadd dword ptr [eax], ecx
// 00428f01  751e                 jne 0x428f21
// 00428f03  8b17                 mov edx, dword ptr [edi]
// 00428f05  8b4204               mov eax, dword ptr [edx + 4]
// 00428f08  8bcf                 mov ecx, edi
// 00428f0a  ffd0                 call eax
// 00428f0c  8d4f08               lea ecx, [edi + 8]
// 00428f0f  83caff               or edx, 0xffffffff
// 00428f12  f00fc111             lock xadd dword ptr [ecx], edx
// 00428f16  7509                 jne 0x428f21
// 00428f18  8b07                 mov eax, dword ptr [edi]
// 00428f1a  8b5008               mov edx, dword ptr [eax + 8]
// 00428f1d  8bcf                 mov ecx, edi
// 00428f1f  ffd2                 call edx
// 00428f21  83461cff             add dword ptr [esi + 0x1c], -1
// 00428f25  7503                 jne 0x428f2a
// 00428f27  895e18               mov dword ptr [esi + 0x18], ebx
// 00428f2a  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 00428f2d  75a1                 jne 0x428ed0
// 00428f2f  8b7e14               mov edi, dword ptr [esi + 0x14]
// 00428f32  3bfb                 cmp edi, ebx
// 00428f34  761b                 jbe 0x428f51
// 00428f36  8b4610               mov eax, dword ptr [esi + 0x10]
// 00428f39  4f                   dec edi
// 00428f3a  391cb8               cmp dword ptr [eax + edi*4], ebx
// 00428f3d  8d04b8               lea eax, [eax + edi*4]
// 00428f40  740b                 je 0x428f4d
// 00428f42  8b08                 mov ecx, dword ptr [eax]
// 00428f44  51                   push ecx
// 00428f45  e8ca915500           call 0x982114
// 00428f4a  83c404               add esp, 4
// 00428f4d  3bfb                 cmp edi, ebx
// 00428f4f  77e5                 ja 0x428f36
// 00428f51  8b4610               mov eax, dword ptr [esi + 0x10]
// 00428f54  3bc3                 cmp eax, ebx
// 00428f56  7409                 je 0x428f61
// 00428f58  50                   push eax
// 00428f59  e8b6915500           call 0x982114
// 00428f5e  83c404               add esp, 4
// 00428f61  5f                   pop edi
// 00428f62  895e10               mov dword ptr [esi + 0x10], ebx
// 00428f65  895e14               mov dword ptr [esi + 0x14], ebx
// 00428f68  5e                   pop esi
// 00428f69  5b                   pop ebx
// 00428f6a  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Counted
{
    virtual void f0();
    virtual void dispose();
    virtual void destroy();
    long use_count;
    long weak_count;
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count) == 0)
            destroy();
    }
    void release()
    {
        if (_InterlockedDecrement(&use_count) == 0)
        {
            dispose();
            weak_release();
        }
    }
};

struct Count
{
    Counted* pi;
    void reset()
    {
        if (pi != 0)
            pi->release();
    }
};

struct Elem
{
    int a;
    Count pn;
};

struct Q
{
    char pad[0x10];
    Elem** map;
    unsigned mapsize;
    unsigned off;
    unsigned size;
    void tidy();
};

void Q::tidy()
{
    while (size != 0)
    {
        if (size != 0)
        {
            unsigned b = off + size - 1;
            if (mapsize <= b)
                b -= mapsize;
            Count* c = &map[b]->pn;
            c->reset();
            if (--size == 0)
                off = 0;
        }
    }
    for (unsigned i = mapsize; 0 < i;)
    {
        --i;
        if (map[i] != 0)
            operator delete(map[i]);
    }
    if (map != 0)
        operator delete(map);
    mapsize = 0;
    map = 0;
}
