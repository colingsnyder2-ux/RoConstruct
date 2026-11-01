// from server: 100% by colin
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

namespace RBX {
class TextureProxyBase {
public:
    virtual ~TextureProxyBase();
    char padding[52];
    volatile unsigned int value;
    unsigned int reserved;
};
}
struct Ref {
    RBX::TextureProxyBase* volatile p;
    Ref(RBX::TextureProxyBase*);
    Ref(const Ref&);
    ~Ref();
    void assign(RBX::TextureProxyBase*);
};

struct Vector3 {
    float x, y, z;
};

namespace RBX { namespace Render {
class TextureProxy : public TextureProxyBase {
public:
    Ref texture;
    Ref owner;
    Vector3 position;

    TextureProxy(Ref);
    Ref clone(const Vector3&, const Ref&);
};
} }

inline Ref::Ref(RBX::TextureProxyBase* object) : p(0) {
    assign(object);
}

Ref RBX::Render::TextureProxy::clone(const Vector3& vector, const Ref& source) {
    TextureProxyBase* src = source.p;
    TextureProxy* object = dynamic_cast<TextureProxy*>(src);
    TextureProxy* result = new TextureProxy(Ref(object));
    result->value = value;
    result->texture.assign(object);
    result->position.x = vector.x;
    result->position.y = vector.y;
    result->position.z = vector.z;
    result->owner.assign(this);
    return Ref(result);
}
