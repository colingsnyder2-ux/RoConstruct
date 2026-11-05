// from server: 90% by atomic.potato
struct SoundChannel
{
    int *vtable;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;

    void set();
};

void SoundChannel::set()
{
    vtable = (int *)0xb92dd4;
    field4 = 0xb92dcc;
    field18 = 0xb92dc0;
    field1C = 0xb92db4;
}
