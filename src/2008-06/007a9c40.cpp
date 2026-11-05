// from server: 100% by king_originala
namespace Ogre {
    struct AxisAlignedBox {
        char data[32];
        ~AxisAlignedBox();
        AxisAlignedBox& operator=(const AxisAlignedBox&);
    };
}

extern void (__thiscall *destroyBox)(Ogre::AxisAlignedBox*);
extern Ogre::AxisAlignedBox& (__thiscall *assignBox)(
    Ogre::AxisAlignedBox*, const Ogre::AxisAlignedBox&);

inline Ogre::AxisAlignedBox::~AxisAlignedBox()
{
    destroyBox(this);
}

inline Ogre::AxisAlignedBox& Ogre::AxisAlignedBox::operator=(
    const Ogre::AxisAlignedBox& value)
{
    return assignBox(this, value);
}

struct S {
    char padding[0x27c];
    Ogre::AxisAlignedBox bounds;
    void setBounds(Ogre::AxisAlignedBox value);
};

void S::setBounds(Ogre::AxisAlignedBox value)
{
    bounds = value;
}
