// from server: 29% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    long refCount1;
    long refCount2;
};

struct Controller {
    char pad0[0xc];
    char field_c;
    char pad_d[0xf];
    int field_1c;
    void update(float dt);
};

struct InputObject {
    void** vptr;
    char getKey(int code);
};

struct GuiObject {
    void** vptr;
    void* getSomething();
};

struct Widget {
    void setPosition(float* pos);
    void setVisible(bool v);
};

extern "C" {
    void* __cdecl sub_597ff0(void* self);
    void* __cdecl sub_5fc7f0(void* self, void* out);
    void* __cdecl sub_495840(void* p);
    void* __cdecl sub_5a56b0(void* p);
    void* __cdecl sub_48e0d0(void* p);
    void* __cdecl sub_475020();
    void* __cdecl sub_457f10(void* self, void* a, void* b);
    void* __cdecl sub_51d850(void* self);
    void* __cdecl sub_50f3a0(void* self, float v);
    void* __cdecl sub_599d90(void* self, float v);
    void* __cdecl sub_5a7f80(void* self, float* v);
    void* __cdecl sub_5a8210(void* self, int v);
}

extern float g_79646c;
extern float g_79fe50;
extern float g_793760;
extern float g_7b1360;
extern float g_7b135c;
extern float g_7a8370;
extern float g_78d394;

void Controller::update(float dt)
{
    void* esi = sub_597ff0(&this->field_c);
    void* local20 = 0;
    void* eax = sub_5fc7f0(&this->field_c, &local20);
    void* ebx = *(void**)eax;
    void* local24 = local20;
    if (local24) {
        RefCounted* edi = (RefCounted*)local24;
        if (_InterlockedExchangeAdd(&edi->refCount1, -1) == 1) {
            void** vt = (void**)edi->vptr;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(edi);
            if (_InterlockedExchangeAdd(&edi->refCount2, -1) == 1) {
                void** vt2 = (void**)edi->vptr;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(edi);
            }
        }
    }
    void* edi2 = sub_495840(ebx);
    if (ebx == edi2) {
        local20 = sub_5a56b0(edi2);
    }
    void* eax2 = sub_48e0d0(edi2);
    if (esi == 0 || local20 == 0 || eax2 == 0) {
        return;
    }
    GuiObject* gui = (GuiObject*)((char*)eax2 + 0x228);
    void** vt3 = (void**)gui->vptr;
    void* (*fn3)(void*) = (void* (*)(void*))vt3[1];
    void* edi3 = fn3(gui);

    InputObject* input = (InputObject*)esi;
    void** ivt = (void**)input->vptr;
    char (*getKey)(void*, int) = (char (*)(void*, int))ivt[4];

    char b111 = getKey(input, 0x111);
    char b112 = getKey(input, 0x112);
    char b114 = getKey(input, 0x114);
    char b113 = getKey(input, 0x113);
    char b77 = getKey(input, 0x77);
    char b73 = getKey(input, 0x73);
    char b64 = getKey(input, 0x64);
    char b61 = getKey(input, 0x61);
    char b20 = getKey(input, 0x20);

    if (b111 != 0 || b112 != 0) {
        if (b114 == 0 && b113 == 0) {
            this->field_1c = 0;
        } else {
            float f;
            if (b114 != 0) {
                f = g_7b1360;
            } else {
                f = g_7b135c;
            }
            f = f * dt;
            f = f * g_7a8370;
            sub_599d90(edi3, f);
            this->field_1c++;
        }
    } else {
        if (b114 != 0) {
            if (b113 != 0) {
                float f = g_7b135c * dt * g_7a8370;
                sub_599d90(edi3, f);
                this->field_1c++;
            }
        } else {
            if (b113 != 0) {
                float f = g_7b1360 * dt * g_7a8370;
                sub_599d90(edi3, f);
                this->field_1c++;
            }
        }
    }

    float scale;
    if (b111 != 0) {
        scale = 1.0f;
    } else if (b112 != 0) {
        scale = g_79646c;
    } else {
        scale = 0.0f;
    }

    float pos[3];
    sub_457f10(edi3, &pos[0], &pos[1]);
    sub_51d850(&pos[0]);
    pos[1] = 0.0f;
    sub_50f3a0(&pos[1], g_79fe50);

    pos[0] = pos[0] * scale;
    pos[1] = pos[1] * g_78d394;
    pos[2] = pos[2] * scale;

    sub_5a7f80(local20, pos);

    if (b20 != 0) {
        sub_5a8210(local20, 1);
    }
}
