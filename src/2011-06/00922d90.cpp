// from server: 42% by atomic.potato
struct S
{
    int vtable;
    int value;
    int pad;
    int offset;

    int __cdecl operator()(int value);
};

int S::operator()(int value)
{
    return offset + value;
}
