// from server: 59% by atomic.potato
struct Vec3 { float x, y, z; };

extern "C" {
    Vec3* __cdecl G3D_Line_origin();
    void* __cdecl sub_79b2b0(void* p);
    void __cdecl sub_79c7a0(void* p, float f);
    void __cdecl sub_96ab00(void* a, void* b);
    void __cdecl sub_972290(unsigned char a, const char* b);
}

extern unsigned char g_e580b3;
extern void* g_e5809c;

struct Humanoid;

struct Climbing {
    void* vtable0;
    void* vtable4;
    char pad[0x98];
    Vec3 field_a0;
    Vec3 field_ac;
    Vec3 field_b8;
    Vec3 field_c4;
    float field_d0;
    void construct(Humanoid* h, void* a);
};

void Climbing::construct(Humanoid* h, void* a)
{
    sub_96ab00(this, a);
    this->vtable0 = (void*)0xc046c4;
    this->vtable4 = (void*)0xc046b8;

    Vec3* v;
    v = G3D_Line_origin();
    this->field_a0 = *v;
    v = G3D_Line_origin();
    this->field_ac = *v;
    v = G3D_Line_origin();
    this->field_b8 = *v;
    v = G3D_Line_origin();
    this->field_c4 = *v;
    this->field_d0 = 0.0f;

    sub_79c7a0((char*)h + 0x298, 0.0f);

    if (g_e580b3 != 0) {
        void* p = sub_79b2b0(h);
        if (p != 0) {
            p = sub_79b2b0(h);
            void* q = *(void**)((char*)p + 0x198);
            if (*(void**)((char*)q + 0x110) != 0) {
                if (g_e5809c != 0) {
                    unsigned char r = ((unsigned char (__cdecl*)(const char*, const char*, int))g_e5809c)((const char*)0xc04638, (const char*)0xc04418, 0x1a);
                    if (r != 0) return;
                }
                sub_972290(g_e580b3, (const char*)0xc04558);
            }
        }
    }
}
