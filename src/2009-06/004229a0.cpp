// from server: 100% by EspClaude
// roc 2009-06 004229a0  unit: ThreadLogManager  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004229a0
//
// 004229a0  6aff                 push -1
// 004229a2  6825008600           push 0x860025
// 004229a7  64a100000000         mov eax, dword ptr fs:[0]
// 004229ad  50                   push eax
// 004229ae  64892500000000       mov dword ptr fs:[0], esp
// 004229b5  83ec24               sub esp, 0x24
// 004229b8  53                   push ebx
// 004229b9  33db                 xor ebx, ebx
// 004229bb  895c2404             mov dword ptr [esp + 4], ebx
// 004229bf  56                   push esi
// 004229c0  8bf1                 mov esi, ecx
// 004229c2  381d88039e00         cmp byte ptr [0x9e0388], bl
// 004229c8  7513                 jne 0x4229dd
// 004229ca  5e                   pop esi
// 004229cb  33c0                 xor eax, eax
// 004229cd  5b                   pop ebx
// 004229ce  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004229d2  64890d00000000       mov dword ptr fs:[0], ecx
// 004229d9  83c430               add esp, 0x30
// 004229dc  c3                   ret 
// 004229dd  395e04               cmp dword ptr [esi + 4], ebx
// 004229e0  7575                 jne 0x422a57
// 004229e2  55                   push ebp
// 004229e3  68c8000000           push 0xc8
// 004229e8  e84b602f00           call 0x718a38
// 004229ed  8be8                 mov ebp, eax
// 004229ef  83c404               add esp, 4
// 004229f2  896c2410             mov dword ptr [esp + 0x10], ebp
// 004229f6  895c2438             mov dword ptr [esp + 0x38], ebx
// 004229fa  3beb                 cmp ebp, ebx
// 004229fc  743c                 je 0x422a3a
// 004229fe  8b06                 mov eax, dword ptr [esi]
// 00422a00  8b5004               mov edx, dword ptr [eax + 4]
// 00422a03  57                   push edi
// 00422a04  8d4c2418             lea ecx, [esp + 0x18]
// 00422a08  51                   push ecx
// 00422a09  8bce                 mov ecx, esi
// 00422a0b  ffd2                 call edx
// 00422a0d  8bf8                 mov edi, eax
// 00422a0f  bb01000000           mov ebx, 1
// 00422a14  8d4e0c               lea ecx, [esi + 0xc]
// 00422a17  c644243c01           mov byte ptr [esp + 0x3c], 1
// 00422a1c  895c2410             mov dword ptr [esp + 0x10], ebx
// 00422a20  ff15bce48900         call dword ptr [0x89e4bc]
// 00422a26  50                   push eax
// 00422a27  8bcf                 mov ecx, edi
// 00422a29  ff15bce48900         call dword ptr [0x89e4bc]
// 00422a2f  50                   push eax
// 00422a30  8bcd                 mov ecx, ebp
// 00422a32  e8695d2e00           call 0x7087a0
// 00422a37  5f                   pop edi
// 00422a38  eb02                 jmp 0x422a3c
// 00422a3a  33c0                 xor eax, eax
// 00422a3c  894604               mov dword ptr [esi + 4], eax
// 00422a3f  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 00422a47  5d                   pop ebp
// 00422a48  f6c301               test bl, 1
// 00422a4b  740a                 je 0x422a57
// 00422a4d  8d4c2410             lea ecx, [esp + 0x10]
// 00422a51  ff15c4e48900         call dword ptr [0x89e4c4]
// 00422a57  8b4604               mov eax, dword ptr [esi + 4]
// 00422a5a  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00422a5e  5e                   pop esi
// 00422a5f  5b                   pop ebx
// 00422a60  64890d00000000       mov dword ptr fs:[0], ecx
// 00422a67  83c430               add esp, 0x30
// 00422a6a  c3                   ret 
// copied from an identical function in another client (function ?getReporter@ThreadLogManager@@QAEPAUCrashReporter@@XZ)

// from server: 94% by king_originala
// roc 2008-06 00427950  unit: ThreadLogManager  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00427950
//
// 00427950  6aff                 push -1
// 00427952  6805f07b00           push 0x7bf005
// 00427957  64a100000000         mov eax, dword ptr fs:[0]
// 0042795d  50                   push eax
// 0042795e  64892500000000       mov dword ptr fs:[0], esp
// 00427965  83ec24               sub esp, 0x24
// 00427968  53                   push ebx
// 00427969  33db                 xor ebx, ebx
// 0042796b  895c2404             mov dword ptr [esp + 4], ebx
// 0042796f  56                   push esi
// 00427970  8bf1                 mov esi, ecx
// 00427972  381d86e49200         cmp byte ptr [0x92e486], bl
// 00427978  7513                 jne 0x42798d
// 0042797a  5e                   pop esi
// 0042797b  33c0                 xor eax, eax
// 0042797d  5b                   pop ebx
// 0042797e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00427982  64890d00000000       mov dword ptr fs:[0], ecx
// 00427989  83c430               add esp, 0x30
// 0042798c  c3                   ret 
// 0042798d  395e04               cmp dword ptr [esi + 4], ebx
// 00427990  7575                 jne 0x427a07
// 00427992  55                   push ebp
// 00427993  68c8000000           push 0xc8
// 00427998  e8838f2700           call 0x6a0920
// 0042799d  8be8                 mov ebp, eax
// 0042799f  83c404               add esp, 4
// 004279a2  896c2410             mov dword ptr [esp + 0x10], ebp
// 004279a6  895c2438             mov dword ptr [esp + 0x38], ebx
// 004279aa  3beb                 cmp ebp, ebx
// 004279ac  743c                 je 0x4279ea
// 004279ae  8b06                 mov eax, dword ptr [esi]
// 004279b0  8b5004               mov edx, dword ptr [eax + 4]
// 004279b3  57                   push edi
// 004279b4  8d4c2418             lea ecx, [esp + 0x18]
// 004279b8  51                   push ecx
// 004279b9  8bce                 mov ecx, esi
// 004279bb  ffd2                 call edx
// 004279bd  8bf8                 mov edi, eax
// 004279bf  bb01000000           mov ebx, 1
// 004279c4  8d4e0c               lea ecx, [esi + 0xc]
// 004279c7  c644243c01           mov byte ptr [esp + 0x3c], 1
// 004279cc  895c2410             mov dword ptr [esp + 0x10], ebx
// 004279d0  ff1564248000         call dword ptr [0x802464]
// 004279d6  50                   push eax
// 004279d7  8bcf                 mov ecx, edi
// 004279d9  ff1564248000         call dword ptr [0x802464]
// 004279df  50                   push eax
// 004279e0  8bcd                 mov ecx, ebp
// 004279e2  e8b9f31700           call 0x5a6da0
// 004279e7  5f                   pop edi
// 004279e8  eb02                 jmp 0x4279ec
// 004279ea  33c0                 xor eax, eax
// 004279ec  894604               mov dword ptr [esi + 4], eax
// 004279ef  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 004279f7  5d                   pop ebp
// 004279f8  f6c301               test bl, 1
// 004279fb  740a                 je 0x427a07
// 004279fd  8d4c2410             lea ecx, [esp + 0x10]
// 00427a01  ff1568248000         call dword ptr [0x802468]
// 00427a07  8b4604               mov eax, dword ptr [esi + 4]
// 00427a0a  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00427a0e  5e                   pop esi
// 00427a0f  5b                   pop ebx
// 00427a10  64890d00000000       mov dword ptr fs:[0], ecx
// 00427a17  83c430               add esp, 0x30
// 00427a1a  c3                   ret 

typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

extern unsigned char loggingEnabled;

struct String
{
    unsigned char storage[28];

    __declspec(dllimport) ~String();
    __declspec(dllimport) const char* c_str() const;
};

struct NameString
{
    unsigned char storage[28];

    __declspec(dllimport) ~NameString();
    __declspec(dllimport) const char* c_str() const;
};

struct CrashReporter
{
    unsigned char storage[200];

    CrashReporter(const char*, const char*);
};

struct ThreadLogManager
{
    virtual void reserved();
    virtual NameString getName();

    CrashReporter* reporter;
    unsigned int reservedData;
    String description;

    CrashReporter* getReporter();
};

CrashReporter* ThreadLogManager::getReporter()
{
    if (!loggingEnabled)
        return 0;

    if (!reporter)
        reporter = new CrashReporter(getName().c_str(), description.c_str());

    return reporter;
}