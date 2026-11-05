// from server: 62% by atomic.potato
struct S
{
    void* field0C;
    void f();
};

extern "C" void __stdcall sub_5e0c40(void*);
extern "C" void __stdcall sub_607920(void*);

void S::f()
{
    void* value = field0C;
    sub_5e0c40(value);
    sub_607920(*(void**)((char*)field0C + 0xaa0));
}
