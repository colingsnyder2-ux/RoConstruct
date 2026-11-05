// from server: 100% by king_originala
struct FaceInstance {
    int getSurfaceType() const;
};

struct S {
    FaceInstance* getFace(int index);
    int* getSurfaceTypes(int* result);
};

int* S::getSurfaceTypes(int* result)
{
    for (int i = 0; i < 6; ++i)
        result[i] = getFace(i)->getSurfaceType();
    return result;
}
