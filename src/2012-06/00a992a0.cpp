// from server: 43% by atomic.potato
extern "C" void sub_983144(void);
extern "C" void basic_string_destructor(void *);

struct S {
    void f();
};

void S::f()
{
    sub_983144();
    basic_string_destructor((char *)this - 0x50);
}
