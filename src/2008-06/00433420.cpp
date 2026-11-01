// from server: 100% by king_originala
struct Window
{
    virtual ~Window();
    Window();

    char storage[0x54];
};

struct Splitter
{
    Splitter();
    ~Splitter();

    char storage[0x118];
};

struct CObjectBrowser : Window
{
    Splitter first;
    Splitter second;

    CObjectBrowser();
    virtual ~CObjectBrowser();
};

CObjectBrowser::CObjectBrowser()
{
}
