// from server: 75% by atomic.potato
struct S
{
    int value;
};

extern "C" S* __cdecl GetValue();
extern "C" int __cdecl CheckValue(S*, S*);

S* __cdecl FlagStandService(void* self, S* value)
{
    if (value && CheckValue(*(S**)((char*)value + 12), GetValue()))
        return (S*)((char*)value - 28);
    return 0;
}
