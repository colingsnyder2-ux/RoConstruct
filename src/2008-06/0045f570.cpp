// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
struct String;
extern void (__thiscall *constructString)(String *, const char *);
extern void (__thiscall *destroyString)(String *);
extern String *(__thiscall *assignString)(String *, const String *);

struct String {
    char storage[28];
    String(const char *);
    ~String();
    String &operator=(const String &);
};

__forceinline String::String(const char *s) {
    constructString(this, s);
}

__forceinline String::~String() {
    destroyString(this);
}

__forceinline String &String::operator=(const String &s) {
    return *assignString(this, &s);
}

struct Item {
    char padding[0x130];
    double value;
    String text;
    void setValue(unsigned int);
};

struct Statistics {
    char padding[0x210];
    int firstLimit;
    int firstCount;
    int secondLimit;
    int secondCount;
};

extern int profileCount;
extern int profileBegin;
extern int profileEnd;
extern unsigned int firstValue;
extern unsigned int secondValue;
extern unsigned int __cdecl getValue();
extern void __cdecl formatItem(Item *, double, const char *, ...);

struct S {
    char padding[0x158];
    Item *profile;
    Item *first;
    Item *second;
    Item *third;
    Item *firstStats;
    Item *secondStats;
    Statistics *stats;
    void RenderStatsItem();
};

void S::RenderStatsItem() {
    __declspec(align(64)) char workspace[64];
    int count = profileCount;

    if (!count) {
        String text("n/a");
        Item *item = profile;
        item->value = 0.0;
        item->text = text;
    } else {
        int total = profileEnd;
        if (!total) {
            formatItem(profile, 0.0, "%.0f%%, %.2g", 0.0, 1.0);
        } else {
            total -= profileBegin;
            float samples = float(count);
            count = total + count;
            float elapsed = float(count);
            float ratio = (samples - elapsed) / (samples - 1.0f);
            formatItem(profile, ratio, "%.0f%%, %.2g",
                       100.0f * ratio, samples / elapsed);
        }
    }

    formatItem(firstStats, double(stats->firstCount), "%d/%d",
               stats->firstCount, stats->firstLimit);
    formatItem(secondStats, double(stats->secondCount), "%d/%d",
               stats->secondCount, stats->secondLimit);
    first->setValue(firstValue);
    second->setValue(secondValue);
    third->setValue(getValue());
}
