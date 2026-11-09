// from server: 100% by EspClaude
// roc 2009-06 005153c0
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Texture {
    int key;
    float x;
    float y;
    int w;

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
    if (y < other.y)
        return true;
    if (y > other.y)
        return false;
    return w < other.w;
}
