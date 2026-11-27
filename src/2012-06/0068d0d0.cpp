// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Rect2D;
struct Extents;
struct ICameraOwner
{
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual const Extents &computeCameraOwnerExtents();
};
struct Camera
{
    enum ZoomType { ZOOM_IN_OR_OUT };
    ICameraOwner *getCameraOwner();
    void zoomExtents(const Extents &, const Rect2D &, ZoomType);
    bool zoomExtents(const Rect2D &viewPort);
};
bool Camera::zoomExtents(const Rect2D &viewPort)
{
    if (ICameraOwner *owner = getCameraOwner())
    {
        zoomExtents(owner->computeCameraOwnerExtents(), viewPort, ZOOM_IN_OR_OUT);
        return true;
    }
    return false;
}