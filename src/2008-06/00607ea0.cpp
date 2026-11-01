// from server: 100% by colin
struct FaceMap {
    int lookup(int face);
};

struct Body {
    char reserved[0x9c];
    FaceMap* faces;
    int geometry;
};

struct Contact {
    int reserved0[2];
    int kind;
    int firstFace;
    int secondFace;
    int reserved1[3];
    int firstIndex;
    int secondIndex;
};

struct S {
    int reserved[3];
    Body* bodies[2];

    Contact* create(int first, int second, int kind, int firstIndex, int secondIndex);
    void f(int firstBody, int secondBody, int firstFace, int secondFace);
};

void S::f(int firstBody, int secondBody, int firstFace, int secondFace)
{
    int firstIndex = (firstFace % 2) * 3 + firstFace / 4;
    if (firstFace > 12)
        firstIndex = (firstIndex + 3) % 6;

    int secondIndex = (secondFace % 2) * 3 + secondFace / 4;
    if (secondFace > 12)
        secondIndex = (secondIndex + 3) % 6;

    Body* second = bodies[secondBody];
    Body* first = bodies[firstBody];
    int secondGeometry = second->geometry;
    int firstGeometry = first->geometry;

    Contact* contact = create(
        firstGeometry, secondGeometry, 6, firstIndex, secondIndex);

    int mappedSecond = bodies[secondBody]->faces->lookup(secondFace);
    int mappedFirst = bodies[firstBody]->faces->lookup(firstFace);

    contact->firstFace = mappedFirst;
    contact->firstIndex = firstIndex;
    contact->secondIndex = secondIndex;
    contact->secondFace = mappedSecond;
    contact->kind = 6;
}
