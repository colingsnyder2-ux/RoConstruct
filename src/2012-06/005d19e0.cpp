// from server: 68% by tajop
struct SceneUpdaterItem {
    virtual void v0();
    unsigned int flags;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    float m24;
    int m28;
    int m2C;
    float m30;
    float m34;
    SceneUpdaterItem(unsigned int a0, int a1, int a2, int a3, int a4, int a5, float a6, float a7, int a8, int a9, int a10, int a11, float a12);
};

SceneUpdaterItem::SceneUpdaterItem(unsigned int a0, int a1, int a2, int a3, int a4, int a5, float a6, float a7, int a8, int a9, int a10, int a11, float a12)
    : flags(a0 | 0x200), m8(a1), mC(a2), m10(a3), m14(a8), m18(a9), m1C(a10), m20(a11), m24(a12), m28(a5), m2C(a4), m30(a6), m34(a7)
{
}
