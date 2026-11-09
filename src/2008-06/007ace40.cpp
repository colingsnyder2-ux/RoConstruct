// from server: 100% by king_originala
struct Reference
{
    void* value;

    Reference(const Reference& other) : value(0) { assign(other.value); }
    ~Reference();
    void __thiscall assign(void*);
};

namespace Ogre
{
    struct MaterialPtr;
}

extern Ogre::MaterialPtr* (__thiscall *copyMaterialPtr)(
    Ogre::MaterialPtr*, const Ogre::MaterialPtr&);

namespace Ogre
{
    struct MaterialPtr
    {
        void* object;
        void* count;

        MaterialPtr(const MaterialPtr& other)
        {
            copyMaterialPtr(this, other);
        }

        ~MaterialPtr();
    };
}

struct MaterialBase
{
    virtual ~MaterialBase();
};

struct Material : MaterialBase
{
    unsigned char kind;
    Reference first;
    Reference second;
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;
    float g;
    Ogre::MaterialPtr material;

    Material(const Material&);
    virtual ~Material();
};

Material::Material(const Material& other)
    : kind(other.kind),
      first(other.first),
      second(other.second),
      a(other.a),
      b(other.b),
      c(other.c),
      d(other.d),
      e(other.e),
      f(other.f),
      g(other.g),
      material(other.material)
{
}
