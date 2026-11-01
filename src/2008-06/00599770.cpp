// from server: 100% by king_originala
struct Face {
    int getType();
    bool isActive();
};

struct Faces {
    Face* get(int index);
};

struct Part {
    char padding[196];
    Faces faces;
    bool hasActiveFace();
};

bool Part::hasActiveFace()
{
    for (int i = 0; i < 6; ++i) {
        Face* face = faces.get(i);
        if ((face->getType() == 8 || face->getType() == 7) &&
            face->isActive())
            return true;
    }
    return false;
}
