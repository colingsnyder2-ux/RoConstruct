// from server: 29% by Intel
extern "C" int __cdecl func_005c9fe8(int, const char*, int);
extern "C" int __cdecl func_00511180(void*);
extern "C" int __cdecl func_008f7fb0(int, float, float);
extern "C" int __cdecl func_008fa700(void*, void*);

struct VAnimationTrackState
{
    void EventDesc(float a, float b);
};

void VAnimationTrackState::EventDesc(float a, float b)
{
    char* g = (char*)0x00e580e1;
    if (*g != 0)
    {
        func_005c9fe8((int)(unsigned char)*g, (const char*)0x00b44e9c, 0);
    }
    int local = 0;
    while (func_008fa700(this, &local))
    {
        func_008f7fb0(local, a, b);
    }
    func_00511180(&local);
}
