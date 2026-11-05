// from server: 54% by atomic.potato
struct S
{
    int padding[190];
    int value;
    void Set(int);
};

void S::Set(int value)
{
    if (this->value != value)
    {
        this->value = value;
        this->value = 0x00c20e7c;
    }
}
