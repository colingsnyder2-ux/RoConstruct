// from server: 63% by king_originala
struct TextureProxy
{
    void first();
    void second();
    ~TextureProxy();
};

TextureProxy::~TextureProxy()
{
    first();
    second();
}
