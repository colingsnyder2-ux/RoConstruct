// from server: 100% by tajop
class TexturePtr {
public:
    __declspec(dllimport) TexturePtr(const TexturePtr& r);
private:
    char pad0[0x10];
};

struct ManualObject {
    TexturePtr tex;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    char f24;
    ManualObject(const ManualObject& other);
};

ManualObject::ManualObject(const ManualObject& other)
    : tex(other.tex), f10(other.f10), f14(other.f14), f18(other.f18),
      f1c(other.f1c), f20(other.f20), f24(other.f24)
{
}
