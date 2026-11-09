// from server: 42% by atomic.potato
struct S
{
    int f(int*, int*);
};

int S::f(int* out, int* value)
{
    int* p = value ? value - 7 : 0;
    int (*fn)(int*) = *(int (**)(int*))((char*)this + 8);
    int base = *(int*)((char*)this + 12);
    int result = fn((int*)((char*)this + base + (int)p));
    *out = *(int*)result;
    return 0;
}
