// from server: 100% by king_originala
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


// from server: 100% by Gemini
// roc 2008-06 00554750  unit: RBX::RunService  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00554750
//
// 00554750  55                   push ebp
// 00554751  8bec                 mov ebp, esp
// 00554753  6aff                 push -1
// 00554755  68e1dc7c00           push 0x7cdce1
// 0055475a  64a100000000         mov eax, dword ptr fs:[0]
// 00554760  50                   push eax
// 00554761  64892500000000       mov dword ptr fs:[0], esp
// 00554768  83ec2c               sub esp, 0x2c
// 0055476b  53                   push ebx
// 0055476c  56                   push esi
// 0055476d  33c0                 xor eax, eax
// 0055476f  57                   push edi
// 00554770  8965f0               mov dword ptr [ebp - 0x10], esp
// 00554773  8945fc               mov dword ptr [ebp - 4], eax
// 00554776  3bc8                 cmp ecx, eax
// 00554778  7406                 je 0x554780
// 0055477a  8d8170feffff         lea eax, [ecx - 0x190]
// 00554780  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00554783  8b7508               mov esi, dword ptr [ebp + 8]
// 00554786  8b11                 mov edx, dword ptr [ecx]
// 00554788  56                   push esi
// 00554789  50                   push eax
// 0055478a  8b02                 mov eax, dword ptr [edx]
// 0055478c  ffd0                 call eax

struct Callback {
    virtual void invoke(void *, void *) = 0;
};

struct S {
    void f(void *, Callback *);
};

void S::f(void *a, Callback *callback)
{
    try {
        void *owner = 0;
        if (this)
            owner = reinterpret_cast<char *>(this) - 0x190;
        callback->invoke(owner, a);
    }
    catch (std::exception& error) {
        std::string what(error.what());
        singleton()->print(2, "Exception caught in onEvent. %s", what.c_str());
    }
}
