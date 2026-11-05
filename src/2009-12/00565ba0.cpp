// from server: 85% by atomic.potato
extern "C" void sub_570790(void*, const char*, const char*, int);

struct S {
    void f(const char*, const char*);
};

void S::f(const char* a, const char* b)
{
    if (a != 0 && *a != 0 && b != 0)
        sub_570790((char*)this + 0xa40, a, b, 1);
}
