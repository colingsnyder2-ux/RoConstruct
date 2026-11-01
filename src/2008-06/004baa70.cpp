// from server: 100% by tester
extern "C" int (__cdecl *printf)(const char*, ...);

extern char G_format[];

struct Exposer {
    int Show(int value);
};

int Exposer::Show(int value)
{
    return printf(G_format, value);
}
