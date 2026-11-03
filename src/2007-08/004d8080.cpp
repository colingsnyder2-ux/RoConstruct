// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
struct Texture {
    int x;
    float y;
    float z;
    bool lessThan(const Texture& other) const;
};
bool Texture::lessThan(const Texture& other) const
{
    if (x < other.x)
        return true;
    if (x > other.x)
        return false;
    if (y < other.y)
        return true;
    if (y > other.y)
        return false;
    return z < other.z;
}
