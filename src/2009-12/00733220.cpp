// from server: 58% by atomic.potato
typedef unsigned int DWORD;

extern "C" void std_string_copy(void *, const void *);
extern "C" void call_503dc0(void *);

struct EventDesc {
    char data[0xB0];
    int f();
};

int EventDesc::f()
{
    std_string_copy((void *)((char *)0 + 0), (const void *)((char *)this + 0x94));
    call_503dc0((void *)((char *)this + 0xB0));
    return 0;
}
