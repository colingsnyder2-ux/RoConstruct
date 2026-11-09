// from server: 100% by atomic.potato
struct S {
    int a;
    int b;
    int c;
    float x;
    float y;
    float z;
    float u;
    float v;
    float w;
    S* init();
};

float* getVec();

S* S::init() {
    a = 0;
    b = 6;
    c = -1;
    float* p = getVec();
    x = p[0];
    y = p[1];
    z = p[2];
    float* q = getVec();
    u = q[0];
    v = q[1];
    w = q[2];
    return this;
}
