// from server: 100% by tester
struct CPropertyGridItemBrickColor
{
    char pad[0x20];
    void* field_20;
};

void __stdcall func_00671b80(void* dst, void* src);

void* __stdcall func_00671bc0(void* dst, CPropertyGridItemBrickColor* src)
{
    void* value;
    if (src == 0)
        value = 0;
    else
        value = src->field_20;
    func_00671b80(dst, value);
    return dst;
}
