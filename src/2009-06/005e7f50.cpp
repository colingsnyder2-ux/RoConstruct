// from server: 78% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056ebb0  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 334 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056ebb0
//
// 0056ebb0  51                   push ecx
// 0056ebb1  53                   push ebx
// 0056ebb2  55                   push ebp
// 0056ebb3  8b2d78288000         mov ebp, dword ptr [0x802878]
// 0056ebb9  56                   push esi
// 0056ebba  57                   push edi
// 0056ebbb  8bf9                 mov edi, ecx
// 0056ebbd  8b07                 mov eax, dword ptr [edi]
// 0056ebbf  8b4008               mov eax, dword ptr [eax + 8]
// 0056ebc2  50                   push eax
// 0056ebc3  b9d0be9200           mov ecx, 0x92bed0
// 0056ebc8  ffd5                 call ebp
// 0056ebca  84c0                 test al, al
// 0056ebcc  744a                 je 0x56ec18
// 0056ebce  8d7704               lea esi, [edi + 4]
// 0056ebd1  56                   push esi
// 0056ebd2  e8f972eaff           call 0x415ed0
// 0056ebd7  85c0                 test eax, eax
// 0056ebd9  6a08                 push 8
// 0056ebdb  0f95c3               setne bl
// 0056ebde  e83d1d1300           call 0x6a0920
// 0056ebe3  83c408               add esp, 8
// 0056ebe6  85c0                 test eax, eax
// 0056ebe8  740b                 je 0x56ebf5
// 0056ebea  c70084ba8000         mov dword ptr [eax], 0x80ba84
// 0056ebf0  885804               mov byte ptr [eax + 4], bl
// 0056ebf3  eb02                 jmp 0x56ebf7
// 0056ebf5  33c0                 xor eax, eax
// 0056ebf7  8d542410             lea edx, [esp + 0x10]
// 0056ebfb  8bc8                 mov ecx, eax
// 0056ebfd  3bd6                 cmp edx, esi
// 0056ebff  7404                 je 0x56ec05
// 0056ec01  8b0e                 mov ecx, dword ptr [esi]
// 0056ec03  8906                 mov dword ptr [esi], eax
// 0056ec05  85c9                 test ecx, ecx
// 0056ec07  7408                 je 0x56ec11
// 0056ec09  8b01                 mov eax, dword ptr [ecx]
// 0056ec0b  8b10                 mov edx, dword ptr [eax]
// 0056ec0d  6a01                 push 1
// 0056ec0f  ffd2                 call edx
// 0056ec11  e81ae0ffff           call 0x56cc30
// 0056ec16  8907                 mov dword ptr [edi], eax
// 0056ec18  8b07                 mov eax, dword ptr [edi]
// 0056ec1a  8b4008               mov eax, dword ptr [eax + 8]
// 0056ec1d  50                   push eax
// 0056ec1e  b9dcbe9200           mov ecx, 0x92bedc
// 0056ec23  ffd5                 call ebp
// 0056ec25  84c0                 test al, al
// 0056ec27  745b                 je 0x56ec84
// 0056ec29  8d7704               lea esi, [edi + 4]
// 0056ec2c  56                   push esi
// 0056ec2d  e8be73eaff           call 0x415ff0
// 0056ec32  d81dc4358100         fcomp dword ptr [0x8135c4]
// 0056ec38  83c404               add esp, 4
// 0056ec3b  dfe0                 fnstsw ax
// 0056ec3d  f6c444               test ah, 0x44
// 0056ec40  7b04                 jnp 0x56ec46
// 0056ec42  b301                 mov bl, 1
// 0056ec44  eb02                 jmp 0x56ec48
// 0056ec46  32db                 xor bl, bl
// 0056ec48  6a08                 push 8
// 0056ec4a  e8d11c1300           call 0x6a0920
// 0056ec4f  83c404               add esp, 4
// 0056ec52  85c0                 test eax, eax
// 0056ec54  740b                 je 0x56ec61
// 0056ec56  c70084ba8000         mov dword ptr [eax], 0x80ba84
// 0056ec5c  885804               mov byte ptr [eax + 4], bl
// 0056ec5f  eb02                 jmp 0x56ec63
// 0056ec61  33c0                 xor eax, eax
// 0056ec63  8d542410             lea edx, [esp + 0x10]
// 0056ec67  8bc8                 mov ecx, eax
// 0056ec69  3bd6                 cmp edx, esi
// 0056ec6b  7404                 je 0x56ec71
// 0056ec6d  8b0e                 mov ecx, dword ptr [esi]
// 0056ec6f  8906                 mov dword ptr [esi], eax
// 0056ec71  85c9                 test ecx, ecx
// 0056ec73  7408                 je 0x56ec7d
// 0056ec75  8b01                 mov eax, dword ptr [ecx]
// 0056ec77  8b10                 mov edx, dword ptr [eax]
// 0056ec79  6a01                 push 1
// 0056ec7b  ffd2                 call edx
// 0056ec7d  e8aedfffff           call 0x56cc30
// 0056ec82  8907                 mov dword ptr [edi], eax
// 0056ec84  8b07                 mov eax, dword ptr [edi]
// 0056ec86  8b4008               mov eax, dword ptr [eax + 8]
// 0056ec89  50                   push eax
// 0056ec8a  b9e8be9200           mov ecx, 0x92bee8
// 0056ec8f  ffd5                 call ebp
// 0056ec91  84c0                 test al, al
// 0056ec93  745b                 je 0x56ecf0
// 0056ec95  8d7704               lea esi, [edi + 4]
// 0056ec98  56                   push esi
// 0056ec99  e8e273eaff           call 0x416080
// 0056ec9e  dc1da8878100         fcomp qword ptr [0x8187a8]
// 0056eca4  83c404               add esp, 4
// 0056eca7  dfe0                 fnstsw ax
// 0056eca9  f6c444               test ah, 0x44
// 0056ecac  7b04                 jnp 0x56ecb2
// 0056ecae  b301                 mov bl, 1
// 0056ecb0  eb02                 jmp 0x56ecb4
// 0056ecb2  32db                 xor bl, bl
// 0056ecb4  6a08                 push 8
// 0056ecb6  e8651c1300           call 0x6a0920
// 0056ecbb  83c404               add esp, 4
// 0056ecbe  85c0                 test eax, eax
// 0056ecc0  740b                 je 0x56eccd
// 0056ecc2  c70084ba8000         mov dword ptr [eax], 0x80ba84
// 0056ecc8  885804               mov byte ptr [eax + 4], bl
// 0056eccb  eb02                 jmp 0x56eccf
// 0056eccd  33c0                 xor eax, eax
// 0056eccf  8d542410             lea edx, [esp + 0x10]
// 0056ecd3  8bc8                 mov ecx, eax
// 0056ecd5  3bd6                 cmp edx, esi
// 0056ecd7  7404                 je 0x56ecdd
// 0056ecd9  8b0e                 mov ecx, dword ptr [esi]
// 0056ecdb  8906                 mov dword ptr [esi], eax
// 0056ecdd  85c9                 test ecx, ecx
// 0056ecdf  7408                 je 0x56ece9
// 0056ece1  8b01                 mov eax, dword ptr [ecx]
// 0056ece3  8b10                 mov edx, dword ptr [eax]
// 0056ece5  6a01                 push 1
// 0056ece7  ffd2                 call edx
// 0056ece9  e842dfffff           call 0x56cc30
// 0056ecee  8907                 mov dword ptr [edi], eax
// 0056ecf0  8bcf                 mov ecx, edi
// 0056ecf2  5f                   pop edi
// 0056ecf3  5e                   pop esi
// 0056ecf4  5d                   pop ebp
// 0056ecf5  5b                   pop ebx
// 0056ecf6  83c404               add esp, 4
// 0056ecf9  e932e8ffff           jmp 0x56d530

struct TypeInfo {};
extern bool (__thiscall *type_equal)(const TypeInfo*, const TypeInfo&);

extern const TypeInfo int_type;
extern const TypeInfo float_type;
extern const TypeInfo double_type;
extern const double double_zero;

struct Holder;
struct HolderTable {
    void* (__thiscall *destroy)(Holder*, unsigned int);
};

struct Holder {
    const HolderTable* table;
    bool value;
};

extern const HolderTable bool_holder_table;
extern void* __cdecl allocate(unsigned int);

struct Owned {
    Holder* pointer;
    ~Owned();
    void swap(Owned&);
};

inline Owned::~Owned()
{
    if (pointer)
        pointer->table->destroy(pointer, 1);
}

inline void Owned::swap(Owned& other)
{
    if (this != &other) {
        Holder* old = pointer;
        pointer = other.pointer;
        other.pointer = old;
    }
}

extern int __cdecl cast_int(const Owned*);
extern float __cdecl cast_float(const Owned*);
extern double __cdecl cast_double(const Owned*);

struct Descriptor {
    unsigned long words[2];
    const TypeInfo* type;
    const TypeInfo& getType() const;
};

__forceinline const TypeInfo& Descriptor::getType() const
{
    return *type;
}

extern Descriptor* __cdecl bool_descriptor();

struct S {
    Descriptor* descriptor;
    Owned value;
    void finish();
    void func_0056ebb0();
};

void S::func_0056ebb0()
{
    bool (__thiscall *equal)(const TypeInfo*, const TypeInfo&) = type_equal;

    if (equal(&int_type, descriptor->getType())) {
        bool result = cast_int(&value) != 0;
        Holder* holder = static_cast<Holder*>(allocate(8));
        if (holder) {
            holder->table = &bool_holder_table;
            holder->value = result;
        } else {
            holder = 0;
        }
        {
            Owned temporary;
            temporary.pointer = holder;
            temporary.swap(value);
        }
        descriptor = bool_descriptor();
    }

    if (equal(&float_type, descriptor->getType())) {
        bool result = static_cast<double>(cast_float(&value)) != 0.0;
        Holder* holder = static_cast<Holder*>(allocate(8));
        if (holder) {
            holder->table = &bool_holder_table;
            holder->value = result;
        } else {
            holder = 0;
        }
        {
            Owned temporary;
            temporary.pointer = holder;
            temporary.swap(value);
        }
        descriptor = bool_descriptor();
    }

    if (equal(&double_type, descriptor->getType())) {
        bool result = cast_double(&value) != double_zero;
        Holder* holder = static_cast<Holder*>(allocate(8));
        if (holder) {
            holder->table = &bool_holder_table;
            holder->value = result;
        } else {
            holder = 0;
        }
        {
            Owned temporary;
            temporary.pointer = holder;
            temporary.swap(value);
        }
        descriptor = bool_descriptor();
    }

    finish();
}
