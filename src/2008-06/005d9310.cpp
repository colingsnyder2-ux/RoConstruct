// from server: 100% by colin
// from server: 91% by king_originala
// roc 2008-06 005d9310  unit: RBX::Humanoid  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d9310
//
// 005d9310  837c240400           cmp dword ptr [esp + 4], 0
// 005d9315  7523                 jne 0x5d933a
// 005d9317  81c1d0feffff         add ecx, 0xfffffed0
// 005d931d  e8eef7ffff           call 0x5d8b10
// 005d9322  85c0                 test eax, eax
// 005d9324  7408                 je 0x5d932e
// 005d9326  8b80c8020000         mov eax, dword ptr [eax + 0x2c8]
// 005d932c  eb02                 jmp 0x5d9330
// 005d932e  33c0                 xor eax, eax
// 005d9330  85c0                 test eax, eax
// 005d9332  7406                 je 0x5d933a
// 005d9334  8b4010               mov eax, dword ptr [eax + 0x10]
// 005d9337  c20400               ret 4
// 005d933a  33c0                 xor eax, eax
// 005d933c  c20400               ret 4
#include <intrin.h>

struct Link {
    char padding[0x10];
    int value;
};

struct Object {
    char padding[0x2C8];
    Link* link;
};

struct Owner {
    Object* getObject();
};

struct S {
    int f(int argument);
};

int S::f(int argument)
{
    if (argument == 0) {
        Object* object = reinterpret_cast<Owner*>(
            reinterpret_cast<char*>(this) - 0x130)->getObject();
        Link* link = object ? object->link : 0;
        _ReadWriteBarrier();
        if (link)
            return link->value;
    }
    return 0;
}
