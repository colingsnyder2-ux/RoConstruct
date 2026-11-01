// from server: 100% by king_originala
struct Result {
    unsigned int reserved;
    unsigned int first;
    unsigned int second;
    unsigned char flag;
};

struct ProductPart {
    void finish();
};

struct Product {
    unsigned char padding[16];
    ProductPart part;
};

struct S {
    Product& createProduct(unsigned int source, Result* result,
                           unsigned int* value, unsigned int option,
                           unsigned int zero);
    Result* f(Result* result, unsigned int source,
              unsigned int option, unsigned int value);
};

Result* S::f(Result* result, unsigned int source,
             unsigned int option, unsigned int value)
{
    volatile unsigned int zero = 0;
    if (source) {
        createProduct(source, result, &value, option, 0).part.finish();
        return result;
    }
    result->first = 0;
    result->second = 0;
    result->flag = 0;
    return result;
}
