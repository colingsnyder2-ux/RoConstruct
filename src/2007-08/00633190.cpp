// from server: 100% by colin
struct MyXTPCommandBars
{
    void sub_006A40E0(int, unsigned int);
};

extern "C" MyXTPCommandBars* __cdecl sub_006325E0();

void __stdcall sub_00633190(unsigned int a1)
{
    MyXTPCommandBars* p = sub_006325E0();
    if (p)
        p->sub_006A40E0(a1, 0x81);
}
