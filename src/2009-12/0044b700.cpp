// from server: 64% by atomic.potato
struct CIDEDocManager
{
    char padding[36];
    void *value;
    void *get(void *);
};

void *CIDEDocManager::get(void *value)
{
    if (value == 0)
        value = this->value;
    return value;
}
