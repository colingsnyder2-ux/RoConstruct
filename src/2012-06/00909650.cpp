// from server: 41% by atomic.potato
struct S
{
    void f(float);
    float value[39];
};

void S::f(float value)
{
    if (this->value[38] != value)
        this->value[38] = value;
}
