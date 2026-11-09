// from server: 37% by atomic.potato
extern "C" void __cdecl stream_buffer(void *, void *, void *, void *, void *, void *, void *);

void f(void *a)
{
    char z = 0;
    stream_buffer(&z, &z, &z, a, a, a, a);
}
