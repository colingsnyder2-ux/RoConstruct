// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Mesh {
    int value;
    int f(int offset);
};

#pragma optimize("", off)
int Mesh::f(int offset)
{
    do {} while (0);
    do {} while (0);
    return value + offset;
}
#pragma optimize("", on)