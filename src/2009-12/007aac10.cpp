// from server: 42% by atomic.potato
extern "C" unsigned int __cdecl func_007addf0();

extern float flt_009a6a88;

struct RotateConnector
{
    char pad[0x7c];
    float field_0x7c;
    unsigned char field_0x80;
    void set(float value);
};

void RotateConnector::set(float value)
{
    unsigned int count = func_007addf0();
    float divisor = (float)(int)count;
    field_0x7c = value / divisor;
    if (value == flt_009a6a88)
        field_0x80 = 1;
}
