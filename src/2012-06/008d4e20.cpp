// from server: 100% by atomic.potato
extern "C" void __stdcall UpdateGlobal(void*);

struct Handles
{
    char padding[0x188];
    int value;
    void SetValue(int);
};

void Handles::SetValue(int value)
{
    if (this->value != value)
    {
        this->value = value;
        UpdateGlobal((void*)0x00E550EC);
    }
}
