// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Texture {
    int key;
    float x;
    float y;

    bool f(const Texture& other);
};

bool Texture::f(const Texture& other)
{
    if (key < other.key)
        return true;
    if (key > other.key)
        return false;
    if (x < other.x)
        return true;
    if (x > other.x)
        return false;
    return y < other.y;
}
