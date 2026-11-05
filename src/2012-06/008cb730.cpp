// from server: 97% by atomic.potato
struct RBX_VPartInstance_EventDesc {
    char pad[0x2ec];
    int field_2ec;
    void set(int);
};

extern "C" void __cdecl sub_414da0(void *);

void RBX_VPartInstance_EventDesc::set(int value)
{
    field_2ec = value;
    sub_414da0((void *)0xe35f48);
}
