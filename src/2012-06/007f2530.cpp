// from server: 58% by atomic.potato
extern "C" void __stdcall sub_734d10(void*);

struct EventDesc {
    unsigned char pad[0x2c];
    void* field_2c;
    void f(void* value);
};

void EventDesc::f(void* value)
{
    if (value != 0)
        sub_734d10((char*)field_2c + ((char*)value - (char*)0x1c));
    else
        sub_734d10(field_2c);
}
