// from server: 100% by colin
// from server: 93% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_manual_edge_5278315e0a22c6ae.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/Array.h"
struct Owner;
struct Edge { char prefix[12]; Owner* first; Owner* second; int firstIndex,secondIndex; Owner* getFirst()const {return first;} Owner* getSecond()const {return second;} };
struct Primitive { Owner* owner; G3D::Array<Edge*> edges; G3D::Array<Owner*> neighbors; void addEdge(Edge*); };
void Primitive::addEdge(Edge* edge) { int index=edges.size(); if(owner==edge->first)edge->firstIndex=index;else edge->secondIndex=index; edges.append(edge); Owner* other = owner==edge->first ? edge->second : edge->first; neighbors.append(other); }
