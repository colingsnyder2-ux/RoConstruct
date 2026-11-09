// from server: 42% by atomic.potato
extern "C" void __stdcall sub_005b96f0(short, short, void *);

void __stdcall sub_005bb350(short a, short b, void *c, void *d)
{
    sub_005b96f0(b, a, d);
}
