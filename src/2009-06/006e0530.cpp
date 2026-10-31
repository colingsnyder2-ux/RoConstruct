// from server: 86% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0064fd70  unit: RBX::ChatOutput  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064fd70
//
// 0064fd70  83ec08               sub esp, 8
// 0064fd73  56                   push esi
// 0064fd74  8bf1                 mov esi, ecx
// 0064fd76  8b8690010000         mov eax, dword ptr [esi + 0x190]
// 0064fd7c  57                   push edi
// 0064fd7d  8bbe8c010000         mov edi, dword ptr [esi + 0x18c]
// 0064fd83  03c7                 add eax, edi
// 0064fd85  3bf8                 cmp edi, eax
// 0064fd87  7606                 jbe 0x64fd8f
// 0064fd89  ff1590288000         call dword ptr [0x802890]
// 0064fd8f  8b8e74010000         mov ecx, dword ptr [esi + 0x174]
// 0064fd95  894c2408             mov dword ptr [esp + 8], ecx
// 0064fd99  8d4c2408             lea ecx, [esp + 8]
// 0064fd9d  897c240c             mov dword ptr [esp + 0xc], edi
// 0064fda1  e87a66deff           call 0x436420
// 0064fda6  8b38                 mov edi, dword ptr [eax]
// 0064fda8  8b8690010000         mov eax, dword ptr [esi + 0x190]
// 0064fdae  33d2                 xor edx, edx
// 0064fdb0  3bc2                 cmp eax, edx
// 0064fdb2  7433                 je 0x64fde7
// 0064fdb4  ff868c010000         inc dword ptr [esi + 0x18c]
// 0064fdba  8b8e8c010000         mov ecx, dword ptr [esi + 0x18c]
// 0064fdc0  53                   push ebx
// 0064fdc1  8b9e88010000         mov ebx, dword ptr [esi + 0x188]
// 0064fdc7  03db                 add ebx, ebx
// 0064fdc9  03db                 add ebx, ebx
// 0064fdcb  3bd9                 cmp ebx, ecx
// 0064fdcd  5b                   pop ebx
// 0064fdce  7706                 ja 0x64fdd6
// 0064fdd0  89968c010000         mov dword ptr [esi + 0x18c], edx
// 0064fdd6  48                   dec eax
// 0064fdd7  898690010000         mov dword ptr [esi + 0x190], eax
// 0064fddd  3bc2                 cmp eax, edx
// 0064fddf  7506                 jne 0x64fde7
// 0064fde1  89968c010000         mov dword ptr [esi + 0x18c], edx
// 0064fde7  3bfa                 cmp edi, edx
// 0064fde9  7410                 je 0x64fdfb
// 0064fdeb  8bcf                 mov ecx, edi
// 0064fded  e8cefaffff           call 0x64f8c0
// 0064fdf2  57                   push edi
// 0064fdf3  e882080500           call 0x6a067a
// 0064fdf8  83c404               add esp, 4
// 0064fdfb  5f                   pop edi
// 0064fdfc  5e                   pop esi
// 0064fdfd  83c408               add esp, 8
// 0064fe00  c3                   ret 

extern "C" void (__cdecl *invalid_parameter_noinfo)();
void __cdecl operator delete(void *);

struct Item {
    ~Item();
};

struct Iterator {
    void *owner;
    unsigned int offset;
    Item *&operator*() const;
};

struct S {
    char padding0[0x174];
    void *owner;
    char padding1[0x10];
    unsigned int mapSize;
    unsigned int offset;
    unsigned int size;

    void pop_front();
};

void S::pop_front()
{
    unsigned int first = offset;
    if (first > first + size)
        invalid_parameter_noinfo();

    Iterator it;
    it.owner = owner;
    it.offset = first;
    Item *item = *it;

    if (size != 0) {
        ++offset;
        if (mapSize * 4 <= offset)
            offset = 0;
        if (--size == 0)
            offset = 0;
    }

    delete item;
}
