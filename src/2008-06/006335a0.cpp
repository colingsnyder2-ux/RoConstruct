// from server: 100% by king_originala
struct Error
{
    char data[40];
    Error();
    ~Error();
};

extern __declspec(noreturn) void throw_error(const Error&);

struct Matrix
{
    float data[9];
    Matrix(const Matrix&);
};

struct Value
{
    Matrix rotation;
    float x;
    float y;
    float z;
};

struct FunctionTable
{
    void (__cdecl *first)();
    void (__cdecl *invoke)(void*, Value);
};

struct S
{
    FunctionTable* table;
    unsigned int reserved;
    char storage[1];

    void f(Value value);
};

void S::f(Value value)
{
    if (table == 0)
        throw_error(Error());

    table->invoke(storage, value);
}
