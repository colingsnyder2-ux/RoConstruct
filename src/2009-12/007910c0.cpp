// from server: 27% by atomic.potato
extern "C" int __cdecl sub_7897F0(int, int);
extern "C" int __cdecl sub_788FF0(int, int, int);
extern "C" int __cdecl sub_789380(int, int);
extern "C" int __cdecl sub_69FC40(int, float*, int);
extern "C" int __cdecl sub_69FCA0(int);
extern "C" int __cdecl sub_746DB0(int);
extern "C" int __cdecl sub_788EB0(int, int, int);
extern "C" int __cdecl sub_7E20E0(int, int, int);
extern "C" int __cdecl sub_7F4878(int, int);

extern int g_b62b44;

struct LuaArguments {
    char pad0[4];
    float x;
    float y;
    float z;
    float w;
    float vx;
    float vy;
    float vz;
    int __cdecl method(const char* name, int a3);
};

int LuaArguments::method(const char* name, int a3)
{
    if (name == (const char*)0x9e8188)
    {
        float fx = x;
        float fy = y;
        float fz = z;
        float* p = (float*)sub_7897F0(a3, 12);
        if (p)
        {
            p[0] = fx;
            p[1] = fy;
            p[2] = fz;
        }
        sub_788FF0(a3, -10000, g_b62b44);
        sub_789380(a3, -2);
        return 1;
    }
    if (name == (const char*)0x9ea5a8)
    {
        float tmp[3];
        tmp[0] = w;
        tmp[1] = vx;
        tmp[2] = vy;
        sub_69FC40(a3, tmp, 0);
        return 1;
    }
    if (name == (const char*)0x9ea5a0)
    {
        return 1;
    }
    if (name == (const char*)0x9ea598)
    {
        return 1;
    }
    if (name == (const char*)0x9ea588)
    {
        sub_788EB0(a3, 0x790f40, 0);
        return 1;
    }
    if (name == (const char*)0x9ea57c)
    {
        sub_788EB0(a3, 0x791070, 0);
        return 1;
    }
    sub_7E20E0((int)&name, 0x9e1d58, a3);
    sub_7F4878((int)&name, 0xa904f0);
    sub_746DB0(a3);
    sub_69FCA0(a3);
    return 1;
}
