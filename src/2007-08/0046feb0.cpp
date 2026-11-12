// from server: 100% by EspClaude
// roc 2007-08 0046feb0  size: 268 bytes
// library glg3dcpp\Texture.cpp
// switch on interpolate mode (jump table at 0x46ffa4: modes 3,4,5 -> true; 1,2,6 -> false;
// default -> alwaysAssertM(false, "Illegal interpolate mode") at line 0x3cb, return false)

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

extern bool ignoreAssertion;
extern const char assertionExpression[];
extern const char assertionMessage[];
extern const char assertionFile[];

extern bool (__cdecl* assertionHandler)(
    const char*, const String&, const char*, int, bool*, bool);

extern void (__stdcall* terminateProcess)(int);
extern void __cdecl lockAssertions();
extern void __cdecl unlockAssertions();

bool __cdecl isMipMapped(int mode)
{
    switch (mode) {
    case 3:
    case 4:
    case 5:
        return true;
    case 1:
    case 2:
    case 6:
        return false;
    default:
        if (!ignoreAssertion) {
            lockAssertions();
            bool terminate = assertionHandler &&
                assertionHandler(
                    assertionExpression,
                    String(assertionMessage),
                    assertionFile,
                    0x3cb,
                    &ignoreAssertion,
                    true);
            if (terminate) {
                terminateProcess(-1);
            }
            unlockAssertions();
        }
        return false;
    }
}
