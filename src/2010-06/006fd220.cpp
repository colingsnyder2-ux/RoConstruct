// from server: 40% by atomic.potato
struct RefCounted {
    void AddRef();
    void Release();
};

struct Callback {
    virtual void f0();
    virtual void Invoke(int id, void* p);
};

struct VAnimationTrack {
    char pad0[0x38];
    void (__thiscall *callback)(float, float, float);
    char pad3c[0x40 - 0x3c];
    RefCounted* ref40;
    RefCounted* ref44;
    RefCounted* ref48;
    RefCounted* ref4c;
    RefCounted* ref50;
    RefCounted* ref54;
    void Invoke(Callback* cb);
};

extern "C" void* __cdecl sub_7a8bea(void*, void*, void*, int, int);
extern "C" void __cdecl sub_7a89b2(void*, void*);
extern "C" void* __cdecl sub_5a8d40();

void VAnimationTrack::Invoke(Callback* cb)
{
    void* a;
    RefCounted* b;
    void* c;
    RefCounted* d;
    void* e;
    RefCounted* f;

    a = ref40;
    if (ref44) {
        b = ref44;
        ((void (__thiscall*)(RefCounted*))((*(void***)b)[2]))(b);
    } else {
        b = 0;
    }
    cb->Invoke(1, &a);

    c = ref48;
    if (ref4c) {
        d = ref4c;
        ((void (__thiscall*)(RefCounted*))((*(void***)d)[2]))(d);
    } else {
        d = 0;
    }
    cb->Invoke(2, &c);

    e = ref50;
    if (ref54) {
        f = ref54;
        ((void (__thiscall*)(RefCounted*))((*(void***)f)[2]))(f);
    } else {
        f = 0;
    }
    cb->Invoke(3, &e);

    void* result = sub_7a8bea(0, (void*)0xbdf9bc, (void*)0xb79040, 0, 0);
    if (!result) {
        sub_7a89b2((void*)0xb12290, (void*)0xa00a54);
    }

    void* p1 = sub_5a8d40();
    void* p2 = sub_5a8d40();
    void* p3 = sub_5a8d40();

    float f1 = *(float*)p1;
    float f2 = *(float*)p2;
    float f3 = *(float*)p3;

    callback(f3, f2, f1);

    if (b) {
        ((void (__thiscall*)(void*, int))((*(void***)b)[0]))(b, 1);
    }
    if (d) {
        ((void (__thiscall*)(void*, int))((*(void***)d)[0]))(d, 1);
    }
    if (f) {
        ((void (__thiscall*)(void*, int))((*(void***)f)[0]))(f, 1);
    }
}
