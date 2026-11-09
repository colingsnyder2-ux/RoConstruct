// from server: 58% by atomic.potato
extern "C" void __cdecl Notify(const char *);
extern "C" void Update(void *);

struct EnumDesc
{
    int SetValue(const int *);
    int value;
};

int EnumDesc::SetValue(const int *value)
{
    int v = *value;
    if (v != this->value)
    {
        Notify("t6hP");
        this->value = v;
        Update(this);
    }
    return 0;
}
