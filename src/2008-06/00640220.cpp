// from server: 100% by king_originala
struct String;
extern void (__thiscall *destroyString)(String*);

struct String {
    char storage[28];
    ~String() { destroyString(this); }
};

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    char padding[20];
    virtual ~Base();
};

struct GameTool : Base {
    String cursor;
    virtual ~GameTool();
};

GameTool::~GameTool()
{
}
