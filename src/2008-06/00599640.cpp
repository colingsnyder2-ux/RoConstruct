// from server: 100% by king_originala
struct FaceInstance {
    int getSurfaceType() const;
};

struct Faces {
    FaceInstance* get(int index);
};

struct S {
    char padding[0x1f4];
    Faces faces;
    bool f();
};

bool S::f()
{
    for (int i = 0; i < 6; ++i) {
        FaceInstance* face = faces.get(i);
        if (face->getSurfaceType() == 6 ||
            face->getSurfaceType() == 8 ||
            face->getSurfaceType() == 7)
            return true;
    }
    return false;
}
