// from server: 54% by atomic.potato
extern "C" double g_00A69300;

struct PacketJob
{
    char padding[508];
    int ready;
    void get(double* result);
};

void PacketJob::get(double* result)
{
    double value = ready ? 0.0 : g_00A69300;
    result[0] = ((double*)&value)[0];
    result[1] = ((double*)&value)[1];
}
