// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

extern const float scale;
extern Vector3* __cdecl lookup(const Vector3&);
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)
#pragma float_control(precise, off)

struct Block {
    void* header;
    float x, y, z;
    Vector3* vector;
    float magnitude;

    void update();
};

void Block::update()
{
    Vector3 scaled = { x * scale, y * scale, z * scale };
    vector = lookup(scaled);
    magnitude = (float)sqrt(vector->x * vector->x
                         + vector->y * vector->y
                         + vector->z * vector->z);
}
