// from server: 100% by Intel
// from server: 94% by EspClaude
// roc 2007-08 00463520  unit: CSettingsDialog  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00463520
//
// 00463520  56                   push esi
// 00463521  8bf1                 mov esi, ecx
// 00463523  8b06                 mov eax, dword ptr [esi]
// 00463525  8b5010               mov edx, dword ptr [eax + 0x10]
// 00463528  6a77                 push 0x77
// 0046352a  ffd2                 call edx
// 0046352c  84c0                 test al, al
// 0046352e  7579                 jne 0x4635a9
// 00463530  8b06                 mov eax, dword ptr [esi]
// 00463532  8b5010               mov edx, dword ptr [eax + 0x10]
// 00463535  6a73                 push 0x73
// 00463537  8bce                 mov ecx, esi
// 00463539  ffd2                 call edx
// 0046353b  84c0                 test al, al
// 0046353d  756a                 jne 0x4635a9
// 0046353f  8b06                 mov eax, dword ptr [esi]
// 00463541  8b5010               mov edx, dword ptr [eax + 0x10]
// 00463544  6a61                 push 0x61
// 00463546  8bce                 mov ecx, esi
// 00463548  ffd2                 call edx
// 0046354a  84c0                 test al, al
// 0046354c  755b                 jne 0x4635a9
// 0046354e  8b06                 mov eax, dword ptr [esi]
// 00463550  8b5010               mov edx, dword ptr [eax + 0x10]
// 00463553  6a64                 push 0x64
// 00463555  8bce                 mov ecx, esi
// 00463557  ffd2                 call edx
// 00463559  84c0                 test al, al
// 0046355b  754c                 jne 0x4635a9
// 0046355d  8b06                 mov eax, dword ptr [esi]
// 0046355f  8b5010               mov edx, dword ptr [eax + 0x10]
// 00463562  6811010000           push 0x111
// 00463567  8bce                 mov ecx, esi
// 00463569  ffd2                 call edx
// 0046356b  84c0                 test al, al
// 0046356d  753a                 jne 0x4635a9
// 0046356f  8b06                 mov eax, dword ptr [esi]
// 00463571  8b5010               mov edx, dword ptr [eax + 0x10]
// 00463574  6812010000           push 0x112
// 00463579  8bce                 mov ecx, esi
// 0046357b  ffd2                 call edx
// 0046357d  84c0                 test al, al
// 0046357f  7528                 jne 0x4635a9
// 00463581  8b06                 mov eax, dword ptr [esi]
// 00463583  8b5010               mov edx, dword ptr [eax + 0x10]
// 00463586  6814010000           push 0x114
// 0046358b  8bce                 mov ecx, esi
// 0046358d  ffd2                 call edx
// 0046358f  84c0                 test al, al
// 00463591  7516                 jne 0x4635a9
// 00463593  8b06                 mov eax, dword ptr [esi]
// 00463595  8b5010               mov edx, dword ptr [eax + 0x10]
// 00463598  6813010000           push 0x113
// 0046359d  8bce                 mov ecx, esi
// 0046359f  ffd2                 call edx
// 004635a1  84c0                 test al, al
// 004635a3  7504                 jne 0x4635a9
// 004635a5  33c0                 xor eax, eax
// 004635a7  5e                   pop esi
// 004635a8  c3                   ret 
// 004635a9  b801000000           mov eax, 1
// 004635ae  5e                   pop esi
// 004635af  c3                   ret 

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
