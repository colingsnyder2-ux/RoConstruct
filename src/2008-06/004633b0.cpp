// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct BaseView {
    BaseView();
    virtual ~BaseView();
    unsigned char storage[0x198];
};

struct View : BaseView {
    View();
    virtual ~View();
    int state;
};

inline View::View() : state(0) {}

View* __cdecl CreateView()
{
    return new View;
}
