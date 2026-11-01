// from server: 100% by colin
// from server: 95% by colin
// roc 2008-06 00560460  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 300 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00560460
//
// 00560460  6aff                 push -1
// 00560462  68dcec7c00           push 0x7cecdc
// 00560467  64a100000000         mov eax, dword ptr fs:[0]
// 0056046d  50                   push eax
// 0056046e  64892500000000       mov dword ptr fs:[0], esp
// 00560475  83ec40               sub esp, 0x40
// 00560478  53                   push ebx
// 00560479  56                   push esi
// 0056047a  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00560482  837c247410           cmp dword ptr [esp + 0x74], 0x10
// 00560487  8b742460             mov esi, dword ptr [esp + 0x60]
// 0056048b  bb01000000           mov ebx, 1
// 00560490  895c2450             mov dword ptr [esp + 0x50], ebx
// 00560494  7304                 jae 0x56049a
// 00560496  8d742460             lea esi, [esp + 0x60]
// 0056049a  8d44242c             lea eax, [esp + 0x2c]
// 0056049e  50                   push eax
// 0056049f  83c60b               add esi, 0xb
// 005604a2  e819c0ffff           call 0x55c4c0
// 005604a7  56                   push esi
// 005604a8  50                   push eax
// 005604a9  8d4c241c             lea ecx, [esp + 0x1c]
// 005604ad  51                   push ecx
// 005604ae  c644246002           mov byte ptr [esp + 0x60], 2
// 005604b3  ff15e4238000         call dword ptr [0x8023e4]
// 005604b9  83c410               add esp, 0x10
// 005604bc  83781810             cmp dword ptr [eax + 0x18], 0x10
// 005604c0  c644245003           mov byte ptr [esp + 0x50], 3
// 005604c5  7205                 jb 0x5604cc
// 005604c7  8b4004               mov eax, dword ptr [eax + 4]
// 005604ca  eb03                 jmp 0x5604cf
// 005604cc  83c004               add eax, 4
// 005604cf  50                   push eax
// 005604d0  8d4c240c             lea ecx, [esp + 0xc]
// 005604d4  e847e9ffff           call 0x55ee20
// 005604d9  8d4c2410             lea ecx, [esp + 0x10]
// 005604dd  c644245005           mov byte ptr [esp + 0x50], 5
// 005604e2  ff1568248000         call dword ptr [0x802468]
// 005604e8  8d4c242c             lea ecx, [esp + 0x2c]
// 005604ec  c644245006           mov byte ptr [esp + 0x50], 6
// 005604f1  ff1568248000         call dword ptr [0x802468]
// 005604f7  8b542408             mov edx, dword ptr [esp + 8]
// 005604fb  52                   push edx
// 005604fc  ff151c2b8000         call dword ptr [0x802b1c]
// 00560502  8b742458             mov esi, dword ptr [esp + 0x58]
// 00560506  85c0                 test eax, eax
// 00560508  752b                 jne 0x560535
// 0056050a  6816b78000           push 0x80b716
// 0056050f  8bce                 mov ecx, esi
// 00560511  ff1558248000         call dword ptr [0x802458]
// 00560517  8b442408             mov eax, dword ptr [esp + 8]
// 0056051b  83c0f0               add eax, -0x10
// 0056051e  895c240c             mov dword ptr [esp + 0xc], ebx
// 00560522  885c2450             mov byte ptr [esp + 0x50], bl
// 00560526  8d480c               lea ecx, [eax + 0xc]
// 00560529  83caff               or edx, 0xffffffff
// 0056052c  f00fc111             lock xadd dword ptr [ecx], edx
// 00560530  4a                   dec edx
// 00560531  85d2                 test edx, edx
// 00560533  eb29                 jmp 0x56055e
// 00560535  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00560539  51                   push ecx
// 0056053a  8bce                 mov ecx, esi
// 0056053c  ff1558248000         call dword ptr [0x802458]
// 00560542  8b442408             mov eax, dword ptr [esp + 8]
// 00560546  83c0f0               add eax, -0x10
// 00560549  895c240c             mov dword ptr [esp + 0xc], ebx
// 0056054d  885c2450             mov byte ptr [esp + 0x50], bl
// 00560551  8d500c               lea edx, [eax + 0xc]
// 00560554  83c9ff               or ecx, 0xffffffff
// 00560557  f00fc10a             lock xadd dword ptr [edx], ecx
// 0056055b  49                   dec ecx
// 0056055c  85c9                 test ecx, ecx
// 0056055e  7f0a                 jg 0x56056a
// 00560560  8b08                 mov ecx, dword ptr [eax]
// 00560562  8b11                 mov edx, dword ptr [ecx]
// 00560564  50                   push eax
// 00560565  8b4204               mov eax, dword ptr [edx + 4]
// 00560568  ffd0                 call eax
// 0056056a  8d4c245c             lea ecx, [esp + 0x5c]
// 0056056e  c644245000           mov byte ptr [esp + 0x50], 0
// 00560573  ff1568248000         call dword ptr [0x802468]
// 00560579  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0056057d  8bc6                 mov eax, esi
// 0056057f  5e                   pop esi
// 00560580  5b                   pop ebx
// 00560581  64890d00000000       mov dword ptr fs:[0], ecx
// 00560588  83c44c               add esp, 0x4c
// 0056058b  c3                   ret 

// from server: 84% by king_originala
// roc 2008-06 00560460  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 300 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00560460
//
// 00560460  6aff                 push -1
// 00560462  68dcec7c00           push 0x7cecdc
// 00560467  64a100000000         mov eax, dword ptr fs:[0]
// 0056046d  50                   push eax
// 0056046e  64892500000000       mov dword ptr fs:[0], esp
// 00560475  83ec40               sub esp, 0x40
// 00560478  53                   push ebx
// 00560479  56                   push esi
// 0056047a  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00560482  837c247410           cmp dword ptr [esp + 0x74], 0x10
// 00560487  8b742460             mov esi, dword ptr [esp + 0x60]
// 0056048b  bb01000000           mov ebx, 1
// 00560490  895c2450             mov dword ptr [esp + 0x50], ebx
// 00560494  7304                 jae 0x56049a
// 00560496  8d742460             lea esi, [esp + 0x60]
// 0056049a  8d44242c             lea eax, [esp + 0x2c]
// 0056049e  50                   push eax
// 0056049f  83c60b               add esi, 0xb
// 005604a2  e819c0ffff           call 0x55c4c0
// 005604a7  56                   push esi
// 005604a8  50                   push eax
// 005604a9  8d4c241c             lea ecx, [esp + 0x1c]
// 005604ad  51                   push ecx
// 005604ae  c644246002           mov byte ptr [esp + 0x60], 2
// 005604b3  ff15e4238000         call dword ptr [0x8023e4]
// 005604b9  83c410               add esp, 0x10
// 005604bc  83781810             cmp dword ptr [eax + 0x18], 0x10
// 005604c0  c644245003           mov byte ptr [esp + 0x50], 3
// 005604c5  7205                 jb 0x5604cc
// 005604c7  8b4004               mov eax, dword ptr [eax + 4]
// 005604ca  eb03                 jmp 0x5604cf
// 005604cc  83c004               add eax, 4
// 005604cf  50                   push eax
// 005604d0  8d4c240c             lea ecx, [esp + 0xc]
// 005604d4  e847e9ffff           call 0x55ee20
// 005604d9  8d4c2410             lea ecx, [esp + 0x10]
// 005604dd  c644245005           mov byte ptr [esp + 0x50], 5
// 005604e2  ff1568248000         call dword ptr [0x802468]
// 005604e8  8d4c242c             lea ecx, [esp + 0x2c]
// 005604ec  c644245006           mov byte ptr [esp + 0x50], 6
// 005604f1  ff1568248000         call dword ptr [0x802468]
// 005604f7  8b542408             mov edx, dword ptr [esp + 8]
// 005604fb  52                   push edx
// 005604fc  ff151c2b8000         call dword ptr [0x802b1c]
// 00560502  8b742458             mov esi, dword ptr [esp + 0x58]
// 00560506  85c0                 test eax, eax
// 00560508  752b                 jne 0x560535
// 0056050a  6816b78000           push 0x80b716
// 0056050f  8bce                 mov ecx, esi
// 00560511  ff1558248000         call dword ptr [0x802458]
// 00560517  8b442408             mov eax, dword ptr [esp + 8]
// 0056051b  83c0f0               add eax, -0x10
// 0056051e  895c240c             mov dword ptr [esp + 0xc], ebx
// 00560522  885c2450             mov byte ptr [esp + 0x50], bl
// 00560526  8d480c               lea ecx, [eax + 0xc]
// 00560529  83caff               or edx, 0xffffffff
// 0056052c  f00fc111             lock xadd dword ptr [ecx], edx
// 00560530  4a                   dec edx
// 00560531  85d2                 test edx, edx
// 00560533  eb29                 jmp 0x56055e
// 00560535  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00560539  51                   push ecx
// 0056053a  8bce                 mov ecx, esi
// 0056053c  ff1558248000         call dword ptr [0x802458]
// 00560542  8b442408             mov eax, dword ptr [esp + 8]
// 00560546  83c0f0               add eax, -0x10
// 00560549  895c240c             mov dword ptr [esp + 0xc], ebx
// 0056054d  885c2450             mov byte ptr [esp + 0x50], bl
// 00560551  8d500c               lea edx, [eax + 0xc]
// 00560554  83c9ff               or ecx, 0xffffffff
// 00560557  f00fc10a             lock xadd dword ptr [edx], ecx
// 0056055b  49                   dec ecx
// 0056055c  85c9                 test ecx, ecx
// 0056055e  7f0a                 jg 0x56056a
// 00560560  8b08                 mov ecx, dword ptr [eax]
// 00560562  8b11                 mov edx, dword ptr [ecx]
// 00560564  50                   push eax
// 00560565  8b4204               mov eax, dword ptr [edx + 4]
// 00560568  ffd0                 call eax
// 0056056a  8d4c245c             lea ecx, [esp + 0x5c]
// 0056056e  c644245000           mov byte ptr [esp + 0x50], 0
// 00560573  ff1568248000         call dword ptr [0x802468]
// 00560579  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0056057d  8bc6                 mov eax, esi
// 0056057f  5e                   pop esi
// 00560580  5b                   pop ebx
// 00560581  64890d00000000       mov dword ptr fs:[0], ecx
// 00560588  83c44c               add esp, 0x4c
// 0056058b  c3                   ret 

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct String
{
    unsigned int allocator;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;

    __declspec(dllimport) String(const char*);
    __declspec(dllimport) ~String();
    const char* c_str() const;
};

inline const char* String::c_str() const
{
    return capacity >= 16 ? storage.pointer : storage.buffer;
}

struct StringData;

struct StringManager
{
    virtual void unused() = 0;
    virtual void release(StringData*) = 0;
};

struct StringData
{
    StringManager* manager;
    int length;
    int capacity;
    volatile long references;
};

struct LocalString
{
    char* pointer;

    LocalString(const char*);
    ~LocalString();
};

inline LocalString::~LocalString()
{
    StringData* data = reinterpret_cast<StringData*>(pointer) - 1;
    if (_InterlockedDecrement(&data->references) <= 0)
        data->manager->release(data);
}


struct BaseString
{
    unsigned int allocator;
    union { char buffer[16]; char* pointer; } storage;
    unsigned int length;
    unsigned int capacity;
    __declspec(dllimport) ~BaseString();
    const char* c_str() const { return capacity >= 16 ? storage.pointer : storage.buffer; }
};

struct JoinedString
{
    unsigned int allocator;
    union { char buffer[16]; char* pointer; } storage;
    unsigned int length;
    unsigned int capacity;
    __declspec(dllimport) ~JoinedString();
    const char* c_str() const { return capacity >= 16 ? storage.pointer : storage.buffer; }
};
extern BaseString getBase();
extern __declspec(dllimport) JoinedString operator+(const BaseString&, const char*);
extern "C" __declspec(dllimport) int __stdcall PathFileExistsA(const char*);

String func_00560460(String source)
{
    const char* suffix = source.c_str();
    suffix += 11;
    LocalString path((getBase() + suffix).c_str());

    if (!PathFileExistsA(path.pointer))
        return String("");

    return String(path.pointer);
}
