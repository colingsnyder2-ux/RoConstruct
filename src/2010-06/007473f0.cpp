// from server: 61% by atomic.potato
struct D6Link
{
    int get();
};

extern "C" int __cdecl sub_750b10(int);

int D6Link::get()
{
    int value = *(int *)((char *)this + 4);
    if (value != 0)
        return sub_750b10(*(int *)((char *)value + 0x2c));
    return 0;
}
