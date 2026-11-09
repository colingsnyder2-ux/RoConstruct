// from server: 100% by king_originala
struct Part {
    char padding[0x1F0];
    bool locked;
};

struct Hit {
    char padding[4];
    int face;
};

struct Decal {
    void setPart(Part*);
    void setFaceId(int);
};

struct DecalTool {
    char padding[0x48];
    Decal* decal;

    Hit* findHit(Part*, Part**, int*);
    void update(Part*);
};

void DecalTool::update(Part* part)
{
    int auxiliary;
    Hit* hit = findHit(part, &part, &auxiliary);

    if (part && decal && hit && !part->locked) {
        decal->setPart(part);
        decal->setFaceId(hit->face);
    } else {
        if (decal)
            decal->setPart(0);
    }
}
