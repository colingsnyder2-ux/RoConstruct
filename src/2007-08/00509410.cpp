// from server: 100% by colin
struct GCamera {
    void setCoordinateFrame(const float*);
    void setFieldOfView(const float*);
    void setNearPlaneZ(const float*);
    void setFarPlaneZ(const float*);
    void setViewport(const float*);
    void setProjectionMatrix(const float*);
    void set(const float*, const float*, const float*, const float*, const float*, const float*);
};

void GCamera::set(const float* a, const float* b, const float* c, const float* d, const float* e, const float* f)
{
    setCoordinateFrame(a);
    setFieldOfView(b);
    setNearPlaneZ(c);
    setFarPlaneZ(d);
    setViewport(e);
    setProjectionMatrix(f);
}
