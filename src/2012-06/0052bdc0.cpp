// roc 2012-06 0052bdc0  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0052bdc0
//
// 0052bdc0  51                   push ecx
// 0052bdc1  8b01                 mov eax, dword ptr [ecx]
// 0052bdc3  8b5018               mov edx, dword ptr [eax + 0x18]
// 0052bdc6  56                   push esi
// 0052bdc7  c744240400000000     mov dword ptr [esp + 4], 0
// 0052bdcf  ffd2                 call edx
// 0052bdd1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0052bdd5  68e83bb400           push 0xb43be8
// 0052bdda  8bce                 mov ecx, esi
// 0052bddc  ff154826b200         call dword ptr [0xb22648]
// 0052bde2  8bc6                 mov eax, esi
// 0052bde4  5e                   pop esi
// 0052bde5  59                   pop ecx
// 0052bde6  c20800               ret 8
// copied from an identical function in another client (function ?f@S@@QAEPAUString@@PAU2@H@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct String {
    char storage[28];
};

typedef void (__thiscall *StringConstructor)(String *, const char *);
extern StringConstructor constructString;
extern const char authoring[];

struct S {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();

    String *f(String *result, int unused);
};

String *S::f(String *result, int unused)
{
    volatile int local = 0;
    slot6();
    constructString(result, authoring);
    return result;
}