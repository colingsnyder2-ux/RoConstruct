// from server: 100% by atomic.potato
extern "C" void __cdecl sub_630d23(void*);

struct Obj {
  void init(const char* a, const char* b);
};

extern Obj g_conn_8be57c;

void __cdecl register_ConnectionRejected() {
  g_conn_8be57c.init((const char*)0x79c548, (const char*)0x79c55c);
  sub_630d23((void*)0x778720);
}
