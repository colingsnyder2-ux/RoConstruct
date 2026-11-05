// from server: 100% by colin
struct CXTPDialogBar_CControlCaptionPopup
{
    int sub_0071dec0(int);
};

extern "C" int __stdcall sub_00670f70();

int CXTPDialogBar_CControlCaptionPopup::sub_0071dec0(int a)
{
    if (*(int *)((char *)this + 0x178) != 0)
        return ((int (__thiscall *)(CXTPDialogBar_CControlCaptionPopup *, int))sub_00670f70)(this, a);
    return 1;
}
