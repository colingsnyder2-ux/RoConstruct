// from server: 100% by king_originala
struct String {
    unsigned int allocator;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;

    String(const char*);
    ~String();
    const char* c_str() const;
};

extern void (__thiscall* constructString)(String*, const char*);
extern void (__thiscall* destroyString)(String*);

__forceinline String::String(const char* text)
{
    constructString(this, text);
}

__forceinline String::~String()
{
    destroyString(this);
}

__forceinline const char* String::c_str() const
{
    return capacity >= 16 ? storage.pointer : storage.buffer;
}

extern bool initialized;
extern bool ignoreAssertion;
extern const char assertionExpression[];
extern const char assertionMessage[];
extern const char assertionFile[];

extern bool (__cdecl* assertionHandler)(
    const char*, const String&, const char*, int, bool*, bool);

extern void (__stdcall* terminateProcess)(int);
extern void __cdecl lockAssertions();
extern void __cdecl unlockAssertions();
extern String __cdecl makeDriverVersion();

const String& __cdecl driverVersion()
{
    if (!ignoreAssertion && !initialized) {
        lockAssertions();
        bool terminate = assertionHandler &&
            assertionHandler(
                assertionExpression,
                String(assertionMessage),
                assertionFile,
                622,
                &ignoreAssertion,
                true);
        if (terminate) {
            terminateProcess(-1);
            __assume(0);
        }
        unlockAssertions();
    }

    static String version(makeDriverVersion().c_str());
    return version;
}
