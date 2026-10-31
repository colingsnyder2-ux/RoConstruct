// from server: 25% by Intel
struct Vec4S {
    float f0;
    short w0;
    float f1;
    short w1;
    void subtract(Vec4S* out, const Vec4S* other);
};

void Vec4S::subtract(Vec4S* out, const Vec4S* other)
{
    out->f0 = f0 - other->f0;
    out->w0 = w0 - other->w0;
    out->f1 = f1 - other->f1;
    out->w1 = w1 - other->w1;
}
