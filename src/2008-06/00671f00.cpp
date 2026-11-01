// from server: 100% by king_originala
struct Mesh;

extern unsigned short (__thiscall *getNumSubMeshes)(const Mesh*);
extern void* (__thiscall *getSubMesh)(const Mesh*, unsigned short);

struct MeshRef {
    void* control;
    Mesh* mesh;
};

struct Matrix {
    float elements[16];
};

struct RenderObject {
    char padding0[84];
    int m_x;
    char padding1[152];
    Matrix matrix;

    void f(int value);
    void setState(void* value);
};

struct Sink {
    void f(void* value);
};

struct S {
    char padding[0x98];
    Sink* sink;

    RenderObject* create();
    void f(const MeshRef& mesh, const Matrix& matrix, void* state);
};

void S::f(const MeshRef& mesh, const Matrix& matrix, void* state)
{
    for (int i = 0; i < getNumSubMeshes(mesh.mesh); ++i) {
        RenderObject* object = create();
        object->f((int)getSubMesh(mesh.mesh, (unsigned short)i));
        object->matrix = matrix;
        object->setState(state);
        sink->f(object);
    }
}
