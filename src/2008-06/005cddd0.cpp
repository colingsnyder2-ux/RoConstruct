// from server: 100% by tester
struct Desc;
extern Desc desc_cameraType;
struct Sub { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); };
struct Cam {
    char pad[0x1d4];
    int cameraType;
    void raiseChanged(const Desc&);
    Sub* getSub();
    void setCameraType(int t);
};
void Cam::setCameraType(int t) {
    if (cameraType != t) {
        cameraType = t;
        raiseChanged(desc_cameraType);
        Sub* s = getSub();
        if (s) s->v3();
    }
}
