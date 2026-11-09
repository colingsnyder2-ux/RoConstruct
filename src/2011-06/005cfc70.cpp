// from server: 83% by atomic.potato
struct Inner {
    int value;
};

struct Outer {
    char pad0[0x68];
    Inner* begin;
    Inner* end;
    int get(int);
};

extern "C" Inner* __cdecl helper(int);

int Outer::get(int index)
{
    Inner* p = helper(index);
    int v = p->value;
    if (v < 0)
        return 0;
    int count = (int)((char*)end - (char*)begin) >> 2;
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v].value;
}
