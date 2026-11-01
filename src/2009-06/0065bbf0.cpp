// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace G3D { class Vector3 { public: float x, y, z;
    Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {} }; }
class Part {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual int getFormFactor() const;
    G3D::Vector3 toUiSize(const G3D::Vector3& size) const;
};
G3D::Vector3 Part::toUiSize(const G3D::Vector3& size) const
{
    G3D::Vector3 answer(size);
    switch (getFormFactor()) {
    case 1:
        answer.y = size.y * 0.8333333f;
        break;
    case 2:
        answer.y = size.y * 2.5f;
        break;
    }
    return answer;
}
