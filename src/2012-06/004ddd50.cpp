// from server: 100% by tajop
class TexturePtr {
public:
    __declspec(dllimport) TexturePtr(const TexturePtr& r);
private:
    char pad0[0x10];
};

struct S
{
    float x;
    float y;
    TexturePtr texture;
    S(const S& value);
};

S::S(const S& value)
    : x(value.x), y(value.y), texture(value.texture)
{
}
