// from server: 100% by Xemicl
// roc 2012-06 004057b0  unit: VCApp::?$CComObject  size: 382 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004057b0
//
// 004057b0  b858fd0000           mov eax, 0xfd58
// 004057b5  e826db5700           call 0x9832e0
// 004057ba  e825cc5700           call 0x9823e4
// 004057bf  50                   push eax
// 004057c0  8d4c240c             lea ecx, [esp + 0xc]
// 004057c4  e815cc5700           call 0x9823de
// 004057c9  8d0424               lea eax, [esp]
// 004057cc  50                   push eax
// 004057cd  8d4c243c             lea ecx, [esp + 0x3c]
// 004057d1  51                   push ecx
// 004057d2  c744240820fd0000     mov dword ptr [esp + 8], 0xfd20
// 004057da  e821696700           call 0xa7c100
// 004057df  85c0                 test eax, eax
// 004057e1  7430                 je 0x405813
// 004057e3  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004057e7  85c0                 test eax, eax
// 004057e9  7407                 je 0x4057f2
// 004057eb  8b542408             mov edx, dword ptr [esp + 8]
// 004057ef  895004               mov dword ptr [eax + 4], edx
// 004057f2  837c241400           cmp dword ptr [esp + 0x14], 0
// 004057f7  740c                 je 0x405805
// 004057f9  8b442410             mov eax, dword ptr [esp + 0x10]
// 004057fd  50                   push eax
// 004057fe  6a00                 push 0
// 00405800  e8d3cb5700           call 0x9823d8
// 00405805  b805400080           mov eax, 0x80004005
// 0040580a  81c458fd0000         add esp, 0xfd58
// 00405810  c20800               ret 8
// 00405813  56                   push esi
// 00405814  33f6                 xor esi, esi
// 00405816  57                   push edi
// 00405817  8974240c             mov dword ptr [esp + 0xc], esi
// 0040581b  39742408             cmp dword ptr [esp + 8], esi
// 0040581f  0f8697000000         jbe 0x4058bc
// 00405825  e836362b00           call 0x6b8e60
// 0040582a  8bf0                 mov esi, eax
// 0040582c  b8e78745ca           mov eax, 0xca4587e7
// 00405831  f7642408             mul dword ptr [esp + 8]
// 00405835  c1ea09               shr edx, 9
// 00405838  33ff                 xor edi, edi
// 0040583a  85d2                 test edx, edx
// 0040583c  7640                 jbe 0x40587e
// 0040583e  53                   push ebx
// 0040583f  8d5c244c             lea ebx, [esp + 0x4c]
// 00405843  53                   push ebx
// 00405844  8d4c242c             lea ecx, [esp + 0x2c]
// 00405848  ff154826b200         call dword ptr [0xb22648]
// 0040584e  8b16                 mov edx, dword ptr [esi]
// 00405850  8b5208               mov edx, dword ptr [edx + 8]
// 00405853  8d442428             lea eax, [esp + 0x28]
// 00405857  50                   push eax
// 00405858  8bce                 mov ecx, esi
// 0040585a  ffd2                 call edx
// 0040585c  8d4c2428             lea ecx, [esp + 0x28]
// 00405860  ff153c26b200         call dword ptr [0xb2263c]
// 00405866  b8e78745ca           mov eax, 0xca4587e7
// 0040586b  f764240c             mul dword ptr [esp + 0xc]
// 0040586f  47                   inc edi
// 00405870  c1ea09               shr edx, 9
// 00405873  81c388020000         add ebx, 0x288
// 00405879  3bfa                 cmp edi, edx
// 0040587b  72c6                 jb 0x405843
// 0040587d  5b                   pop ebx
// 0040587e  8b06                 mov eax, dword ptr [esi]
// 00405880  8b5014               mov edx, dword ptr [eax + 0x14]
// 00405883  8bce                 mov ecx, esi
// 00405885  ffd2                 call edx
// 00405887  50                   push eax
// 00405888  8d4c2424             lea ecx, [esp + 0x24]
// 0040588c  ff15c847b200         call dword ptr [0xb247c8]
// 00405892  8bc8                 mov ecx, eax
// 00405894  ff159847b200         call dword ptr [0xb24798]
// 0040589a  50                   push eax
// 0040589b  8d4c2410             lea ecx, [esp + 0x10]
// 0040589f  e80cf6ffff           call 0x404eb0
// 004058a4  8d4c2420             lea ecx, [esp + 0x20]
// 004058a8  ff15d047b200         call dword ptr [0xb247d0]
// 004058ae  8b06                 mov eax, dword ptr [esi]
// 004058b0  8b10                 mov edx, dword ptr [eax]
// 004058b2  6a01                 push 1
// 004058b4  8bce                 mov ecx, esi
// 004058b6  ffd2                 call edx
// 004058b8  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004058bc  8bbc2468fd0000       mov edi, dword ptr [esp + 0xfd68]
// 004058c3  85ff                 test edi, edi
// 004058c5  7507                 jne 0x4058ce
// 004058c7  bf03400080           mov edi, 0x80004003
// 004058cc  eb2a                 jmp 0x4058f8
// 004058ce  85f6                 test esi, esi
// 004058d0  7504                 jne 0x4058d6
// 004058d2  33c0                 xor eax, eax
// 004058d4  eb0f                 jmp 0x4058e5
// 004058d6  56                   push esi
// 004058d7  ff15102bb200         call dword ptr [0xb22b10]
// 004058dd  50                   push eax
// 004058de  56                   push esi
// 004058df  ff150c2bb200         call dword ptr [0xb22b0c]
// 004058e5  8907                 mov dword ptr [edi], eax
// 004058e7  85c0                 test eax, eax
// 004058e9  750b                 jne 0x4058f6
// 004058eb  85f6                 test esi, esi
// 004058ed  7407                 je 0x4058f6
// 004058ef  bf0e000780           mov edi, 0x8007000e
// 004058f4  eb02                 jmp 0x4058f8
// 004058f6  33ff                 xor edi, edi
// 004058f8  56                   push esi
// 004058f9  ff15042bb200         call dword ptr [0xb22b04]
// 004058ff  8b442414             mov eax, dword ptr [esp + 0x14]
// 00405903  85c0                 test eax, eax
// 00405905  7407                 je 0x40590e
// 00405907  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040590b  894804               mov dword ptr [eax + 4], ecx
// 0040590e  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 00405913  740c                 je 0x405921
// 00405915  8b542418             mov edx, dword ptr [esp + 0x18]
// 00405919  52                   push edx
// 0040591a  6a00                 push 0
// 0040591c  e8b7ca5700           call 0x9823d8
// 00405921  8bc7                 mov eax, edi
// 00405923  5f                   pop edi
// 00405924  5e                   pop esi
// 00405925  81c458fd0000         add esp, 0xfd58
// 0040592b  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX000014@@QAEHKPAPAG@Z)

namespace ns_ROCX000014 {
// from server: 100% by king_originala
// roc 2008-06 00406f60  unit: VCApp::?$CComObject  size: 381 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00406f60
//
// 00406f60  b858fd0000           mov eax, 0xfd58
// 00406f65  e8b6a52900           call 0x6a1520
// 00406f6a  e8f9992900           call 0x6a0968
// 00406f6f  50                   push eax
// 00406f70  8d4c240c             lea ecx, [esp + 0xc]
// 00406f74  e8e9992900           call 0x6a0962
// 00406f79  8d0424               lea eax, [esp]
// 00406f7c  50                   push eax
// 00406f7d  8d4c243c             lea ecx, [esp + 0x3c]
// 00406f81  51                   push ecx
// 00406f82  c744240820fd0000     mov dword ptr [esp + 8], 0xfd20
// 00406f8a  e8ebf33900           call 0x7a637a
// 00406f8f  85c0                 test eax, eax
// 00406f91  7430                 je 0x406fc3
// 00406f93  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00406f97  85c0                 test eax, eax
// 00406f99  7407                 je 0x406fa2
// 00406f9b  8b542408             mov edx, dword ptr [esp + 8]
// 00406f9f  895004               mov dword ptr [eax + 4], edx
// 00406fa2  837c241400           cmp dword ptr [esp + 0x14], 0
// 00406fa7  740c                 je 0x406fb5
// 00406fa9  8b442410             mov eax, dword ptr [esp + 0x10]
// 00406fad  50                   push eax
// 00406fae  6a00                 push 0
// 00406fb0  e8a7992900           call 0x6a095c
// 00406fb5  b805400080           mov eax, 0x80004005
// 00406fba  81c458fd0000         add esp, 0xfd58
// 00406fc0  c20800               ret 8
// 00406fc3  56                   push esi
// 00406fc4  33f6                 xor esi, esi
// 00406fc6  57                   push edi
// 00406fc7  8974240c             mov dword ptr [esp + 0xc], esi
// 00406fcb  39742408             cmp dword ptr [esp + 8], esi
// 00406fcf  0f8696000000         jbe 0x40706b
// 00406fd5  e8d6581500           call 0x55c8b0
// 00406fda  8bf0                 mov esi, eax
// 00406fdc  b8e78745ca           mov eax, 0xca4587e7
// 00406fe1  f7642408             mul dword ptr [esp + 8]
// 00406fe5  c1ea09               shr edx, 9
// 00406fe8  33ff                 xor edi, edi
// 00406fea  85d2                 test edx, edx
// 00406fec  7640                 jbe 0x40702e
// 00406fee  53                   push ebx
// 00406fef  8d5c244c             lea ebx, [esp + 0x4c]
// 00406ff3  53                   push ebx
// 00406ff4  8d4c242c             lea ecx, [esp + 0x2c]
// 00406ff8  ff1558248000         call dword ptr [0x802458]
// 00406ffe  8b16                 mov edx, dword ptr [esi]
// 00407000  8b5204               mov edx, dword ptr [edx + 4]
// 00407003  8d442428             lea eax, [esp + 0x28]
// 00407007  50                   push eax
// 00407008  8bce                 mov ecx, esi
// 0040700a  ffd2                 call edx
// 0040700c  8d4c2428             lea ecx, [esp + 0x28]
// 00407010  ff1568248000         call dword ptr [0x802468]
// 00407016  b8e78745ca           mov eax, 0xca4587e7
// 0040701b  f764240c             mul dword ptr [esp + 0xc]
// 0040701f  47                   inc edi
// 00407020  c1ea09               shr edx, 9
// 00407023  81c388020000         add ebx, 0x288
// 00407029  3bfa                 cmp edi, edx
// 0040702b  72c6                 jb 0x406ff3
// 0040702d  5b                   pop ebx
// 0040702e  8b06                 mov eax, dword ptr [esi]
// 00407030  8b5010               mov edx, dword ptr [eax + 0x10]
// 00407033  8bce                 mov ecx, esi
// 00407035  ffd2                 call edx
// 00407037  50                   push eax
// 00407038  8d4c2424             lea ecx, [esp + 0x24]
// 0040703c  ff15103f8000         call dword ptr [0x803f10]
// 00407042  8bc8                 mov ecx, eax
// 00407044  ff15e03e8000         call dword ptr [0x803ee0]
// 0040704a  50                   push eax
// 0040704b  8d4c2410             lea ecx, [esp + 0x10]
// 0040704f  e8dcf8ffff           call 0x406930
// 00407054  8d4c2420             lea ecx, [esp + 0x20]
// 00407058  ff15143f8000         call dword ptr [0x803f14]
// 0040705e  56                   push esi
// 0040705f  e816962900           call 0x6a067a
// 00407064  8b742410             mov esi, dword ptr [esp + 0x10]
// 00407068  83c404               add esp, 4
// 0040706b  8bbc2468fd0000       mov edi, dword ptr [esp + 0xfd68]
// 00407072  85ff                 test edi, edi
// 00407074  7507                 jne 0x40707d
// 00407076  bf03400080           mov edi, 0x80004003
// 0040707b  eb2a                 jmp 0x4070a7
// 0040707d  85f6                 test esi, esi
// 0040707f  7504                 jne 0x407085
// 00407081  33c0                 xor eax, eax
// 00407083  eb0f                 jmp 0x407094
// 00407085  56                   push esi
// 00407086  ff1528298000         call dword ptr [0x802928]
// 0040708c  50                   push eax
// 0040708d  56                   push esi
// 0040708e  ff152c298000         call dword ptr [0x80292c]
// 00407094  8907                 mov dword ptr [edi], eax
// 00407096  85c0                 test eax, eax
// 00407098  750b                 jne 0x4070a5
// 0040709a  85f6                 test esi, esi
// 0040709c  7407                 je 0x4070a5
// 0040709e  bf0e000780           mov edi, 0x8007000e
// 004070a3  eb02                 jmp 0x4070a7
// 004070a5  33ff                 xor edi, edi
// 004070a7  56                   push esi
// 004070a8  ff1544298000         call dword ptr [0x802944]
// 004070ae  8b442414             mov eax, dword ptr [esp + 0x14]
// 004070b2  85c0                 test eax, eax
// 004070b4  7407                 je 0x4070bd
// 004070b6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004070ba  894804               mov dword ptr [eax + 4], ecx
// 004070bd  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 004070c2  740c                 je 0x4070d0
// 004070c4  8b542418             mov edx, dword ptr [esp + 0x18]
// 004070c8  52                   push edx
// 004070c9  6a00                 push 0
// 004070cb  e88c982900           call 0x6a095c
// 004070d0  8bc7                 mov eax, edi
// 004070d2  5f                   pop edi
// 004070d3  5e                   pop esi
// 004070d4  81c458fd0000         add esp, 0xfd58
// 004070da  c20800               ret 8

typedef unsigned long DWORD;
typedef unsigned short* BSTR;

extern "C" void* __cdecl getContext();
extern "C" void __stdcall releaseContext(int, void*);
extern "C" int __stdcall readRecords(void*, DWORD*);
extern "C" void __cdecl destroyObject(void*);

extern BSTR (__stdcall* SysAllocStringByteLen)(const char*, unsigned int);
extern unsigned int (__stdcall* SysStringByteLen)(BSTR);
extern void (__stdcall* SysFreeString)(BSTR);

struct ContextLink {
    DWORD reserved;
    DWORD value;
};

struct ContextGuard {
    DWORD saved;
    ContextLink* link;
    void* context;
    int owned;
    ContextGuard(void*);
    void cleanup();
};

inline void ContextGuard::cleanup()
{
    if (link)
        link->value = saved;
    if (owned)
        releaseContext(0, context);
}

struct StringStorage {
    char bytes[28];
};

extern void (__thiscall* constructString)(StringStorage*, const char*);
extern void (__thiscall* destructString)(StringStorage*);
extern StringStorage* (__thiscall* constructResultString)(StringStorage*, const char*);
extern const char* (__thiscall* resultStringData)(StringStorage*);
extern void (__thiscall* destructResultString)(StringStorage*);

struct Result {
    BSTR value;
    void assign(const char*);
};

struct Collector {
    virtual ~Collector() {}
    virtual void slot0() = 0;
    virtual void append(StringStorage*) = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual const char* result() = 0;
};

extern Collector* __cdecl createCollector();

struct S {
    int f(DWORD unused, BSTR* output);
};

int S::f(DWORD unused, BSTR* output)
{
    DWORD size;
    Result result;
    ContextGuard guard(getContext());
    union {
        char storage[32];
        StringStorage resultString;
        struct {
            DWORD padding;
            StringStorage itemString;
        } item;
    } temporary;
    char buffer[64800];

    size = 64800;
    if (readRecords(buffer, &size)) {
        guard.cleanup();
        return (int)0x80004005;
    }

    BSTR value = 0;
    result.value = value;
    if (size > 0) {
        Collector* collector = createCollector();
        unsigned int index = 0;

        if (index < size / 648) {
            const char* record = buffer + 8;
            do {
                constructString(&temporary.item.itemString, record);
                collector->append(&temporary.item.itemString);
                destructString(&temporary.item.itemString);
                ++index;
                record += 648;
            } while (index < size / 648);
        }

        result.assign(resultStringData(
            constructResultString(&temporary.resultString, collector->result())));
        destructResultString(&temporary.resultString);
        delete collector;
        value = result.value;
    }

    int status;
    if (!output) {
        status = (int)0x80004003;
    } else {
        BSTR copy;
        if (!value)
            copy = 0;
        else
            copy = SysAllocStringByteLen(
                (const char*)value, SysStringByteLen(value));
        *output = copy;
        if (!copy && value)
            status = (int)0x8007000e;
        else
            status = 0;
    }

    SysFreeString(value);
    guard.cleanup();
    return status;
}
}
