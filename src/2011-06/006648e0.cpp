// from server: 58% by atomic.potato
struct Vec3 { float x, y, z; };

struct Sub {
    char pad0[0xdc];
    void get(int idx, Vec3* out);
};

extern "C" float g_a9bdd8;
extern "C" float g_a9bdd4;
extern "C" float atan2f(float, float);

struct S {
    char pad0[0xdc];
    Sub m_sub;
    int sub_664830(float);
    int f(int arg);
};

int S::f(int arg)
{
    Vec3 v;
    m_sub.get(2, &v);
    float ang = atan2f(-(-v.x), -(-v.z));
    float t = ang * g_a9bdd8 + (float)arg;
    int n = (int)t;
    float r = (float)n * g_a9bdd4 - v.y;
    return sub_664830(r);
}
