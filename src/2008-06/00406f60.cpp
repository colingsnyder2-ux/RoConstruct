// from server: 100% by king_originala
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
        destroyObject(collector);
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
