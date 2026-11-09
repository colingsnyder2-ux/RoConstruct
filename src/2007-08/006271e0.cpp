// from server: 100% by colin
struct GettingUp {
    char pad[8];
    void* field8;
    void construct(void*);
};

struct Other {
    void method1(void*);
    void method2(void*);
};

void GettingUp::construct(void* other)
{
    ((Other*)other)->method1(this);
    ((Other*)field8)->method2(other);
}
