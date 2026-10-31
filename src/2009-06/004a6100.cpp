// from server: 100% by EspClaude
// roc 2009-06 004a6100  unit: G3D::TextureManager::TextureArgs  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004a6100
//
// 004a6100  6aff                 push -1
// 004a6102  686a708500           push 0x85706a
// 004a6107  64a100000000         mov eax, dword ptr fs:[0]
// 004a610d  50                   push eax
// 004a610e  64892500000000       mov dword ptr fs:[0], esp
// 004a6115  83ec20               sub esp, 0x20
// 004a6118  c7042400000000       mov dword ptr [esp], 0
// 004a611f  803d1fc9a30000       cmp byte ptr [0xa3c91f], 0
// 004a6126  0f8594000000         jne 0x4a61c0
// 004a612c  803df5c8a30000       cmp byte ptr [0xa3c8f5], 0
// 004a6133  0f8587000000         jne 0x4a61c0
// 004a6139  53                   push ebx
// 004a613a  e851300d00           call 0x579190
// 004a613f  833dd8c99f0000       cmp dword ptr [0x9fc9d8], 0
// 004a6146  744b                 je 0x4a6193
// 004a6148  68580b8c00           push 0x8c0b58
// 004a614d  8d4c240c             lea ecx, [esp + 0xc]
// 004a6151  ff15b4e48900         call dword ptr [0x89e4b4]
// 004a6157  6a01                 push 1
// 004a6159  681fc9a300           push 0xa3c91f
// 004a615e  6837020000           push 0x237
// 004a6163  68400b8c00           push 0x8c0b40
// 004a6168  8d442418             lea eax, [esp + 0x18]
// 004a616c  50                   push eax
// 004a616d  68300b8c00           push 0x8c0b30
// 004a6172  c744244400000000     mov dword ptr [esp + 0x44], 0
// 004a617a  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 004a6182  ff15d8c99f00         call dword ptr [0x9fc9d8]
// 004a6188  83c418               add esp, 0x18
// 004a618b  84c0                 test al, al
// 004a618d  7404                 je 0x4a6193
// 004a618f  b301                 mov bl, 1
// 004a6191  eb02                 jmp 0x4a6195
// 004a6193  32db                 xor bl, bl
// 004a6195  f644240401           test byte ptr [esp + 4], 1
// 004a619a  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004a61a2  740a                 je 0x4a61ae
// 004a61a4  8d4c2408             lea ecx, [esp + 8]
// 004a61a8  ff15c4e48900         call dword ptr [0x89e4c4]
// 004a61ae  84db                 test bl, bl
// 004a61b0  5b                   pop ebx
// 004a61b1  7408                 je 0x4a61bb
// 004a61b3  6aff                 push -1
// 004a61b5  ff15bce88900         call dword ptr [0x89e8bc]
// 004a61bb  e840300d00           call 0x579200
// 004a61c0  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004a61c4  a006c9a300           mov al, byte ptr [0xa3c906]
// 004a61c9  64890d00000000       mov dword ptr fs:[0], ecx
// 004a61d0  83c42c               add esp, 0x2c
// 004a61d3  c3                   ret 
// copied from an identical function in another client (function ?checkGLCaps@ns_ROCX000011@@YA_NXZ)

namespace ns_ROCX000011 {
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
                567,
                &ignoreAssertion,
                true);
        if (terminate) {
            terminateProcess(-1);
        }
        unlockAssertions();
    }
    return glCapsInitialized;
}
}
