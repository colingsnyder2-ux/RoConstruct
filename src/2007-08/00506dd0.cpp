// from server: 100% by tajop
struct Vector3 {
    float x, y, z;
};

struct Ray {
    void* vtable;
    char pad_04[8];      // untouched by ctor
    float f_0c;          // target: fstp [esi+0xc]
    float f_10;          // target: fstp [esi+0x10]
    Vector3 m_invDirection; // target: lea ecx,[esi+0x14]
    void set(const Vector3& origin, const Vector3& direction);
    Ray();
};

extern float G3D_ray_epsilon;
extern float G3D_ray_inf;
extern double G3D_ray_inf_d;
extern int G3D_ray_inf_init_flag;
extern int G3D_ray_inf_ptr;

void __fastcall sub_475050(void* p);
void __fastcall sub_506b40(Ray* self, float f);

Ray::Ray()
{
    vtable = (void*)0x7a060c;
    sub_475050(&m_invDirection);
    f_0c = G3D_ray_epsilon;
    if (!(G3D_ray_inf_init_flag & 1)) {
        G3D_ray_inf_init_flag |= 1;
        G3D_ray_inf_d = *(double*)G3D_ray_inf_ptr;
    }
    f_10 = (float)G3D_ray_inf_d;
    sub_506b40(this, G3D_ray_inf);
}
