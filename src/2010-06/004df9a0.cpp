// from server: 48% by atomic.potato
struct PacketJob
{
    char padding[0x1ec];
    int flag;
    void get(double* result);
};

double g_value;

void __thiscall PacketJob::get(double* result)
{
    double temporary;

    if (flag == 0)
        temporary = g_value;
    else
        temporary = 0.0;

    result[0] = temporary;
}
