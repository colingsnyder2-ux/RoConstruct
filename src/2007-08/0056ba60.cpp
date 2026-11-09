// from server: 24% by colin
struct ArchiveBinder {
    bool loadInstancesXML(void* stream, int a, int b);
};

extern "C" {
    void* __stdcall sub_77E534(void*, void*);
    void* __stdcall sub_77E698(void*, const char*);
    void* __stdcall sub_77E52C(void*, int, int);
    void* __stdcall sub_77E530(void*, int, int);
    void* __stdcall sub_77E4AC(void*, void*);
    void* __stdcall sub_77E4B0(void*);
    void* __stdcall sub_77E6AC(void*);
    void __cdecl sub_412DC0(void*, void*);
    void __cdecl sub_630B9E(void*, void*);
    void __cdecl sub_408740(void*, void*, void*, void*);
    void __cdecl sub_549650(void*, void*);
    void __cdecl sub_56B8B0(void*, void*, int);
}

bool ArchiveBinder::loadInstancesXML(void* stream, int a, int b)
{
    char buf[0x20];
    int v;
    void* p;
    void* q;
    int pos;
    int oldPos;
    char c;

    buf[0] = 0;
    sub_77E534(stream, buf);
    p = *(void**)buf;
    q = *(void**)((char*)p + 4);
    if (*(int*)((char*)q + (int)p + 8) != 0) {
        sub_77E698(buf, "SerializerV2::load can't read header");
        sub_412DC0(buf, buf);
        sub_630B9E(buf, buf);
    }

    if (*(int*)buf != 0x7a9e80) {
        void* vtable = *(void**)stream;
        void* ecx = *(void**)((char*)vtable + 4);
        sub_77E52C((char*)ecx + (int)stream, 0, 0);
        sub_77E530(stream, 0, 0);
        sub_56B8B0(stream, (void*)a, b);
        return true;
    }

    sub_77E534(stream, buf);
    p = *(void**)buf;
    q = *(void**)((char*)p + 4);
    if (*(int*)((char*)q + (int)p + 8) != 0) {
        sub_77E698(buf, "SerializerV2::load can't read old fileFormatVersion");
        sub_412DC0(buf, buf);
        sub_630B9E(buf, buf);
    }

    if (*(int*)buf != 1) {
        sub_77E698(buf, "SerializerV2::load canfileFormatVersion!=1");
        sub_412DC0(buf, buf);
        sub_630B9E(buf, buf);
    }

    sub_77E534(stream, buf);
    p = *(void**)buf;
    q = *(void**)((char*)p + 4);
    if (*(int*)((char*)q + (int)p + 8) != 0) {
        sub_77E698(buf, "SerializerV2::load can't read contentPos");
        sub_412DC0(buf, buf);
        sub_630B9E(buf, buf);
    }

    if (a != 0) {
        sub_77E4AC(stream, buf);
        pos = *(int*)((char*)buf + 8) + *(int*)buf;
        sub_77E52C(stream, 0, 0);
        sub_77E530(stream, 0, a);
        if (sub_77E4B0(stream) != 0) {
            do {
                sub_77E534(stream, buf);
                p = *(void**)buf;
                q = *(void**)((char*)p + 4);
                if (*(int*)((char*)q + (int)p + 8) != 0) {
                    sub_77E698(buf, "SerializerV2::load error reading compound file (1)");
                    sub_412DC0(buf, buf);
                    sub_630B9E(buf, buf);
                }
                sub_77E534(stream, buf);
                p = *(void**)buf;
                q = *(void**)((char*)p + 4);
                if (*(int*)((char*)q + (int)p + 8) != 0) {
                    sub_77E698(buf, "SerializerV2::load error reading compound file (2)");
                    sub_412DC0(buf, buf);
                    sub_630B9E(buf, buf);
                }
                sub_77E534(stream, buf);
                p = *(void**)buf;
                q = *(void**)((char*)p + 4);
                if (*(int*)((char*)q + (int)p + 8) != 0) {
                    sub_77E698(buf, "SerializerV2::load error reading compound file (3)");
                    sub_412DC0(buf, buf);
                    sub_630B9E(buf, buf);
                }
                if (buf[0] == 0) {
                    sub_408740(buf, stream, buf, buf);
                    sub_549650(buf, buf);
                    sub_77E6AC(buf);
                }
            } while (sub_77E4B0(stream) != 0);
        }
        sub_77E52C(stream, 0, 0);
        sub_77E530(stream, pos, 0);
    }

    sub_77E534(stream, buf);
    p = *(void**)buf;
    q = *(void**)((char*)p + 4);
    if (*(int*)((char*)q + (int)p + 8) != 0) {
        sub_77E698(buf, "SerializerV2::load error reading compound file (4)");
        sub_412DC0(buf, buf);
        sub_630B9E(buf, buf);
    }

    if (buf[0] != 0) {
        sub_77E698(buf, "SerializerV2::load error reading compound file (5)");
        sub_412DC0(buf, buf);
        sub_630B9E(buf, buf);
    }

    return true;
}
