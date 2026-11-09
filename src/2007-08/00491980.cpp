// from server: 100% by colin
struct VPlayerListener {
    char pad[0x11c];
    int field_0x11c;
    int check();
};

extern "C" bool __cdecl sub_0049af30(VPlayerListener*, int);

int VPlayerListener::check()
{
    if (field_0x11c == 0)
    {
        if (!sub_0049af30(this, 1))
            return 0;
    }
    return 1;
}
