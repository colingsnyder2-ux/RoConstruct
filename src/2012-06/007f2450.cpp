// from server: 73% by atomic.potato
struct EventDesc
{
    unsigned char pad[0x2c];
    void* field_2c;
    void f(void* value);
};

extern "C" void sub_734e50(void* value);

void EventDesc::f(void* value)
{
    if (value != 0)
        sub_734e50((char*)field_2c + ((char*)value - (char*)0x1c));
    else
        sub_734e50(field_2c);
}
