// from server: 82% by atomic.potato
extern "C" void sub_54fbe0(void *);

struct EventDesc {
    void *field_2c;
    void method(void *);
};

void EventDesc::method(void *arg)
{
    char *p;
    if (arg != 0)
        p = (char *)arg - 0x1c;
    else
        p = 0;
    sub_54fbe0((char *)field_2c + (int)p);
}
