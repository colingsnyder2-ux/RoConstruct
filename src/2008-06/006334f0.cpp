// from server: 100% by king_originala
struct Result
{
    int value;
};

struct S
{
    int unused[2];
    int offset;
    Result f(void* object);
};

Result S::f(void* object)
{
    char* base = object ? static_cast<char*>(object) - 20 : 0;
    Result result;
    result.value = *reinterpret_cast<int*>(base + offset);
    return result;
}
