// from server: 42% by atomic.potato
extern "C" unsigned int __cdecl func_0074e710();

struct RotateConnector
{
    char pad[0x7c];
    float field_7c;
    unsigned char field_80;
    void set(float value);
};

void RotateConnector::set(float value)
{
    unsigned int count = func_0074e710();
    float divisor = (float)(int)count;
    field_7c = value / divisor;
    if (!(value == *(float *)0xa07828))
        field_80 = 1;
}
