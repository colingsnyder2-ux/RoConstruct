// from server: 100% by EspClaude
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
