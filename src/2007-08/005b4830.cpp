// from server: 100% by colin
struct Geometry {
    char pad[0x20];
    Geometry* bulletCollisionObject;
    Geometry* getBulletCollisionObject();
};

Geometry* Geometry::getBulletCollisionObject()
{
    Geometry* p = bulletCollisionObject;
    if (p)
        return p->bulletCollisionObject;
    return 0;
}
