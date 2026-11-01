// from server: 100% by tester
namespace G3D {
class Rect2D
{
    float x0, y0, x1, y1;
};
}

namespace RBX {
class Camera
{
public:
    void zoomExtents(const G3D::Rect2D& viewPort);
};

class ICameraOwner
{
public:
    virtual ~ICameraOwner();
    virtual Camera* getCamera() const = 0;
};

class RootInstance
{
    char data[0x284];
public:
    virtual ~RootInstance();
};

class Workspace : public RootInstance, public ICameraOwner
{
    char gap28c[0x48];
    G3D::Rect2D viewPort;
public:
    virtual Camera* getCamera() const;
    void zoomToExtents();
};

void Workspace::zoomToExtents()
{
    getCamera()->zoomExtents(viewPort);
}
}
