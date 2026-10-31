// from server: 100% by EspClaude
// roc 2009-06 004a5f40  unit: G3D::TextureManager::TextureArgs  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004a5f40
//
// 004a5f40  6aff                 push -1
// 004a5f42  686a708500           push 0x85706a
// 004a5f47  64a100000000         mov eax, dword ptr fs:[0]
// 004a5f4d  50                   push eax
// 004a5f4e  64892500000000       mov dword ptr fs:[0], esp
// 004a5f55  83ec20               sub esp, 0x20
// 004a5f58  c7042400000000       mov dword ptr [esp], 0
// 004a5f5f  803d1dc9a30000       cmp byte ptr [0xa3c91d], 0
// 004a5f66  0f8594000000         jne 0x4a6000
// 004a5f6c  803df5c8a30000       cmp byte ptr [0xa3c8f5], 0
// 004a5f73  0f8587000000         jne 0x4a6000
// 004a5f79  53                   push ebx
// 004a5f7a  e811320d00           call 0x579190
// 004a5f7f  833dd8c99f0000       cmp dword ptr [0x9fc9d8], 0
// 004a5f86  744b                 je 0x4a5fd3
// 004a5f88  68580b8c00           push 0x8c0b58
// 004a5f8d  8d4c240c             lea ecx, [esp + 0xc]
// 004a5f91  ff15b4e48900         call dword ptr [0x89e4b4]
// 004a5f97  6a01                 push 1
// 004a5f99  681dc9a300           push 0xa3c91d
// 004a5f9e  682b020000           push 0x22b
// 004a5fa3  68400b8c00           push 0x8c0b40
// 004a5fa8  8d442418             lea eax, [esp + 0x18]
// 004a5fac  50                   push eax
// 004a5fad  68300b8c00           push 0x8c0b30
// 004a5fb2  c744244400000000     mov dword ptr [esp + 0x44], 0
// 004a5fba  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 004a5fc2  ff15d8c99f00         call dword ptr [0x9fc9d8]
// 004a5fc8  83c418               add esp, 0x18
// 004a5fcb  84c0                 test al, al
// 004a5fcd  7404                 je 0x4a5fd3
// 004a5fcf  b301                 mov bl, 1
// 004a5fd1  eb02                 jmp 0x4a5fd5
// 004a5fd3  32db                 xor bl, bl
// 004a5fd5  f644240401           test byte ptr [esp + 4], 1
// 004a5fda  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004a5fe2  740a                 je 0x4a5fee
// 004a5fe4  8d4c2408             lea ecx, [esp + 8]
// 004a5fe8  ff15c4e48900         call dword ptr [0x89e4c4]
// 004a5fee  84db                 test bl, bl
// 004a5ff0  5b                   pop ebx
// 004a5ff1  7408                 je 0x4a5ffb
// 004a5ff3  6aff                 push -1
// 004a5ff5  ff15bce88900         call dword ptr [0x89e8bc]
// 004a5ffb  e800320d00           call 0x579200
// 004a6000  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004a6004  a004c9a300           mov al, byte ptr [0xa3c904]
// 004a6009  64890d00000000       mov dword ptr fs:[0], ecx
// 004a6010  83c42c               add esp, 0x2c
// 004a6013  c3                   ret 
// copied from an identical function in another client (function ?checkGLCaps@ns_ROCX00000f@@YA_NXZ)

namespace ns_ROCX00000f {
//

//

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
                555,
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
