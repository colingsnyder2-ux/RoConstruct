// from server: 27% by atomic.potato
struct Vec3 {
    float x;
    float y;
    float z;
};

int __stdcall f(const Vec3* v) {
    float a = v->x;
    float b = v->y;
    float m = a;
    int idx = 0;
    if (b > m) {
        m = b;
        idx = 1;
    }
    float c = v->z;
    if (c > m) {
        m = c;
        idx = 2;
    }
    float neg = -1.0f;
    float na = a * neg;
    if (na > m) {
        m = na;
        idx = 3;
    }
    float nb = b * neg;
    if (nb > m) {
        m = nb;
        idx = 4;
    }
    float nc = c * neg;
    if (nc > m) {
        idx = 5;
    }
    return idx;
}
