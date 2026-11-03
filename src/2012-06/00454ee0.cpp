// from server: 35% by Intel
// roc 2012-06 00454ee0  unit: G3D::VVector3::?$XItem  size: 213 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00454ee0
//
// 00454ee0  6aff                 push -1
// 00454ee2  68e2eea900           push 0xa9eee2
// 00454ee7  64a100000000         mov eax, dword ptr fs:[0]
// 00454eed  50                   push eax
// 00454eee  64892500000000       mov dword ptr fs:[0], esp
// 00454ef5  83ec2c               sub esp, 0x2c
// 00454ef8  0f57c0               xorps xmm0, xmm0
// 00454efb  53                   push ebx
// 00454efc  8d442404             lea eax, [esp + 4]
// 00454f00  50                   push eax
// 00454f01  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 00454f07  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 00454f0d  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 00454f13  e828f7ffff           call 0x454640
// 00454f18  8bc8                 mov ecx, eax
// 00454f1a  c744243800000000     mov dword ptr [esp + 0x38], 0
// 00454f22  ff159847b200         call dword ptr [0xb24798]
// 00454f28  50                   push eax
// 00454f29  8d4c2418             lea ecx, [esp + 0x18]
// 00454f2d  ff154826b200         call dword ptr [0xb22648]
// 00454f33  8d4c2408             lea ecx, [esp + 8]
// 00454f37  51                   push ecx
// 00454f38  8d542418             lea edx, [esp + 0x18]
// 00454f3c  52                   push edx
// 00454f3d  c644244001           mov byte ptr [esp + 0x40], 1
// 00454f42  e849022f00           call 0x745190
// 00454f47  83c408               add esp, 8
// 00454f4a  8d4c2414             lea ecx, [esp + 0x14]
// 00454f4e  8ad8                 mov bl, al
// 00454f50  c644243800           mov byte ptr [esp + 0x38], 0
// 00454f55  ff153c26b200         call dword ptr [0xb2263c]
// 00454f5b  8d4c2404             lea ecx, [esp + 4]
// 00454f5f  ff15d047b200         call dword ptr [0xb247d0]
// 00454f65  8b442440             mov eax, dword ptr [esp + 0x40]
// 00454f69  84db                 test bl, bl
// 00454f6b  5b                   pop ebx
// 00454f6c  7425                 je 0x454f93
// 00454f6e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00454f72  8b542408             mov edx, dword ptr [esp + 8]
// 00454f76  8908                 mov dword ptr [eax], ecx
// 00454f78  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00454f7c  895004               mov dword ptr [eax + 4], edx
// 00454f7f  894808               mov dword ptr [eax + 8], ecx
// 00454f82  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00454f86  64890d00000000       mov dword ptr fs:[0], ecx
// 00454f8d  83c438               add esp, 0x38
// 00454f90  c20400               ret 4
// 00454f93  0f57c0               xorps xmm0, xmm0
// 00454f96  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00454f9a  f30f1100             movss dword ptr [eax], xmm0
// 00454f9e  f30f114004           movss dword ptr [eax + 4], xmm0
// 00454fa3  f30f114008           movss dword ptr [eax + 8], xmm0
// 00454faf  64890d00000000       mov dword ptr fs:[0], ecx
// 00454fb2  83c438               add esp, 0x38
// 00454fb2  c20400               ret 4

struct Str_00454640 { int words[8]; };
extern void (__thiscall* str_ctor_00454640)(Str_00454640*, Str_00454640*);

struct X_00454640 {
    char pad[0xa4];
    Str_00454640 value;
    Str_00454640* copy(Str_00454640* out);
};

struct String {
    char reserved[4];
    union {
        char buffer[16];
        char* pointer;
    } data;
    unsigned int length;
    unsigned int capacity;
};

extern "C" unsigned int __stdcall func_00745190(void* a1, void* a2, void* a3, void* a4);
extern "C" void* __stdcall func_00b24798();
extern "C" void __stdcall func_00b22648(void* thisptr, void* arg);
extern "C" void __stdcall func_00b2263c(void* thisptr);
extern "C" void __stdcall func_00b247d0(void* thisptr);

struct VVector3_XItem {
    char pad[0xa4];
    Str_00454640 value;
    Str_00454640* copy(Str_00454640* out);
    void method(float* out);
};

Str_00454640* X_00454640::copy(Str_00454640* out)
{
    volatile int zero = 0;
    str_ctor_00454640(out, &value);
    return out;
}

void VVector3_XItem::method(float* out)
{
    Str_00454640 local_str;
    int cookie = 0;
    String s1;
    String s2;
    float temp[3] = {0.0f, 0.0f, 0.0f};

    copy(&local_str);
    cookie = 0;
    void* ptr = func_00b24798();
    func_00b22648(&s1, ptr);
    unsigned char result = func_00745190(&s2, &s1, &temp[0], &temp[1]);
    func_00b2263c(&s1);
    func_00b247d0(&local_str);

    if (result) {
        out[0] = *reinterpret_cast<float*>(&temp[0]);
        out[1] = *reinterpret_cast<float*>(&temp[1]);
        out[2] = *reinterpret_cast<float*>(&temp[2]);
    } else {
        out[0] = 0.0f;
        out[1] = 0.0f;
        out[2] = 0.0f;
    }
}
