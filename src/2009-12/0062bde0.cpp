// from server: 100% by atomic.potato
extern unsigned char g_00b32bcc;

struct S
{
    void f(unsigned char value);
};

void S::f(unsigned char value)
{
    g_00b32bcc = value;
}
