// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
#pragma optimize("", off)

struct Base {
    char data[0x20];
    Base();
    ~Base();
};

struct Member {
    char data[0x0C];
    Member();
};

struct Mesh : Base {
    unsigned int value;
    Member member;
    Mesh();
};

Mesh::Mesh()
{
    value = 0;
}
