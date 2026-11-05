// from server: 27% by atomic.potato
extern "C" {
    void __stdcall func_00a40a10();
    void __cdecl func_0080b0ac();
    void* __cdecl func_0080b2ea(int, int, int, int, int);
    void __cdecl func_0040c730(void*);
    void __cdecl func_006800f0(void*);
}

struct DescribedBase {
    virtual void f0();
    virtual void f1();
    virtual int f2();
};

struct VHumanoid {
    char pad0[0x28];
    int (__stdcall *fn28)(void*, void*);
    char pad2c[4];
    int field30;
    int field34;
    DescribedBase* field38;
    char pad3c[4];
    char result;
    void func(int, int);
};

void VHumanoid::func(int a, int b) {
    int local0 = field34;
    DescribedBase* p = field38;
    int local1;
    if (p) {
        local1 = p->f2();
    } else {
        local1 = 0;
    }
    int* arg = (int*)&a;
    void* obj = (void*)arg;
    ((void (__thiscall*)(void*, int, void*))((void**)obj)[1])(obj, 1, &local0);
    int v = local0;
    void* r = func_0080b2ea(v, 0, 0xc073f8, 0xc1a8f8, 0);
    if (!r) {
        func_00a40a10();
        func_0080b0ac();
    }
    int edx = *(int*)((char*)this + 0x2c);
    int ebp = *(int*)((char*)this + 0x28);
    int esi = *(int*)((char*)this + 0x30);
    func_006800f0(&local0);
    int ecx = *(int*)((char*)r + 0x144);
    int edx2 = *(int*)(ecx + esi);
    edx2 += *(int*)&local0;
    int eax = *(int*)&local0;
    ((void (__stdcall*)(int))ebp)(eax);
    result = (char)eax;
    func_0040c730((char*)&b + 4);
    int* q = (int*)&local0;
    if (q) {
        ((void (__thiscall*)(void*, int))((void**)q)[0])(q, 1);
    }
}
