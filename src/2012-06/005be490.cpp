// from server: 100% by Viper
struct RakPeer
{
    int f(int param);
};

extern "C" int __stdcall func(int, int, int);

int RakPeer::f(int param)
{
    return func(param, 0xb804a8, 0x9fd);
}
