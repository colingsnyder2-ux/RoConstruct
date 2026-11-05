// from server: 100% by colin
// from server: 99% by colin
// roc 2008-06 0046fd30  unit: RBX::LDraw2Lua::LuaWriter  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046fd30
//
// 0046fd30  6aff                 push -1
// 0046fd32  683a4a7c00           push 0x7c4a3a
// 0046fd37  64a100000000         mov eax, dword ptr fs:[0]
// 0046fd3d  50                   push eax
// 0046fd3e  64892500000000       mov dword ptr fs:[0], esp
// 0046fd45  83ec20               sub esp, 0x20
// 0046fd48  c7042400000000       mov dword ptr [esp], 0
// 0046fd4f  803d8eee960000       cmp byte ptr [0x96ee8e], 0
// 0046fd56  0f8594000000         jne 0x46fdf0
// 0046fd5c  803d65ee960000       cmp byte ptr [0x96ee65], 0
// 0046fd63  0f8587000000         jne 0x46fdf0
// 0046fd69  53                   push ebx
// 0046fd6a  e8d1ab0900           call 0x50a940
// 0046fd6f  833d8c27940000       cmp dword ptr [0x94278c], 0
// 0046fd76  744b                 je 0x46fdc3
// 0046fd78  6898cc8100           push 0x81cc98
// 0046fd7d  8d4c240c             lea ecx, [esp + 0xc]
// 0046fd81  ff1558248000         call dword ptr [0x802458]
// 0046fd87  6a01                 push 1
// 0046fd89  688eee9600           push 0x96ee8e
// 0046fd8e  6831020000           push 0x231
// 0046fd93  6880cc8100           push 0x81cc80
// 0046fd98  8d442418             lea eax, [esp + 0x18]
// 0046fd9c  50                   push eax

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
extern bool glCapsInitialized;

bool __cdecl checkGLCaps()
{
    if (!ignoreAssertion && !initialized) {
        lockAssertions();
        bool terminate = assertionHandler &&
            assertionHandler(
                assertionExpression,
                String(assertionMessage),
                assertionFile,
                561,
                &ignoreAssertion,
                true);
        if (terminate) {
            terminateProcess(-1);
        }
        unlockAssertions();
    }
    return glCapsInitialized;
}
