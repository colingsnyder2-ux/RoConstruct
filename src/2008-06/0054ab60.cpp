// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
#pragma optimize("", off)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Mesh {
    unsigned char storage[48];
    Mesh();
};

extern Mesh* mesh;

void __cdecl initializeMesh()
{
    mesh = new Mesh;
}
