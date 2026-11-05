// from server: 59% by atomic.potato
struct RBX_TreeStage
{
    void dummy(void*);
};

extern "C" void* __cdecl sub_006a1db0(void*);
extern "C" void __cdecl sub_006dc360(void*, void*, void*);

void RBX_TreeStage::dummy(void* value)
{
    sub_006dc360(value, this, sub_006a1db0(value));
}
