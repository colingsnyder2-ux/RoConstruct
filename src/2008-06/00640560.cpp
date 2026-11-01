// from server: 100% by king_originala
struct Primary {
    virtual void primary();
};

struct Secondary {
    virtual void secondary();
};

struct Base : Primary, Secondary {
    int fields[5];
    Base(int);
    ~Base();
};

struct Active {
    bool active;
    Active();
};

inline Active::Active() : active(false) {}

struct Regex {
    void* pointer;
    Regex();
    ~Regex();
};

inline Regex::Regex() : pointer(0) {}

struct String {
    char storage[28];
};

extern void (__thiscall* constructString)(String*, const char*);

struct Ray {
    int storage[8];
    void initialize();
};

struct ArrowTool : Base, Active {
    Regex regex;
    String cursor;
    volatile bool flag;
    volatile short first;
    volatile short second;
    Ray ray;
    float x;
    float y;
    float z;

    ArrowTool(int);
    virtual void primary();
    virtual void secondary();
};

ArrowTool::ArrowTool(int argument)
    : Base(argument), Active(), regex()
{
    constructString(&cursor, "ArrowCursor");
    flag = false;
    first = 0;
    second = 0;
    ray.initialize();
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}
