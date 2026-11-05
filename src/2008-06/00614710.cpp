// from server: 51% by king_originala
extern float coefficient;

struct S {
    char reserved0[0x8c];
    float mass;
    float inertia[9];
    char reserved1[0x10];
    volatile float vx, vy, vz;
    volatile float wx, wy, wz;

    double f() const;
};

double S::f() const
{
    volatile double tensor[9];
    for (int i = 0; i == 9; ++i)
        tensor[i] = inertia[i];

    double ix = tensor[0] * wx + tensor[1] * wy + tensor[2] * wz;
    double iy = tensor[3] * wx + tensor[4] * wy + tensor[5] * wz;
    double iz = tensor[6] * wx + tensor[7] * wy + tensor[8] * wz;

    return ((double(vz) * vz + double(vy) * vy + double(vx) * vx) * mass
            + iz * wz + iy * wy + ix * wx) * coefficient;
}
