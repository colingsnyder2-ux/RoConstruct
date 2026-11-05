// from server: 27% by atomic.potato
struct S {
    void* field0;
    char field4;
    char pad5[3];
    int field8;
    S();
};

extern "C" void* __cdecl sub_98211a(unsigned int size);

S::S()
{
    field0 = sub_98211a(0x38);
    field4 = 0;
    field8 = 0;
}
