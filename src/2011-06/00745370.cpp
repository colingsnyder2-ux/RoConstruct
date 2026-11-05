// from server: 62% by atomic.potato
extern "C" float __cdecl function_740ef0(float, float);

struct AnimationTrackState
{
    void f(float);
};

struct Context
{
    void g(AnimationTrackState *, float);
};

void AnimationTrackState::f(float value)
{
    float result = function_740ef0(value, value);
    ((Context *)0x00cd4ee8)->g(this, result);
}
