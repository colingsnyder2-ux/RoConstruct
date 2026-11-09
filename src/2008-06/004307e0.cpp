// from server: 100% by king_originala
struct Bar
{
#define V(n) virtual void v##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84)
    virtual int Load(unsigned int, int);
    V(86) V(87) V(88)
    virtual void SetVisible(int);
#undef V
    void ApplyFlags(unsigned int, unsigned int);
    void SetPosition(int);
};

struct Options
{
    char pad0[0x20];
    int a;
    char pad1[8];
    int b;
};

struct Bars
{
    char pad[0x74];
    Options* options;

    Bar* SetMenu(const char*, unsigned int);
    Bar* Add(const char*, int, int);
    void f(unsigned int*, int);
};

extern char menuName[];
extern char standardName[];
extern char cameraName[];
extern char mouseName[];
extern char testName[];
extern char commandName[];
extern unsigned int values[];
extern int globalValue;

struct S
{
    char pad[0xec];
    Bars* bars;

    void Link(Bar*, Bar*);
    bool f(unsigned char);
};

bool S::f(unsigned char enabled)
{
    Bars* p = bars;
    Bar* menu = p->SetMenu(menuName, 0x80);
    if (!menu)
        return false;

    menu->ApplyFlags(0x1700, 0);

    Bar* standard = p->Add(standardName, 0, 0);
    if (!standard || !standard->Load(0x80, enabled))
        return false;

    Bar* camera = p->Add(cameraName, 0, 0);
    if (!camera || !camera->Load(0x87, enabled))
        return false;

    Bar* mouse = p->Add(mouseName, 0, 0);
    if (!mouse || !mouse->Load(0x89, enabled))
        return false;

    Bar* test = p->Add(testName, 0, 0);
    if (!test || !test->Load(0x91, enabled))
        return false;

    Bar* command = p->Add(commandName, 1, 0);
    if (!command || !command->Load(0x96, enabled))
        return false;

    command->SetPosition(0x73);
    command->SetVisible(0);
    Link(mouse, standard);
    Link(camera, mouse);
    p->f(values, 0x1a);
    p->options->a = 1;
    globalValue = 0x1194;
    p->options->b = 1;
    return true;
}
