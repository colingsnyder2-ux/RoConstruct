// from server: 66% by atomic.potato
typedef unsigned char byte;

extern "C" float __cdecl sub_006FE450(float, float, float);
extern "C" void __cdecl sub_00701600(int, void*);

struct VAnimationTrackState
{
    void __cdecl EventDesc(float a, float b, float c);
};

void __cdecl VAnimationTrackState::EventDesc(float a, float b, float c)
{
    float r = sub_006FE450(c, b, a);
    sub_00701600(0x00C22710, this);
    (void)r;
}
