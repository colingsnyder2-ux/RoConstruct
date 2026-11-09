// from server: 28% by atomic.potato
struct Slot {
    char pad[0xc];
    void sub_6c16f0(int);
};

void __stdcall target(Slot* self, int arg)
{
    self->sub_6c16f0(arg);
}
