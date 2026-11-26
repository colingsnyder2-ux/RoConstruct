// from server: 100% by Xemicl
// roc 2012-06 004313c0  unit: ThreadLogManager  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004313c0
//
// 004313c0  6aff                 push -1
// 004313c2  682573aa00           push 0xaa7325
// 004313c7  64a100000000         mov eax, dword ptr fs:[0]
// 004313cd  50                   push eax
// 004313ce  64892500000000       mov dword ptr fs:[0], esp
// 004313d5  83ec24               sub esp, 0x24
// 004313d8  53                   push ebx
// 004313d9  33db                 xor ebx, ebx
// 004313db  895c2404             mov dword ptr [esp + 4], ebx
// 004313df  56                   push esi
// 004313e0  8bf1                 mov esi, ecx
// 004313e2  381d705dd600         cmp byte ptr [0xd65d70], bl
// 004313e8  7513                 jne 0x4313fd
// 004313ea  5e                   pop esi
// 004313eb  33c0                 xor eax, eax
// 004313ed  5b                   pop ebx
// 004313ee  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004313f2  64890d00000000       mov dword ptr fs:[0], ecx
// 004313f9  83c430               add esp, 0x30
// 004313fc  c3                   ret 
// 004313fd  395e04               cmp dword ptr [esi + 4], ebx
// 00431400  7575                 jne 0x431477
// 00431402  55                   push ebp
// 00431403  68c8000000           push 0xc8
// 00431408  e80d0d5500           call 0x98211a
// 0043140d  8be8                 mov ebp, eax
// 0043140f  83c404               add esp, 4
// 00431412  896c2410             mov dword ptr [esp + 0x10], ebp
// 00431416  895c2438             mov dword ptr [esp + 0x38], ebx
// 0043141a  3beb                 cmp ebp, ebx
// 0043141c  743c                 je 0x43145a
// 0043141e  8b06                 mov eax, dword ptr [esi]
// 00431420  8b5004               mov edx, dword ptr [eax + 4]
// 00431423  57                   push edi
// 00431424  8d4c2418             lea ecx, [esp + 0x18]
// 00431428  51                   push ecx
// 00431429  8bce                 mov ecx, esi
// 0043142b  ffd2                 call edx
// 0043142d  8bf8                 mov edi, eax
// 0043142f  bb01000000           mov ebx, 1
// 00431434  8d4e0c               lea ecx, [esi + 0xc]
// 00431437  c644243c01           mov byte ptr [esp + 0x3c], 1
// 0043143c  895c2410             mov dword ptr [esp + 0x10], ebx
// 00431440  ff154026b200         call dword ptr [0xb22640]
// 00431446  50                   push eax
// 00431447  8bcf                 mov ecx, edi
// 00431449  ff154026b200         call dword ptr [0xb22640]
// 0043144f  50                   push eax
// 00431450  8bcd                 mov ecx, ebp
// 00431452  e849155400           call 0x9729a0
// 00431457  5f                   pop edi
// 00431458  eb02                 jmp 0x43145c
// 0043145a  33c0                 xor eax, eax
// 0043145c  894604               mov dword ptr [esi + 4], eax
// 0043145f  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 00431467  5d                   pop ebp
// 00431468  f6c301               test bl, 1
// 0043146b  740a                 je 0x431477
// 0043146d  8d4c2410             lea ecx, [esp + 0x10]
// 00431471  ff153c26b200         call dword ptr [0xb2263c]
// 00431477  8b4604               mov eax, dword ptr [esi + 4]
// 0043147a  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0043147e  5e                   pop esi
// 0043147f  5b                   pop ebx
// 00431480  64890d00000000       mov dword ptr fs:[0], ecx
// 00431487  83c430               add esp, 0x30
// 0043148a  c3                   ret 
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