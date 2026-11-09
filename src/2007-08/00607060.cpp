// from server: 47% by colin
struct ClumpStage {
    void process(void*);
};

struct Instance {
    void* getChild(int);
};

struct ChildContainer {
    void* findChild(void*);
};

struct ChildList {
    void* begin();
    void* end();
};

struct ChildIterator {
    void* current;
    void* owner;
};

struct ChildNode {
    void* next;
    void* child;
};

struct ClumpStageImpl {
    char pad[0x2c];
    ChildList children;
    char pad2[0x14];
    ChildContainer container;
    char pad3[0x14];
    ChildContainer container2;
};

extern "C" {
    int __stdcall sub_5B4830(void*);
    void* __stdcall sub_5B4DC0(void*);
    void* __stdcall sub_5B4DE0(void*, void*);
    int __stdcall sub_5E29B0(void*, void*, void*);
    int __stdcall sub_6056F0(void*, void*);
    int __stdcall sub_605A10(void*);
    int __stdcall sub_605B30(void*, void*);
    int __stdcall sub_605C80(void*, void*);
    int __stdcall sub_606F70(void*, void*);
    int __stdcall sub_60B200(void*, void*, void*);
    int __stdcall sub_60BC60(void*, void*);
    int __stdcall sub_60BF00(void*);
    int __stdcall sub_60BF10(void*, void*);
    int __stdcall sub_570200(void*, void*, void*);
    void __stdcall sub_77E6D8();
}

void ClumpStage::process(void* param) {
    ClumpStageImpl* self = (ClumpStageImpl*)this;
    void* child = param;
    
    if (sub_5B4830(child)) {
        sub_606F70(self, child);
    }
    
    void* first = sub_5B4DC0(child);
    void* current = first;
    
    if (current) {
        ChildContainer* cont = &self->container;
        ChildContainer* cont2 = &self->container2;
        
        do {
            if (sub_60BC60(cont, current)) {
                void* c = current;
                sub_60BF00(c);
                void* r = (void*)sub_60B200(c, current, current);
                sub_60BF00(r);
            } else {
                if (sub_605A10(self)) {
                    ChildIterator iter;
                    iter.current = current;
                    iter.owner = 0;
                    
                    if (sub_605B30(cont, &iter) == 0) {
                        if (sub_605B30(cont2, &iter) == 0) {
                            void* node = (void*)sub_570200(&self->children, &iter, &iter);
                            void* n = *(void**)node;
                            if (n != 0 && n != &self->children) {
                                sub_77E6D8();
                            }
                            if (*(void**)((char*)node + 4) != iter.current) {
                                sub_605C80(self, current);
                            }
                        }
                    }
                }
            }
            
            ChildIterator iter2;
            iter2.current = current;
            iter2.owner = 0;
            sub_5E29B0(cont, &iter2, &iter2);
            current = sub_5B4DE0(child, current);
        } while (current);
    }
    
    sub_6056F0(self, child);
    sub_60BF10((void*)0, child);
}
