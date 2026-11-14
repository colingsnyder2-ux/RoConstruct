# Native DataModel rendering integration, 2026-11-14

Status: incomplete, inactive. Existing castle demo remains unchanged by this campaign.

The proposed entry creates real DataModel/PartInstance objects, sets studs through
Surface, parents parts into Workspace, registers ViewNew chunks through the real
descendant signal, and uses AggregatingSceneManager before ViewRbxGfx::render.
It has not run: the native-only dependency probe fails to link. No donor App
archive, fallback Parts, replacement geometry, stub providers or forced duplicate
selection are used to hide missing implementations.

Recovered native implementations:

- ViewNew::Part constructor, 004ebcc0: 425 bytes exact.
- PartInstance::outfitChanged, 0059e3a0: 42 bytes exact.
- OutfitChanged descriptor initializer, 007f4b90: 43 bytes exact.
- ViewRbxGfx destructor, 004db4f0: 209 bytes exact.
- AggregateChunk::makeMesh, 00552270: 137 bytes exact.
- AggregateChunk::renderShadows, 00552300: 900 bytes exact.

These are local relocation-masked code/data checks, not call-binding, ABI,
selected-provider, runtime, server credit or P5/P6 proof. The two other recovered
view methods remain drafts: onWorkspaceDescendentAdded is 548/541 bytes;
suppressSkybox is 350/354. Their divergence is retained in check-results.log.

Chunk sort accessors now inline as observed in the original Part constructor.
Provider selection macros allow the existing PartInstance destructor and scene
manager constructors to come from one source each; default recovery builds keep
their original bodies. No /FORCE:MULTIPLE or binary rewriting is used.

Latest native-only probe: 61 provider sources compile, zero duplicate definitions,
185 unresolved symbols. See closure.json and link.log for the complete current
list. Key missing implementations include:

- DataModel factory/lifetime and initializeContents dependencies. Canonical
  DataModel is explicitly incomplete; its constructor and complete virtual/lifetime
  contract cannot be replaced by an implicitly generated constructor.
- ViewNew::Part::getMaterial and updateMesh. A different worker currently leases
  ViewNewPartUpdateMesh.cpp; do not create competing canonical implementations.
- RenderNew::RenderScene::render (007ab0a0, 7199 bytes).
- Several native Instance/reflection, physics and texture providers.

Parenting header proposals are isolated in instance-parent/, with no field or
virtual-slot changes. Their ABI/call identity remains unproved. Candidate include/
contains an earlier unused accessor-header experiment and is not in compile paths.

Next required work: recover/select those genuine providers, establish consistent
native header ABI and direct-call identities, close the link, then run a bounded
real Part/stud aggregation smoke test before changing the interactive castle.

Commands (foreground, per user request; no wake-run):

    python rebuild/2008-06/tests/native_check_runner.py run work/native-candidates/rbx-pipeline-1114/checks.json --workers 2
    python work/native-candidates/rbx-pipeline-1114/compile_entry.py

The second command only compiles and links a /NOENTRY closure probe. It never
executes an unclosed or mixed-ABI image. A nonzero result is expected until the
remaining dependencies are implemented.
