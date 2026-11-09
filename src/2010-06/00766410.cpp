// from server: 16% by atomic.potato
struct Vec3 { float x, y, z; };

struct P_func_00679420 { void g(); };
struct S_func_00679420 {
    char pad[244];
    P_func_00679420* m_p;
    void f();
};

struct Line {
    char pad[0x40];
    void f(const Vec3* a, const Vec3* b);
};

struct Obj {
    char pad0[0x48];
    Vec3 v48;
    char pad1[8];
    float f4c;
    float f50;
    float f54;
};

struct Result {
    int i0;
    int i4;
    int i8;
    float f0c;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
};

extern "C" Vec3* __cdecl getVec();
extern "C" int __cdecl func691260(const Vec3* a, const Vec3* b, Vec3* out);

struct FilterStairs {
    char pad0[0x48];
    Vec3 v48;
    char pad1[8];
    float f4c;
    float f50;
    float f54;
    Result* f(Obj* obj, Result* out, int* arr);
};

Result* FilterStairs::f(Obj* obj, Result* out, int* arr)
{
    Result local;
    local.i0 = 6;
    local.i4 = -1;
    Vec3* p = getVec();
    local.f0c = p->x;
    local.f10 = p->y;
    local.f14 = p->z;
    p = getVec();
    local.f18 = p->x;
    local.f1c = p->y;
    local.f20 = p->z;

    S_func_00679420* s = (S_func_00679420*)obj;
    s->f();

    Line* line = (Line*)s;
    Vec3 tmp;
    line->f(&this->v48, &tmp);

    int count = ((int*)((char*)obj + 0xf0))[0];
    int n = ((int (__thiscall*)(void*))((*(void***)obj)[0x30/4]))((void*)((char*)obj + 0xf0));

    float best = 0.0f;
    char found = 0;
    int i = 0;
    if (n > 0)
    {
        do
        {
            if (arr != 0)
            {
                int cnt = arr[1];
                int j = 0;
                if (cnt > 0)
                {
                    int* p2 = (int*)arr[0];
                    while (*p2 != 0)
                    {
                        j++;
                        p2++;
                        if (j >= cnt)
                            break;
                    }
                    if (j < cnt)
                    {
                        arr = (int*)((char*)arr + j * 4);
                    }
                }
            }

            Vec3 v;
            ((void (__thiscall*)(void*, Vec3*, int))((*(void***)obj)[0x20/4]))((void*)((char*)obj + 0xf0), &v, 0);

            float d = v.x * tmp.x + v.y * tmp.y + v.z * tmp.z;
            if (d >= this->f4c)
            {
                Vec3 out2;
                out2.x = 0.0f;
                out2.y = 0.0f;
                out2.z = 0.0f;
                if (func691260(&tmp, &v, &out2))
                {
                    float dx = this->f4c - (s->m_p ? 0.0f : 0.0f);
                    (void)dx;
                }
            }
            i++;
        } while (i < n);
    }

    if (!found)
    {
        Result r2;
        r2.i0 = 0;
        r2.i4 = 6;
        r2.i8 = -1;
        Vec3* q = getVec();
        r2.f0c = q->x;
        r2.f10 = q->y;
        r2.f14 = q->z;
        q = getVec();
        r2.f18 = q->x;
        r2.f1c = q->y;
        r2.f20 = q->z;
        *out = r2;
        return out;
    }

    *out = local;
    return out;
}
