// from server: 100% by king_originala
struct Normal {
    float x, y, z;
};

struct ExceptionObject {
    void* vtable;
    const char* message;
    int owned;
};

extern Normal* normals;
extern int normalCount;

typedef void (__thiscall *ExceptionConstructor)(
    ExceptionObject*, const char* const&);

extern ExceptionConstructor constructException;
extern unsigned char exceptionTypeInfo;

extern "C" __declspec(noreturn) void __stdcall
throwException(void*, void*);

Normal* __stdcall getNormal(int index)
{
    if (index >= 0 && index < normalCount)
        return normals + index;

    ExceptionObject error;
    index = reinterpret_cast<int>("RBX Mesh::getNormal() index out of range");
    constructException(
        &error, *reinterpret_cast<const char* const*>(&index));
    throwException(&error, &exceptionTypeInfo);
}
