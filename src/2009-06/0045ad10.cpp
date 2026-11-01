// from server: 100% by EspClaude
// from server: 83% by EspClaude
// roc 2009-06 0045ad10  unit: CRobloxWnd  size: 254 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0045ad10
//
// 0045ad10  6aff                 push -1
// 0045ad12  6846248500           push 0x852446
// 0045ad17  64a100000000         mov eax, dword ptr fs:[0]
// 0045ad1d  50                   push eax
// 0045ad1e  64892500000000       mov dword ptr fs:[0], esp
// 0045ad25  83ec08               sub esp, 8
// 0045ad28  56                   push esi
// 0045ad29  57                   push edi
// 0045ad2a  6a3c                 push 0x3c
// 0045ad2c  8bf1                 mov esi, ecx
// 0045ad2e  e805dd2b00           call 0x718a38
// 0045ad33  83c404               add esp, 4
// 0045ad36  89442408             mov dword ptr [esp + 8], eax
// 0045ad3a  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0045ad42  85c0                 test eax, eax
// 0045ad44  743c                 je 0x45ad82
// 0045ad46  8b8e00010000         mov ecx, dword ptr [esi + 0x100]
// 0045ad4c  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 0045ad52  51                   push ecx
// 0045ad53  83ec08               sub esp, 8
// 0045ad56  8bfc                 mov edi, esp
// 0045ad58  8917                 mov dword ptr [edi], edx
// 0045ad5a  8b96d0000000         mov edx, dword ptr [esi + 0xd0]
// 0045ad60  89642418             mov dword ptr [esp + 0x18], esp
// 0045ad64  895704               mov dword ptr [edi + 4], edx
// 0045ad67  85d2                 test edx, edx
// 0045ad69  740c                 je 0x45ad77
// 0045ad6b  83c204               add edx, 4
// 0045ad6e  b901000000           mov ecx, 1
// 0045ad73  f00fc10a             lock xadd dword ptr [edx], ecx
// 0045ad77  8bc8                 mov ecx, eax
// 0045ad79  e812cf0c00           call 0x527c90
// 0045ad7e  8bf8                 mov edi, eax
// 0045ad80  eb02                 jmp 0x45ad84
// 0045ad82  33ff                 xor edi, edi
// 0045ad84  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 0045ad8a  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0045ad92  3bf9                 cmp edi, ecx
// 0045ad94  740c                 je 0x45ada2
// 0045ad96  85c9                 test ecx, ecx
// 0045ad98  7408                 je 0x45ada2
// 0045ad9a  8b11                 mov edx, dword ptr [ecx]
// 0045ad9c  8b02                 mov eax, dword ptr [edx]
// 0045ad9e  6a01                 push 1
// 0045ada0  ffd0                 call eax
// 0045ada2  6844010000           push 0x144
// 0045ada7  89bef8000000         mov dword ptr [esi + 0xf8], edi
// 0045adad  e886dc2b00           call 0x718a38
// 0045adb2  83c404               add esp, 4
// 0045adb5  8944240c             mov dword ptr [esp + 0xc], eax
// 0045adb9  c744241801000000     mov dword ptr [esp + 0x18], 1
// 0045adc1  85c0                 test eax, eax
// 0045adc3  7412                 je 0x45add7
// 0045adc5  8b8e00010000         mov ecx, dword ptr [esi + 0x100]
// 0045adcb  51                   push ecx
// 0045adcc  8bc8                 mov ecx, eax
// 0045adce  e8fd5f2a00           call 0x700dd0
// 0045add3  8bf8                 mov edi, eax
// 0045add5  eb02                 jmp 0x45add9
// 0045add7  33ff                 xor edi, edi
// 0045add9  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 0045addf  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0045ade7  3bf9                 cmp edi, ecx
// 0045ade9  740c                 je 0x45adf7
// 0045adeb  85c9                 test ecx, ecx
// 0045aded  7408                 je 0x45adf7
// 0045adef  8b11                 mov edx, dword ptr [ecx]
// 0045adf1  8b02                 mov eax, dword ptr [edx]
// 0045adf3  6a01                 push 1
// 0045adf5  ffd0                 call eax
// 0045adf7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0045adfb  89befc000000         mov dword ptr [esi + 0xfc], edi
// 0045ae01  5f                   pop edi
// 0045ae02  64890d00000000       mov dword ptr fs:[0], ecx
// 0045ae09  5e                   pop esi
// 0045ae0a  83c414               add esp, 0x14
// 0045ae0d  c3                   ret 

// from server: 100% by colin
// roc 2008-06 0045b3a0  unit: CRobloxWnd  size: 241 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045b3a0
//
// 0045b3a0  6aff                 push -1
// 0045b3a2  68262b7c00           push 0x7c2b26
// 0045b3a7  64a100000000         mov eax, dword ptr fs:[0]
// 0045b3ad  50                   push eax
// 0045b3ae  64892500000000       mov dword ptr fs:[0], esp
// 0045b3b5  83ec08               sub esp, 8
// 0045b3b8  56                   push esi
// 0045b3b9  57                   push edi
// 0045b3ba  6a4c                 push 0x4c
// 0045b3bc  8bf1                 mov esi, ecx
// 0045b3be  e85d552400           call 0x6a0920
// 0045b3c3  83c404               add esp, 4
// 0045b3c6  89442408             mov dword ptr [esp + 8], eax
// 0045b3ca  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0045b3d2  85c0                 test eax, eax
// 0045b3d4  742f                 je 0x45b405
// 0045b3d6  8b4e70               mov ecx, dword ptr [esi + 0x70]
// 0045b3d9  83ec08               sub esp, 8
// 0045b3dc  8bfc                 mov edi, esp
// 0045b3de  890f                 mov dword ptr [edi], ecx
// 0045b3e0  8b5674               mov edx, dword ptr [esi + 0x74]
// 0045b3e3  89642414             mov dword ptr [esp + 0x14], esp
// 0045b3e7  895704               mov dword ptr [edi + 4], edx
// 0045b3ea  85d2                 test edx, edx
// 0045b3ec  740c                 je 0x45b3fa
// 0045b3ee  83c204               add edx, 4
// 0045b3f1  b901000000           mov ecx, 1
// 0045b3f6  f00fc10a             lock xadd dword ptr [edx], ecx
// 0045b3fa  8bc8                 mov ecx, eax
// 0045b3fc  e88fe50700           call 0x4d9990
// 0045b401  8bf8                 mov edi, eax
// 0045b403  eb02                 jmp 0x45b407
// 0045b405  33ff                 xor edi, edi
// 0045b407  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0045b40d  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0045b415  3bf9                 cmp edi, ecx
// 0045b417  740c                 je 0x45b425
// 0045b419  85c9                 test ecx, ecx
// 0045b41b  7408                 je 0x45b425
// 0045b41d  8b11                 mov edx, dword ptr [ecx]
// 0045b41f  8b02                 mov eax, dword ptr [edx]
// 0045b421  6a01                 push 1
// 0045b423  ffd0                 call eax
// 0045b425  6844010000           push 0x144
// 0045b42a  89beb0000000         mov dword ptr [esi + 0xb0], edi
// 0045b430  e8eb542400           call 0x6a0920
// 0045b435  83c404               add esp, 4
// 0045b438  8944240c             mov dword ptr [esp + 0xc], eax
// 0045b43c  c744241801000000     mov dword ptr [esp + 0x18], 1
// 0045b444  85c0                 test eax, eax
// 0045b446  7412                 je 0x45b45a
// 0045b448  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 0045b44e  51                   push ecx
// 0045b44f  8bc8                 mov ecx, eax
// 0045b451  e8ba8d2100           call 0x674210
// 0045b456  8bf8                 mov edi, eax
// 0045b458  eb02                 jmp 0x45b45c
// 0045b45a  33ff                 xor edi, edi
// 0045b45c  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 0045b462  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0045b46a  3bf9                 cmp edi, ecx
// 0045b46c  740c                 je 0x45b47a
// 0045b46e  85c9                 test ecx, ecx
// 0045b470  7408                 je 0x45b47a
// 0045b472  8b11                 mov edx, dword ptr [ecx]
// 0045b474  8b02                 mov eax, dword ptr [edx]
// 0045b476  6a01                 push 1
// 0045b478  ffd0                 call eax
// 0045b47a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0045b47e  89beb4000000         mov dword ptr [esi + 0xb4], edi
// 0045b484  5f                   pop edi
// 0045b485  64890d00000000       mov dword ptr fs:[0], ecx
// 0045b48c  5e                   pop esi
// 0045b48d  83c414               add esp, 0x14
// 0045b490  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct ControlBlock {
    int reserved;
    volatile long references;
};

struct Shared {
    void* object;
    ControlBlock* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->references);
}

struct First {
    virtual ~First();
    char storage[0x38];

    First(Shared, void*);
};

struct Second {
    virtual ~Second();
    char storage[0x140];

    Second(void*);
};

struct CRobloxWnd {
    char padding0[0xcc];
    Shared shared;
    char padding1[0x24];
    First* first;
    Second* second;
    void* argument;

    void sub_45b3a0();
};

void CRobloxWnd::sub_45b3a0()
{
    First* replacementFirst = new First(shared, argument);
    if (replacementFirst != first && first)
        delete first;
    first = replacementFirst;

    Second* replacementSecond = new Second(argument);
    if (replacementSecond != second && second)
        delete second;
    second = replacementSecond;
}
