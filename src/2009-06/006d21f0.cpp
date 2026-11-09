// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class __declspec(novtable) IndexedTree {
public:
    IndexedTree();
    virtual ~IndexedTree();
    int a, b, c, d, e;
};
class IndexedMesh : public IndexedTree {
public:
    IndexedMesh();
    virtual ~IndexedMesh();
    void* first;
    void* last;
    void* end;
};
IndexedMesh::IndexedMesh() : first(0), last(0), end(0) {}
}
