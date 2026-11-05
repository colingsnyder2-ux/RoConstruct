// from server: 25% by atomic.potato
extern "C" void __cdecl sub_004f4f70(void*);

struct S
{
    S(void*);
};

S::S(void* p)
{
    sub_004f4f70(p);
}
