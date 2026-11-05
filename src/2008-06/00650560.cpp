// from server: 100% by colin
struct String;

extern String& (__thiscall* stringAssign)(String*, const String&);

struct String {
    unsigned int proxy;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned int length;
    unsigned int capacity;

    __declspec(dllimport) String();
    __declspec(dllimport) String(const String&);
    ~String();
    String& operator=(const String&);
};





__forceinline String& String::operator=(const String& other)
{
    return stringAssign(this, other);
}

struct Color {
    float r, g, b;
};

struct BrickColor {
    int value;
    Color* color(Color*) const;
};

struct Team {
    BrickColor getTeamColor() const;
};

struct Player {
    char padding[0x110];
    String name;
    char padding2[0x50];
    bool neutral;
};

struct ServiceProvider {
    bool teamsEnabled();
    Team* getTeamFromPlayer(Player*);
};

extern ServiceProvider* __cdecl func_0049ab50(Player*);
extern const Color& __cdecl func_005149f0();
extern const Color& __cdecl func_00514a60();
extern unsigned int __cdecl func_00669f60(const String&);
extern const Color& __cdecl func_0064f830(unsigned int);

struct ChatOutput {
    Color color;
    String name;
    String text;
    float time;
    bool flag;

    ChatOutput(Player*, const String&, float);
};

ChatOutput::ChatOutput(Player* player, const String& message, float timestamp)
    : name(), text(message), time(timestamp), flag(false)
{
    name = player->name;

    Color temporary;
    const Color* result;
    ServiceProvider* service = func_0049ab50(player);

    if (service && service->teamsEnabled()) {
        if (!player->neutral) {
            Team* team = service->getTeamFromPlayer(player);
            if (team)
                result = team->getTeamColor().color(&temporary);
            else
                result = &func_005149f0();
        } else {
            result = &func_00514a60();
        }
    } else {
        result = &func_0064f830(func_00669f60(name) & 7);
    }

    color.r = result->r;
    color.g = result->g;
    color.b = result->b;
}
