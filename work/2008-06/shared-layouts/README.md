# Shared layout recovery

Owner: Codex. UI implementation ownership remains Claude's. No active ABI change
has been made in this checkpoint; no new class has been swapped into the client.

Reproduce original evidence:

```
python rebuild/2008-06/tests/record_native_layouts.py shared-layouts/original-evidence.json
```

The receipt pins the original executable, observer and runtime metadata. It
parses x86 complete-object locators, hierarchy descriptors and base-class PMDs,
and independently checks the three MFC runtime size records in the original PE.
The mined source declarations remain codegen analogs, not header authority.

| Class | Proven inheritance / offset | Complete size |
|---|---|---|
| CRobloxDoc | VerbBinder<CRobloxDoc, CDocument> at 0 | 0x98 |
| CRobloxView | VerbBinder<CRobloxView, CView> at 0; RBX::VerbContainer at 0x78; Listener<ServiceProvider, ServiceAdded> at 0xa0; Listener<ServiceProvider, ServiceRemoving> at 0xa4; Listener<Network::Players, SuperSafeChanged> at 0xa8 | 0x1f0 |
| CMainFrame | CXTPMDIFrameWnd at 0; Listener<FillToolColor, BrickColor> at 0xf0 | 0x4b4 |
| HUMAN::HumanoidState | INamed at 0; HitTestFilter at 4 | Not supplied by MFC metadata |
| HUMAN::MovingNoPhysicsBase | Named<HumanoidState, sMovingNoPhysicsBase> at 0; SimJob at 0xa0; noncopyable at 0xa4 | Not supplied by MFC metadata |
| HUMAN::RunningNoPhysics | Named<MovingNoPhysicsBase, sRunningNoPhysics> at 0 | Not supplied by MFC metadata |

Doc construction: 00451ac0 calls intermediate constructor 00451590. The latter
calls CDocument construction, sets vtable 00817c24, and constructs a tree member
at +0x54 through 00446110. Doc then sets vtable 00817ce4, zeros +0x74, builds a
vector-like member at +0x78, and zeros +0x90/+0x94. Constructor shapes establish
storage and lifetime boundaries, not pointee types.

Important unresolved distinction: src/2008-06/00451590.cpp uses map<int,int>;
the mined destructor analog uses set<void*>. Neither establishes the native
template arguments. CRobloxView's recovered OnInitialUpdate uses a command-ID
to Name-pointer map at +0x58, providing a useful next lead for the common binder.
The binder template's document instantiation must be checked through native
binding and command-routing uses before selecting the shared member type.

Next: resolve VerbBinder member semantics and document owner/vector pointees;
derive View/Frame constructor member boundaries and complete Humanoid state
fields. Compile size/offset probes with the pinned original compiler before
using shared declarations. Run P5 and scoped P6 gates after each active swap.
