// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Product
{
    char storage[36];
    Product(void* arg);
};

struct FactoryProduct
{
    Product* product;
    FactoryProduct(void* arg);
};

FactoryProduct::FactoryProduct(void* arg)
{
    product = new Product(arg);
}
