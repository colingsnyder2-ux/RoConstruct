// from server: 100% by king_originala
#include <string>
#include <exception>
// from server: 100% by colin
// roc 2008-06 004965a0  unit: RBX::Network::Players::Plugin  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004965a0
//
// 004965a0  55                   push ebp
// 004965a1  8bec                 mov ebp, esp
// 004965a3  6aff                 push -1
// 004965a5  68796b7c00           push 0x7c6b79
// 004965aa  64a100000000         mov eax, dword ptr fs:[0]
// 004965b0  50                   push eax
// 004965b1  64892500000000       mov dword ptr fs:[0], esp
// 004965b8  83ec2c               sub esp, 0x2c
// 004965bb  53                   push ebx
// 004965bc  56                   push esi
// 004965bd  57                   push edi
// 004965be  8965f0               mov dword ptr [ebp - 0x10], esp
// 004965c1  33f6                 xor esi, esi
// 004965c3  8975fc               mov dword ptr [ebp - 4], esi
// 004965c6  c645fc01             mov byte ptr [ebp - 4], 1
// 004965ca  3bce                 cmp ecx, esi
// 004965cc  7406                 je 0x4965d4
// 004965ce  8db1d0feffff         lea esi, [ecx - 0x130]
// 004965d4  83ec48               sub esp, 0x48
// 004965d7  8d4508               lea eax, [ebp + 8]
// 004965da  8bcc                 mov ecx, esp
// 004965dc  8965ec               mov dword ptr [ebp - 0x14], esp
// 004965df  50                   push eax
// 004965e0  e89bfeffff           call 0x496480
// 004965e5  8b4d50               mov ecx, dword ptr [ebp + 0x50]
// 004965e8  8b11                 mov edx, dword ptr [ecx]
// 004965ea  8b02                 mov eax, dword ptr [edx]
// 004965ec  56                   push esi
// 004965ed  ffd0                 call eax

// from server: 84% by colin
// from server: 83% by colin
// roc 2008-06 004965a0  unit: RBX::Network::Players::Plugin  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004965a0
//
// 004965a0  55                   push ebp
// 004965a1  8bec                 mov ebp, esp
// 004965a3  6aff                 push -1
// 004965a5  68796b7c00           push 0x7c6b79
// 004965aa  64a100000000         mov eax, dword ptr fs:[0]
// 004965b0  50                   push eax
// 004965b1  64892500000000       mov dword ptr fs:[0], esp
// 004965b8  83ec2c               sub esp, 0x2c
// 004965bb  53                   push ebx
// 004965bc  56                   push esi
// 004965bd  57                   push edi
// 004965be  8965f0               mov dword ptr [ebp - 0x10], esp
// 004965c1  33f6                 xor esi, esi
// 004965c3  8975fc               mov dword ptr [ebp - 4], esi
// 004965c6  c645fc01             mov byte ptr [ebp - 4], 1
// 004965ca  3bce                 cmp ecx, esi
// 004965cc  7406                 je 0x4965d4
// 004965ce  8db1d0feffff         lea esi, [ecx - 0x130]
// 004965d4  83ec48               sub esp, 0x48
// 004965d7  8d4508               lea eax, [ebp + 8]
// 004965da  8bcc                 mov ecx, esp
// 004965dc  8965ec               mov dword ptr [ebp - 0x14], esp
// 004965df  50                   push eax
// 004965e0  e89bfeffff           call 0x496480
// 004965e5  8b4d50               mov ecx, dword ptr [ebp + 0x50]
// 004965e8  8b11                 mov edx, dword ptr [ecx]
// 004965ea  8b02                 mov eax, dword ptr [edx]
// 004965ec  56                   push esi
// 004965ed  ffd0                 call eax

// from server: 81% by king_originala
// roc 2008-06 004965a0  unit: RBX::Network::Players::Plugin  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004965a0
//
// 004965a0  55                   push ebp
// 004965a1  8bec                 mov ebp, esp
// 004965a3  6aff                 push -1
// 004965a5  68796b7c00           push 0x7c6b79
// 004965aa  64a100000000         mov eax, dword ptr fs:[0]
// 004965b0  50                   push eax
// 004965b1  64892500000000       mov dword ptr fs:[0], esp
// 004965b8  83ec2c               sub esp, 0x2c
// 004965bb  53                   push ebx
// 004965bc  56                   push esi
// 004965bd  57                   push edi
// 004965be  8965f0               mov dword ptr [ebp - 0x10], esp
// 004965c1  33f6                 xor esi, esi
// 004965c3  8975fc               mov dword ptr [ebp - 4], esi
// 004965c6  c645fc01             mov byte ptr [ebp - 4], 1
// 004965ca  3bce                 cmp ecx, esi
// 004965cc  7406                 je 0x4965d4
// 004965ce  8db1d0feffff         lea esi, [ecx - 0x130]
// 004965d4  83ec48               sub esp, 0x48
// 004965d7  8d4508               lea eax, [ebp + 8]
// 004965da  8bcc                 mov ecx, esp
// 004965dc  8965ec               mov dword ptr [ebp - 0x14], esp
// 004965df  50                   push eax
// 004965e0  e89bfeffff           call 0x496480
// 004965e5  8b4d50               mov ecx, dword ptr [ebp + 0x50]
// 004965e8  8b11                 mov edx, dword ptr [ecx]
// 004965ea  8b02                 mov eax, dword ptr [edx]
// 004965ec  56                   push esi
// 004965ed  ffd0                 call eax

struct Message {
    char data[72];
    Message(const Message&);
    ~Message();
};

struct Callback {
    virtual void invoke(void*, Message) = 0;
};

struct Plugin {
    void dispatch(Message, Callback*);
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


void Plugin::dispatch(Message message, Callback* callback)
{
    try {
        void* owner = this ? reinterpret_cast<char*>(this) - 0x130 : 0;
        callback->invoke(owner, message);
    }
    catch (std::exception& error) {
        std::string what(error.what());
        singleton()->print(2, "Exception caught in onEvent. %s", what.c_str());
    }
}


