// from server: 63% by atomic.potato
struct EventDesc
{
    int pad[11];
    void* data;
    void f(void*);
};

extern "C" void sub_008fa160(void*);

void EventDesc::f(void* value)
{
    char* base = (char*)data;
    if (value)
        sub_008fa160(base + (int)value - 0x1c);
    else
        sub_008fa160(base);
}
