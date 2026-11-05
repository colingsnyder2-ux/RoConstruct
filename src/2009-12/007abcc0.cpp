// from server: 98% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl get_value(int);
struct C
{
    int check_value();
};

int S::f()
{
    int value = get_value(*(int*)((char*)this + 8));
    return ((C*)value)->check_value() ? 0 : -1;
}
