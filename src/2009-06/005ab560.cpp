// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Mesh {
    unsigned int* data;
    unsigned int* get(unsigned int index);
};

#pragma optimize("", off)
unsigned int* Mesh::get(unsigned int index)
{
    do {
    } while (0);

    return data + index;
}