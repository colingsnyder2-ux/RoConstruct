// from server: 100% by tester
struct CPropertyGridItemBrickColor
{
    void sub_00671CC0(int* pt, int* local);
    int* method(int* pt);
};

extern "C" int (__stdcall *GetCursorPos)(int* lpPoint);

int* CPropertyGridItemBrickColor::method(int* pt)
{
    int local[2];
    GetCursorPos(local);
    sub_00671CC0(pt, local);
    return pt;
}
