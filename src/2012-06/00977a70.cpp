// from server: 96% by atomic.potato
struct VCEvent {
    char pad0[0x9c];
    int field_9c;
    char pad1[0x10];
    int field_b0;
    int field_b4;
    int* sub_9756f0(int* out);
    void func();
};

void VCEvent::func()
{
    int tmp[2];
    field_9c = 1;
    int* p = sub_9756f0(tmp);
    field_b0 = p[0];
    field_b4 = p[1];
}
