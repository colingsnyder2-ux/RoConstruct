// from server: 100% by Xemicl
// from server: 100% by king_originala
// roc 2008-06 00557780  unit: RBX::VInstance::?$NonFactoryProduct  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00557780
//
// 00557780  55                   push ebp
// 00557781  8bec                 mov ebp, esp
// 00557783  6aff                 push -1
// 00557785  6879e17c00           push 0x7ce179
// 0055778a  64a100000000         mov eax, dword ptr fs:[0]
// 00557790  50                   push eax
// 00557791  64892500000000       mov dword ptr fs:[0], esp
// 00557798  83ec2c               sub esp, 0x2c
// 0055779b  53                   push ebx
// 0055779c  56                   push esi
// 0055779d  57                   push edi
// 0055779e  8965f0               mov dword ptr [ebp - 0x10], esp
// 005577a1  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005577a8  c645fc01             mov byte ptr [ebp - 4], 1
// 005577ac  85c9                 test ecx, ecx
// 005577ae  7405                 je 0x5577b5
// 005577b0  8d519c               lea edx, [ecx - 0x64]
// 005577b3  eb02                 jmp 0x5577b7
// 005577b5  33d2                 xor edx, edx
// 005577b7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005577ba  83ec10               sub esp, 0x10
// 005577bd  8bc4                 mov eax, esp
// 005577bf  8908                 mov dword ptr [eax], ecx
// 005577c1  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005577c4  894804               mov dword ptr [eax + 4], ecx
// 005577c7  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005577ca  8965ec               mov dword ptr [ebp - 0x14], esp
// 005577cd  85c9                 test ecx, ecx
// 005577cf  740c                 je 0x5577dd
// 005577d1  83c104               add ecx, 4
// 005577d4  be01000000           mov esi, 1
// 005577d9  f00fc131             lock xadd dword ptr [ecx], esi
// 005577dd  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 005577e0  894808               mov dword ptr [eax + 8], ecx
// 005577e3  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 005577e6  89480c               mov dword ptr [eax + 0xc], ecx
// 005577e9  8b4514               mov eax, dword ptr [ebp + 0x14]
// 005577ec  85c0                 test eax, eax
// 005577ee  740c                 je 0x5577fc
// 005577f0  83c004               add eax, 4
// 005577f3  b901000000           mov ecx, 1
// 005577f8  f00fc108             lock xadd dword ptr [eax], ecx
// 005577fc  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 005577ff  8b01                 mov eax, dword ptr [ecx]
// 00557801  52                   push edx
// 00557802  8b10                 mov edx, dword ptr [eax]
// 00557804  ffd2                 call edx
// 00557806  8d4d08               lea ecx, [ebp + 8]
// 00557809  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 00557810  e84bb4ecff           call 0x422c60
// 00557815  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00557818  5f                   pop edi
// 00557819  5e                   pop esi
// 0055781a  64890d00000000       mov dword ptr fs:[0], ecx
// 00557821  5b                   pop ebx
// 00557822  8be5                 mov esp, ebp
// 00557824  5d                   pop ebp
// 00557825  c21400               ret 0x14
// 00557828  8b4de4               mov ecx, dword ptr [ebp - 0x1c]
// 0055782b  8b01                 mov eax, dword ptr [ecx]
// 0055782d  8b5004               mov edx, dword ptr [eax + 4]
// 00557830  ffd2                 call edx
// 00557832  50                   push eax
// 00557833  8d4dc8               lea ecx, [ebp - 0x38]
// 00557836  ff1558248000         call dword ptr [0x802458]
// 0055783c  8d45e8               lea eax, [ebp - 0x18]
// 0055783f  b303                 mov bl, 3
// 00557841  50                   push eax
// 00557842  885dfc               mov byte ptr [ebp - 4], bl
// 00557845  e8d61d0100           call 0x569620
// 0055784a  83c404               add esp, 4
// 0055784d  837de010             cmp dword ptr [ebp - 0x20], 0x10
// 00557851  8b4dcc               mov ecx, dword ptr [ebp - 0x34]
// 00557854  c645fc04             mov byte ptr [ebp - 4], 4
// 00557858  7303                 jae 0x55785d
// 0055785a  8d4dcc               lea ecx, [ebp - 0x34]
// 0055785d  8b00                 mov eax, dword ptr [eax]
// 0055785f  51                   push ecx
// 00557860  68c4b98000           push 0x80b9c4
// 00557865  6a02                 push 2
// 00557867  50                   push eax
// 00557868  e8331b0100           call 0x5693a0
// 0055786d  83c410               add esp, 0x10
// 00557870  8d4de8               lea ecx, [ebp - 0x18]
// 00557873  885dfc               mov byte ptr [ebp - 4], bl
// 00557876  e8e58d0a00           call 0x600660
// 0055787b  8d4dc8               lea ecx, [ebp - 0x38]
// 0055787e  c645fc02             mov byte ptr [ebp - 4], 2
// 00557882  ff1568248000         call dword ptr [0x802468]
// 00557888  b806785500           mov eax, 0x557806
// 0055788d  c3                   ret 

// from server: 100% by colin
// roc 2008-06 00557780  unit: RBX::VInstance::?$NonFactoryProduct  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00557780
//
// 00557780  55                   push ebp
// 00557781  8bec                 mov ebp, esp
// 00557783  6aff                 push -1
// 00557785  6879e17c00           push 0x7ce179
// 0055778a  64a100000000         mov eax, dword ptr fs:[0]
// 00557790  50                   push eax
// 00557791  64892500000000       mov dword ptr fs:[0], esp
// 00557798  83ec2c               sub esp, 0x2c
// 0055779b  53                   push ebx
// 0055779c  56                   push esi
// 0055779d  57                   push edi
// 0055779e  8965f0               mov dword ptr [ebp - 0x10], esp
// 005577a1  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005577a8  c645fc01             mov byte ptr [ebp - 4], 1
// 005577ac  85c9                 test ecx, ecx
// 005577ae  7405                 je 0x5577b5
// 005577b0  8d519c               lea edx, [ecx - 0x64]
// 005577b3  eb02                 jmp 0x5577b7
// 005577b5  33d2                 xor edx, edx
// 005577b7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005577ba  83ec10               sub esp, 0x10
// 005577bd  8bc4                 mov eax, esp
// 005577bf  8908                 mov dword ptr [eax], ecx
// 005577c1  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005577c4  894804               mov dword ptr [eax + 4], ecx
// 005577c7  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005577ca  8965ec               mov dword ptr [ebp - 0x14], esp
// 005577cd  85c9                 test ecx, ecx
// 005577cf  740c                 je 0x5577dd
// 005577d1  83c104               add ecx, 4
// 005577d4  be01000000           mov esi, 1
// 005577d9  f00fc131             lock xadd dword ptr [ecx], esi
// 005577dd  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 005577e0  894808               mov dword ptr [eax + 8], ecx
// 005577e3  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 005577e6  89480c               mov dword ptr [eax + 0xc], ecx
// 005577e9  8b4514               mov eax, dword ptr [ebp + 0x14]
// 005577ec  85c0                 test eax, eax
// 005577ee  740c                 je 0x5577fc
// 005577f0  83c004               add eax, 4
// 005577f3  b901000000           mov ecx, 1
// 005577f8  f00fc108             lock xadd dword ptr [eax], ecx
// 005577fc  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 005577ff  8b01                 mov eax, dword ptr [ecx]
// 00557801  52                   push edx
// 00557802  8b10                 mov edx, dword ptr [eax]
// 00557804  ffd2                 call edx

// from server: 88% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <exception>

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct Control
{
    long reserved;
    volatile long references;
};

struct Shared
{
    void* object;
    Control* control;

    Shared(const Shared& other);
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->references);
}

struct Arguments
{
    Shared first;
    Shared second;
    ~Arguments();
};

struct Callback
{
    virtual void invoke(void* owner, Arguments arguments) = 0;
};

struct StandardOut {
    void print(int, const char *, ...);
};

struct OutHandle {
    StandardOut *pointer;
    void *count;
    ~OutHandle();
    StandardOut *operator->() const { return pointer; }
};

OutHandle __cdecl singleton();

struct S
{
    void f(Arguments arguments, Callback* callback);
};

void S::f(Arguments arguments, Callback* callback)
{
    try
    {
        void* owner = this ? reinterpret_cast<char*>(this) - 304 : 0;
        callback->invoke(owner, arguments);
    }
    catch (std::exception &e)
    {
        std::string message(e.what());
        singleton()->print(2, "Exception caught in onEvent. %s", message.c_str());
    }
}
