// from server: 100% by king_originala
struct Primary {
    virtual void primary();
};

struct Secondary {
    virtual void secondary();
};

struct Base : Primary, Secondary {
    char storage[20];
    Base(int);
    ~Base();
};

struct String {
    char storage[28];
};

extern String* (__thiscall *constructString)(String*);

struct GameTool : Base {
    String cursor;
    virtual void primary();
    virtual void secondary();
    GameTool(int);
};

GameTool::GameTool(int argument) : Base(argument)
{
    constructString(&cursor);
}
