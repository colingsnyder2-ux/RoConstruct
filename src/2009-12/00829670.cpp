// from server: 43% by atomic.potato
struct S
{
    int pad0[9];
    int *p24;
};

extern "C" void Call823300(S *, int, int, int, int *);
extern "C" void Call81F480(S *);

void __stdcall Function00829670(int, int, int, int, int *slot)
{
    S *p = (S *)0;
    Call823300(p, 0, 0, -0x33, slot);
    Call81F480(p);
}
