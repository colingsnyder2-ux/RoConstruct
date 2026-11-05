// from server: 100% by atomic.potato
extern "C" int __cdecl sub_6a17c6(void*, void*, void*, void*, void*);

int __stdcall f(void* value)
{
    int result = sub_6a17c6(value, 0, (void*)0x92907c, (void*)0x92ac78, 0);
    return result != 0;
}
