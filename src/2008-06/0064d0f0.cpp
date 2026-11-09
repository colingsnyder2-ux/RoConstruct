// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_edgelist_36c4299bac801c3e.cpp

// Candidate translation unit (score above; library headers required).
#include <list>
struct Edge;struct Object{char padding[0x40];Edge* edge;};struct Edge{virtual void slot0();virtual void slot1();virtual Object*getObject();char padding[0x18];std::list<Edge*>::iterator position;};struct Stage{char padding[0x10];std::list<Edge*> edges;void addEdge(Edge*);};void Stage::addEdge(Edge*edge){if(edge->getObject())edge->getObject()->edge=edge;edges.push_back(edge);edge->position=--edges.end();}
