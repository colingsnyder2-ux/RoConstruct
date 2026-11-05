// from server: 40% by colin
struct Running {
    char pad0[4];
    void* field4;
    char pad8[0x0c];
    void* field14;
    char pad18[4];
    float field1c;
    char pad20[8];
    float field28;
    char pad2c[4];
    float field30;
    float field34;
    float field38;
    float field3c;
    float field40;
    float field44;
    float field48;
    float field4c;
    void onComputeForceImpl(float dt);
};

extern "C" void __cdecl sub_626690();
extern "C" void* __cdecl sub_5a6250(void*);
extern "C" void __cdecl sub_530100(void*);
extern "C" void __cdecl sub_5eb2a0(void*, void*);
extern "C" void __cdecl sub_5eb4e0(void*);
extern "C" void __cdecl sub_5eb4a0(void*);
extern "C" void __cdecl sub_5e1cd0(void*);
extern "C" void __cdecl sub_5e79a0(void*, void*);
extern "C" void __cdecl sub_5eb2e0(void*, void*);
extern "C" void __cdecl sub_5cf030(void*, void*);
extern "C" void __cdecl sub_624d80(void*);
extern "C" void __cdecl sub_50f630(void*, void*);
extern "C" void __cdecl sub_4a04a0(void*, void*, void*, void*);

extern float g_7c2b38;
extern float g_7c2b40;
extern float g_7c2b44;
extern float g_8b43fc;
extern float g_8b4400;
extern float g_8b4404;
extern float g_8b4408;
extern float g_79f758;

void Running::onComputeForceImpl(float dt)
{
    sub_626690();

    if (field38 != 0.0f)
        field38 = field38 + dt;

    void* v = sub_5a6250(field4);
    if (!v)
        return;

    void* esi = *(void**)((char*)v + 4);
    if (!esi)
        return;

    sub_530100(esi);

    float local38;
    sub_5eb2a0(esi, &local38);

    float f = (field48 + field34 - *(float*)((char*)esi + 0xc4)) * local38 * g_7c2b38;
    float local48 = f;

    sub_5eb4e0(esi);
    float f2 = local48 - *(float*)((char*)esi + 4);
    float local4c = f2;

    sub_5eb2a0(esi, &local38);
    float f3 = *(float*)((char*)esi + 4) * g_8b43fc;

    float local10;
    if (f2 >= -f3 && f2 <= f3)
    {
        local10 = 0.0f;
    }
    else
    {
        local10 = 0.0f;
    }

    float local18 = 0.0f;
    float local1c = 0.0f;
    float local20 = 0.0f;
    sub_5e79a0(esi, &local18);

    void* ebx = 0;
    if (field14)
    {
        ebx = *(void**)((char*)field14 + 0x1d8);
    }

    float local4c2;
    if (ebx)
    {
        void* eax = *(void**)((char*)ebx + 0x64);
        eax = *(void**)((char*)eax + 4);
        void* ecx = *(void**)((char*)eax + 0x1c);
        if (ecx)
            sub_624d80(ecx);
        else
            local4c2 = *(float*)((char*)eax + 0x7c);
    }
    else
    {
        void* ecx = *(void**)((char*)esi + 0x1c);
        if (ecx)
            sub_624d80(ecx);
        else
            local4c2 = *(float*)((char*)esi + 0x7c);
    }

    float local4c3;
    {
        void* ecx = *(void**)((char*)esi + 0x1c);
        if (ecx)
            sub_624d80(ecx);
        else
            local4c3 = *(float*)((char*)esi + 0x7c);
    }

    float local10b;
    if (local4c3 == local4c2)
        local10b = local4c2;
    else
        local10b = local4c3;

    if (field4c != 0.0f)
    {
        sub_530100(v);
        sub_530100(esi);

        float t = (field4c - *(float*)((char*)v + 0xac)) * g_7c2b40 - *(float*)((char*)esi + 0xb8) * g_7c2b44;
        if (t > 0.0f)
        {
            sub_5eb4a0(esi);
            float* ebp = (float*)((char*)0 + 4);
            (void)ebp;
            sub_5e1cd0(esi);
            float d = *(float*)((char*)0 + 4);
            (void)d;
        }
    }

    float local10c = field3c + field28;
    float local14 = field44 + field30;

    sub_530100(esi);

    float local28;
    {
        void* ecx = *(void**)((char*)esi + 0x1c);
        float val;
        if (ecx)
            sub_624d80(ecx);
        else
            val = *(float*)((char*)esi + 0x7c);
        local28 = val;
    }

    float local24;
    sub_5eb4a0(esi);
    sub_50f630((void*)0, &local24);

    float a = (local10c - *(float*)((char*)esi + 0xb4)) * g_7c2b44;
    float b;
    if (field40 != 0.0f)
        b = (field40 - *(float*)((char*)esi + 0xb8)) * g_7c2b44;
    else
        b = 0.0f;
    float c = (local14 - *(float*)((char*)esi + 0xbc)) * g_7c2b44;

    float local3c = -g_8b4400;
    float local40 = -g_8b4408;
    float local44 = local28 - local3c;
    float local3c2 = a - local40;
    float local40b = b - local44;

    sub_4a04a0(&local3c2, &local40b, &local44, &g_8b4400);

    float local18b = local3c2 * local10b;
    float local1cb = local40b * local10b;
    float local20b = local44 * local10b;

    if (ebx)
    {
        float scale = *(float*)((char*)ebx + 0x74);
        if (scale <= g_79f758)
        {
            local18b = local18b * scale * scale;
            local1cb = local1cb * scale;
            local20b = local20b * scale;
        }
    }

    sub_5eb2e0(esi, &local18b);

    if (ebx)
    {
        void* edx = *(void**)((char*)ebx + 0x64);
        void* eax = *(void**)((char*)edx + 4);
        void* ecx = *(void**)((char*)eax + 0x20);
        float n3c = -local18b;
        float n40 = -local1cb;
        float n44 = -local20b;
        if (ecx)
        {
            sub_5cf030(&n3c, (char*)this + 0x1c);
        }
    }
}
