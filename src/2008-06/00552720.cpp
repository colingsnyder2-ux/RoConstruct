// from server: 100% by king_originala
struct Texture {
    unsigned int value;
    Texture(const Texture&);
    ~Texture();
};

struct AggregateChunk {
    char padding[44];
    Texture texture;
    Texture getTexture();
};

#pragma optimize("", off)
Texture AggregateChunk::getTexture()
{
    return texture;
}
#pragma optimize("", on)
