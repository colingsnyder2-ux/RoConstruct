// from server: 58% by atomic.potato
struct S
{
    int f(int);
};

extern "C" void call_730df0(S *);
extern "C" void call_73f730(char *, int);

int S::f(int value)
{
    int unused = 0;
    call_730df0(this);
    call_73f730((char *)this + 0xb4, value);
    return value;
}
