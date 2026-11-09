// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
inline void* operator new(unsigned int, void* p) { return p; }
namespace G3D {
template<class T> class Array {
    T* data; int num; int numAllocated;
public:
    int size() const { return num; }
    T& operator[](int n) { return data[n]; }
    bool inArray(const T* p) { return (p >= data) && (p < data + num); }
    void resize(int n, bool shrinkIfNecessary = true);
    void append(const T& value) {
        if (num < numAllocated) {
            new (data + num) T(value);
            ++num;
        } else if (inArray(&value)) {
            T tmp = value;
            append(tmp);
        } else {
            resize(num + 1, false);
            data[num - 1] = value;
        }
    }
    void push_back(const T& v) { append(v); }
};
}
namespace RBX { namespace Render {
class Material {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual float reflect() const;
    virtual float transparent() const;
};
struct RenderSurface { char pad[0x34]; Material* material; char pad2[0x44 - 0x38]; };
class RenderScene {
public:
    char pad[0x28];
    G3D::Array<RenderSurface> proxyArray;
    G3D::Array<RenderSurface*> diffuseProxyArray;
    G3D::Array<RenderSurface*> reflectProxyArray;
    G3D::Array<RenderSurface*> transparentProxyArray;
    void classifyProxies();
};
void RenderScene::classifyProxies()
{
    for (int i = 0; i < proxyArray.size(); i++)
    {
        RenderSurface* ptr = &proxyArray[i];
        if (ptr->material)
        {
            if (ptr->material->transparent() > 0.0f)
            {
                transparentProxyArray.push_back(ptr);
            }
            else
            {
                diffuseProxyArray.push_back(ptr);
                if (ptr->material->reflect() > 0.0f)
                    reflectProxyArray.push_back(ptr);
            }
        }
    }
}
}}
