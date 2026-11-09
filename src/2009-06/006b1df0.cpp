// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void __cdecl assertFail(const char*);
struct Primitive {
    int getGeometryType() const;
};
struct Contact { };
struct BlockBlockContact : Contact {
    char storage[0x38];
    BlockBlockContact(Primitive*, Primitive*);
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct BallBlockContact : Contact {
    char storage[0x38];
    BallBlockContact(Primitive*, Primitive*);
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct BallBallContact : Contact {
    char storage[0x7c];
    BallBallContact(Primitive*, Primitive*);
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
class ContactManager {
public:
    Contact* createContact(Primitive* p0, Primitive* p1);
};
Contact* ContactManager::createContact(Primitive* p0, Primitive* p1)
{
    int type0 = p0->getGeometryType();
    int type1 = p1->getGeometryType();
    if (type0 > type1) {
        Primitive* t = p0;
        p0 = p1;
        p1 = t;
    }
    type0 = p0->getGeometryType();
    type1 = p1->getGeometryType();
    switch (type0) {
    case 1:
        switch (type1) {
        case 1:
            return new BlockBlockContact(p0, p1);
        case 2:
            return new BallBlockContact(p0, p1);
        }
    case 2:
        return new BallBallContact(p0, p1);
    default:
        assertFail("ContactManager::createContact");
        return 0;
    }
}
