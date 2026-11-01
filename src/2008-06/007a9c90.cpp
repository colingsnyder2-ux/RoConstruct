// from server: 100% by king_originala
struct Vertex {
    float x, y, z;
};

struct Exception {
    void* vtable;
    char* message;
    int owned;
};

extern Vertex* vertices;
extern int vertexCount;
extern void (__thiscall *exceptionConstructor)(Exception*, const char* const&);
extern unsigned char exceptionType;

extern "C" __declspec(noreturn)
void __stdcall throwException(void*, void*);

Vertex* __stdcall getVertex(int index)
{
    if (index >= 0 && index < vertexCount)
        return vertices + index;

    Exception error;
    const char*& message = reinterpret_cast<const char*&>(index);
    message = "RBX Mesh::getVertex() index out of range";
    exceptionConstructor(&error, message);
    throwException(&error, &exceptionType);
}
