// from server: 49% by colin
struct Box {
    char a;
    char b;
    float c;
    int d;
};

struct Chunk {
    char a;
    char b;
    float c;
    int d;
    int e;
    Chunk(const Box& box, const Box& box2);
};

extern "C" int __stdcall sub_474F70(int);

Chunk::Chunk(const Box& box, const Box& box2)
{
    a = box.a;
    b = box.b;
    c = box.c;
    d = 0;
    sub_474F70(box.d);
    e = 0;
    sub_474F70(box2.d);
}
