// from server: 50% by atomic.potato
struct CIDEDocManager
{
    char padding[36];
    void *value;

    void Get(void **result, void *a, void *b, void *value);
};

void CIDEDocManager::Get(void **result, void *a, void *b, void *value)
{
    if (value == 0)
        value = this->value;
    result[5] = value;
}
