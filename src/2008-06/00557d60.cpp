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


// from server: 100% by king_originala
// roc 2008-06 00557d60  unit: RBX::VInstance::?$AbstractFactoryProduct  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00557d60
//
// 00557d60  55                   push ebp
// 00557d61  8bec                 mov ebp, esp
// 00557d63  6aff                 push -1
// 00557d65  6831e27c00           push 0x7ce231
// 00557d6a  64a100000000         mov eax, dword ptr fs:[0]
// 00557d70  50                   push eax
// 00557d71  64892500000000       mov dword ptr fs:[0], esp
// 00557d78  83ec2c               sub esp, 0x2c
// 00557d7b  53                   push ebx
// 00557d7c  56                   push esi
// 00557d7d  33d2                 xor edx, edx
// 00557d7f  57                   push edi
// 00557d80  8965f0               mov dword ptr [ebp - 0x10], esp
// 00557d83  8955fc               mov dword ptr [ebp - 4], edx
// 00557d86  3bca                 cmp ecx, edx
// 00557d88  7406                 je 0x557d90
// 00557d8a  8d915cffffff         lea edx, [ecx - 0xa4]
// 00557d90  8b7d08               mov edi, dword ptr [ebp + 8]
// 00557d93  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00557d96  8b31                 mov esi, dword ptr [ecx]
// 00557d98  83ec0c               sub esp, 0xc
// 00557d9b  8bc4                 mov eax, esp
// 00557d9d  8938                 mov dword ptr [eax], edi
// 00557d9f  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 00557da2  897804               mov dword ptr [eax + 4], edi
// 00557da5  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00557da8  897808               mov dword ptr [eax + 8], edi
// 00557dab  8b06                 mov eax, dword ptr [esi]
// 00557dad  52                   push edx
// 00557dae  ffd0                 call eax

struct Value {
    unsigned long x;
    unsigned long y;
    unsigned long z;
};

struct Object;

struct Callback {
    virtual void invoke(Object* object, Value value) = 0;
};

struct S {
    unsigned char member;
    void f(Value value, Callback& callback);
};

struct Padding {
    unsigned char data[164];
};

struct Object : Padding, S {
};

void S::f(Value value, Callback& callback)
{
    try {
        Object* object = static_cast<Object*>(this);
        callback.invoke(object, value);
    }
    catch (std::exception& error) {
        std::string what(error.what());
        singleton()->print(2, "Exception caught in onEvent. %s", what.c_str());
    }
}
