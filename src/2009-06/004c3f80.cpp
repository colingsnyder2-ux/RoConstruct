// from server: 100% by atomic.potato
extern "C" int __cdecl sub_4b37d0(void*);
extern "C" char __cdecl sub_4d3630(void*, void*);

int f(void* a, void* b) {
  if (sub_4b37d0(a) != 0) {
    if (sub_4d3630(a, b) == 0) {
      return 1;
    }
  }
  return 0;
}
