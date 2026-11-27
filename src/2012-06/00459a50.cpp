// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
struct XItem
{
    float value;
    unsigned short type;
    int __stdcall equals(const XItem& other) const;
};
int __stdcall XItem::equals(const XItem& other) const
{
    if (value == other.value && type == other.type)
        return 1;
    return 0;
}