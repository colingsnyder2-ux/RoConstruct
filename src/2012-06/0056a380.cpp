// from server: 69% by atomic.potato
struct PacketJob
{
    char padding[0x234];
    int active;
    void getValue(double *out);
};

double packetJobDefault = 0.0;

void PacketJob::getValue(double *out)
{
    double value;

    if (active == 0)
        value = packetJobDefault;
    else
        value = 0.0;

    *(int *)out = *(int *)&value;
    *((int *)out + 1) = *((int *)&value + 1);
}
