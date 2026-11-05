// from server: 46% by atomic.potato
struct RBX_VPartInstance_EventDesc {
    char pad0[0x80];
    double value;
    char str[0x1c];
    void set(int);
};

extern "C" void __stdcall sub_9724f0(void *, int);
extern "C" void __stdcall sub_b22658(void *);
extern "C" void __stdcall sub_b2263c(void *);
extern double dbl_b4fd78;

void RBX_VPartInstance_EventDesc::set(int a)
{
    char buf[0x1c];
    sub_9724f0(buf, a);
    int v = a;
    double d = (double)v;
    if (v < 0)
        d += dbl_b4fd78;
    value = d;
    sub_b22658((char *)this + 0x88);
    sub_b2263c(buf);
}
