// from server: 24% by atomic.potato
struct DescribedBase {
    void* vtable;
    int refcount;
    void AddRef();
    void Release();
};

struct VServer {
    char pad0[0x28];
    void* field28;
    void* field2c;
    void* field30;
    void* field34;
    void* field38;
    void* field3c;
};

struct BoundFuncDesc {
    char pad0[0x28];
    void* field28;
    void* field2c;
    void* field30;
    void* field34;
    void* field38;
    void* field3c;
    void func(void* a, void* b);
};

extern "C" void* __cdecl sub_80B2EA(void*, void*, void*, int, void*);
extern "C" void __cdecl sub_80B0AC(void*, void*);
extern "C" void __cdecl sub_5BD890(void*);
extern "C" void __cdecl sub_A40A10(void*);

void BoundFuncDesc::func(void* a, void* b)
{
    void* v1 = field30;
    void* v2 = field34;
    if (v2) {
        v2 = (void*)((int(__thiscall*)(void*))(*(void***)v2)[2])(v2);
    } else {
        v2 = 0;
    }
    void* v3 = field38;
    void* v4 = field3c;
    if (v4) {
        v4 = (void*)((int(__thiscall*)(void*))(*(void***)v4)[2])(v4);
    } else {
        v4 = 0;
    }
    void* obj = sub_80B2EA(v1, (void*)0xC29F90, (void*)0xC073F8, 0, 0);
    if (!obj) {
        sub_A40A10((void*)0xA5C10C);
        sub_80B0AC((void*)0xB989FC, (void*)0xA5C10C);
    }
    void* p1 = 0;
    void* p2 = 0;
    sub_5BD890(&p1);
    sub_5BD890(&p2);
    ((void(__thiscall*)(void*, void*, void*))field28)((char*)field2c + (int)obj, p1, p2);
}
