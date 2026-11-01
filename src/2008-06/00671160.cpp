// from server: 100% by king_originala
struct Mesh;
struct String;

extern void (__thiscall *destroyMesh)(Mesh *);
extern void (__thiscall *destroyString)(String *);

struct Mesh {
    char data[28];
    ~Mesh();
};

struct String {
    char data[12];
    ~String();
};

inline Mesh::~Mesh()
{
    destroyMesh(this);
}

inline String::~String()
{
    destroyString(this);
}

struct Value {
    Mesh mesh;
    String string;
};

struct Node {
    Node *left;
    Node *parent;
    Node *right;
    char data[40];
    unsigned char color;
    unsigned char nil;
};

void __cdecl operator delete(void *) throw();

struct S {
    void clear(Node *);
};

void S::clear(Node *node)
{
    Node *current = node;
    for (; !current->nil; node = current) {
        clear(current->right);
        current = current->left;
        reinterpret_cast<Value *>(node->data)->~Value();
        operator delete(node);
    }
}
