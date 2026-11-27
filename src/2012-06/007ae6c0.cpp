// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
struct Element {
    void* px;
    void* pn;
    ~Element();
};
struct ElementArray {
    Element* px;
    ~ElementArray();
};
ElementArray::~ElementArray()
{
    delete[] px;
}
}