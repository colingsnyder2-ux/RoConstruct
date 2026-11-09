// from server: 43% by atomic.potato
struct S
{
    struct Data
    {
        float value;
    };

    char padding[0xb4];
    Data* data;
    void f(float value);
};

void S::f(float value)
{
    if (data->value != value)
    {
        data->value = value;
        data->value = 0.0f;
    }
}
