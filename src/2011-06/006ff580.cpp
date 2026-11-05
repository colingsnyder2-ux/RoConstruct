// from server: 76% by atomic.potato
typedef void *ObjectPtr;

extern "C" ObjectPtr __stdcall sub_004b17f0(ObjectPtr);

struct GeometryService_006ff580 {
    char pad0[148];
    ObjectPtr m_value;
    void f(ObjectPtr value);
};

void GeometryService_006ff580::f(ObjectPtr value)
{
    m_value = 0;
    if (value)
        m_value = sub_004b17f0(value);
}
