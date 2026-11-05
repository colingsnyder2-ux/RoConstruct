// from server: 100% by king_originala
namespace Ogre {
    struct SubMesh {
        unsigned char storage[0xC4];
        SubMesh();
        ~SubMesh();
    };

    struct AxisAlignedBox {
        float minimum[3];
        float maximum[3];
        int extent;
        AxisAlignedBox();
    };
}

extern void (__thiscall *constructSubMesh)(Ogre::SubMesh*);
extern void (__thiscall *constructAxisAlignedBox)(Ogre::AxisAlignedBox*);

__forceinline Ogre::SubMesh::SubMesh() {
    constructSubMesh(this);
}

__forceinline Ogre::AxisAlignedBox::AxisAlignedBox() {
    constructAxisAlignedBox(this);
}

struct S : Ogre::SubMesh {
    bool flag;
    void* pointer;
    Ogre::AxisAlignedBox bounds;
    S();
};

S::S() : flag(false), pointer(0) {}
