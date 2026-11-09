// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// roc-lib: rbxgs-dll roc_array_public_members_bd89ce2b9404cfdc.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Array.h>
#include <string>
#include <G3D/Vector2.h>
#include <G3D/Vector3.h>
#include <new>
#include <vector>
namespace RBX { class Primitive; }
typedef G3D::Vector2 E;
typedef G3D::Array<E> A;
void constructArray(A* p, int n) { new (p) A(n); }
void copyArray(A* p, const A& b) { new (p) A(b); }
void destroyArray(A* p) { p->~A(); }
void assignArray(A& a, const A& b) { a = b; }
void assignVector(A& a, const std::vector<E>& b) { a = b; }
void resizeArray(A& a, int n, bool shrink) { a.resize(n, shrink); }
void insertArray(A& a, int n, const E& v) { a.insert(n, v); }
void appendOne(A& a, const E& v) { a.append(v); }
void appendTwo(A& a, const E& v, const E& w) { a.append(v, w); }
void appendThree(A& a, const E& v, const E& w, const E& x) { a.append(v, w, x); }
void appendFour(A& a, const E& v, const E& w, const E& x, const E& y) { a.append(v, w, x, y); }
void appendArray(A& a, const A& b) { a.append(b); }
void removeArray(A& a, int n, int count) { a.remove(n, count); }
void fastRemoveArray(A& a, int n) { a.fastRemove(n); }
E popArray(A& a, bool shrink) { return a.pop(shrink); }
void discardArray(A& a, bool shrink) { a.popDiscard(shrink); }
void clearArray(A& a) { a.clear(); }
void fastClearArray(A& a) { a.fastClear(); }
void swapArray(A& a, A& b) { a.swap(b); }
