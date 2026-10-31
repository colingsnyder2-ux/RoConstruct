// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00618300  unit: RBX::NewNullTool  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00618300
//
// 00618300  83ec0c               sub esp, 0xc
// 00618303  53                   push ebx
// 00618304  56                   push esi
// 00618305  8bf1                 mov esi, ecx
// 00618307  33db                 xor ebx, ebx
// 00618309  385e34               cmp byte ptr [esi + 0x34], bl
// 0061830c  7462                 je 0x618370
// 0061830e  8b4614               mov eax, dword ptr [esi + 0x14]
// 00618311  50                   push eax
// 00618312  e8c9aff8ff           call 0x5a32e0
// 00618317  83c404               add esp, 4
// 0061831a  3bc3                 cmp eax, ebx
// 0061831c  7452                 je 0x618370
// 0061831e  8d4c2408             lea ecx, [esp + 8]
// 00618322  51                   push ecx
// 00618323  8b8830010000         mov ecx, dword ptr [eax + 0x130]
// 00618329  885c240c             mov byte ptr [esp + 0xc], bl
// 0061832d  885c240d             mov byte ptr [esp + 0xd], bl
// 00618331  885c240e             mov byte ptr [esp + 0xe], bl
// 00618335  885c240f             mov byte ptr [esp + 0xf], bl
// 00618339  885c2410             mov byte ptr [esp + 0x10], bl
// 0061833d  885c2411             mov byte ptr [esp + 0x11], bl
// 00618341  885c2412             mov byte ptr [esp + 0x12], bl
// 00618345  885c2413             mov byte ptr [esp + 0x13], bl
// 00618349  885c2414             mov byte ptr [esp + 0x14], bl
// 0061834d  e80e66fbff           call 0x5ce960
// 00618352  8d4c2408             lea ecx, [esp + 8]
// 00618356  e8357ef8ff           call 0x5a0190
// 0061835b  84c0                 test al, al
// 0061835d  7511                 jne 0x618370
// 0061835f  8b542418             mov edx, dword ptr [esp + 0x18]
// 00618363  83c638               add esi, 0x38
// 00618366  56                   push esi
// 00618367  52                   push edx
// 00618368  e8e3f3fbff           call 0x5d7750
// 0061836d  83c408               add esp, 8
// 00618370  5e                   pop esi
// 00618371  5b                   pop ebx
// 00618372  83c40c               add esp, 0xc
// 00618375  c20400               ret 4

struct Instance;
struct Camera;

struct S {
    unsigned char flags[9];
    S();
    int f();
};

inline S::S()
{
    flags[0] = 0;
    flags[1] = 0;
    flags[2] = 0;
    flags[3] = 0;
    flags[4] = 0;
    flags[5] = 0;
    flags[6] = 0;
    flags[7] = 0;
    flags[8] = 0;
}

struct Camera {
    void func_005ce960(S*);
};

struct ServiceProvider {
    char padding[0x130];
    Camera* camera;
};

ServiceProvider* __cdecl func_005a32e0(Instance*);
void __cdecl func_005d7750(const float*, const float*);

struct NewNullTool {
    char padding0[0x14];
    Instance* instance;
    char padding1[0x1c];
    unsigned char enabled;
    char padding2[3];
    float position[3];

    void func_00618300(const float*);
};

void NewNullTool::func_00618300(const float* argument)
{
    if (enabled) {
        ServiceProvider* provider = func_005a32e0(instance);
        if (provider) {
            S state;
            provider->camera->func_005ce960(&state);
            if (!(unsigned char)state.f())
                func_005d7750(argument, position);
        }
    }
}
