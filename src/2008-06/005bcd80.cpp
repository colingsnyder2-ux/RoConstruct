// from server: 100% by king_originala
namespace std {
template<class T> struct char_traits;
template<class T> class allocator;

template<class T, class Traits, class Allocator>
class basic_string {
    char storage[28];
public:
    basic_string(const T*);
    ~basic_string();
    basic_string& operator=(const basic_string&);
};
}

typedef std::basic_string<char, std::char_traits<char>,
                          std::allocator<char> > String;

extern void (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);
extern String& (__thiscall *stringAssign)(String*, const String&);

template<class T, class Traits, class Allocator>
__forceinline std::basic_string<T, Traits, Allocator>::basic_string(const T* s)
{
    stringConstruct(this, s);
}

template<class T, class Traits, class Allocator>
__forceinline std::basic_string<T, Traits, Allocator>::~basic_string()
{
    stringDestroy(this);
}

template<class T, class Traits, class Allocator>
__forceinline std::basic_string<T, Traits, Allocator>&
std::basic_string<T, Traits, Allocator>::operator=(const basic_string& s)
{
    return stringAssign(this, s);
}

struct Service {
    char padding[0x134];
    int enabled;
    unsigned int handle;
    char padding2[0x44];
    char collection1[0x20];
    char collection2[0x20];
};

struct SoundServiceStatsItem {
    char padding[0x130];
    double value;
    String text;
    char padding2[4];
    Service* service;
    int measurement1;
    int measurement2;
    unsigned int count1;
    unsigned int count2;

    void update();
};

extern void __cdecl setFormattedValue(
    SoundServiceStatsItem*, double, const char*, ...);
extern int __stdcall queryMeasurements(int*, int*);
extern void __cdecl accumulateCounts(
    void*, unsigned int*, unsigned int*);

void SoundServiceStatsItem::update()
{
    if (service->enabled) {
        unsigned int handle = service->handle;
        setFormattedValue(this, double(handle), "fmod %08x", handle);

        int first;
        int second;
        if (queryMeasurements(&first, &second) == 0) {
            measurement1 = first;
            measurement2 = second;
        }

        unsigned int* secondCount = &count2;
        unsigned int* firstCount = &count1;
        Service* current = service;
        *secondCount = 0;
        *firstCount = 0;
        accumulateCounts(current->collection1, firstCount, secondCount);
        accumulateCounts(current->collection2, firstCount, secondCount);
    } else {
        String disabled("-disabled-");
        value = 0.0;
        text = disabled;
    }
}
