// from server: 32% by atomic.potato
struct S
{
    char padding[0xc0];

    int GetValue();
    void SetValue(const int* value);
    void f();
};

int S::GetValue()
{
    return *(int*)(padding + 0xc0);
}

void S::SetValue(const int* value)
{
    *(int*)padding = *value;
}

void S::f()
{
    int value = GetValue();
    SetValue(&value);
}
