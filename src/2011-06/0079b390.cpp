// from server: 48% by atomic.potato
extern "C" unsigned int __fastcall func_0079f690();

struct RotateConnector
{
    char pad[0x7c];
    float field_7c;
    unsigned char field_80;

    void Set(float value);
};

void RotateConnector::Set(float value)
{
    unsigned int n = func_0079f690();
    float d = (float)n;
    field_7c = value / d;
    if (!(value == 0.0f))
        field_80 = 1;
}
