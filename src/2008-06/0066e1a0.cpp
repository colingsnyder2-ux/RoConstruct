// from server: 100% by colin
// from server: 98% by king_originala
// roc 2008-06 0066e1a0  unit: RBX::GroupDragTool  size: 397 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066e1a0
//
// 0066e1a0  6aff                 push -1
// 0066e1a2  683bc67d00           push 0x7dc63b
// 0066e1a7  64a100000000         mov eax, dword ptr fs:[0]
// 0066e1ad  50                   push eax
// 0066e1ae  64892500000000       mov dword ptr fs:[0], esp
// 0066e1b5  81ec90000000         sub esp, 0x90
// 0066e1bb  53                   push ebx
// 0066e1bc  33db                 xor ebx, ebx
// 0066e1be  56                   push esi
// 0066e1bf  8bf1                 mov esi, ecx
// 0066e1c1  895c240c             mov dword ptr [esp + 0xc], ebx
// 0066e1c5  895c2410             mov dword ptr [esp + 0x10], ebx
// 0066e1c9  895c2408             mov dword ptr [esp + 8], ebx
// 0066e1cd  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0066e1d0  899c24a0000000       mov dword ptr [esp + 0xa0], ebx
// 0066e1d7  3bcb                 cmp ecx, ebx
// 0066e1d9  0f8415010000         je 0x66e2f4
// 0066e1df  55                   push ebp
// 0066e1e0  8bac24ac000000       mov ebp, dword ptr [esp + 0xac]
// 0066e1e7  57                   push edi
// 0066e1e8  8d7e28               lea edi, [esi + 0x28]
// 0066e1eb  eb03                 jmp 0x66e1f0
// 0066e1ed  8d4900               lea ecx, [ecx]
// 0066e1f0  8b07                 mov eax, dword ptr [edi]
// 0066e1f2  50                   push eax
// 0066e1f3  8d542424             lea edx, [esp + 0x24]
// 0066e1f7  52                   push edx
// 0066e1f8  e8b39ff7ff           call 0x5e81b0
// 0066e1fd  8b4660               mov eax, dword ptr [esi + 0x60]
// 0066e200  50                   push eax
// 0066e201  8d4c2454             lea ecx, [esp + 0x54]
// 0066e205  51                   push ecx
// 0066e206  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0066e209  e8a29ff7ff           call 0x5e81b0
// 0066e20e  d90560378400         fld dword ptr [0x843760]
// 0066e214  51                   push ecx
// 0066e215  8d542454             lea edx, [esp + 0x54]
// 0066e219  d91c24               fstp dword ptr [esp]
// 0066e21c  52                   push edx
// 0066e21d  8d442428             lea eax, [esp + 0x28]
// 0066e221  50                   push eax
// 0066e222  e869bcfdff           call 0x649e90
// 0066e227  83c40c               add esp, 0xc
// 0066e22a  84c0                 test al, al
// 0066e22c  0f85c0000000         jne 0x66e2f2
// 0066e232  8b442414             mov eax, dword ptr [esp + 0x14]
// 0066e236  3b442418             cmp eax, dword ptr [esp + 0x18]
// 0066e23a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0066e23e  7d16                 jge 0x66e256
// 0066e240  8d0c81               lea ecx, [ecx + eax*4]
// 0066e243  3bcb                 cmp ecx, ebx
// 0066e245  7408                 je 0x66e24f
// 0066e247  8b17                 mov edx, dword ptr [edi]
// 0066e249  8911                 mov dword ptr [ecx], edx
// 0066e24b  8b442414             mov eax, dword ptr [esp + 0x14]
// 0066e24f  40                   inc eax
// 0066e250  89442414             mov dword ptr [esp + 0x14], eax
// 0066e254  eb3b                 jmp 0x66e291
// 0066e256  3bf9                 cmp edi, ecx
// 0066e258  721d                 jb 0x66e277
// 0066e25a  8d0c81               lea ecx, [ecx + eax*4]
// 0066e25d  3bf9                 cmp edi, ecx
// 0066e25f  7316                 jae 0x66e277
// 0066e261  8b17                 mov edx, dword ptr [edi]
// 0066e263  8d44241c             lea eax, [esp + 0x1c]
// 0066e267  50                   push eax
// 0066e268  8d4c2414             lea ecx, [esp + 0x14]
// 0066e26c  89542420             mov dword ptr [esp + 0x20], edx
// 0066e270  e84bf1ffff           call 0x66d3c0
// 0066e275  eb1a                 jmp 0x66e291
// 0066e277  53                   push ebx
// 0066e278  40                   inc eax
// 0066e279  50                   push eax
// 0066e27a  8d4c2418             lea ecx, [esp + 0x18]
// 0066e27e  e84dedffff           call 0x66cfd0
// 0066e283  8b0f                 mov ecx, dword ptr [edi]
// 0066e285  8b542414             mov edx, dword ptr [esp + 0x14]
// 0066e289  8b442410             mov eax, dword ptr [esp + 0x10]
// 0066e28d  894c90fc             mov dword ptr [eax + edx*4 - 4], ecx
// 0066e291  8b5624               mov edx, dword ptr [esi + 0x24]
// 0066e294  8d4c2410             lea ecx, [esp + 0x10]
// 0066e298  51                   push ecx
// 0066e299  52                   push edx
// 0066e29a  8d842488000000       lea eax, [esp + 0x88]
// 0066e2a1  50                   push eax
// 0066e2a2  8bce                 mov ecx, esi
// 0066e2a4  e8c7e6ffff           call 0x66c970
// 0066e2a9  8b08                 mov ecx, dword ptr [eax]
// 0066e2ab  894e24               mov dword ptr [esi + 0x24], ecx
// 0066e2ae  8b5004               mov edx, dword ptr [eax + 4]
// 0066e2b1  895628               mov dword ptr [esi + 0x28], edx
// 0066e2b4  d94008               fld dword ptr [eax + 8]
// 0066e2b7  d95e2c               fstp dword ptr [esi + 0x2c]
// 0066e2ba  d9400c               fld dword ptr [eax + 0xc]
// 0066e2bd  d95e30               fstp dword ptr [esi + 0x30]
// 0066e2c0  d94010               fld dword ptr [eax + 0x10]
// 0066e2c3  d95e34               fstp dword ptr [esi + 0x34]
// 0066e2c6  d94014               fld dword ptr [eax + 0x14]
// 0066e2c9  d95e38               fstp dword ptr [esi + 0x38]
// 0066e2cc  d94018               fld dword ptr [eax + 0x18]
// 0066e2cf  d95e3c               fstp dword ptr [esi + 0x3c]
// 0066e2d2  d9401c               fld dword ptr [eax + 0x1c]
// 0066e2d5  d95e40               fstp dword ptr [esi + 0x40]
// 0066e2d8  395e24               cmp dword ptr [esi + 0x24], ebx
// 0066e2db  7415                 je 0x66e2f2
// 0066e2dd  8bce                 mov ecx, esi
// 0066e2df  e8acfaffff           call 0x66dd90
// 0066e2e4  884500               mov byte ptr [ebp], al
// 0066e2e7  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0066e2ea  3bcb                 cmp ecx, ebx
// 0066e2ec  0f85fefeffff         jne 0x66e1f0
// 0066e2f2  5f                   pop edi
// 0066e2f3  5d                   pop ebp
// 0066e2f4  395e24               cmp dword ptr [esi + 0x24], ebx
// 0066e2f7  8b442408             mov eax, dword ptr [esp + 8]
// 0066e2fb  50                   push eax
// 0066e2fc  0f94c3               sete bl
// 0066e2ff  c78424a4000000ffffffff mov dword ptr [esp + 0xa4], 0xffffffff
// 0066e30a  e8119ae9ff           call 0x507d20
// 0066e30f  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 0066e316  83c404               add esp, 4
// 0066e319  5e                   pop esi
// 0066e31a  8ac3                 mov al, bl
// 0066e31c  5b                   pop ebx
// 0066e31d  64890d00000000       mov dword ptr fs:[0], ecx
// 0066e324  81c49c000000         add esp, 0x9c
// 0066e32a  c20400               ret 4

void __cdecl alignedFree(void*);

struct Transform {
    float data[12];
};

struct Context {
    Transform get(int);
};

extern const float tolerance;
bool __cdecl equivalent(const Transform&, const Transform&, float);

struct Array {
    int* data;
    int size;
    int capacity;

    Array();
    ~Array();
    void append(const int&);
    void resize(int, bool);
};

inline Array::Array()
{
    size = 0;
    capacity = 0;
    data = 0;
}

inline Array::~Array()
{
    alignedFree(data);
}

#include <intrin.h>

struct State {
    Context* context;
    int handle;
    float values[6];

    State& operator=(const State&);
};

inline State& State::operator=(const State& other)
{
    context = other.context;
    handle = other.handle;
    values[0] = other.values[0];
    values[1] = other.values[1];
    values[2] = other.values[2];
    values[3] = other.values[3];
    values[4] = other.values[4];
    values[5] = other.values[5];
    return *this;
}

struct S {
    char reserved0[0x14];
    Context* context;
    char reserved1[0x0c];
    State state;
    char reserved2[0x1c];
    int handle;

    State next(Context*, const Array&);
    bool update();
    bool f(bool*);
};

bool S::f(bool* changed)
{
    Array excluded;
    Context* current = state.context;

    while (current) {
        Transform first = current->get(state.handle);
        Transform second = context->get(handle);

        if (equivalent(first, second, tolerance))
            break;

        if (excluded.size < excluded.capacity) {
            int* destination = excluded.data + excluded.size;
            if (destination)
                *destination = state.handle;
            ++excluded.size;
        } else if (&state.handle >= excluded.data &&
                   &state.handle < excluded.data + excluded.size) {
            int temporary = state.handle;
            excluded.append(temporary);
        } else {
            excluded.resize(excluded.size + 1, false);
            excluded.data[excluded.size - 1] = state.handle;
        }

        state = next(state.context, excluded);
        _ReadWriteBarrier();

        if (!state.context)
            break;

        *changed = update();
        current = state.context;
    }

    return state.context == 0;
}
