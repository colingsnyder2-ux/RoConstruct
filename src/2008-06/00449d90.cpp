// from server: 100% by colin
struct Text;

extern void (__cdecl *TextFormat)(Text *, const char *, ...);
extern const char *(__thiscall *TextData)(const Text *);

struct Text {
    char *data;
    __declspec(dllimport) Text();
    __declspec(dllimport) ~Text() throw();
};





struct Window {
    char padding[32];
    void *handle;
};

struct Application {
    struct Table {
        void *unused[31];
        Window *(__thiscall *getWindow)(Application *);
    };
    Table *table;
};

extern Application *__cdecl GetApplication();

extern void *(__stdcall *ShellExecuteA)(
    void *, const char *, const char *, const char *, const char *, int);

void OpenWiki()
{
    Text command;
    TextFormat(&command, "url.dll,FileProtocolHandler %s",
               "http://wiki.roblox.com");

    Application *application = GetApplication();
    Window *window;
    if (application)
        window = application->table->getWindow(application);
    else
        window = 0;

    ShellExecuteA(window->handle, "open", "rundll32.exe",
                  TextData(&command), 0, 10);
}
