// from server: 28% by atomic.potato
struct Slot {
    char pad[12];
    void sub_72F230(int);
};

void __stdcall target(Slot* self, int arg)
{
    self->sub_72F230(arg);
}
