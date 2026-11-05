// from server: 75% by atomic.potato
extern void G1_func_00411f60(void*);

struct S {
    void f(void*);
};

void S::f(void* value)
{
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0xcc8) != value) {
        *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0xcc8) = value;
        G1_func_00411f60(reinterpret_cast<void*>(0x00ccaf38));
    }
}
