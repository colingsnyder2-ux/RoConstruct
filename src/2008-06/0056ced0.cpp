// from server: 100% by king_originala
struct Type
{
    unsigned char data[16];
    Type(const char*, const void*);
    ~Type();
};

const Type& singleton()
{
    static Type instance(
        reinterpret_cast<const char*>(0x0082F6C8),
        reinterpret_cast<const void*>(0x00931034));
    return instance;
}
