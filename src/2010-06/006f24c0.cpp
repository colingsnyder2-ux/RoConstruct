// from server: 100% by tester
struct VPlayers_BoundFuncDesc {
    int getSomething();
};

extern void G1_func_006f1f70();

int VPlayers_BoundFuncDesc::getSomething()
{
    G1_func_006f1f70();
    int* p = *(int**)((char*)this + 0x94);
    return *(short*)((char*)p + 0xa8);
}
