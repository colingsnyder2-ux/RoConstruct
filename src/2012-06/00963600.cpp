// from server: 95% by atomic.potato
extern "C" void __cdecl sub_00954e80(void*);
extern "C" void __cdecl sub_007bb970(void*);

struct EdgeStage
{
    void f(unsigned int);
};

void EdgeStage::f(unsigned int value)
{
    sub_00954e80((void*)value);
    sub_007bb970((void*)value);
}
