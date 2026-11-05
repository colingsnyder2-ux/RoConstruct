// from server: 100% by atomic.potato
struct Item;

struct Inner {
  Item* convert();
};

struct Outer {
  Inner* get();
};

struct Item {
  char pad0[0x24];
  void* field_24;
  char pad1[8];
  float f30;
  float f34;
  float f38;
  float f3c;
  float f40;
  float f44;
};

void __cdecl fn511160(void*, void*, void*);
void __cdecl fn510e00(void*, void*, void*);

struct MyClass {
  char pad0[4];
  unsigned char field_4;
  char pad1[0x1f];
  void* field_24;
  void apply(float, float, float);
  void method(MyClass*, Outer*);
};

void MyClass::method(MyClass* a, Outer* b) {
  Item* item = b->get()->convert();
  fn511160(a, &item->field_24, this->field_24);
  fn510e00(a, item, this->field_24);
  if (this->field_4) {
    a->apply(item->f30, item->f34, item->f38);
    a->apply(item->f3c, item->f40, item->f44);
  }
}
