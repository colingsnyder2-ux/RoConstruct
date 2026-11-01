// from server: 100% by king_originala
struct Ball {
    int getBulletSphereShape() const;
};

struct Iterator {
    unsigned int data[3];
};

struct Container {
    Iterator insert(const int& value);
};

struct Input {
    unsigned char padding[12];
    Ball* balls[2];
};

struct TreeStage {
    unsigned char padding[20];
    unsigned char changed;
    unsigned char reserved[35];
    Container shapes;

    void update(Input* input);
};

void TreeStage::update(Input* input)
{
    Ball** current = input->balls;
    int remaining = 2;
    do {
        if (*current) {
            int result = (*current)->getBulletSphereShape();
            if (result) {
                int shape = result;
                shapes.insert(shape);
                changed = 1;
            }
        }
        ++current;
    } while (--remaining);
}
