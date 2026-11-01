// from server: 42% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct Inner {
    int a;
    int b;
};

struct Node {
    Inner* first;
    Inner* second;
};

struct Holder {
    char pad[0x10];
    int field10;
};

struct View {
    char pad0[0x94];
    Node* begin;
    char pad1[0x4];
    Node* end;
    char pad2[0x4];
    Node* cap;

    void func(int a, int b, int c, int d);
};

struct Sink {
    void push_back(Node*);
};

extern "C" void __cdecl sub_4E7440(Sink*, Node*);

void View::func(int a, int b, int c, int d)
{
    Node* first = this->begin;
    Node* last = this->end;
    if (this->cap < last)
        _invalid_parameter_noinfo();
    Node* it = this->end;
    Node* base = this->begin;
    if (it > this->cap)
        _invalid_parameter_noinfo();
    Node* cur = this->begin;
    while (cur != 0 && cur != base) {
        if (cur == last)
            break;
        if (cur == 0)
            _invalid_parameter_noinfo();
        if (cur->first != 0) {
            Node tmp;
            tmp.first = cur->first;
            tmp.second = cur->second;
            if (tmp.second != 0)
                _InterlockedExchangeAdd((volatile long*)((char*)tmp.second + 4), 1);
            sub_4E7440((Sink*)&a, &tmp);
        }
        cur = (Node*)((char*)cur + 8);
    }
}
