// from server: 100% by king_originala
struct Texture {
    unsigned long value;
    Texture(const Texture& other);
};

struct S {
    unsigned char first;
    unsigned char second;
    float scalar;
    Texture texture;

    S(const S& other);
};

#pragma optimize("", off)
S::S(const S& other)
    : first(other.first),
      second(other.second),
      scalar(other.scalar),
      texture(other.texture)
{
}
#pragma optimize("", on)
