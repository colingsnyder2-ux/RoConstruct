// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
namespace G3D {
template <class T>
class Array {
private:
    T* data;
    int num;
    int numAllocated;
    void resize(int n);
    void init(int n, int a) {
        this->num = 0;
        this->numAllocated = 0;
        data = 0;
        if (a > 0) {
            resize(n);
        } else {
            data = 0;
        }
    }
public:
    Array() { init(0, 0); }
    ~Array();
};
}
namespace RBX {
class Primitive;
class ContactConnector;
class Contact
{
public:
    Contact(Primitive* p0, Primitive* p1);
    virtual ~Contact();
    char pad[0x34 - 4];
};
class BlockBlockContact : public Contact
{
public:
    BlockBlockContact(Primitive* p0, Primitive* p1);
    virtual ~BlockBlockContact();
private:
    G3D::Array<ContactConnector*> connectors; // 0x34
    G3D::Array<ContactConnector*> matched;    // 0x40
    int unk4c;                                // 0x4c
    int unk50;                                // 0x50
    float overlap;                            // 0x54
    int separatingAxisId;                     // 0x58
    int separatingBodyId;                     // 0x5c
    int bodyId;                               // 0x60
    int feature[2];                           // 0x64
};
BlockBlockContact::BlockBlockContact(Primitive* p0, Primitive* p1)
    : Contact(p0, p1), overlap(1e9f), separatingAxisId(0), bodyId(0)
{
    feature[0] = -1;
    feature[1] = -1;
    unk4c = 0;
    unk50 = 0;
}
}
