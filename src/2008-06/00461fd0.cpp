// from server: 100% by king_originala
extern "C" void __cdecl sub_6a094a(void*);

struct Base {
    char data[0x58];
    ~Base();
};

struct Member {
    char data[0x5c];
    ~Member();
};

struct S : Base {
    Member member_58;
    void* field_b4;
    void* field_b8;

    ~S();
};

S::~S()
{
    field_b4 = (void*)0x81aa5c;
    if (field_b8)
        sub_6a094a(field_b8);
}
