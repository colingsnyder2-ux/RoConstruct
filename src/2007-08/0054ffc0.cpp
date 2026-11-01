// from server: 100% by colin
struct StreamBuffer {
    int read(char* buf, int count);
};

int decompressByte(StreamBuffer* sb)
{
    char c;
    int r = sb->read(&c, 1);
    if (r == 1)
        return (unsigned char)c;
    return (r == -1) ? -1 : -2;
}
