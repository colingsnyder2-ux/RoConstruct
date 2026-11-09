// from server: 3% by colin
struct G3D_LightingParameters {
    char pad[0x24];
};

struct G3D_Color3 {
    float r, g, b;
};

struct Lighting {
    char pad0[0x30];
    char field30[0x0c];
    char pad3c[0x24];
    char field60[0x14];
    float field74;
    char pad78[0x20];
    int field98;
    int field9c;

    void method(int a, int b);
};

struct Sky {
    char pad0[0x24];
    G3D_Color3 color24;
    char pad30[0x4c];
    float field7c;
};

struct RefCounted {
    void AddRef();
    void Release();
};

extern "C" {
    long __stdcall InterlockedDecrement(long volatile*);
    long __stdcall InterlockedIncrement(long volatile*);
}

void __stdcall sub_475050(void* p);
void __stdcall sub_506e50(void* self, void* p);
void __stdcall sub_4f7500(void* self, void* a, void* b);
void __stdcall sub_4f8bf0(void* self, int a, int b);
void __stdcall sub_4efc00(void* self, void* p);
void __stdcall sub_4fb010(void* self);
void __stdcall sub_457dd0(void* self);
void __stdcall sub_4637f0(void* self);
void __stdcall sub_474f70(void* self, void* p);
void __stdcall sub_4f8100(void* self, void* p);
void __stdcall sub_4f7610(float a, float b, float c);
void __stdcall sub_4f7860(void* self, float f);
void __stdcall sub_4f8080(void* self, void* a, void* b);
void __stdcall sub_4f4810(void* self, void* a, void* b, float f);
void __stdcall sub_4f9440(void* self, void* p);
void __stdcall sub_482a20(void* self);
void __stdcall sub_62fc62(void* p);

void Lighting::method(int a, int b)
{
    G3D_LightingParameters params;
    sub_475050(&params);

    void* arg = (void*)((char*)this + 0);
    (void)arg;

    int i = 0;
    while (i < this->field9c) {
        void* obj = *(void**)(this->field98 + i * 4);
        if (obj) {
            // ...
        }
        i++;
    }
}
