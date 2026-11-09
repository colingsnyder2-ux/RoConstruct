// from server: 77% by atomic.potato
struct GenericJob
{
    char pad[0x1f4];
    int field_1F4;
    void get(double* value, double* scale);
};

double g_half = 2147483648.0;

void GenericJob::get(double* value, double* scale)
{
    int v = field_1F4;
    double result = (double)v;
    if (v < 0)
        result += g_half;
    result *= *scale;
    *value = result;
    reinterpret_cast<unsigned char*>(value)[8] = v > 0;
}
