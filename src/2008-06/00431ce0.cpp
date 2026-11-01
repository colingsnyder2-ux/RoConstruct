// from server: 100% by king_originala
struct CDataModelPropGrid {
    void f(bool);
    void Update();
    char padding[0xf8];
    unsigned char field_0xf8;
};

void CDataModelPropGrid::Update() {
    f(field_0xf8 == 0);
}
