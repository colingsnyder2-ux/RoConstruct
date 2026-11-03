// from server: 94% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004674a0  unit: CSettingsDialog  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004674a0
//
// 004674a0  56                   push esi
// 004674a1  8bf1                 mov esi, ecx
// 004674a3  8b06                 mov eax, dword ptr [esi]
// 004674a5  8b5014               mov edx, dword ptr [eax + 0x14]
// 004674a8  6a77                 push 0x77
// 004674aa  ffd2                 call edx
// 004674ac  84c0                 test al, al
// 004674ae  7579                 jne 0x467529
// 004674b0  8b06                 mov eax, dword ptr [esi]
// 004674b2  8b5014               mov edx, dword ptr [eax + 0x14]
// 004674b5  6a73                 push 0x73
// 004674b7  8bce                 mov ecx, esi
// 004674b9  ffd2                 call edx
// 004674bb  84c0                 test al, al
// 004674bd  756a                 jne 0x467529
// 004674bf  8b06                 mov eax, dword ptr [esi]
// 004674c1  8b5014               mov edx, dword ptr [eax + 0x14]
// 004674c4  6a61                 push 0x61
// 004674c6  8bce                 mov ecx, esi
// 004674c8  ffd2                 call edx
// 004674ca  84c0                 test al, al
// 004674cc  755b                 jne 0x467529
// 004674ce  8b06                 mov eax, dword ptr [esi]
// 004674d0  8b5014               mov edx, dword ptr [eax + 0x14]
// 004674d3  6a64                 push 0x64
// 004674d5  8bce                 mov ecx, esi
// 004674d7  ffd2                 call edx
// 004674d9  84c0                 test al, al
// 004674db  754c                 jne 0x467529
// 004674dd  8b06                 mov eax, dword ptr [esi]
// 004674df  8b5014               mov edx, dword ptr [eax + 0x14]
// 004674e2  6811010000           push 0x111
// 004674e7  8bce                 mov ecx, esi
// 004674e9  ffd2                 call edx
// 004674eb  84c0                 test al, al
// 004674ed  753a                 jne 0x467529
// 004674ef  8b06                 mov eax, dword ptr [esi]
// 004674f1  8b5014               mov edx, dword ptr [eax + 0x14]
// 004674f4  6812010000           push 0x112
// 004674f9  8bce                 mov ecx, esi
// 004674fb  ffd2                 call edx
// 004674fd  84c0                 test al, al
// 004674ff  7528                 jne 0x467529
// 00467501  8b06                 mov eax, dword ptr [esi]
// 00467503  8b5014               mov edx, dword ptr [eax + 0x14]
// 00467506  6814010000           push 0x114
// 0046750b  8bce                 mov ecx, esi
// 0046750d  ffd2                 call edx
// 0046750f  84c0                 test al, al
// 00467511  7516                 jne 0x467529
// 00467513  8b06                 mov eax, dword ptr [esi]
// 00467515  8b5014               mov edx, dword ptr [eax + 0x14]
// 00467518  6813010000           push 0x113
// 0046751d  8bce                 mov ecx, esi
// 0046751f  ffd2                 call edx
// 00467521  84c0                 test al, al
// 00467523  7504                 jne 0x467529
// 00467525  33c0                 xor eax, eax
// 00467527  5e                   pop esi
// 00467528  c3                   ret 
// 00467529  b801000000           mov eax, 1
// 0046752e  5e                   pop esi
// 0046752f  c3                   ret 

struct S {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual bool key(int code) = 0;

    bool f();
};

bool S::f()
{
    return key(0x77) ||
           key(0x73) ||
           key(0x61) ||
           key(0x64) ||
           key(0x111) ||
           key(0x112) ||
           key(0x114) ||
           key(0x113);
}
