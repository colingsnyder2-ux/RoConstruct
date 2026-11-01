// from server: 100% by colin
// from server: 93% by colin
// roc 2008-06 0061aac0  unit: RBX::Lua::LuaArguments  size: 275 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0061aac0
//
// 0061aac0  6aff                 push -1
// 0061aac2  685a927d00           push 0x7d925a
// 0061aac7  64a100000000         mov eax, dword ptr fs:[0]
// 0061aacd  50                   push eax
// 0061aace  64892500000000       mov dword ptr fs:[0], esp
// 0061aad5  83ec50               sub esp, 0x50
// 0061aad8  8b442468             mov eax, dword ptr [esp + 0x68]
// 0061aadc  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0061aae0  56                   push esi
// 0061aae1  50                   push eax
// 0061aae2  51                   push ecx
// 0061aae3  8d542410             lea edx, [esp + 0x10]
// 0061aae7  52                   push edx
// 0061aae8  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0061aaf0  e8fbf9ffff           call 0x61a4f0
// 0061aaf5  83c40c               add esp, 0xc
// 0061aaf8  8b742408             mov esi, dword ptr [esp + 8]
// 0061aafc  c744245c01000000     mov dword ptr [esp + 0x5c], 1
// 0061ab04  85f6                 test esi, esi
// 0061ab06  7468                 je 0x61ab70
// 0061ab08  6a00                 push 0
// 0061ab0a  687c909200           push 0x92907c
// 0061ab0f  68fc919200           push 0x9291fc
// 0061ab14  6a00                 push 0
// 0061ab16  56                   push esi
// 0061ab17  e8aa6c0800           call 0x6a17c6
// 0061ab1c  83c414               add esp, 0x14
// 0061ab1f  85c0                 test eax, eax
// 0061ab21  7548                 jne 0x61ab6b
// 0061ab23  8b7608               mov esi, dword ptr [esi + 8]
// 0061ab26  8b4604               mov eax, dword ptr [esi + 4]
// 0061ab29  83c004               add eax, 4
// 0061ab2c  83781810             cmp dword ptr [eax + 0x18], 0x10
// 0061ab30  7205                 jb 0x61ab37
// 0061ab32  8b4004               mov eax, dword ptr [eax + 4]
// 0061ab35  eb03                 jmp 0x61ab3a
// 0061ab37  83c004               add eax, 4
// 0061ab3a  50                   push eax
// 0061ab3b  8d442414             lea eax, [esp + 0x14]
// 0061ab3f  687c418400           push 0x84417c
// 0061ab44  50                   push eax
// 0061ab45  e8c6efeeff           call 0x509b10
// 0061ab4a  83c40c               add esp, 0xc
// 0061ab4d  50                   push eax
// 0061ab4e  8d4c2430             lea ecx, [esp + 0x30]
// 0061ab52  c644246002           mov byte ptr [esp + 0x60], 2
// 0061ab57  e8f4f1deff           call 0x409d50
// 0061ab5c  68c81b8d00           push 0x8d1bc8
// 0061ab61  8d4c2430             lea ecx, [esp + 0x30]
// 0061ab65  51                   push ecx
// 0061ab66  e8216a0800           call 0x6a158c
// 0061ab6b  8d46ec               lea eax, [esi - 0x14]
// 0061ab6e  eb02                 jmp 0x61ab72
// 0061ab70  33c0                 xor eax, eax
// 0061ab72  57                   push edi
// 0061ab73  8b7c2468             mov edi, dword ptr [esp + 0x68]
// 0061ab77  50                   push eax
// 0061ab78  57                   push edi
// 0061ab79  e8c2deffff           call 0x618a40
// 0061ab7e  83c408               add esp, 8
// 0061ab81  8b742410             mov esi, dword ptr [esp + 0x10]
// 0061ab85  c744240801000000     mov dword ptr [esp + 8], 1
// 0061ab8d  c644246000           mov byte ptr [esp + 0x60], 0
// 0061ab92  85f6                 test esi, esi
// 0061ab94  742a                 je 0x61abc0
// 0061ab96  8d5604               lea edx, [esi + 4]
// 0061ab99  83c8ff               or eax, 0xffffffff
// 0061ab9c  f00fc102             lock xadd dword ptr [edx], eax
// 0061aba0  751e                 jne 0x61abc0
// 0061aba2  8b16                 mov edx, dword ptr [esi]
// 0061aba4  8b4204               mov eax, dword ptr [edx + 4]
// 0061aba7  8bce                 mov ecx, esi
// 0061aba9  ffd0                 call eax
// 0061abab  8d4e08               lea ecx, [esi + 8]
// 0061abae  83caff               or edx, 0xffffffff
// 0061abb1  f00fc111             lock xadd dword ptr [ecx], edx
// 0061abb5  7509                 jne 0x61abc0
// 0061abb7  8b06                 mov eax, dword ptr [esi]
// 0061abb9  8b5008               mov edx, dword ptr [eax + 8]
// 0061abbc  8bce                 mov ecx, esi
// 0061abbe  ffd2                 call edx
// 0061abc0  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 0061abc4  8bc7                 mov eax, edi
// 0061abc6  5f                   pop edi
// 0061abc7  5e                   pop esi
// 0061abc8  64890d00000000       mov dword ptr fs:[0], ecx
// 0061abcf  83c45c               add esp, 0x5c
// 0061abd2  c3                   ret 
#include <intrin.h>

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Shared {
    char* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct String {
    unsigned long reserved;
    union {
        char local[16];
        char* heap;
    } storage;
    unsigned long length;
    unsigned long capacity;
    ~String();
};

struct Error {
    char data[40];
    Error(const String&);
    Error(const Error&);
    ~Error();
};

struct Result {
    void* object;
    Control* control;
    ~Result();
};

extern Shared __cdecl acquire(void*, int);
extern String __cdecl format(const char*, ...);
extern Result __cdecl assign(void*);
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

Result __cdecl reconstruct(void* source, int index)
{
    Shared value = acquire(source, index);
    char* instance;

    if (value.object) {
        char* p = value.object;
        _ReadWriteBarrier();
        if (!__RTDynamicCast(p, 0, (void*)0x9291fc,
                            (void*)0x92907c, 0)) {
            p = *(char**)(p + 8);
            String* name = (String*)(*(char**)(p + 4) + 4);
            throw Error(format("Object %s is not an Instance",
                               name->capacity >= 16
                                   ? name->storage.heap
                                   : name->storage.local));
        }
        instance = p - 20;
    } else {
        instance = 0;
    }

    return assign(instance);
}
