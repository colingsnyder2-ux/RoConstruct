// from server: 21% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

struct String {
    char pad[0x1c];
    String(const String&);
    String(const char*);
    String();
    ~String();
};

extern "C" {
    void* __cdecl sub_633f10();
    void __cdecl sub_7a72c0();
    void* __cdecl sub_809dd0();
    void __cdecl sub_88a7c0(void*, int, int, int, int, int, int, int, int, int);
    void __cdecl sub_88af70();
    void __cdecl sub_88b1e0(void*, const char*, int);
    void* __stdcall sub_b22648(const char*);
    void __stdcall sub_b2263c(void*);
    void __stdcall sub_b22644(void*, void*);
}

struct UnifiedImageWidget {
    void method(int a, int b);
};

void UnifiedImageWidget::method(int a, int b)
{
    void* self = this;
    int saved = 0;
    void* r = sub_633f10();
    float x0 = ((float*)r)[0];
    float x1 = ((float*)r)[1];
    float x2 = ((float*)r)[2];
    float x3 = ((float*)r)[3];

    struct {
        int a;
        int b;
        int c;
        int d;
        float e;
        float f;
        float g;
        float h;
    } local;
    local.a = 2;
    local.b = 0;
    local.c = 0x82;
    local.d = 1;
    local.e = x0;
    local.f = x1;
    local.g = x2;
    local.h = x3;

    sub_88a7c0(&local, 0, 0, 0, 0, 0, 0, 0, 0, 0);

    String s1("Chat");
    void* p1 = sub_b22648("ChatMenuPanel");
    (void)p1;
    sub_b2263c(&s1);

    String s2;
    sub_88b1e0(&s2, "D$HP", 0xf);

    void* g = sub_809dd0();
    void* gi = *(void**)g;

    String s3("RBXAuthenticationNegotiation:");
    sub_b22648("RBXAuthenticationNegotiation:");

    sub_88af70();

    RefCounted* rc = (RefCounted*)gi;
    if (rc) {
        _InterlockedExchangeAdd(&rc->ref1, 1);
    }

    sub_b22644(&s3, &s2);

    sub_88af70();

    if (rc) {
        if (_InterlockedExchangeAdd(&rc->ref1, -1) == 1) {
            void** vt = *(void***)rc;
            ((void(__thiscall*)(void*))vt[1])(rc);
            if (_InterlockedExchangeAdd(&rc->ref2, -1) == 1) {
                void** vt2 = *(void***)rc;
                ((void(__thiscall*)(void*))vt2[2])(rc);
            }
        }
    }

    if (rc) {
        if (_InterlockedExchangeAdd(&rc->ref1, -1) == 1) {
            void** vt = *(void***)rc;
            ((void(__thiscall*)(void*))vt[1])(rc);
            if (_InterlockedExchangeAdd(&rc->ref2, -1) == 1) {
                void** vt2 = *(void***)rc;
                ((void(__thiscall*)(void*))vt2[2])(rc);
            }
        }
    }
}
