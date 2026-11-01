// from server: 100% by king_originala
struct CaptionPart
{
    void func_00420bd0();
};

struct CSelectionCaption
{
    char padding[0x190];
    CaptionPart caption;

    int func_006a0c68();
    int func_00465e00(void *);
};

int CSelectionCaption::func_00465e00(void *)
{
    int result = func_006a0c68();
    if (result == -1)
        return result;

    caption.func_00420bd0();
    return 0;
}
