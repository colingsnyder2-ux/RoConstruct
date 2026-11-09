// from server: 65% by atomic.potato
extern "C" void sub_0067a5c0(void *, void *);
extern "C" void sub_0098b6f4(void *, const char *);

struct S
{
    int f(const char *);
};

int S::f(const char *text)
{
    char buffer[28];
    sub_0098b6f4(buffer, "Duplicate");
    sub_0067a5c0(this, buffer);
    *(void **)this = (void *)0x009cfddc;
    return (int)this;
}
