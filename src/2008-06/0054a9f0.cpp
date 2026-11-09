// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
#pragma optimize("g", off)

struct First {
    char data[12];
    First();
    ~First();
};

struct Array {
    char data[12];
    Array();
    ~Array();
};

struct Third {
    char data[12];
    Third();
    ~Third();
};

struct IteratorBase {
    unsigned int value;
    IteratorBase();
};

struct Mesh {
    First first;
    Array second;
    Third third;
    Array fourth;
    IteratorBase fifth;

    Mesh();
};

Mesh::Mesh()
{
}
