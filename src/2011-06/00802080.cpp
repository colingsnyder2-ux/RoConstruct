// from server: 27% by atomic.potato
struct S {
    void* field0;
    char field4;
    char pad5[3];
    int field8;
    S();
};

extern "C" void* __cdecl sub_80a05e(unsigned int size);

S::S()
{
    void* p = sub_80a05e(0x38);
    field0 = p;
    field4 = 0;
    field8 = 0;
}
