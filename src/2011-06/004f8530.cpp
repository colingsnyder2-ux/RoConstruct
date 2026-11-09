// from server: 37% by atomic.potato
extern "C" float __cdecl sub_4f6ea0(float);
extern "C" void __cdecl sub_4f1580(float, float);

void SendDataJob(float a, float b)
{
    float value = sub_4f6ea0(a);
    sub_4f1580(b, value);
}
