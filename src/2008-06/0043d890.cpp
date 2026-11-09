// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector3ComponentItem
{
    int value;
    int padding[75];
    int index;
    int f(int, int);
};
int Vector3ComponentItem::f(int a, int b)
{
    return *(float *)(a + index * 4) == *(float *)(b + index * 4);
}
