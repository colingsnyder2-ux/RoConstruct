// from server: 43% by atomic.potato
typedef unsigned int DWORD;

extern "C" double g_009A6AD0;

struct PacketJob
{
    double GetValue(double* out);
};

double PacketJob::GetValue(double* out)
{
    double value = (reinterpret_cast<const DWORD*>(reinterpret_cast<const char*>(this) + 0x1EC) != 0)
        ? g_009A6AD0
        : 0.0;

    *out = value;
    return value;
}
