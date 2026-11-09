// from server: 100% by EspClaude
// roc 2009-06 004a61e0  unit: G3D::TextureManager::TextureArgs  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004a61e0
//
// 004a61e0  6aff                 push -1
// 004a61e2  686a708500           push 0x85706a
// 004a61e7  64a100000000         mov eax, dword ptr fs:[0]
// 004a61ed  50                   push eax
// 004a61ee  64892500000000       mov dword ptr fs:[0], esp
// 004a61f5  83ec20               sub esp, 0x20
// 004a61f8  c7042400000000       mov dword ptr [esp], 0
// 004a61ff  803d20c9a30000       cmp byte ptr [0xa3c920], 0
// 004a6206  0f8594000000         jne 0x4a62a0
// 004a620c  803df5c8a30000       cmp byte ptr [0xa3c8f5], 0
// 004a6213  0f8587000000         jne 0x4a62a0
// 004a6219  53                   push ebx
// 004a621a  e8712f0d00           call 0x579190
// 004a621f  833dd8c99f0000       cmp dword ptr [0x9fc9d8], 0
// 004a6226  744b                 je 0x4a6273
// 004a6228  68580b8c00           push 0x8c0b58
// 004a622d  8d4c240c             lea ecx, [esp + 0xc]
// 004a6231  ff15b4e48900         call dword ptr [0x89e4b4]
// 004a6237  6a01                 push 1
// 004a6239  6820c9a300           push 0xa3c920
// 004a623e  683d020000           push 0x23d
// 004a6243  68400b8c00           push 0x8c0b40
// 004a6248  8d442418             lea eax, [esp + 0x18]
// 004a624c  50                   push eax
// 004a624d  68300b8c00           push 0x8c0b30
// 004a6252  c744244400000000     mov dword ptr [esp + 0x44], 0
// 004a625a  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 004a6262  ff15d8c99f00         call dword ptr [0x9fc9d8]
// 004a6268  83c418               add esp, 0x18
// 004a626b  84c0                 test al, al
// 004a626d  7404                 je 0x4a6273
// 004a626f  b301                 mov bl, 1
// 004a6271  eb02                 jmp 0x4a6275
// 004a6273  32db                 xor bl, bl
// 004a6275  f644240401           test byte ptr [esp + 4], 1
// 004a627a  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004a6282  740a                 je 0x4a628e
// 004a6284  8d4c2408             lea ecx, [esp + 8]
// 004a6288  ff15c4e48900         call dword ptr [0x89e4c4]
// 004a628e  84db                 test bl, bl
// 004a6290  5b                   pop ebx
// 004a6291  7408                 je 0x4a629b
// 004a6293  6aff                 push -1
// 004a6295  ff15bce88900         call dword ptr [0x89e8bc]
// 004a629b  e8602f0d00           call 0x579200
// 004a62a0  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004a62a4  a007c9a300           mov al, byte ptr [0xa3c907]
// 004a62a9  64890d00000000       mov dword ptr fs:[0], ecx
// 004a62b0  83c42c               add esp, 0x2c
// 004a62b3  c3                   ret 
// copied from an identical function in another client (function ?checkGLCaps@ns_ROCX000012@@YA_NXZ)

namespace ns_ROCX000012 {
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
                573,
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
