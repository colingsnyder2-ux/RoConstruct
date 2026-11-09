// from server: 97% by atomic.potato
extern "C" void __cdecl sub_532d80(void*, void*);
struct S
{
    void sub_52b060(void*);
};
void* f(void* a, void* b)
{
    sub_532d80(b, a);
    ((S*)a)->sub_52b060((char*)b + 4);
    return a;
}
