// from server: 100% by user
// from server: 99% by colin
// roc 2008-06 0066d0d0  unit: RBX::GroupDragTool  size: 387 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066d0d0
//
// 0066d0d0  6aff                 push -1
// 0066d0d2  6878c57d00           push 0x7dc578
// 0066d0d7  64a100000000         mov eax, dword ptr fs:[0]
// 0066d0dd  50                   push eax
// 0066d0de  64892500000000       mov dword ptr fs:[0], esp
// 0066d0e5  83ec34               sub esp, 0x34
// 0066d0e8  56                   push esi
// 0066d0e9  57                   push edi
// 0066d0ea  8bf1                 mov esi, ecx
// 0066d0ec  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0066d0f4  c744242006000000     mov dword ptr [esp + 0x20], 6
// 0066d0fc  e85f38eaff           call 0x510960
// 0066d101  d900                 fld dword ptr [eax]
// 0066d103  d95c2424             fstp dword ptr [esp + 0x24]
// 0066d107  d94004               fld dword ptr [eax + 4]
// 0066d10a  d95c2428             fstp dword ptr [esp + 0x28]
// 0066d10e  d94008               fld dword ptr [eax + 8]
// 0066d111  d95c242c             fstp dword ptr [esp + 0x2c]
// 0066d115  e84638eaff           call 0x510960
// 0066d11a  d900                 fld dword ptr [eax]
// 0066d11c  8d4c2408             lea ecx, [esp + 8]
// 0066d120  d95c2430             fstp dword ptr [esp + 0x30]
// 0066d124  d94004               fld dword ptr [eax + 4]
// 0066d127  d95c2434             fstp dword ptr [esp + 0x34]
// 0066d12b  d94008               fld dword ptr [eax + 8]
// 0066d12e  8b4610               mov eax, dword ptr [esi + 0x10]
// 0066d131  50                   push eax
// 0066d132  d95c243c             fstp dword ptr [esp + 0x3c]
// 0066d136  e84532ffff           call 0x660380
// 0066d13b  d905d8398400         fld dword ptr [0x8439d8]
// 0066d141  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0066d144  8b81e4020000         mov eax, dword ptr [ecx + 0x2e4]
// 0066d14a  8b8084000000         mov eax, dword ptr [eax + 0x84]
// 0066d150  51                   push ecx
// 0066d151  d91c24               fstp dword ptr [esp]
// 0066d154  8d542428             lea edx, [esp + 0x28]
// 0066d158  52                   push edx
// 0066d159  8b5614               mov edx, dword ptr [esi + 0x14]
// 0066d15c  8d4c2410             lea ecx, [esp + 0x10]
// 0066d160  51                   push ecx
// 0066d161  52                   push edx
// 0066d162  50                   push eax
// 0066d163  8d4644               lea eax, [esi + 0x44]
// 0066d166  50                   push eax
// 0066d167  c744245c00000000     mov dword ptr [esp + 0x5c], 0
// 0066d16f  e83c8ffaff           call 0x6160b0
// 0066d174  83c418               add esp, 0x18
// 0066d177  85c0                 test eax, eax
// 0066d179  7475                 je 0x66d1f0
// 0066d17b  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0066d17f  8db828020000         lea edi, [eax + 0x228]
// 0066d185  51                   push ecx
// 0066d186  57                   push edi
// 0066d187  8bce                 mov ecx, esi
// 0066d189  897c2424             mov dword ptr [esp + 0x24], edi
// 0066d18d  e8defaffff           call 0x66cc70
// 0066d192  84c0                 test al, al
// 0066d194  745a                 je 0x66d1f0
// 0066d196  807c245400           cmp byte ptr [esp + 0x54], 0
// 0066d19b  7410                 je 0x66d1ad
// 0066d19d  8b5614               mov edx, dword ptr [esi + 0x14]
// 0066d1a0  52                   push edx
// 0066d1a1  57                   push edi
// 0066d1a2  8bce                 mov ecx, esi
// 0066d1a4  e817f3ffff           call 0x66c4c0
// 0066d1a9  84c0                 test al, al
// 0066d1ab  7443                 je 0x66d1f0
// 0066d1ad  8d4c241c             lea ecx, [esp + 0x1c]
// 0066d1b1  e87af1ffff           call 0x66c330
// 0066d1b6  d9442424             fld dword ptr [esp + 0x24]
// 0066d1ba  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 0066d1be  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0066d1c2  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0066d1c6  8906                 mov dword ptr [esi], eax
// 0066d1c8  894e04               mov dword ptr [esi + 4], ecx
// 0066d1cb  d95e08               fstp dword ptr [esi + 8]
// 0066d1ce  d9442428             fld dword ptr [esp + 0x28]
// 0066d1d2  d95e0c               fstp dword ptr [esi + 0xc]
// 0066d1d5  d944242c             fld dword ptr [esp + 0x2c]
// 0066d1d9  d95e10               fstp dword ptr [esi + 0x10]
// 0066d1dc  d9442430             fld dword ptr [esp + 0x30]
// 0066d1e0  d95e14               fstp dword ptr [esi + 0x14]
// 0066d1e3  d9442434             fld dword ptr [esp + 0x34]
// 0066d1e7  d95e18               fstp dword ptr [esi + 0x18]
// 0066d1ea  d9442438             fld dword ptr [esp + 0x38]
// 0066d1ee  eb3a                 jmp 0x66d22a
// 0066d1f0  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 0066d1f4  c70600000000         mov dword ptr [esi], 0
// 0066d1fa  c7460406000000       mov dword ptr [esi + 4], 6
// 0066d201  e85a37eaff           call 0x510960
// 0066d206  d900                 fld dword ptr [eax]
// 0066d208  d95e08               fstp dword ptr [esi + 8]
// 0066d20b  d94004               fld dword ptr [eax + 4]
// 0066d20e  d95e0c               fstp dword ptr [esi + 0xc]
// 0066d211  d94008               fld dword ptr [eax + 8]
// 0066d214  d95e10               fstp dword ptr [esi + 0x10]
// 0066d217  e84437eaff           call 0x510960
// 0066d21c  d900                 fld dword ptr [eax]
// 0066d21e  d95e14               fstp dword ptr [esi + 0x14]
// 0066d221  d94004               fld dword ptr [eax + 4]
// 0066d224  d95e18               fstp dword ptr [esi + 0x18]
// 0066d227  d94008               fld dword ptr [eax + 8]
// 0066d22a  8d4c2408             lea ecx, [esp + 8]
// 0066d22e  d95e1c               fstp dword ptr [esi + 0x1c]
// 0066d231  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 0066d239  e84289faff           call 0x615b80
// 0066d23e  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0066d242  5f                   pop edi
// 0066d243  8bc6                 mov eax, esi
// 0066d245  5e                   pop esi
// 0066d246  64890d00000000       mov dword ptr fs:[0], ecx
// 0066d24d  83c440               add esp, 0x40
// 0066d250  c20c00               ret 0xc

// from server: 93% by king_originala
// roc 2008-06 0066d0d0  unit: RBX::GroupDragTool  size: 387 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066d0d0
//
// 0066d0d0  6aff                 push -1
// 0066d0d2  6878c57d00           push 0x7dc578
// 0066d0d7  64a100000000         mov eax, dword ptr fs:[0]
// 0066d0dd  50                   push eax
// 0066d0de  64892500000000       mov dword ptr fs:[0], esp
// 0066d0e5  83ec34               sub esp, 0x34
// 0066d0e8  56                   push esi
// 0066d0e9  57                   push edi
// 0066d0ea  8bf1                 mov esi, ecx
// 0066d0ec  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0066d0f4  c744242006000000     mov dword ptr [esp + 0x20], 6
// 0066d0fc  e85f38eaff           call 0x510960
// 0066d101  d900                 fld dword ptr [eax]
// 0066d103  d95c2424             fstp dword ptr [esp + 0x24]
// 0066d107  d94004               fld dword ptr [eax + 4]
// 0066d10a  d95c2428             fstp dword ptr [esp + 0x28]
// 0066d10e  d94008               fld dword ptr [eax + 8]
// 0066d111  d95c242c             fstp dword ptr [esp + 0x2c]
// 0066d115  e84638eaff           call 0x510960
// 0066d11a  d900                 fld dword ptr [eax]
// 0066d11c  8d4c2408             lea ecx, [esp + 8]
// 0066d120  d95c2430             fstp dword ptr [esp + 0x30]
// 0066d124  d94004               fld dword ptr [eax + 4]
// 0066d127  d95c2434             fstp dword ptr [esp + 0x34]
// 0066d12b  d94008               fld dword ptr [eax + 8]
// 0066d12e  8b4610               mov eax, dword ptr [esi + 0x10]
// 0066d131  50                   push eax
// 0066d132  d95c243c             fstp dword ptr [esp + 0x3c]
// 0066d136  e84532ffff           call 0x660380
// 0066d13b  d905d8398400         fld dword ptr [0x8439d8]
// 0066d141  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0066d144  8b81e4020000         mov eax, dword ptr [ecx + 0x2e4]
// 0066d14a  8b8084000000         mov eax, dword ptr [eax + 0x84]
// 0066d150  51                   push ecx
// 0066d151  d91c24               fstp dword ptr [esp]
// 0066d154  8d542428             lea edx, [esp + 0x28]
// 0066d158  52                   push edx
// 0066d159  8b5614               mov edx, dword ptr [esi + 0x14]
// 0066d15c  8d4c2410             lea ecx, [esp + 0x10]
// 0066d160  51                   push ecx
// 0066d161  52                   push edx
// 0066d162  50                   push eax
// 0066d163  8d4644               lea eax, [esi + 0x44]
// 0066d166  50                   push eax
// 0066d167  c744245c00000000     mov dword ptr [esp + 0x5c], 0
// 0066d16f  e83c8ffaff           call 0x6160b0
// 0066d174  83c418               add esp, 0x18
// 0066d177  85c0                 test eax, eax
// 0066d179  7475                 je 0x66d1f0
// 0066d17b  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0066d17f  8db828020000         lea edi, [eax + 0x228]
// 0066d185  51                   push ecx
// 0066d186  57                   push edi
// 0066d187  8bce                 mov ecx, esi
// 0066d189  897c2424             mov dword ptr [esp + 0x24], edi
// 0066d18d  e8defaffff           call 0x66cc70
// 0066d192  84c0                 test al, al
// 0066d194  745a                 je 0x66d1f0
// 0066d196  807c245400           cmp byte ptr [esp + 0x54], 0
// 0066d19b  7410                 je 0x66d1ad
// 0066d19d  8b5614               mov edx, dword ptr [esi + 0x14]
// 0066d1a0  52                   push edx
// 0066d1a1  57                   push edi
// 0066d1a2  8bce                 mov ecx, esi
// 0066d1a4  e817f3ffff           call 0x66c4c0
// 0066d1a9  84c0                 test al, al
// 0066d1ab  7443                 je 0x66d1f0
// 0066d1ad  8d4c241c             lea ecx, [esp + 0x1c]
// 0066d1b1  e87af1ffff           call 0x66c330
// 0066d1b6  d9442424             fld dword ptr [esp + 0x24]
// 0066d1ba  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 0066d1be  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0066d1c2  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0066d1c6  8906                 mov dword ptr [esi], eax
// 0066d1c8  894e04               mov dword ptr [esi + 4], ecx
// 0066d1cb  d95e08               fstp dword ptr [esi + 8]
// 0066d1ce  d9442428             fld dword ptr [esp + 0x28]
// 0066d1d2  d95e0c               fstp dword ptr [esi + 0xc]
// 0066d1d5  d944242c             fld dword ptr [esp + 0x2c]
// 0066d1d9  d95e10               fstp dword ptr [esi + 0x10]
// 0066d1dc  d9442430             fld dword ptr [esp + 0x30]
// 0066d1e0  d95e14               fstp dword ptr [esi + 0x14]
// 0066d1e3  d9442434             fld dword ptr [esp + 0x34]
// 0066d1e7  d95e18               fstp dword ptr [esi + 0x18]
// 0066d1ea  d9442438             fld dword ptr [esp + 0x38]
// 0066d1ee  eb3a                 jmp 0x66d22a
// 0066d1f0  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 0066d1f4  c70600000000         mov dword ptr [esi], 0
// 0066d1fa  c7460406000000       mov dword ptr [esi + 4], 6
// 0066d201  e85a37eaff           call 0x510960
// 0066d206  d900                 fld dword ptr [eax]
// 0066d208  d95e08               fstp dword ptr [esi + 8]
// 0066d20b  d94004               fld dword ptr [eax + 4]
// 0066d20e  d95e0c               fstp dword ptr [esi + 0xc]
// 0066d211  d94008               fld dword ptr [eax + 8]
// 0066d214  d95e10               fstp dword ptr [esi + 0x10]
// 0066d217  e84437eaff           call 0x510960
// 0066d21c  d900                 fld dword ptr [eax]
// 0066d21e  d95e14               fstp dword ptr [esi + 0x14]
// 0066d221  d94004               fld dword ptr [eax + 4]
// 0066d224  d95e18               fstp dword ptr [esi + 0x18]
// 0066d227  d94008               fld dword ptr [eax + 8]
// 0066d22a  8d4c2408             lea ecx, [esp + 8]
// 0066d22e  d95e1c               fstp dword ptr [esi + 0x1c]
// 0066d231  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 0066d239  e84289faff           call 0x615b80
// 0066d23e  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0066d242  5f                   pop edi
// 0066d243  8bc6                 mov eax, esi
// 0066d245  5e                   pop esi
// 0066d246  64890d00000000       mov dword ptr fs:[0], ecx
// 0066d24d  83c440               add esp, 0x40
// 0066d250  c20c00               ret 0xc

struct Vec {
    float x, y, z;

    Vec(const Vec& v) : x(v.x), y(v.y), z(v.z) {}
};

extern const Vec& __cdecl zeroVector();
extern float tolerance;

struct Item {};

struct Result {
    Item* item;
    int kind;
    Vec position;
    Vec direction;

    Result() : item(0), kind(6), position(zeroVector()),
               direction(zeroVector()) {}

    void prepare();
};

struct Holder {
    char padding[0x84];
    void* value;
};

struct Context {
    char padding[0x2e4];
    Holder* holder;
};

struct Temporary {
    char storage[20];

    Temporary(Context*);
    ~Temporary();
};

struct Hit {
    char padding[0x228];
    Item item;
};

extern Hit* __cdecl findHit(
    void*, void*, void*, Temporary*, Vec*, float);

struct S {
    char padding0[0x10];
    Context* context;
    void* target;
    char padding1[0x2c];
    char data[1];

    bool accepts(Item*, int);
    bool validates(Item*, void*);
    Result run(int, bool);
};

Result S::run(int value, bool check)
{
    Result result;
    Temporary temporary(context);
    Holder* holder = context->holder;
    void* world = holder->value;
    Hit* hit = findHit(data, world, target,
                       &temporary, &result.position, tolerance);
    if (hit) {
        Item* item = &hit->item;
        result.item = item;
        if (accepts(item, value)) {
            if (!check || validates(item, target)) {
                result.prepare();
                return result;
            }
        }
    }
    return Result();
}
