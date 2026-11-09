// from server: 47% by Intel
struct VPlayers_BoundFuncDesc {
    int func();
};

extern "C" int __stdcall sub_550D30(int, int, int);

int VPlayers_BoundFuncDesc::func() {
    int v1;
    int v2 = sub_550D30(0, (int)this + 56, v1);
    int v3;
    if (v3) {
        int (__stdcall *callback)(int, int) = (int (__stdcall *)(int, int))*(int *)((int)this + 48);
        int v4 = *(int *)((int)this + 52);
        callback(v2, v4 + v3 - 28);
    } else {
        int (__stdcall *callback)(int, int) = (int (__stdcall *)(int, int))*(int *)((int)this + 48);
        int v4 = *(int *)((int)this + 52);
        callback(v2, v4);
    }
    return 0;
}
