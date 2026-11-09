// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

namespace std {
template<class T> struct char_traits;
template<class T> class allocator;

template<class T, class Traits, class Alloc>
class basic_string {
    char storage[28];
public:
    __declspec(dllimport) basic_string(const basic_string&);
    __declspec(dllimport) ~basic_string();
};

typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct Node {
    Node* next;
    char storage[20];

    Node(int, std::string);
};

struct Players {
    char padding[0x20];
    Node* first;
    Node* last;

    void append(int, std::string);
};

void Players::append(int value, std::string text)
{
    Node* node = new Node(value, text);
    if (!last)
        first = node;
    else
        last->next = node;
    last = node;
}
