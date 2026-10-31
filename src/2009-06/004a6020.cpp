// from server: 100% by EspClaude
// roc 2009-06 004a6020  unit: G3D::TextureManager::TextureArgs  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004a6020
//
// 004a6020  6aff                 push -1
// 004a6022  686a708500           push 0x85706a
// 004a6027  64a100000000         mov eax, dword ptr fs:[0]
// 004a602d  50                   push eax
// 004a602e  64892500000000       mov dword ptr fs:[0], esp
// 004a6035  83ec20               sub esp, 0x20
// 004a6038  c7042400000000       mov dword ptr [esp], 0
// 004a603f  803d1ec9a30000       cmp byte ptr [0xa3c91e], 0
// 004a6046  0f8594000000         jne 0x4a60e0
// 004a604c  803df5c8a30000       cmp byte ptr [0xa3c8f5], 0
// 004a6053  0f8587000000         jne 0x4a60e0
// 004a6059  53                   push ebx
// 004a605a  e831310d00           call 0x579190
// 004a605f  833dd8c99f0000       cmp dword ptr [0x9fc9d8], 0
// 004a6066  744b                 je 0x4a60b3
// 004a6068  68580b8c00           push 0x8c0b58
// 004a606d  8d4c240c             lea ecx, [esp + 0xc]
// 004a6071  ff15b4e48900         call dword ptr [0x89e4b4]
// 004a6077  6a01                 push 1
// 004a6079  681ec9a300           push 0xa3c91e
// 004a607e  6831020000           push 0x231
// 004a6083  68400b8c00           push 0x8c0b40
// 004a6088  8d442418             lea eax, [esp + 0x18]
// 004a608c  50                   push eax
// 004a608d  68300b8c00           push 0x8c0b30
// 004a6092  c744244400000000     mov dword ptr [esp + 0x44], 0
// 004a609a  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 004a60a2  ff15d8c99f00         call dword ptr [0x9fc9d8]
// 004a60a8  83c418               add esp, 0x18
// 004a60ab  84c0                 test al, al
// 004a60ad  7404                 je 0x4a60b3
// 004a60af  b301                 mov bl, 1
// 004a60b1  eb02                 jmp 0x4a60b5
// 004a60b3  32db                 xor bl, bl
// 004a60b5  f644240401           test byte ptr [esp + 4], 1
// 004a60ba  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004a60c2  740a                 je 0x4a60ce
// 004a60c4  8d4c2408             lea ecx, [esp + 8]
// 004a60c8  ff15c4e48900         call dword ptr [0x89e4c4]
// 004a60ce  84db                 test bl, bl
// 004a60d0  5b                   pop ebx
// 004a60d1  7408                 je 0x4a60db
// 004a60d3  6aff                 push -1
// 004a60d5  ff15bce88900         call dword ptr [0x89e8bc]
// 004a60db  e820310d00           call 0x579200
// 004a60e0  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004a60e4  a005c9a300           mov al, byte ptr [0xa3c905]
// 004a60e9  64890d00000000       mov dword ptr fs:[0], ecx
// 004a60f0  83c42c               add esp, 0x2c
// 004a60f3  c3                   ret 
// copied from an identical function in another client (function ?checkGLCaps@ns_ROCX000010@@YA_NXZ)

namespace ns_ROCX000010 {
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
}
