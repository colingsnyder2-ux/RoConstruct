"""Verify recovered ResizeTool methods and their original call targets."""
import hashlib, json, struct, sys
from pathlib import Path
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
out = root / 'rebuild/2008-06/out/native-layouts'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
flags.insert(0, '/I' + str(out / 'workspace-model-vector-include'))
checks = [
 ('NativeResizeToolMethodsTrial', [
  ('?isSticky@ResizeTool', 0x5c63a0, [('??2@', 0x6a0920), ('??0ResizeTool@', 0x5c62f0)]),
  ('?getCursorName@ResizeTool', 0x63ec60, [('??_C@', 0x84a3e8), ('?getCursorName@ArrowToolBase@', 0x6161a0)]),
  ('?onMouseHover@ResizeTool', 0x63f630, [('?findTargetPV@ResizeTool@', 0x63f040), ('?onMouseHover@ArrowToolBase@', 0x6404b0)]),
  ('?onMouseDown@ResizeTool', 0x63f670, [('?findTargetPV@ResizeTool@', 0x63f040), ('?onMouseDown@ArrowToolBase@', 0x617780)]),
  ('?onMouseUp@ResizeTool', 0x63ed20, [('?recordCameraHistory@', 0x58c5c0)])]),
 ('NativeHandleRadiusTrial', [('?distanceToHandleRadius@HitTest', 0x677140, [('__real@3f000000', 0x819bac), ('__real@41e54ca3', 0x84dee4), ('__real@3c8ee7a7', 0x84dee0)])]),
 ('NativeHandleHitTestTrial', [('?hitTestHandleLocal@HandleHitTest', 0x6656b0,
    [('?faceCenter@Extents@', 0x60f7b0), ('?normalIdToVector3@', 0x5ec570),
     ('?distanceToHandleRadius@HitTest@', 0x677140), ('??_7Sphere@G3D@@', 0x827404),
     ('?collisionTimeForMovingPointFixedSphere@CollisionDetection@', 0x7bb5a0)])]),
 ('NativeClosestRayTrial', [('?closestPointOnRay@Math', 0x5df270, [('__real@3ee4f8b588e368f1', 0x828f80)])]),
 ('NativeResizeToolMoveTrial', [
  ('?onMouseMove@ResizeTool', 0x63ee20, [('?lock@?$weak_ptr@VPVInstance@', 0x5cab00),
    ('?fromOriginAndDirection@Ray@', 0x518830), ('?getUnitMouseRay@MouseCommand@', 0x615d00),
    ('?closestPointOnRay@Math@', 0x5df270), ('_floor', 0x6a1bb0), ('?capturedDrag@ResizeTool@', 0x63ed80)])]),
 ('NativeResizeToolDragTrial', [
  ('?capturedDrag@ResizeTool', 0x63ed80, [('?lock@?$weak_ptr@VPVInstance@', 0x5cab00),
    ('?destroyJoints@PartInstance@', 0x598c70), ('?resize@PartInstance@', 0x59e150),
    ('??$create@VSoundService@Soundscape@', 0x5807b0), ('?playSound@SoundService@', 0x5bd820),
    ('?join@PartInstance@', 0x598c90)])]),
 ('NativeResizeToolFindTrial', [
  ('?findTargetPV@ResizeTool', 0x63f040, [('?createService@?$ServiceClient@VSelection', 0x581cc0),
    ('??_R0?AVPartInstance@', 0x92dd50), ('??_R0?AVInstance@', 0x92907c), ('___RTDynamicCast', 0x6a17c6),
    ('?getUnitMouseRay@MouseCommand@', 0x615d00), ('?hitTestHandleLocal@HandleHitTest@', 0x6656b0),
    ('??$shared_from@VPartInstance@', 0x618a40), ('??_7Ray@G3D@@', 0x8282c4)])]),
 ('NativeResizeToolRenderTrial', [
  ('?handles2d@DrawAdorn', 0x677b20, [('?project@GCamera@', 0x510d00), ('?xy@Vector3@', 0x5185d0)]),
  ('?handles3d@DrawAdorn', 0x6776a0, [('?identity@Matrix3@', 0x513e20), ('?cylinder@DrawAdorn@', 0x6773f0),
    ('?distanceToHandleRadius@HitTest@', 0x677140), ('?orange@Color3@', 0x5149b0),
    ('?c@?1??resizeColor@', 0x97d5a8), ('??_7Sphere@G3D@@', 0x827404), ('?clear@Color4@', 0x7baf10)]),
  ('?render2d@ResizeTool', 0x63f470, [('?createService@?$ServiceClient@VSelection', 0x581cc0),
    ('??_R0?AVPartInstance@', 0x92dd50), ('??_R0?AVInstance@', 0x92907c), ('___RTDynamicCast', 0x6a17c6),
    ('?getCoordinateFrame@PartInstance@', 0x598cb0), ('?getPartSizeXml@PartInstance@', 0x598cd0),
    ('?handles2d@DrawAdorn@', 0x677b20), ('?c@?1??resizeColor@', 0x97d5a8), ('?$S2@?1??resizeColor@', 0x97d5b4)]),
  ('?render3dAdorn@ResizeTool', 0x63f2d0, [('?createService@?$ServiceClient@VSelection', 0x581cc0),
    ('??_R0?AVPartInstance@', 0x92dd50), ('??_R0?AVInstance@', 0x92907c), ('___RTDynamicCast', 0x6a17c6),
    ('?getCoordinateFrame@GCamera@', 0x5107b0), ('?getCoordinateFrame@PartInstance@', 0x598cb0),
    ('?getPartSizeXml@PartInstance@', 0x598cd0), ('?handles3d@DrawAdorn@', 0x6776a0)])]),
 ('NativeResizeToolNameTrial', [
  ('?getName@?$Named@VArrowToolBase@RBX@@$1?sResizeTool', 0x5c64c0,
   [('?flag@', 0x979684), ('?callDoDeclare@', 0x5c61c0), ('?call_once@boost@@', 0x557330), ('?doDeclare@', 0x5c5c90)])])]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
rows, objects = [], []
for stem, methods in checks:
    source = root / ('rebuild/2008-06/tests/' + stem + '.cpp'); obj = out / (stem + '.obj')
    extra_flags = (['/fp:fast', '/QIfist'] if stem == 'NativeResizeToolMoveTrial' else
                   ['/fp:fast'] if stem in ('NativeClosestRayTrial', 'NativeHandleHitTestTrial', 'NativeHandleRadiusTrial', 'NativeResizeToolRenderTrial') else [])
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + extra_flags + ['/Fo' + str(obj), str(source)], out)
    assert code == 0, log
    raw = obj.read_bytes(); sections, symbols, definitions, _ = match._coff_data_index(raw)
    objects.append({'source': str(source.relative_to(root)), 'source_sha256': sha(source), 'object_sha256': sha(obj), 'extra_flags': extra_flags})
    for prefix, address, expected in methods:
        name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
        target, targetrefs, _ = match.target('2008-06', '%08x' % address)
        assert match.exact_match(target, targetrefs, body, refs), name
        start, section = definitions[name]; table = sections[section]; bindings = {}
        for i in range(table[7]):
            offset, symbol, kind = struct.unpack_from('<IIH', raw, table[5] + 10*i); offset -= start
            if not 0 <= offset < len(body) - 3: continue
            value = struct.unpack_from('<I', target, offset)[0]
            if kind == 20: value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            bindings.setdefault(symbols[symbol][0], value)
        for symbol, value in expected:
            assert any(k.startswith(symbol) and v == value for k, v in bindings.items()), (symbol, bindings)
        rows.append({'symbol': name, 'address': hex(address), 'size': len(body), 'exact': True,
                     'bindings': {k: hex(v) for k, v in bindings.items()}})
receipt = {'scope': 'Inactive methods only; full class, name identity and runtime remain unproven.',
           'header_sha256': sha(root / 'rebuild/2008-06/tests/NativeResizeToolTrial.h'),
           'observer_sha256': sha(Path(__file__)),
           'rect_source_sha256': sha(root / 'tools/rbxgs/Client/App/roc_native_rect_center_f0523507542fe513.cpp'),
           'workspace_overlay_sha256': sha(out / 'workspace-model-vector-include/v8datamodel/Workspace.h'),
           'model_overlay_sha256': sha(out / 'workspace-model-vector-include/v8datamodel/ModelInstance.h'), 'objects': objects, 'methods': rows, 'flags': flags}
(root / 'work/2008-06/shared-layouts/resize-tool-methods-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS', len(rows), 'ResizeTool methods and bindings')
