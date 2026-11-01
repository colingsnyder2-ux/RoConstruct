// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#pragma optimize("", off)

struct Mesh {
    int* data;
    int* element(int index);
};

int* Mesh::element(int index)
{
    do {} while (0);
    do {} while (0);
    return data + index;
}