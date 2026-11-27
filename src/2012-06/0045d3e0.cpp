// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast

struct Vector3ComponentItem
{
    int padding[74];
    int offset;
    int equals(const float *, const float *);
};
int Vector3ComponentItem::equals(const float *a, const float *b)
{
    return a[offset] == b[offset];
}
