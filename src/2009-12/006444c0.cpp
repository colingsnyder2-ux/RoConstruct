// from server: 59% by atomic.potato
extern "C" void __cdecl call_4422e0(void *, void *);
extern "C" void call_512230(void *);

void __stdcall function_006444c0(void *a, void *b)
{
    char temporary[28];
    call_4422e0(temporary, b);
    call_512230((char *)a + 16);
}
