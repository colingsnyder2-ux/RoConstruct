// from server: 94% by atomic.potato


struct MechToAssemblyStage
{
    int value0;
    int value4;
    MechToAssemblyStage* f(void*, void*);
void sub_0095e600(void*, void*);
};

MechToAssemblyStage* MechToAssemblyStage::f(void* a, void* b)
{
    sub_0095e600(b, a);
    value0 = 0x00c04320;
    value4 = 0x00c04314;
    return this;
}
