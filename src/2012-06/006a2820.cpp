// from server: 100% by Xemicl
﻿// from server: 100% by tajop
// roc 2012-06 008773f0  unit: DummyJob  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008773f0
//
// 008773f0  8b01                 mov eax, dword ptr [ecx]
// 008773f2  80780e00             cmp byte ptr [eax + 0xe], 0
// 008773f6  7542                 jne 0x87743a
// 008773f8  8b5008               mov edx, dword ptr [eax + 8]
// 008773fb  807a0e00             cmp byte ptr [edx + 0xe], 0
// 008773ff  751c                 jne 0x87741d
// 00877401  8b02                 mov eax, dword ptr [edx]
// 00877403  80780e00             cmp byte ptr [eax + 0xe], 0
// 00877407  7511                 jne 0x87741a
// 00877409  8da42400000000       lea esp, [esp]
// 00877410  8bd0                 mov edx, eax
// 00877412  8b02                 mov eax, dword ptr [edx]
// 00877414  80780e00             cmp byte ptr [eax + 0xe], 0
// 00877418  74f6                 je 0x877410
// 0087741a  8911                 mov dword ptr [ecx], edx
// 0087741c  c3                   ret 
// 0087741d  8b4004               mov eax, dword ptr [eax + 4]
// 00877420  80780e00             cmp byte ptr [eax + 0xe], 0
// 00877424  7512                 jne 0x877438
// 00877426  8b11                 mov edx, dword ptr [ecx]
// 00877428  3b5008               cmp edx, dword ptr [eax + 8]
// 0087742b  750b                 jne 0x877438
// 0087742d  8901                 mov dword ptr [ecx], eax
// 0087742f  8b4004               mov eax, dword ptr [eax + 4]
// 00877432  80780e00             cmp byte ptr [eax + 0xe], 0
// 00877436  74ee                 je 0x877426
// 00877438  8901                 mov dword ptr [ecx], eax
// 0087743a  c3                   ret 

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    char value[0x48];
    char color;
    char isnil;
};

struct TreeIterator {
    Node* ptr;
    void inc();
};

void TreeIterator::inc() {
    if (ptr->isnil) {
    } else if (!ptr->right->isnil) {
        Node* p = ptr->right;
        while (!p->left->isnil)
            p = p->left;
        ptr = p;
    } else {
        Node* p;
        while (!(p = ptr->parent)->isnil && ptr == p->right)
            ptr = p;
        ptr = p;
    }
}
