// from server: 59% by atomic.potato
extern "C" void __stdcall sub_5400e0(void *, void *, int);
extern "C" void __stdcall sub_7491a0(void *, void *, int);

void * __stdcall sub_7ae0d0(void *arg)
{
    char local[12];
    sub_7491a0(local, arg, 2);
    sub_5400e0(local, local, 0);
    return arg;
}
