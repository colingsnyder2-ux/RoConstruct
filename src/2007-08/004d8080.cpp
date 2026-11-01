// from server: 81% by colin
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
    if (z < other.z)
        return true;
    return false;
}
