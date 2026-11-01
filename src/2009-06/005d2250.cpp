// from server: 100% by EspClaude
// from server: 81% by EspClaude
// roc 2009-06 005d2250  unit: VAuthoringSettings::?$FactoryProduct  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d2250
//
// 005d2250  83ec08               sub esp, 8
// 005d2253  55                   push ebp
// 005d2254  8be9                 mov ebp, ecx
// 005d2256  56                   push esi
// 005d2257  8b754c               mov esi, dword ptr [ebp + 0x4c]
// 005d225a  85f6                 test esi, esi
// 005d225c  7471                 je 0x5d22cf
// 005d225e  53                   push ebx
// 005d225f  57                   push edi
// 005d2260  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005d2263  397e0c               cmp dword ptr [esi + 0xc], edi
// 005d2266  7606                 jbe 0x5d226e
// 005d2268  ff15ace98900         call dword ptr [0x89e9ac]
// 005d226e  8b36                 mov esi, dword ptr [esi]
// 005d2270  8bde                 mov ebx, esi
// 005d2272  897c2414             mov dword ptr [esp + 0x14], edi
// 005d2276  85f6                 test esi, esi
// 005d2278  7518                 jne 0x5d2292
// 005d227a  ff15ace98900         call dword ptr [0x89e9ac]
// 005d2280  33c0                 xor eax, eax
// 005d2282  8d4ff8               lea ecx, [edi - 8]
// 005d2285  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 005d2288  7713                 ja 0x5d229d
// 005d228a  85f6                 test esi, esi
// 005d228c  7408                 je 0x5d2296
// 005d228e  8b36                 mov esi, dword ptr [esi]
// 005d2290  eb06                 jmp 0x5d2298
// 005d2292  8b06                 mov eax, dword ptr [esi]
// 005d2294  ebec                 jmp 0x5d2282
// 005d2296  33f6                 xor esi, esi
// 005d2298  3b4e0c               cmp ecx, dword ptr [esi + 0xc]
// 005d229b  7306                 jae 0x5d22a3
// 005d229d  ff15ace98900         call dword ptr [0x89e9ac]
// 005d22a3  8d77f8               lea esi, [edi - 8]
// 005d22a6  85db                 test ebx, ebx
// 005d22a8  752b                 jne 0x5d22d5
// 005d22aa  ff15ace98900         call dword ptr [0x89e9ac]
// 005d22b0  33c0                 xor eax, eax
// 005d22b2  3b7010               cmp esi, dword ptr [eax + 0x10]
// 005d22b5  7206                 jb 0x5d22bd
// 005d22b7  ff15ace98900         call dword ptr [0x89e9ac]
// 005d22bd  8b0e                 mov ecx, dword ptr [esi]
// 005d22bf  6a00                 push 0
// 005d22c1  e88afbffff           call 0x5d1e50
// 005d22c6  8b754c               mov esi, dword ptr [ebp + 0x4c]
// 005d22c9  85f6                 test esi, esi
// 005d22cb  7593                 jne 0x5d2260
// 005d22cd  5f                   pop edi
// 005d22ce  5b                   pop ebx
// 005d22cf  5e                   pop esi
// 005d22d0  5d                   pop ebp
// 005d22d1  83c408               add esp, 8
// 005d22d4  c3                   ret 
// 005d22d5  8b03                 mov eax, dword ptr [ebx]
// 005d22d7  ebd9                 jmp 0x5d22b2

// from server: 100% by king_originala
// roc 2008-06 0055afd0  unit: RBX::VInstance::?$NonFactoryProduct  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055afd0
//
// 0055afd0  83ec08               sub esp, 8
// 0055afd3  55                   push ebp
// 0055afd4  8be9                 mov ebp, ecx
// 0055afd6  56                   push esi
// 0055afd7  8bb508010000         mov esi, dword ptr [ebp + 0x108]
// 0055afdd  85f6                 test esi, esi
// 0055afdf  7474                 je 0x55b055
// 0055afe1  53                   push ebx
// 0055afe2  57                   push edi
// 0055afe3  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0055afe6  397e0c               cmp dword ptr [esi + 0xc], edi
// 0055afe9  7606                 jbe 0x55aff1
// 0055afeb  ff1590288000         call dword ptr [0x802890]
// 0055aff1  8b36                 mov esi, dword ptr [esi]
// 0055aff3  8bde                 mov ebx, esi
// 0055aff5  897c2414             mov dword ptr [esp + 0x14], edi
// 0055aff9  85f6                 test esi, esi
// 0055affb  7518                 jne 0x55b015
// 0055affd  ff1590288000         call dword ptr [0x802890]
// 0055b003  33c0                 xor eax, eax
// 0055b005  8d4ff8               lea ecx, [edi - 8]
// 0055b008  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 0055b00b  7713                 ja 0x55b020
// 0055b00d  85f6                 test esi, esi
// 0055b00f  7408                 je 0x55b019
// 0055b011  8b36                 mov esi, dword ptr [esi]
// 0055b013  eb06                 jmp 0x55b01b
// 0055b015  8b06                 mov eax, dword ptr [esi]
// 0055b017  ebec                 jmp 0x55b005
// 0055b019  33f6                 xor esi, esi
// 0055b01b  3b4e0c               cmp ecx, dword ptr [esi + 0xc]
// 0055b01e  7306                 jae 0x55b026
// 0055b020  ff1590288000         call dword ptr [0x802890]
// 0055b026  8d77f8               lea esi, [edi - 8]
// 0055b029  85db                 test ebx, ebx
// 0055b02b  752e                 jne 0x55b05b
// 0055b02d  ff1590288000         call dword ptr [0x802890]
// 0055b033  33c0                 xor eax, eax
// 0055b035  3b7010               cmp esi, dword ptr [eax + 0x10]
// 0055b038  7206                 jb 0x55b040
// 0055b03a  ff1590288000         call dword ptr [0x802890]
// 0055b040  8b0e                 mov ecx, dword ptr [esi]
// 0055b042  6a00                 push 0
// 0055b044  e8a7f8ffff           call 0x55a8f0
// 0055b049  8bb508010000         mov esi, dword ptr [ebp + 0x108]
// 0055b04f  85f6                 test esi, esi
// 0055b051  7590                 jne 0x55afe3
// 0055b053  5f                   pop edi
// 0055b054  5b                   pop ebx
// 0055b055  5e                   pop esi
// 0055b056  5d                   pop ebp
// 0055b057  83c408               add esp, 8
// 0055b05a  c3                   ret 
// 0055b05b  8b03                 mov eax, dword ptr [ebx]
// 0055b05d  ebd6                 jmp 0x55b035

extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Object;
struct Vector;

struct Entry {
    Object* object;
    unsigned long control;
};

struct Proxy {
    Vector* owner;
};

struct Iterator {
    Proxy* proxy;
    Entry* position;

    Iterator(Entry*, Vector*);
    Vector* owner() const;
    Iterator& operator-=(int);
    Iterator operator-(int) const;
    Entry* operator->() const;
};

struct Vector {
    Proxy* proxy;
    unsigned long reserved[2];
    Entry* first;
    Entry* last;

    Iterator end();
};

struct Object {
    unsigned char reserved[0x4c];
    Vector* children;

    void setParent(Object*);
    void clearChildren();
};

inline Iterator::Iterator(Entry* p, Vector* v)
    : proxy(v->proxy), position(p)
{
}

inline Vector* Iterator::owner() const
{
    return proxy ? proxy->owner : 0;
}

inline Iterator Vector::end()
{
    Entry* p = last;
    if (first > p)
        invalid_parameter_noinfo();
    return Iterator(p, this);
}

inline Iterator& Iterator::operator-=(int n)
{
    if (!proxy)
        invalid_parameter_noinfo();

    if (position - n > owner()->last ||
        position - n < owner()->first)
        invalid_parameter_noinfo();

    position -= n;
    return *this;
}

inline Iterator Iterator::operator-(int n) const
{
    Iterator result = *this;
    result -= n;
    return result;
}

inline Entry* Iterator::operator->() const
{
    if (!proxy)
        invalid_parameter_noinfo();

    if (position >= owner()->last)
        invalid_parameter_noinfo();

    return position;
}

void Object::clearChildren()
{
    while (children)
        (children->end() - 1)->object->setParent(0);
}
