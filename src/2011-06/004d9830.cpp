// from server: 100% by atomic.potato
struct S
{
    int pad[122];
    int value;
    void set(int);
};

extern "C" void __stdcall notify(int);

void S::set(int value)
{
    if (value < 0)
        value = 1;
    if (value == this->value)
        return;
    this->value = value;
    notify(0xcb6830);
}
