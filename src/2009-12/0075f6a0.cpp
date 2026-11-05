// from server: 38% by atomic.potato
struct S
{
    char padding[172];
    float value;
    void update(float);
};

extern "C" void __stdcall UpdateValue(float);

void S::update(float v)
{
    if (value != v)
    {
        value = v;
        UpdateValue(0xb979c4);
    }
}
