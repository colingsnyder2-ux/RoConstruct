// from server: 43% by atomic.potato
struct DxUserInput
{
    static void f(float *destination, const float *value);
};

void DxUserInput::f(float *destination, const float *value)
{
    destination[0] += value[0];
    destination[1] += value[1];
}
