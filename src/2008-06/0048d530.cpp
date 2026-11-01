// from server: 100% by king_originala
union FunctionBuffer {
    double alignment;
    char storage[24];
};

struct FunctionTable {
    void (__cdecl *manager)(FunctionBuffer*, FunctionBuffer*, int);
};

struct Function {
    FunctionTable* table;
    FunctionBuffer buffer;

    Function(const Function&);
    ~Function();
};

__forceinline Function::~Function()
{
    if (table) {
        void (__cdecl *manager)(FunctionBuffer*, FunctionBuffer*, int) =
            table->manager;
        if (manager)
            manager(&buffer, &buffer, 1);
    }
}

Function __cdecl copyFunction(Function value)
{
    return value;
}
