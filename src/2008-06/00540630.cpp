// from server: 100% by king_originala
struct Bucket;

struct Result {
    void initialize(void* value, Bucket* owner);
};

struct Bucket {
    unsigned char padding[12];
    void* value;
    Result* f(Result* result);
};

#pragma optimize("", off)
Result* Bucket::f(Result* result)
{
    result->initialize(value, this);
    return result;
}
#pragma optimize("", on)
