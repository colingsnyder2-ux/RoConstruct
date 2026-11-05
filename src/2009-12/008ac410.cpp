// from server: 91% by atomic.potato
extern "C" int sub_009265f2(int);
extern "C" int sub_007f3c3e(int);

struct S {
    int f();
};

int S::f()
{
    int value = sub_009265f2(*(int*)((char*)this + 0xf8) + 0xcc);
    value = sub_007f3c3e(value);
    if (value)
        return *(int*)((char*)value + 0xe8);
    return 0;
}
