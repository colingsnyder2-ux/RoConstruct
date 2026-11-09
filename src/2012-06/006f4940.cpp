// from server: 73% by atomic.potato
extern "C" void __cdecl sub_403480(int);

struct CameraVerb
{
    int __cdecl f(int);
};

int CameraVerb::f(int value)
{
    sub_403480(value);
    return value;
}
