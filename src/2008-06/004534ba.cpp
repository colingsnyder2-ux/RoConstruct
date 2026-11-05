// from server: 18% by colin
// from server: 17% by colin
// roc 2008-06 004534ba  unit: CRobloxDoc  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004534ba
//
// 004534ba  33c0                 xor eax, eax
// 004534bc  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004534bf  64890d00000000       mov dword ptr fs:[0], ecx
// 004534c6  5f                   pop edi
// 004534c7  5e                   pop esi
// 004534c8  5b                   pop ebx
// 004534c9  8be5                 mov esp, ebp
// 004534cb  5d                   pop ebp
// 004534cc  c20400               ret 4
// 004534cf  8d4dec               lea ecx, [ebp - 0x14]
// 004534d2  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 004534d9  ff15143f8000         call dword ptr [0x803f14]
// 004534df  8b17                 mov edx, dword ptr [edi]
// 004534e1  8b4274               mov eax, dword ptr [edx + 0x74]
// 004534e4  8bcf                 mov ecx, edi
// 004534e6  ffd0                 call eax
// 004534e8  8bcf                 mov ecx, edi
// 004534ea  e871e6ffff           call 0x451b60
// 004534ef  8b17                 mov edx, dword ptr [edi]
// 004534f1  8b4264               mov eax, dword ptr [edx + 0x64]
// 004534f4  6a01                 push 1
// 004534f6  8bcf                 mov ecx, edi
// 004534f8  ffd0                 call eax
// 004534fa  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004534fd  6a01                 push 1
// 004534ff  6a40                 push 0x40
// 00453501  6a21                 push 0x21
// 00453503  51                   push ecx
// 00453504  8d8d40ffffff         lea ecx, [ebp - 0xc0]
// 0045350a  c745fc02000000       mov dword ptr [ebp - 4], 2
// 00453511  ff1504248000         call dword ptr [0x802404]
// 00453517  8b8f94000000         mov ecx, dword ptr [edi + 0x94]
// 0045351d  8d9540ffffff         lea edx, [ebp - 0xc0]
// 00453523  52                   push edx
// 00453524  c645fc03             mov byte ptr [ebp - 4], 3
// 00453528  e843750100           call 0x46aa70
// 0045352d  8b07                 mov eax, dword ptr [edi]
// 0045352f  8b5064               mov edx, dword ptr [eax + 0x64]
// 00453532  6a00                 push 0
// 00453534  8bcf                 mov ecx, edi
// 00453536  ffd2                 call edx
// 00453538  8b8f94000000         mov ecx, dword ptr [edi + 0x94]
// 0045353e  8d45e8               lea eax, [ebp - 0x18]
// 00453541  50                   push eax
// 00453542  e8f9730100           call 0x46a940
// 00453547  8b10                 mov edx, dword ptr [eax]
// 00453549  83ec08               sub esp, 8
// 0045354c  8bcc                 mov ecx, esp
// 0045354e  8911                 mov dword ptr [ecx], edx
// 00453550  8b4004               mov eax, dword ptr [eax + 4]
// 00453553  c645fc04             mov byte ptr [ebp - 4], 4
// 00453557  8965e4               mov dword ptr [ebp - 0x1c], esp
// 0045355a  894104               mov dword ptr [ecx + 4], eax
// 0045355d  85c0                 test eax, eax
// 0045355f  740c                 je 0x45356d
// 00453561  83c004               add eax, 4
// 00453564  b901000000           mov ecx, 1
// 00453569  f00fc108             lock xadd dword ptr [eax], ecx

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Ifstream {
    char pad[0x40];
};

extern "C" void __stdcall ifstream_ctor(Ifstream*, const char*, int, int);
extern "C" void __stdcall ifstream_dtor(Ifstream*);

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(int);
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    char pad[0x94 - 4];
    void* field94;
};

struct Doc : Obj {
    int load(const char* name);
};

struct SharedPtr {
    Control* ctrl;
    void* ptr;
    SharedPtr();
    ~SharedPtr();
};

struct Holder {
    char pad[0x34];
    Holder();
    __declspec(dllimport) ~Holder() throw();
};

extern "C" void __stdcall sub_46aa70(void*, SharedPtr*);
extern "C" void __stdcall sub_46a940(void*, SharedPtr*);
extern "C" void __stdcall sub_451b60(Obj*);
extern "C" void __stdcall sub_58c8b0(void*, int);
extern "C" void __stdcall sub_5773c0(Holder*);
extern "C" void* __cdecl sub_453000(void*);

int Doc::load(const char* name)
{
    SharedPtr sp1;
    SharedPtr sp2;
    Holder h;
    Ifstream fs;
    void* p;

    v25(0);
    sub_451b60(this);
    v25(1);

    ifstream_ctor(&fs, name, 0x21, 0x40);
    sub_46aa70(field94, &sp1);
    v25(0);
    sub_46a940(field94, &sp2);

    if (sp2.ctrl) {
        if (_InterlockedExchangeAdd(&sp2.ctrl->strong, -1) == 1) {
            sp2.ctrl->dispose();
            if (_InterlockedExchangeAdd(&sp2.ctrl->weak, -1) == 1) {
                sp2.ctrl->destroy();
            }
        }
    }

    sub_46a940(field94, &sp2);
    p = sub_453000(sp2.ctrl);

    if (sp1.ctrl) {
        if (_InterlockedExchangeAdd(&sp1.ctrl->strong, -1) == 1) {
            sp1.ctrl->dispose();
            if (_InterlockedExchangeAdd(&sp1.ctrl->weak, -1) == 1) {
                sp1.ctrl->destroy();
            }
        }
    }

    sub_58c8b0(p, 1);
    sub_5773c0(&h);
    ifstream_dtor(&fs);
    return 1;
}
