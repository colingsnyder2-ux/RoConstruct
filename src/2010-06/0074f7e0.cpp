// from server: 59% by atomic.potato
struct ICharacterSubject;
struct Instance;
struct ServiceProvider;

extern "C" void* __stdcall sub_7a8bea(void*, void*, void*, void*, void*);
extern "C" void* __stdcall sub_470bd0(void*);
extern "C" void* __stdcall sub_4b0710(void*);
extern "C" void __stdcall sub_606020(void*, int);

extern float g_a2e0b0;
extern unsigned char g_c03cd0;
extern float g_c03cc4;
extern float g_c03cc8;
extern float g_c03ccc;

struct Humanoid {
    void* vtable;
    char pad[0x1c];
    float field20;
    void func(float, void*, void*);
};

void Humanoid::func(float a, void* b, void* c)
{
    typedef void (__thiscall *Fn24)(Humanoid*, float);
    ((Fn24)(*(void***)this)[0x24/4])(this, field20);

    void* p = sub_7a8bea(this, 0, (void*)0xbc05ec, (void*)0xb78e40, 0);
    if (p) {
        void* q = *(void**)((char*)p + 0x4c);
        if (q) {
            void* r = *(void**)((char*)q + 0x4c);
            if (r) {
                q = sub_470bd0(r);
            } else {
                q = q;
            }
            p = q;
        }
        if (p) {
            void* s = sub_7a8bea(p, 0, (void*)0xb78e40, (void*)0xb7cc50, 0);
            if (s) {
                void* t = sub_4b0710(s);
                if (t) {
                    int flag;
                    if (g_a2e0b0 > field20)
                        flag = 1;
                    else
                        flag = 0;
                    sub_606020(t, flag);
                }
            }
        }
    }

    if (g_a2e0b0 > field20) {
        float dx = *(float*)b - *(float*)c;
        float dy = *(float*)((char*)b + 4) - *(float*)((char*)c + 4);
        float dz = *(float*)((char*)b + 8) - *(float*)((char*)c + 8);
        float v[3];
        v[0] = dx;
        v[1] = dy;
        v[2] = dz;
        typedef void (__thiscall *Fn28)(Humanoid*, float*, int);
        ((Fn28)(*(void***)this)[0x28/4])(this, v, 1);
    } else {
        if (!(g_c03cd0 & 1)) {
            g_c03cd0 |= 1;
            g_c03cc4 = 0.0f;
            g_c03cc8 = 0.0f;
            g_c03ccc = 0.0f;
        }
        typedef void (__thiscall *Fn28)(Humanoid*, float*, int);
        ((Fn28)(*(void***)this)[0x28/4])(this, &g_c03cc4, 0);
    }
}
