// roc 2012-06 006cf670  unit: CInstanceRecord::CNameItem  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cf670
//
// 006cf670  56                   push esi
// 006cf671  8bf1                 mov esi, ecx
// 006cf673  8b06                 mov eax, dword ptr [esi]
// 006cf675  8b5014               mov edx, dword ptr [eax + 0x14]
// 006cf678  6831010000           push 0x131
// 006cf67d  ffd2                 call edx
// 006cf67f  84c0                 test al, al
// 006cf681  7516                 jne 0x6cf699
// 006cf683  8b06                 mov eax, dword ptr [esi]
// 006cf685  8b5014               mov edx, dword ptr [eax + 0x14]
// 006cf688  6832010000           push 0x132
// 006cf68d  8bce                 mov ecx, esi
// 006cf68f  ffd2                 call edx
// 006cf691  84c0                 test al, al
// 006cf693  7504                 jne 0x6cf699
// 006cf695  33c0                 xor eax, eax
// 006cf697  5e                   pop esi
// 006cf698  c3                   ret 
// 006cf699  b801000000           mov eax, 1
// 006cf69e  5e                   pop esi
// 006cf69f  c3                   ret 
// copied from an identical function in another client (function ?f@S@@QAEHXZ)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool check(int value);
    int f();
};

int S::f()
{
    if (check(0x131) || check(0x132))
        return 1;
    return 0;
}