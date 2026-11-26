// from server: 100% by Xemicl
// roc 2012-06 00678560  unit: DummyArbiter  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00678560
//
// 00678560  6aff                 push -1
// 00678562  689c4fab00           push 0xab4f9c
// 00678567  64a100000000         mov eax, dword ptr fs:[0]
// 0067856d  50                   push eax
// 0067856e  64892500000000       mov dword ptr fs:[0], esp
// 00678575  83ec3c               sub esp, 0x3c
// 00678578  53                   push ebx
// 00678579  56                   push esi
// 0067857a  8d4c240c             lea ecx, [esp + 0xc]
// 0067857e  c744240800000000     mov dword ptr [esp + 8], 0
// 00678586  ff155426b200         call dword ptr [0xb22654]
// 0067858c  6868dcb800           push 0xb8dc68
// 00678591  8d4c242c             lea ecx, [esp + 0x2c]
// 00678595  c744245001000000     mov dword ptr [esp + 0x50], 1
// 0067859d  ff154826b200         call dword ptr [0xb22648]
// 006785a3  8d44240c             lea eax, [esp + 0xc]
// 006785a7  50                   push eax
// 006785a8  8d4c242c             lea ecx, [esp + 0x2c]
// 006785ac  51                   push ecx
// 006785ad  c644245402           mov byte ptr [esp + 0x54], 2
// 006785b2  e869453000           call 0x97cb20
// 006785b7  83c408               add esp, 8
// 006785ba  8d4c2428             lea ecx, [esp + 0x28]
// 006785be  8ad8                 mov bl, al
// 006785c0  c644244c01           mov byte ptr [esp + 0x4c], 1
// 006785c5  ff153c26b200         call dword ptr [0xb2263c]
// 006785cb  8b742454             mov esi, dword ptr [esp + 0x54]
// 006785cf  8bce                 mov ecx, esi
// 006785d1  84db                 test bl, bl
// 006785d3  740d                 je 0x6785e2
// 006785d5  8d54240c             lea edx, [esp + 0xc]
// 006785d9  52                   push edx
// 006785da  ff154426b200         call dword ptr [0xb22644]
// 006785e0  eb0b                 jmp 0x6785ed
// 006785e2  682870b700           push 0xb77028
// 006785e7  ff154826b200         call dword ptr [0xb22648]
// 006785ed  8d4c240c             lea ecx, [esp + 0xc]
// 006785f1  c744240801000000     mov dword ptr [esp + 8], 1
// 006785f9  c644244c00           mov byte ptr [esp + 0x4c], 0
// 006785fe  ff153c26b200         call dword ptr [0xb2263c]
// 00678604  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00678608  8bc6                 mov eax, esi
// 0067860a  5e                   pop esi
// 0067860b  5b                   pop ebx
// 0067860c  64890d00000000       mov dword ptr fs:[0], ecx
// 00678613  83c448               add esp, 0x48
// 00678616  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX00001c@@QAE?AUString@2@XZ)

namespace ns_ROCX00001c {
struct String;

extern void (__thiscall *stringDefaultConstruct)(String *);
extern void (__thiscall *stringTextConstruct)(String *, const char *);
extern void (__thiscall *stringCopyConstruct)(String *, const String &);
extern void (__thiscall *stringDestroy)(String *);

extern const char productNameKey[];
extern const char fallbackName[];

struct String {
    unsigned char storage[28];

    String();
    String(const char *);
    String(const String &);
    ~String();
};

inline String::String() {
    stringDefaultConstruct(this);
}

inline String::String(const char *text) {
    stringTextConstruct(this, text);
}

inline String::String(const String &other) {
    stringCopyConstruct(this, other);
}

inline String::~String() {
    stringDestroy(this);
}

extern bool __cdecl readProductName(const String &, String &);

struct S {
    String f();
};

String S::f() {
    String result;
    bool found = readProductName(String(productNameKey), result);
    if (found)
        return result;
    return String(fallbackName);
}
}