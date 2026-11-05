// from server: 100% by EspClaude
// roc 2007-08 00445090  GetSetImpl<CRenderSettings,int>-style getter: (float)(obj->*get)()
struct DescribedBase0 { int a; };
struct DescribedBase { int b; };
class CRenderSettings : public DescribedBase0, public DescribedBase {
public:
    int getInt() const;
};

struct GetSetImpl {
    char pad[8];
    int (CRenderSettings::*get)() const;
    float getValue(const DescribedBase* object) const;
};

float GetSetImpl::getValue(const DescribedBase* object) const
{
    const CRenderSettings* o = static_cast<const CRenderSettings*>(object);
    return (float)(o->*get)();
}
