// from server: 100% by colin
// from server: 99% by king_originala
// roc 2008-06 00444cf0  unit: 1RBX::Metadata::VReflection::?$FactoryProduct  size: 213 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00444cf0
//
// 00444cf0  64a100000000         mov eax, dword ptr fs:[0]
// 00444cf6  6aff                 push -1
// 00444cf8  6868917d00           push 0x7d9168
// 00444cfd  50                   push eax
// 00444cfe  64892500000000       mov dword ptr fs:[0], esp
// 00444d05  83ec08               sub esp, 8
// 00444d08  56                   push esi
// 00444d09  57                   push edi
// 00444d0a  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00444d0e  8b4704               mov eax, dword ptr [edi + 4]
// 00444d11  83c004               add eax, 4
// 00444d14  50                   push eax
// 00444d15  8bf1                 mov esi, ecx
// 00444d17  e8342c1100           call 0x557950
// 00444d1c  85c0                 test eax, eax
// 00444d1e  741a                 je 0x444d3a
// 00444d20  5f                   pop edi
// 00444d21  c6803001000000       mov byte ptr [eax + 0x130], 0
// 00444d28  5e                   pop esi
// 00444d29  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00444d2d  64890d00000000       mov dword ptr fs:[0], ecx
// 00444d34  83c414               add esp, 0x14
// 00444d37  c20400               ret 4
// 00444d3a  8d442408             lea eax, [esp + 8]
// 00444d3e  50                   push eax
// 00444d3f  e82c8ffcff           call 0x40dc70
// 00444d44  83c404               add esp, 4
// 00444d47  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00444d4b  8b4704               mov eax, dword ptr [edi + 4]
// 00444d4e  8b11                 mov edx, dword ptr [ecx]
// 00444d50  8b5204               mov edx, dword ptr [edx + 4]
// 00444d53  83c004               add eax, 4
// 00444d56  50                   push eax
// 00444d57  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00444d5f  ffd2                 call edx
// 00444d61  8b442408             mov eax, dword ptr [esp + 8]
// 00444d65  c6803001000000       mov byte ptr [eax + 0x130], 0
// 00444d6c  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00444d70  56                   push esi
// 00444d71  e87a5b1100           call 0x55a8f0
// 00444d76  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00444d7a  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00444d82  85c0                 test eax, eax
// 00444d84  742c                 je 0x444db2
// 00444d86  8bf0                 mov esi, eax
// 00444d88  83c004               add eax, 4
// 00444d8b  83c9ff               or ecx, 0xffffffff
// 00444d8e  f00fc108             lock xadd dword ptr [eax], ecx
// 00444d92  751e                 jne 0x444db2
// 00444d94  8b16                 mov edx, dword ptr [esi]
// 00444d96  8b4204               mov eax, dword ptr [edx + 4]
// 00444d99  8bce                 mov ecx, esi
// 00444d9b  ffd0                 call eax
// 00444d9d  8d4e08               lea ecx, [esi + 8]
// 00444da0  83caff               or edx, 0xffffffff
// 00444da3  f00fc111             lock xadd dword ptr [ecx], edx
// 00444da7  7509                 jne 0x444db2
// 00444da9  8b06                 mov eax, dword ptr [esi]
// 00444dab  8b5008               mov edx, dword ptr [eax + 8]
// 00444dae  8bce                 mov ecx, esi
// 00444db0  ffd2                 call edx
// 00444db2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00444db6  5f                   pop edi
// 00444db7  5e                   pop esi
// 00444db8  64890d00000000       mov dword ptr fs:[0], ecx
// 00444dbf  83c414               add esp, 0x14
// 00444dc2  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct S;

struct Object {
    virtual void slot0();
    virtual void setName(const void*);
    char padding[0x12C];
    unsigned char flag;
    void attach(S*);
};

struct Control {
    virtual void slot0();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

struct Handle {
    Object* object;
    Control* control;
    ~Handle();
    void release() {
        if (control) control->release();
    }
};

struct Argument {
    void* unused;
    char* name;
};

struct S {
    Object* lookup(const void*);
    void f(Argument*);
};

Handle __cdecl create();

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

inline Handle::~Handle()
{
    if (control)
        control->release();
}

void S::f(Argument* argument)
{
    Object* object;
    {
        const char* key = argument->name + 4;
        object = lookup(key);
    }
    if (object) {
        object->flag = 0;
        return;
    }

    Handle handle = create();
    handle.object->setName(argument->name + 4);
    handle.object->flag = 0;
    handle.object->attach(this);
}
