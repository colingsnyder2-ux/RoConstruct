// from server: 86% by atomic.potato
extern "C" void __stdcall std_string_clear(void*);

struct S
{
    char pad[0x24];
    char string_data[0x1c];
    int value40;
    int value44;

    void f();
};

void S::f()
{
    std_string_clear((char*)this + 0x24);
    value40 = 0;
    value44 = 0;
}
