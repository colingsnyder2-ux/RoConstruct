// from server: 61% by colin
struct Ogre__RbxSceneManagerFactory {
    char pad[0x24];
    float x;
    float y;
    float z;
};

void copy(Ogre__RbxSceneManagerFactory* src, float* dst)
{
    dst[0] = src->x;
    dst[1] = src->y;
    dst[2] = src->z;
}
