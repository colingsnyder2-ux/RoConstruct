// from server: 100% by king_originala
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        char storage[28];
    public:
        __declspec(dllimport) basic_string();
        __declspec(dllimport) ~basic_string();
        __declspec(dllimport) basic_string& operator=(const basic_string&);
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

template<int N, int Size>
struct Interface {
    virtual ~Interface();
    char storage[Size - 4];
};

template<int N>
struct Interface<N, 4> {
    virtual ~Interface();
};

struct Base :
    Interface<0, 16>,
    Interface<1, 4>,
    Interface<2, 12>,
    Interface<3, 4>,
    Interface<4, 32>,
    Interface<5, 32>,
    Interface<6, 32>,
    Interface<7, 32>,
    Interface<8, 32>,
    Interface<9, 108>,
    Interface<10, 24>
{
    Base();
    virtual ~Base();
    void sub_55af90(int);
};

struct ChatWidget : Base {
    std::string text;

    ChatWidget(int, std::string);
    virtual ~ChatWidget();
};

ChatWidget::ChatWidget(int value, std::string initial)
    : Base(), text()
{
    sub_55af90(value);
    text = initial;
}
