// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Geometry {
    virtual void slot0();
    virtual void slot1();
    virtual int getType();
};

struct Primitive {
    char padding[0x9c];
    Geometry* geometry;
};

struct Contact1 {
    char storage[0x38];
    Contact1(Primitive*, Primitive*);
};

struct Contact2 {
    char storage[0x38];
    Contact2(Primitive*, Primitive*);
};

struct Contact3 {
    char storage[0x7c];
    Contact3(Primitive*, Primitive*);
};

void* __stdcall createContact(Primitive* first, Primitive* second)
{
    int firstType = first->geometry->getType();
    int secondType = second->geometry->getType();

    if (firstType > secondType) {
        Primitive* temp = first;
        first = second;
        second = temp;
    }

    firstType = first->geometry->getType();
    secondType = second->geometry->getType();

    switch (firstType) {
    case 1:
        switch (secondType) {
        case 1:
            return new Contact1(first, second);
        case 2:
            return new Contact2(first, second);
        }
    case 2:
        return new Contact3(first, second);
    default:
        return 0;
    }
}
