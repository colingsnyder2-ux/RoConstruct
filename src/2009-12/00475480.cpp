// from server: 46% by atomic.potato
struct DxUserInput {
    void sub_4752E0(int, void*);
    int sub_475480(int);
};

extern "C" int __stdcall sub_98DEB8(void*, const char*);
extern "C" int __stdcall sub_98DEC0(void*);

int DxUserInput::sub_475480(int a)
{
    int local = 0;
    sub_98DEB8(&local, "FileVersion");
    int tmp = 0;
    sub_4752E0(a, &tmp);
    sub_98DEC0(&local);
    return a;
}
