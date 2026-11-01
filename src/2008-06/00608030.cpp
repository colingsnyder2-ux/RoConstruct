// from server: 100% by king_originala
struct Geometry {
    int reserved;
    float extent[3];
    int feature(int);
};

struct Primitive {
    char reserved[0x9c];
    Geometry* geometry;
    void* data;
};

struct Contact {
    char reserved0[8];
    int type;
    int feature0;
    int feature1;
    char reserved1[8];
    float extent;
    int face0;
    int face1;
    int value;
};

struct BlockBlockContact {
    char reserved0[12];
    Primitive* primitive[2];
    char reserved1[0x60];
    int value;

    Contact* create(void*, void*, int, int, int);
    void build(int, int, int, int);
};

void BlockBlockContact::build(int first, int second, int feature0, int feature1)
{
    int face0 = (feature0 % 2) * 3 + feature0 / 4;
    if (feature0 > 12)
        face0 = (face0 + 3) % 6;

    int face1 = (feature1 % 2) * 3 + feature1 / 4;
    if (feature1 > 12)
        face1 = (face1 + 3) % 6;

    Primitive* primitive1 = primitive[second];
    Primitive* primitive0 = primitive[first];
    void* data1 = primitive1->data;
    void* data0 = primitive0->data;
    Contact* contact = create(data0, data1, 5, face0, face1);

    struct Saved {
        int value;
        float extent;
    } saved;

    Geometry* geometry0 = primitive[first]->geometry;
    saved.extent = geometry0->extent[face0 % 3];
    saved.value = value;
    int id1 = primitive[second]->geometry->feature(feature1);
    int id0 = geometry0->feature(feature0);

    contact->feature0 = id0;
    contact->extent = saved.extent;
    contact->feature1 = id1;
    contact->face0 = face0;
    contact->face1 = face1;
    contact->value = saved.value;
    contact->type = 5;
}
