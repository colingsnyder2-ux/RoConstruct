// from server: 39% by atomic.potato
// roc 2009-12 00559a90  unit: RBX::Network::ServerReplicator  size: 386 bytes



struct G3D_Ray {
    char pad[0x14];
    void ctor();
    void dtor();
    void setDir(const float*);
    void setOrigin(const float*);
};

struct RBX_ServerReplicator {
    char pad0[0x266c];
    unsigned char b266c;
    unsigned char b266d;
    unsigned char b266e;
    char pad1[0x2670 - 0x266f];
    int* p2670;
    char pad2[0x267c - 0x2674];
    int* p267c;
    int* p2680;
    char pad3[0x29b8 - 0x2684];
    int v29b8;
    int v29bc;
    void sub_54bbe0(int, void*);
    void sub_536310(int, void*);
    void func(int);
    void _invalid_parameter_noinfo();
};

void RBX_ServerReplicator::func(int arg) {
    G3D_Ray ray;
    char buf[0x400];
    int local8;
    int local14;
    int local10;

    ray.ctor();
    ray.setOrigin((const float*)buf);
    ray.setDir((const float*)buf);
    ray.setDir((const float*)buf);
    ray.setDir((const float*)buf);

    local8 = *(int*)((char*)this + 0x2680);
    if (*(int*)((char*)this + 0x267c) > local8)
        _invalid_parameter_noinfo();

    local14 = *(int*)((char*)this + 0x2670);
    int* ebx = *(int**)((char*)this + 0x267c);
    if (ebx > *(int**)((char*)this + 0x2680))
        _invalid_parameter_noinfo();

    int* edi = *(int**)((char*)this + 0x2670);
    if (edi != 0 && edi != (int*)local14)
        _invalid_parameter_noinfo();

    while (ebx != (int*)local10) {
        if (edi == 0) {
            _invalid_parameter_noinfo();
            if (ebx < (int*)0x10)
                _invalid_parameter_noinfo();
            this->sub_536310(*ebx, &ray);
            if (edi == 0) {
                _invalid_parameter_noinfo();
                if (ebx < (int*)0x10)
                    _invalid_parameter_noinfo();
                ebx++;
            } else {
                edi = (int*)*edi;
            }
        } else {
            edi = (int*)*edi;
        }
    }

    int count = (*(int*)((char*)this + 0x2680) - *(int*)((char*)this + 0x267c)) >> 2;
    if (count <= 0)
        _invalid_parameter_noinfo();

    int* p = *(int**)((char*)this + 0x267c);
    this->sub_54bbe0(*p, &ray);

    int v1 = *(int*)((char*)this + 0x29bc);
    int v2 = *(int*)((char*)this + 0x29b8);
    void** vt = *(void***)this;
    void (*fn)(int, int, int, int, int, int, void*) = (void (*)(int, int, int, int, int, int, void*))vt[0x10];
    fn(0, 2, 3, 0, v2, v1, &ray);

    ray.dtor();
}
