// from server: 100% by tester
extern "C" char* (__cdecl *strncpy)(char* dest, const char* src, unsigned int count);

struct Exposer {
    char pad[0x10f];
    char buf[0xff];
    char flag;
    void set(const char* src);
};

void Exposer::set(const char* src) {
    strncpy(this->buf, src, 0xff);
    this->flag = 0;
}
