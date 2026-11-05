// from server: 58% by atomic.potato
extern "C" void BasicStringCtor(void *, const char *);

struct DeleteSelectionVerb
{
    DeleteSelectionVerb *f(const char *);
};

DeleteSelectionVerb *DeleteSelectionVerb::f(const char *value)
{
    char storage[28];
    BasicStringCtor(storage, value);
    *reinterpret_cast<unsigned long **>(this) =
        reinterpret_cast<unsigned long *>(0x009cfeac);
    return this;
}
