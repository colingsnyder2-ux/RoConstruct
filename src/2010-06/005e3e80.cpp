// from server: 48% by atomic.potato
struct ClearStarterpack
{
    int pad;
    int value;
    void Clear();
};

extern "C" void clear_value(void *);
extern "C" void *get_object(void *);
extern "C" void release_object(void *);

void ClearStarterpack::Clear()
{
    void *value = (void *)this->value;
    clear_value(value);
    value = (void *)this->value;
    if (value != 0)
    {
        value = get_object(value);
        if (value != 0)
            release_object(value);
    }
}
