// from server: 100% by Xemicl
﻿// from server: 100% by king_originala
// roc 2008-06 005e9800  unit: RBX::PhysicsService  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e9800
//
// 005e9800  55                   push ebp
// 005e9801  8bec                 mov ebp, esp
// 005e9803  6aff                 push -1
// 005e9805  68e1697d00           push 0x7d69e1
// 005e980a  64a100000000         mov eax, dword ptr fs:[0]
// 005e9810  50                   push eax
// 005e9811  64892500000000       mov dword ptr fs:[0], esp
// 005e9818  83ec2c               sub esp, 0x2c
// 005e981b  53                   push ebx
// 005e981c  56                   push esi
// 005e981d  33c0                 xor eax, eax
// 005e981f  57                   push edi
// 005e9820  8965f0               mov dword ptr [ebp - 0x10], esp
// 005e9823  8945fc               mov dword ptr [ebp - 4], eax
// 005e9826  3bc8                 cmp ecx, eax
// 005e9828  7403                 je 0x5e982d
// 005e982a  8d41a0               lea eax, [ecx - 0x60]
// 005e982d  8b7508               mov esi, dword ptr [ebp + 8]
// 005e9830  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005e9833  8b11                 mov edx, dword ptr [ecx]
// 005e9835  56                   push esi
// 005e9836  50                   push eax
// 005e9837  8b02                 mov eax, dword ptr [edx]
// 005e9839  ffd0                 call eax
// 005e983b  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005e983e  5f                   pop edi
// 005e983f  5e                   pop esi
// 005e9840  64890d00000000       mov dword ptr fs:[0], ecx
// 005e9847  5b                   pop ebx
// 005e9848  8be5                 mov esp, ebp
// 005e984a  5d                   pop ebp
// 005e984b  c20800               ret 8
// 005e984e  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 005e9851  8b11                 mov edx, dword ptr [ecx]
// 005e9853  8b4204               mov eax, dword ptr [edx + 4]
// 005e9856  ffd0                 call eax
// 005e9858  50                   push eax
// 005e9859  8d4dc8               lea ecx, [ebp - 0x38]
// 005e985c  ff1558248000         call dword ptr [0x802458]
// 005e9862  8d4de4               lea ecx, [ebp - 0x1c]
// 005e9865  bb02000000           mov ebx, 2
// 005e986a  51                   push ecx
// 005e986b  885dfc               mov byte ptr [ebp - 4], bl
// 005e986e  e8adfdf7ff           call 0x569620
// 005e9873  83c404               add esp, 4
// 005e9876  837de010             cmp dword ptr [ebp - 0x20], 0x10
// 005e987a  8b4dcc               mov ecx, dword ptr [ebp - 0x34]
// 005e987d  c645fc03             mov byte ptr [ebp - 4], 3
// 005e9881  7303                 jae 0x5e9886
// 005e9883  8d4dcc               lea ecx, [ebp - 0x34]
// 005e9886  8b00                 mov eax, dword ptr [eax]
// 005e9888  51                   push ecx
// 005e9889  68c4b98000           push 0x80b9c4
// 005e988e  53                   push ebx
// 005e988f  50                   push eax
// 005e9890  e80bfbf7ff           call 0x5693a0
// 005e9895  83c410               add esp, 0x10
// 005e9898  8d4de4               lea ecx, [ebp - 0x1c]
// 005e989b  885dfc               mov byte ptr [ebp - 4], bl
// 005e989e  e8bd6d0100           call 0x600660
// 005e98a3  8d4dc8               lea ecx, [ebp - 0x38]
// 005e98a6  c645fc01             mov byte ptr [ebp - 4], 1
// 005e98aa  ff1568248000         call dword ptr [0x802468]
// 005e98b0  b83b985e00           mov eax, 0x5e983b
// 005e98b5  c3                   ret 

#include <string>
#include <exception>
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


// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Source;
struct Event { void* value; void* extra; };
struct Listener { virtual void onEvent(const Source*, Event) = 0; };
struct Padding { char bytes[0x150]; };
template <class T, class E> struct Notifier { void raise(E event, Listener* listener) const; int state; };
struct Source : Padding, Notifier<Source, Event> {};
template <class T, class E> void Notifier<T,E>::raise(E event, Listener* listener) const
{
    try {
        listener->onEvent(static_cast<const T*>(this), event);
    }
    catch (std::exception& error) {
        std::string what(error.what());
        singleton()->print(2, "Exception caught in onEvent. %s", what.c_str());
    }
}
template void Notifier<Source,Event>::raise(Event,Listener*) const;
