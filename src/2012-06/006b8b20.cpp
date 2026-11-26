// from server: 100% by Xemicl
// roc 2012-06 006b8b20  unit: RBX::MD5HasherImpl  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006b8b20
//
// 006b8b20  51                   push ecx
// 006b8b21  56                   push esi
// 006b8b22  8bf1                 mov esi, ecx
// 006b8b24  8b06                 mov eax, dword ptr [esi]
// 006b8b26  8b5014               mov edx, dword ptr [eax + 0x14]
// 006b8b29  c744240400000000     mov dword ptr [esp + 4], 0
// 006b8b31  ffd2                 call edx
// 006b8b33  83c60c               add esi, 0xc
// 006b8b36  56                   push esi
// 006b8b37  8b742410             mov esi, dword ptr [esp + 0x10]
// 006b8b3b  8bce                 mov ecx, esi
// 006b8b3d  ff154426b200         call dword ptr [0xb22644]
// 006b8b43  8bc6                 mov eax, esi
// 006b8b45  5e                   pop esi
// 006b8b46  59                   pop ecx
// 006b8b47  c20400               ret 4
// copied from an identical function in another client (function ?get@S@ns_ROCX00001f@@QAEPAUString@2@PAU32@@Z)

namespace ns_ROCX00001f {
// from server: 100% by king_originala
// roc 2008-06 0055c710  unit: RBX::MD5HasherImpl  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055c710
//
// 0055c710  51                   push ecx
// 0055c711  56                   push esi
// 0055c712  8bf1                 mov esi, ecx
// 0055c714  8b06                 mov eax, dword ptr [esi]
// 0055c716  8b5010               mov edx, dword ptr [eax + 0x10]
// 0055c719  c744240400000000     mov dword ptr [esp + 4], 0
// 0055c721  ffd2                 call edx
// 0055c723  83c60c               add esi, 0xc
// 0055c726  56                   push esi
// 0055c727  8b742410             mov esi, dword ptr [esp + 0x10]
// 0055c72b  8bce                 mov ecx, esi
// 0055c72d  ff155c248000         call dword ptr [0x80245c]
// 0055c733  8bc6                 mov eax, esi
// 0055c735  5e                   pop esi
// 0055c736  59                   pop ecx
// 0055c737  c20400               ret 4

struct String {
    unsigned char data[28];
};

extern void (__thiscall *copyString)(String *, const String *);

struct S {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot3b();
    virtual void finish();

    unsigned char padding[8];
    String text;

    String *get(String *result);
};

String *S::get(String *result)
{
    volatile int state = 0;
    finish();
    copyString(result, &text);
    return result;
}
}
