// from server: 100% by king_originala
extern "C" char * __cdecl strcpy(char *, const char *);

struct TextResult {
    const char *get();
    void release();
};

typedef const char * (__thiscall *GetText)(TextResult *);
typedef void (__thiscall *ReleaseText)(TextResult *);

extern GetText getText;
extern ReleaseText releaseText;

struct Temporary {
    unsigned short m_a;
    unsigned short m_b;
    int m_p;
    int m_x8;
    int m_xc;
    int m_x10;

    Temporary();
    ~Temporary();
    void append(int);
    void result(TextResult *);
};

extern int textSource;
extern unsigned int managerTable;

struct ThreadLogManager {
    unsigned int *table;
    int value;
    char first[128];
    char generated[128];
    char second[128];
    char reserved[0x644];
    int argument;

    ThreadLogManager(const char *, const char *, int);
};

extern ThreadLogManager *currentManager;

ThreadLogManager::ThreadLogManager(
    const char *secondText, const char *firstText, int suppliedArgument)
{
    currentManager = this;
    argument = suppliedArgument;
    table = &managerTable;
    value = 12;

    strcpy(second, secondText);
    strcpy(first, firstText);

    Temporary temporary;
    temporary.append(textSource);
    TextResult *result = reinterpret_cast<TextResult *>(&suppliedArgument);
    temporary.result(result);
    strcpy(generated, getText(result));
    releaseText(result);
}
