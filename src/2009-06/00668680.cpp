// from server: 81% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005d9c30  unit: RBX::Humanoid  size: 222 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d9c30
//
// 005d9c30  83ec0c               sub esp, 0xc
// 005d9c33  53                   push ebx
// 005d9c34  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005d9c38  57                   push edi
// 005d9c39  8bf9                 mov edi, ecx
// 005d9c3b  837f7c02             cmp dword ptr [edi + 0x7c], 2
// 005d9c3f  0f85b1000000         jne 0x5d9cf6
// 005d9c45  56                   push esi
// 005d9c46  8db7c4feffff         lea esi, [edi - 0x13c]
// 005d9c4c  56                   push esi
// 005d9c4d  e84e10ecff           call 0x49aca0
// 005d9c52  83c404               add esp, 4
// 005d9c55  85c0                 test eax, eax
// 005d9c57  7424                 je 0x5d9c7d
// 005d9c59  6a00                 push 0
// 005d9c5b  68402a9300           push 0x932a40
// 005d9c60  687c909200           push 0x92907c
// 005d9c65  6a00                 push 0
// 005d9c67  50                   push eax
// 005d9c68  e8597b0c00           call 0x6a17c6
// 005d9c6d  83c414               add esp, 0x14
// 005d9c70  85c0                 test eax, eax
// 005d9c72  7409                 je 0x5d9c7d
// 005d9c74  8bc8                 mov ecx, eax
// 005d9c76  e815eaffff           call 0x5d8690
// 005d9c7b  eb02                 jmp 0x5d9c7f
// 005d9c7d  33c0                 xor eax, eax
// 005d9c7f  8d8fc4feffff         lea ecx, [edi - 0x13c]
// 005d9c85  3bc8                 cmp ecx, eax
// 005d9c87  756c                 jne 0x5d9cf5
// 005d9c89  56                   push esi
// 005d9c8a  e8f196fcff           call 0x5a3380
// 005d9c8f  83c404               add esp, 4
// 005d9c92  85c0                 test eax, eax
// 005d9c94  745f                 je 0x5d9cf5
// 005d9c96  d9ee                 fldz 
// 005d9c98  8d54240c             lea edx, [esp + 0xc]
// 005d9c9c  d954240c             fst dword ptr [esp + 0xc]
// 005d9ca0  52                   push edx
// 005d9ca1  d9542414             fst dword ptr [esp + 0x14]
// 005d9ca5  8bce                 mov ecx, esi
// 005d9ca7  d95c2418             fstp dword ptr [esp + 0x18]
// 005d9cab  e800ddffff           call 0x5d79b0
// 005d9cb0  84c0                 test al, al
// 005d9cb2  7428                 je 0x5d9cdc
// 005d9cb4  8bce                 mov ecx, esi
// 005d9cb6  e855edffff           call 0x5d8a10
// 005d9cbb  85c0                 test eax, eax
// 005d9cbd  741d                 je 0x5d9cdc
// 005d9cbf  d9ee                 fldz 
// 005d9cc1  d89828030000         fcomp dword ptr [eax + 0x328]
// 005d9cc7  dfe0                 fnstsw ax
// 005d9cc9  f6c444               test ah, 0x44
// 005d9ccc  7b0e                 jnp 0x5d9cdc
// 005d9cce  8d44240c             lea eax, [esp + 0xc]
// 005d9cd2  50                   push eax
// 005d9cd3  53                   push ebx
// 005d9cd4  e877daffff           call 0x5d7750
// 005d9cd9  83c408               add esp, 8
// 005d9cdc  56                   push esi
// 005d9cdd  e88ed9ffff           call 0x5d7670
// 005d9ce2  83c404               add esp, 4
// 005d9ce5  85c0                 test eax, eax
// 005d9ce7  740c                 je 0x5d9cf5
// 005d9ce9  6800c64500           push 0x45c600
// 005d9cee  8bc8                 mov ecx, eax
// 005d9cf0  e87b27e8ff           call 0x45c470
// 005d9cf5  5e                   pop esi
// 005d9cf6  8b8fe4000000         mov ecx, dword ptr [edi + 0xe4]
// 005d9cfc  85c9                 test ecx, ecx
// 005d9cfe  7406                 je 0x5d9d06
// 005d9d00  53                   push ebx
// 005d9d01  e85ab30600           call 0x645060
// 005d9d06  5f                   pop edi
// 005d9d07  5b                   pop ebx
// 005d9d08  83c40c               add esp, 0xc
// 005d9d0b  c20400               ret 4

struct Vector {
    float x, y, z;
};

struct Body {
    char padding[0x328];
    float value;
};

struct Base {
    bool query(Vector*);
    Body* getBody();
};

struct Model {
    Base* getBase();
};

struct Receiver {
    void setCallback(void (__cdecl*)());
};

struct Delegate {
    void update(void*);
};

struct S {
    char padding0[0x7c];
    int state;
    char padding1[0x64];
    Delegate* delegate;

    void update(void*);
};

extern char instanceType;
extern char modelType;
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern void* __cdecl getInstance(Base*);
extern int __cdecl checkBase(Base*);
extern void __cdecl applyVector(void*, Vector*);
extern void* __cdecl getReceiver(Base*);
extern void __cdecl callback();

void S::update(void* argument)
{
    if (state == 2) {
        Base* base = reinterpret_cast<Base*>(
            reinterpret_cast<char*>(this) - 0x13c);
        void* instance = getInstance(base);
        Base* owner;

        if (instance) {
            Model* model = static_cast<Model*>(
                __RTDynamicCast(instance, 0, &instanceType, &modelType, 0));
            if (model)
                owner = model->getBase();
            else
                owner = 0;
        } else {
            owner = 0;
        }

        if (reinterpret_cast<Base*>(
                reinterpret_cast<char*>(this) - 0x13c) == owner &&
            checkBase(base)) {
            Vector vector;
            vector.x = 0.0f;
            vector.y = 0.0f;
            vector.z = 0.0f;

            if (base->query(&vector)) {
                Body* body = base->getBody();
                if (body && body->value != 0.0f)
                    applyVector(argument, &vector);
            }

            Receiver* receiver = static_cast<Receiver*>(getReceiver(base));
            if (receiver)
                receiver->setCallback(callback);
        }
    }

    if (delegate)
        delegate->update(argument);
}
