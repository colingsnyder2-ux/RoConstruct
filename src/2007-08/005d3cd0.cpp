// from server: 51% by colin
struct Vector3 {
    float x, y, z;
};

struct CoordinateFrame {
    float r00, r01, r02;
    float r10, r11, r12;
    float r20, r21, r22;
    Vector3 translation;
};

struct Tool {
    char pad[0x174];
    CoordinateFrame grip;

    void func_5d3cd0(void* arg);
};

extern float g_79fe50;

void __stdcall func_5095d0(CoordinateFrame* out, const CoordinateFrame* in);
void __stdcall func_509640(CoordinateFrame* out, const Vector3* v, int flag);
void __stdcall func_509660(CoordinateFrame* out, int index, const Vector3* v);
float __stdcall func_50f3a0(float angle);
void __stdcall func_5d3a70(Tool* self, CoordinateFrame* out);

void Tool::func_5d3cd0(void* arg) {
    CoordinateFrame local;
    func_5095d0(&local, &grip);

    Vector3 v1;
    v1.x = grip.translation.x;
    v1.y = grip.translation.y;
    v1.z = grip.translation.z;

    Vector3 v2;
    func_509640(&local, &v1, 0);

    Vector3 v3;
    func_509640(&local, &v2, 2);

    float len = v3.x * v3.y + v3.x * v3.y + v3.z * v3.z;
    float invLen = 1.0f / func_50f3a0(len);

    Vector3 n;
    n.x = v3.x * invLen;
    n.y = v3.y * invLen;
    n.z = v3.z * invLen;

    Vector3 b;
    b.x = v2.y * n.z - v2.z * n.y;
    b.y = v2.z * n.x - v2.x * n.z;
    b.z = v2.x * n.y - v2.y * n.x;

    func_50f3a0(g_79fe50);

    Vector3 r1;
    r1.x = b.y * n.z - b.z * n.y;
    r1.y = b.z * n.x - b.x * n.z;
    r1.z = b.x * n.y - b.y * n.x;

    func_50f3a0(g_79fe50);

    func_509660(&local, 0, &r1);
    func_509660(&local, 1, &b);
    func_509660(&local, 2, &n);

    func_5d3a70(this, &local);
}
