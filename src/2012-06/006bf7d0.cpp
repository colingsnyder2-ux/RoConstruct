// from server: 33% by atomic.potato
struct VSystemAddress
{
    void *vtable;
    char pad[0x0c];
    void *field10;
    void *field14;
    char field18;
    char field19;
};

extern "C" void __stdcall sub_464EB0(void *, void *);
extern "C" void *__stdcall sub_67F5B0(void *);
extern "C" void *__stdcall sub_67F480();
extern "C" void __stdcall sub_708C80(void *);
extern "C" void __stdcall sub_972290(unsigned char, void *);

extern unsigned char byte_E580B3;
extern void *ptr_E5809C;

struct S
{
    void construct(void *a, void *b);
};

void S::construct(void *a, void *b)
{
    VSystemAddress *self = (VSystemAddress *)this;
    sub_464EB0(self, a);
    self->vtable = (void *)0xB6F824;
    self->field10 = (void *)0xD60A74;
    void *r = sub_67F5B0(b);
    self->field14 = r;
    self->field18 = 0;
    self->field19 = 1;
    if (byte_E580B3 != 0)
    {
        if (sub_67F480() == r)
        {
            if (ptr_E5809C != 0)
            {
                typedef char (__stdcall *Fn)(void *, void *, void *);
                Fn fn = (Fn)ptr_E5809C;
                if (fn((void *)0xB6F80C, (void *)0xB52590, (void *)0x42))
                    goto done;
            }
            sub_972290(byte_E580B3, (void *)0xB96820);
        }
    }
done:
    sub_708C80(self);
}
