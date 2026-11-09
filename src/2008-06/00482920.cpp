// from server: 62% by king_originala
extern const char message[];
extern char* __cdecl format(const char*, ...);
extern void __cdecl report(const char*);
extern void __cdecl loadIcon();

struct Error {
    char reserved[0x2c];
    union Storage {
        char local[16];
        char* heap;
    };
    Storage first;
    unsigned firstSize;
    unsigned firstCapacity;
    unsigned reserved44;
    Storage second;
    unsigned secondSize;
    unsigned secondCapacity;
};

struct Window {
    void reportIconFailure();
};

void Window::reportIconFailure()
{
    try {
        loadIcon();
    } catch (const Error& error) {
        const char* first;
        const char* second;

        if (error.firstCapacity >= 16)
            first = error.first.heap;
        else
            first = error.first.local;

        if (error.secondCapacity >= 16)
            second = error.second.heap;
        else
            second = error.second.local;

        report(format(message, second, first));
    }
}
