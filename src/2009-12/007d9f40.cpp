// from server: 55% by atomic.potato
extern "C" int __cdecl f();

extern "C" void __fastcall g(void *, void *, void *, int);

void __stdcall func_007d9f40(void *value)
{
    int result = f();
    g(value, (void *)0x7d9d90, value, result);
}
