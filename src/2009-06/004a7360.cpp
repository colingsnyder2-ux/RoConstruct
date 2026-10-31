// from server: 100% by EspClaude
// roc 2009-06 004a7360  unit: G3D::TextureManager::TextureArgs  size: 304 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004a7360
//
// 004a7360  6aff                 push -1
// 004a7362  6811798500           push 0x857911
// 004a7367  64a100000000         mov eax, dword ptr fs:[0]
// 004a736d  50                   push eax
// 004a736e  64892500000000       mov dword ptr fs:[0], esp
// 004a7375  83ec40               sub esp, 0x40
// 004a7378  53                   push ebx
// 004a7379  33db                 xor ebx, ebx
// 004a737b  895c2408             mov dword ptr [esp + 8], ebx
// 004a737f  381dd0c9a300         cmp byte ptr [0xa3c9d0], bl
// 004a7385  0f8590000000         jne 0x4a741b
// 004a738b  381df4c8a300         cmp byte ptr [0xa3c8f4], bl
// 004a7391  0f8584000000         jne 0x4a741b
// 004a7397  e8f41d0d00           call 0x579190
// 004a739c  391dd8c99f00         cmp dword ptr [0x9fc9d8], ebx
// 004a73a2  7447                 je 0x4a73eb
// 004a73a4  68940e8c00           push 0x8c0e94
// 004a73a9  8d4c2410             lea ecx, [esp + 0x10]
// 004a73ad  ff15b4e48900         call dword ptr [0x89e4b4]
// 004a73b3  895c244c             mov dword ptr [esp + 0x4c], ebx
// 004a73b7  bb01000000           mov ebx, 1
// 004a73bc  53                   push ebx
// 004a73bd  68d0c9a300           push 0xa3c9d0
// 004a73c2  686e020000           push 0x26e
// 004a73c7  68400b8c00           push 0x8c0b40
// 004a73cc  8d44241c             lea eax, [esp + 0x1c]
// 004a73d0  50                   push eax
// 004a73d1  68c00c8c00           push 0x8c0cc0
// 004a73d6  895c2420             mov dword ptr [esp + 0x20], ebx
// 004a73da  ff15d8c99f00         call dword ptr [0x9fc9d8]
// 004a73e0  83c418               add esp, 0x18
// 004a73e3  885c2407             mov byte ptr [esp + 7], bl
// 004a73e7  84c0                 test al, al
// 004a73e9  7505                 jne 0x4a73f0
// 004a73eb  c644240700           mov byte ptr [esp + 7], 0
// 004a73f0  c744244cffffffff     mov dword ptr [esp + 0x4c], 0xffffffff
// 004a73f8  f6c301               test bl, 1
// 004a73fb  740a                 je 0x4a7407
// 004a73fd  8d4c240c             lea ecx, [esp + 0xc]
// 004a7401  ff15c4e48900         call dword ptr [0x89e4c4]
// 004a7407  807c240700           cmp byte ptr [esp + 7], 0
// 004a740c  7408                 je 0x4a7416
// 004a740e  6aff                 push -1
// 004a7410  ff15bce88900         call dword ptr [0x89e8bc]
// 004a7416  e8e51d0d00           call 0x579200
// 004a741b  f605ccc9a30001       test byte ptr [0xa3c9cc], 1
// 004a7422  7557                 jne 0x4a747b
// 004a7424  b801000000           mov eax, 1
// 004a7429  0905ccc9a300         or dword ptr [0xa3c9cc], eax
// 004a742f  8d4c2428             lea ecx, [esp + 0x28]
// 004a7433  51                   push ecx
// 004a7434  89442450             mov dword ptr [esp + 0x50], eax
// 004a7438  e8a3fbffff           call 0x4a6fe0
// 004a743d  83c404               add esp, 4
// 004a7440  83781810             cmp dword ptr [eax + 0x18], 0x10
// 004a7444  c644244c02           mov byte ptr [esp + 0x4c], 2
// 004a7449  7205                 jb 0x4a7450
// 004a744b  8b4004               mov eax, dword ptr [eax + 4]
// 004a744e  eb03                 jmp 0x4a7453
// 004a7450  83c004               add eax, 4
// 004a7453  50                   push eax
// 004a7454  b9b0c9a300           mov ecx, 0xa3c9b0
// 004a7459  ff15b4e48900         call dword ptr [0x89e4b4]
// 004a745f  8d4c2428             lea ecx, [esp + 0x28]
// 004a7463  c644244c01           mov byte ptr [esp + 0x4c], 1
// 004a7468  ff15c4e48900         call dword ptr [0x89e4c4]
// 004a746e  68004f8900           push 0x894f00
// 004a7473  e883262700           call 0x719afb
// 004a7478  83c404               add esp, 4
// 004a747b  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 004a747f  b8b0c9a300           mov eax, 0xa3c9b0
// 004a7484  5b                   pop ebx
// 004a7485  64890d00000000       mov dword ptr fs:[0], ecx
// 004a748c  83c44c               add esp, 0x4c
// 004a748f  c3                   ret 
// copied from an identical function in another client (function ?driverVersion@ns_ROCX000014@@YAABUString@1@XZ)

namespace ns_ROCX000014 {
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
}
