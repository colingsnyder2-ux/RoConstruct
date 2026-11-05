// from server: 100% by king_originala
struct String;

extern void (__thiscall *construct_string)(String *, const char *);
extern void (__cdecl *invalid_parameter_noinfo)();

struct String
{
    char storage[28];
    String(const char *);
    ~String();
};

inline String::String(const char *text)
{
    construct_string(this, text);
}

struct HistoryError
{
    char storage[40];
    HistoryError(const String &);
    HistoryError(const HistoryError &);
    ~HistoryError();
};

struct Change
{
    void play();
};

struct Iterator
{
    void *owner;
    void *position;
    Change **dereference();
    void advance();
    bool equals(const Iterator &) const;
};

inline bool Iterator::equals(const Iterator &other) const
{
    if (!owner || owner != other.owner)
        invalid_parameter_noinfo();
    return position == other.position;
}

struct RestoreFlag
{
    bool *flag;
    bool previous;
    RestoreFlag(bool &);
    ~RestoreFlag();
};

inline RestoreFlag::RestoreFlag(bool &value)
    : flag(&value), previous(value)
{
    value = true;
}

inline RestoreFlag::~RestoreFlag()
{
    *flag = previous;
}

struct History
{
    char padding0[0x138];
    void *owner;
    char padding1[0x10];
    void *end;
    char padding2[4];
    Iterator current;
    Iterator previous;
    bool playing;
    bool enabled;
    void play();
};

void History::play()
{
    if (playing)
        throw HistoryError(String("ChangeHistoryService is currently playing"));

    if (!enabled)
        throw HistoryError(String("ChangeHistoryService is disabled"));

    Iterator finish;
    finish.owner = owner;
    finish.position = end;

    if (current.equals(finish))
        throw HistoryError(String("Attempt to play beyond change history"));

    RestoreFlag restore(playing);
    (*current.dereference())->play();
    previous = current;
    current.advance();
}
