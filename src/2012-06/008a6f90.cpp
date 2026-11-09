// from server: 65% by atomic.potato
extern "C" int sub_495f40(void *);
extern "C" void * __cdecl sub_983b6a(int);

struct TToolVerb
{
    char pad[12];
    void *field_0c;
    int f();
};

TToolVerb *global_00dec790 = (TToolVerb *)0x00dec790;

int TToolVerb::f()
{
    int value = sub_495f40((void *)((char *)field_0c + 0xac4));
    if (value)
    {
        void *converted = sub_983b6a(value);
        return ((int (__thiscall *)(void *, void *))0xb229ec)(global_00dec790, converted);
    }
    return 0;
}
