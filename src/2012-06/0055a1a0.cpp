// from server: 10% by Intel
struct VRegistry {
       VRegistry();
       int value;
       int state;
       int count;
       int* self;
       unsigned char flag;
   };
   VRegistry::VRegistry() {
       value = 0;
       state = 0x800;
       count = 0;
   }
