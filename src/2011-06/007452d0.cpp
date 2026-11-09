// from server: 69% by atomic.potato
struct AnimState {
    void f(float, float, float);
};

extern "C" float __stdcall sub_740ef0(float, float, float);
extern "C" void __stdcall sub_744b90(void*, float);

void AnimState::f(float a, float b, float c)
{
    float r = sub_740ef0(a, b, c);
    sub_744b90((void*)0xcd4fa8, r);
}
