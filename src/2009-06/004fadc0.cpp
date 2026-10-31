// from server: 76% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004a2ac0  unit: RBX::Network::VServer::?$FactoryProduct  size: 348 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a2ac0
//
// 004a2ac0  6aff                 push -1
// 004a2ac2  681b937c00           push 0x7c931b
// 004a2ac7  64a100000000         mov eax, dword ptr fs:[0]
// 004a2acd  50                   push eax
// 004a2ace  64892500000000       mov dword ptr fs:[0], esp
// 004a2ad5  81ec20010000         sub esp, 0x120
// 004a2adb  55                   push ebp
// 004a2adc  56                   push esi
// 004a2add  8bf1                 mov esi, ecx
// 004a2adf  8d4c2414             lea ecx, [esp + 0x14]
// 004a2ae3  e8a8250000           call 0x4a5090
// 004a2ae8  8d442414             lea eax, [esp + 0x14]
// 004a2aec  6a4b                 push 0x4b
// 004a2aee  50                   push eax
// 004a2aef  c784243801000000000000 mov dword ptr [esp + 0x138], 0
// 004a2afa  e851380000           call 0x4a6350
// 004a2aff  e8dc571000           call 0x5a82e0
// 004a2b04  83c004               add eax, 4
// 004a2b07  50                   push eax
// 004a2b08  8d4c2420             lea ecx, [esp + 0x20]
// 004a2b0c  51                   push ecx
// 004a2b0d  e84e3a0000           call 0x4a6560
// 004a2b12  8b86682c0000         mov eax, dword ptr [esi + 0x2c68]
// 004a2b18  8b2d90288000         mov ebp, dword ptr [0x802890]
// 004a2b1e  83c410               add esp, 0x10
// 004a2b21  89442408             mov dword ptr [esp + 8], eax
// 004a2b25  3986642c0000         cmp dword ptr [esi + 0x2c64], eax
// 004a2b2b  7602                 jbe 0x4a2b2f
// 004a2b2d  ffd5                 call ebp
// 004a2b2f  8b96582c0000         mov edx, dword ptr [esi + 0x2c58]
// 004a2b35  53                   push ebx
// 004a2b36  8b9e642c0000         mov ebx, dword ptr [esi + 0x2c64]
// 004a2b3c  57                   push edi
// 004a2b3d  89542414             mov dword ptr [esp + 0x14], edx
// 004a2b41  3b9e682c0000         cmp ebx, dword ptr [esi + 0x2c68]
// 004a2b47  7602                 jbe 0x4a2b4b
// 004a2b49  ffd5                 call ebp
// 004a2b4b  8bbe582c0000         mov edi, dword ptr [esi + 0x2c58]
// 004a2b51  85ff                 test edi, edi
// 004a2b53  7406                 je 0x4a2b5b
// 004a2b55  3b7c2414             cmp edi, dword ptr [esp + 0x14]
// 004a2b59  7402                 je 0x4a2b5d
// 004a2b5b  ffd5                 call ebp
// 004a2b5d  3b5c2410             cmp ebx, dword ptr [esp + 0x10]
// 004a2b61  743a                 je 0x4a2b9d
// 004a2b63  85ff                 test edi, edi
// 004a2b65  752e                 jne 0x4a2b95
// 004a2b67  ffd5                 call ebp
// 004a2b69  33c0                 xor eax, eax
// 004a2b6b  3b5810               cmp ebx, dword ptr [eax + 0x10]
// 004a2b6e  7202                 jb 0x4a2b72
// 004a2b70  ffd5                 call ebp
// 004a2b72  8b03                 mov eax, dword ptr [ebx]
// 004a2b74  50                   push eax
// 004a2b75  8d4c2420             lea ecx, [esp + 0x20]
// 004a2b79  51                   push ecx
// 004a2b7a  8bce                 mov ecx, esi
// 004a2b7c  e85f5f0000           call 0x4a8ae0
// 004a2b81  85ff                 test edi, edi
// 004a2b83  7514                 jne 0x4a2b99
// 004a2b85  ffd5                 call ebp
// 004a2b87  33c0                 xor eax, eax
// 004a2b89  3b5810               cmp ebx, dword ptr [eax + 0x10]
// 004a2b8c  7202                 jb 0x4a2b90
// 004a2b8e  ffd5                 call ebp
// 004a2b90  83c304               add ebx, 4
// 004a2b93  ebbc                 jmp 0x4a2b51
// 004a2b95  8b07                 mov eax, dword ptr [edi]
// 004a2b97  ebd2                 jmp 0x4a2b6b
// 004a2b99  8b07                 mov eax, dword ptr [edi]
// 004a2b9b  ebec                 jmp 0x4a2b89
// 004a2b9d  8b96682c0000         mov edx, dword ptr [esi + 0x2c68]
// 004a2ba3  2b96642c0000         sub edx, dword ptr [esi + 0x2c64]
// 004a2ba9  5f                   pop edi
// 004a2baa  c1fa02               sar edx, 2
// 004a2bad  5b                   pop ebx
// 004a2bae  85d2                 test edx, edx
// 004a2bb0  7702                 ja 0x4a2bb4
// 004a2bb2  ffd5                 call ebp
// 004a2bb4  8b8e642c0000         mov ecx, dword ptr [esi + 0x2c64]
// 004a2bba  8b11                 mov edx, dword ptr [ecx]
// 004a2bbc  8d442414             lea eax, [esp + 0x14]
// 004a2bc0  50                   push eax
// 004a2bc1  52                   push edx
// 004a2bc2  8bce                 mov ecx, esi
// 004a2bc4  e857530100           call 0x4b7f20
// 004a2bc9  8b96582d0000         mov edx, dword ptr [esi + 0x2d58]
// 004a2bcf  8b8e502d0000         mov ecx, dword ptr [esi + 0x2d50]
// 004a2bd5  8b01                 mov eax, dword ptr [ecx]
// 004a2bd7  8b4034               mov eax, dword ptr [eax + 0x34]
// 004a2bda  6a00                 push 0
// 004a2bdc  52                   push edx
// 004a2bdd  8b96542d0000         mov edx, dword ptr [esi + 0x2d54]
// 004a2be3  52                   push edx
// 004a2be4  6a00                 push 0
// 004a2be6  6a03                 push 3
// 004a2be8  6a02                 push 2
// 004a2bea  8d54242c             lea edx, [esp + 0x2c]
// 004a2bee  52                   push edx
// 004a2bef  ffd0                 call eax
// 004a2bf1  8d4c2414             lea ecx, [esp + 0x14]
// 004a2bf5  c7842430010000ffffffff mov dword ptr [esp + 0x130], 0xffffffff
// 004a2c00  e89b250000           call 0x4a51a0
// 004a2c05  8b8c2428010000       mov ecx, dword ptr [esp + 0x128]
// 004a2c0c  5e                   pop esi
// 004a2c0d  5d                   pop ebp
// 004a2c0e  64890d00000000       mov dword ptr fs:[0], ecx
// 004a2c15  81c42c010000         add esp, 0x12c
// 004a2c1b  c3                   ret 

struct BitStream {
    unsigned int used;
    unsigned int capacity;
    unsigned int readOffset;
    unsigned char* data;
    unsigned char ownsData;
    unsigned char buffer[256];

    BitStream();
    ~BitStream();
};

extern "C" void __cdecl writeByte(BitStream*, unsigned char);
extern "C" void __cdecl writeValue(BitStream*, const void*);
extern "C" char* __cdecl getValue();
extern void (__cdecl* const invalidParameter)();

typedef void (__cdecl* ErrorHandler)();

struct Container {
    unsigned char padding[16];
    unsigned int* end;
};

struct Proxy {
    Container* container;
};

struct Iterator {
    unsigned int* position;
    Proxy* proxy;
    unsigned int unused;

    Container* getContainer() const;
    unsigned int value(ErrorHandler) const;
    void advance(ErrorHandler);
};

__forceinline Container* Iterator::getContainer() const
{
    return proxy ? proxy->container : 0;
}

__forceinline unsigned int Iterator::value(ErrorHandler error) const
{
    if (!proxy)
        error();
    if (position >= getContainer()->end)
        error();
    return *position;
}

__forceinline void Iterator::advance(ErrorHandler error)
{
    if (!proxy)
        error();
    if (position >= getContainer()->end)
        error();
    ++position;
}

struct Peer {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void send(BitStream*, int, int, int, unsigned int,
                      unsigned int, int) = 0;
};

struct S {
    unsigned char padding0[0x2c58];
    Proxy* proxy;
    unsigned char padding1[8];
    unsigned int* begin;
    unsigned int* end;
    unsigned char padding2[0xe4];
    Peer* peer;
    unsigned int address;
    unsigned int port;

    void append(BitStream*, unsigned int);
    void finish(unsigned int, BitStream*);
    void f();
};

void S::f()
{
    BitStream stream;
    writeByte(&stream, 0x4b);
    writeValue(&stream, getValue() + 4);

    Iterator last;
    last.position = end;
    ErrorHandler error = invalidParameter;
    if (begin > last.position)
        error();
    last.proxy = proxy;

    {
        Iterator current;
        current.position = begin;
        if (current.position > end)
            error();
        current.proxy = proxy;

        for (;;) {
            if (!current.proxy || current.proxy != last.proxy)
                error();
            if (current.position == last.position)
                break;
            append(&stream, current.value(error));
            current.advance(error);
        }
    }

    if (!(0u < static_cast<unsigned int>(end - begin)))
        error();
    finish(*begin, &stream);
    peer->send(&stream, 2, 3, 0, address, port, 0);
}
