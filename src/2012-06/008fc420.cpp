// from server: 33% by Intel
extern "C" void __stdcall G1_func_008fc030(int, int, int);

struct VAnimationTrackState
{
    int EventDesc(int, int, int);
};

int VAnimationTrackState::EventDesc(int a1, int a2, int a3)
{
    int v3 = a1;
    *(int*)(&a1) = 0;
    if (!v3)
    {
        *(int*)a2 = 0;
        return 0;
    }

    int v4 = *(int*)((char*)this + 0x2C);
    int v5 = a2;
    v3 -= 0x1C;
    G1_func_008fc030(v4 + v3, v5, a3);
    return v5;
}
