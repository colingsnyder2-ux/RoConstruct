// from server: 18% by atomic.potato
struct Vec3 { float x, y, z; };

struct Sphere {
    Vec3 center;
    float radius;
    Vec3 getCenter(Vec3* out) const;
    Vec3 getCenter2(Vec3* out) const;
};

struct AdornBillboarder {
    Vec3 a;
    Vec3 b;
    void f(const Sphere* s);
};

void AdornBillboarder::f(const Sphere* s) {
    Vec3 tmp;
    this->a = s->getCenter(&tmp);
    Vec3 tmp2;
    this->b = s->getCenter2(&tmp2);
}
