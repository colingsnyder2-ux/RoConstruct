// from server: 100% by atomic.potato
struct FirstPersonCommand
{
    unsigned char get() const;
};

extern "C" void* __cdecl sub_006e5640(int);

unsigned char FirstPersonCommand::get() const
{
    void* p = sub_006e5640(*(int*)((char*)this + 0x0c));
    if (p)
        return *(unsigned char*)((char*)p + 0x164);
    return 0;
}
