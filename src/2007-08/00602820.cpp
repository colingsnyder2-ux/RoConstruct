// from server: 36% by colin
struct Humanoid;
struct RunningBase;

struct Running {
    char pad0[4];
    Humanoid* humanoid;
    char pad8[0x34];
    float field_3c;
    float field_40;
    float field_44;
    float field_48;
    void onComputeForceImpl(float);
};

extern float g_7ab974;
extern float g_7c2b34;
extern float g_7a0be0;

extern "C" float* __stdcall sub_5a6c10(int);
extern "C" float __stdcall sub_5ab7a0(float*);
extern "C" float __stdcall sub_5a62a0(int);
extern "C" float __stdcall sub_5993f0(float);
extern "C" bool __stdcall sub_601e80(float*);
extern "C" bool __stdcall sub_6022d0(Running*);
extern "C" void* __stdcall sub_570270(int);
extern "C" void __stdcall sub_48d890(void*, float*);

extern "C" double __cdecl sqrt(double);

void Running::onComputeForceImpl(float arg)
{
    float dx = field_3c;
    float dy = field_40;
    float dz = field_44;
    float len = dx*dy + dx*dy + dz*dz;
    len = (float)sqrt((double)len);

    float* v = sub_5a6c10((int)humanoid);
    float s = g_7ab974;
    field_3c = v[0] * s;
    field_40 = v[1] * s;
    field_44 = v[2] * s;
    field_48 = 0.0f;

    bool b = false;
    if (!sub_601e80(&field_3c))
    {
        float t = sub_5ab7a0(&field_3c);
        float u = sub_5a62a0((int)humanoid);
        float d = u - t;
        float r = sub_5993f0(d);
        field_48 = r * g_7c2b34;
        if (sub_6022d0(this))
        {
            b = true;
            float nx = field_3c;
            float ny = field_40;
            float nz = field_44;
            float l2 = nx*nx + ny*ny + nz*nz;
            float l3 = (float)sqrt((double)l2);
            float f = g_7a0be0;
            field_3c = nx * f;
            field_40 = l3 * f;
            field_44 = field_44 * f;
        }
    }

    float nx = field_3c;
    float ny = field_40;
    float nz = field_44;
    float l2 = nx*nx + ny*ny + nz*nz;
    float l3 = (float)sqrt((double)l2);

    if (l3 != len)
    {
        Humanoid* h = humanoid;
        if (b)
        {
            void* p = h ? (void*)((char*)h + 4) : 0;
            void* q = sub_570270((int)p);
            if (q)
            {
                sub_48d890((char*)q + 0x10, &l3);
            }
        }
        else
        {
            void* p = h ? (void*)((char*)h + 4) : 0;
            void* q = sub_570270((int)p);
            if (q)
            {
                sub_48d890((char*)q + 0x10, &l3);
            }
        }
    }
}
