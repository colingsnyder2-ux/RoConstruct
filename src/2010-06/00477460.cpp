// from server: 27% by colin
struct CTa {
    char pad[0x378];
    int field_378;
    void sub_7cc5e0();
    void sub_7a8150();
    CTa* func_00477460();
};

void CTa::sub_7cc5e0() {}
void CTa::sub_7a8150() {}

CTa* CTa::func_00477460()
{
    sub_7cc5e0();
    field_378 = 0;
    *(int*)this = 0xa1245c;
    sub_7a8150();
    return this;
}
