// from server: 100% by colin
struct SoundChannel
{
    void sub_00588c50();
    void sub_0057aa50(int, int);
    void sub_00588cd0(int, int);
};

void SoundChannel::sub_00588cd0(int a, int b)
{
    sub_00588c50();
    sub_0057aa50(a, b);
}
