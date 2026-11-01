// from server: 100% by king_originala
struct Callback {
    void apply(void* source, void* destination);
};

struct Result {
    char prefix[0x24];
    char value;
};

struct S {
    char prefix[0x130];
    char value[0x34];
    Callback* callback;

    void prepare();
    void populate(Result* result);
    Result* get(Result* result);
};

Result* S::get(Result* result)
{
    prepare();
    populate(result);
    if (callback)
        callback->apply(value, &result->value);
    return result;
}
