// from server: 100% by king_originala
struct ZStream {
    unsigned char* next_in;
    unsigned int avail_in;
    unsigned int total_in;
    unsigned char* next_out;
    unsigned int avail_out;
    unsigned int total_out;
    char* msg;
    unsigned char reserved[0x1c];
};

struct PNG {
    unsigned char reserved0[0x74];
    ZStream zstream;
    unsigned char* zbuf;
    unsigned int zbuf_size;
    unsigned char reserved1[0x1c];
    unsigned int num_rows;
    unsigned char reserved2[0x10];
    unsigned int row_number;
    unsigned char reserved3[0x6c];
    unsigned int flush_rows;
};

extern "C" int __stdcall deflate(ZStream*, int);
extern "C" void __cdecl png_error(PNG*, const char*);
extern "C" void __cdecl png_write_IDAT(PNG*, unsigned char*, unsigned int);
extern "C" void __cdecl png_flush(PNG*);

extern "C" void __cdecl png_write_flush(PNG* p)
{
    if (p->row_number >= p->num_rows)
        return;

    for (;;) {
        if (deflate(&p->zstream, 2) != 0) {
            if (p->zstream.msg)
                png_error(p, p->zstream.msg);
            else
                png_error(p, "zlib error");
        }

        if (p->zstream.avail_out != 0)
            break;

        png_write_IDAT(p, p->zbuf, p->zbuf_size);
        p->zstream.next_out = p->zbuf;
        p->zstream.avail_out = p->zbuf_size;
    }

    if (p->zbuf_size != p->zstream.avail_out) {
        png_write_IDAT(p, p->zbuf, p->zbuf_size - p->zstream.avail_out);
        p->zstream.next_out = p->zbuf;
        p->zstream.avail_out = p->zbuf_size;
    }

    p->flush_rows = 0;
    png_flush(p);
}
