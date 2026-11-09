// from server: 100% by EspClaude
// roc 2007-08 004450d0  GetSetImpl<CRenderSettings,int>-style setter: float value -> (obj->*set)((int)v)
struct DescribedBase0 { int a; };
struct DescribedBase { int b; };
class CRenderSettings : public DescribedBase0, public DescribedBase {
public:
    void setInt(int);
};

struct GetSetImpl {
    char pad[0x10];
    void (CRenderSettings::*set)(int);
    void setValue(DescribedBase* object, const float& value);
};

void GetSetImpl::setValue(DescribedBase* object, const float& value)
{
    CRenderSettings* o = static_cast<CRenderSettings*>(object);
    (o->*set)((int)value);
}
