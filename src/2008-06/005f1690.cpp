// from server: 100% by king_originala
extern float g_8282dc;
extern float g_819bac;
extern int g_97abc4;
extern float g_97abc8;
extern float g_97abcc;
extern unsigned int g_97abd0;

struct Ball {
    char padding[0xB8];
    int values[1];
    void set(int index, int value);
};

struct Value {
    int get();
};

struct PartInstance {
    char padding[0x228];
    Ball ball;
    void setShouldRender(int);
    int* f(int);
    void notify(int);
};

struct FaceInstance {
    PartInstance* part;
    int face;
    void setFirst(int);
    void setSecond(float);
    void setThird(float);
    void reset();
};

void FaceInstance::reset()
{
    if (part->ball.values[face] != 0) {
        part->ball.set(face, 0);
        part->setShouldRender(face);
        int* value = part->f(face);
        part->notify(((Value*)value)->get());
    }

    if (((unsigned char)g_97abd0 & 1) == 0) {
        g_97abd0 |= 1;
        g_97abc8 = g_8282dc;
        g_97abc4 = 0;
        g_97abcc = g_819bac;
    }
    setFirst(g_97abc4);

    if (((unsigned char)g_97abd0 & 1) == 0) {
        g_97abd0 |= 1;
        g_97abc8 = g_8282dc;
        g_97abc4 = 0;
        g_97abcc = g_819bac;
    }
    setSecond(g_97abc8);

    if (((unsigned char)g_97abd0 & 1) == 0) {
        g_97abd0 |= 1;
        g_97abc8 = g_8282dc;
        g_97abc4 = 0;
        g_97abcc = g_819bac;
    }
    setThird(g_97abcc);
}
