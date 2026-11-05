// from server: 41% by atomic.potato
struct Sub1 {
    char pad0[0x14];
    int data[9];
    float f24;
    float f28;
    float f2c;
};

struct Sub2 {
    char pad0[0x24];
    float f24;
    float f28;
    float f2c;
};

struct Vec3 {
    float x, y, z;
};

struct Camera {
    char pad0[0xa0];
    Sub1 sub_a0;
    char pad1[0x40];
    Sub2 sub_e4;
    char pad2[0x6c];
    void* ptr150;

    void func(double d, int a, int b);
};

void f_6dca20(Camera* self, double d);
void f_5f3900(Sub2* dst, Sub2* src);
bool f_6ee680(Vec3* v);
void f_5f1f80(Sub1* dst, void* src);
void* f_461ad0(Camera* self, Vec3* v);
void f_6db750(void* p, void* arg);

void Camera::func(double d, int a, int b)
{
    f_6dca20(this, d);

    Sub2* edi = &this->sub_e4;
    Sub2 tmp;
    f_5f3900(&tmp, edi);

    Vec3 v;
    v.x = edi->f24;
    v.y = edi->f28;
    v.z = edi->f2c;

    if (f_6ee680(&v)) {
        f_5f1f80(&this->sub_a0, &tmp);
        void* r = f_461ad0(this, &v);
        if (this->ptr150) {
            f_6db750(this->ptr150, r);
        }
    }
}
