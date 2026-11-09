// from server: 5% by Intel
struct Vector3 {
    double x, y, z;
};

struct Vector3Array {
    int count;
    Vector3* data;
};

struct AdornBillboarder {
    void __cdecl process(Vector3Array* a, Vector3Array* b);
};

void AdornBillboarder::process(Vector3Array* a, Vector3Array* b) {
    int n = a->count;
    Vector3* src = a->data;
    Vector3* dst = b->data;

    if (n <= 0)
        return;

    int i = n - 1;
    while (true) {
        if (src != dst) {
            double tmp = src->x;
            src->x = dst->x;
            dst->x = tmp;
        }

        Vector3* next_src = src + 1;
        src = next_src;

        Vector3* next_dst = dst + 1;
        dst = next_dst;

        if (--i < 0)
            break;
    }
}
