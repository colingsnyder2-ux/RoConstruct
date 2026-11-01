// from server: 100% by colin
struct Ball {
    int vtbl;
    float realRadius;
    int pad1;
    int pad2;
    float value;
    void compute();
};

extern float G;

void Ball::compute()
{
    value = realRadius * G;
}
