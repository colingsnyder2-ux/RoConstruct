"""python propsweep.py [EXE] [--orig] [--only CLASS.PROP,...]: property-set sweep (FEATURE_LADDER T1 "change a property").
Each case creates an instance (parented to Workspace, or the given service) and assigns one property under pcall, then
waits so render/physics/replication see the change. A group of cases is one `-script` launch; a group that kills the
client is bisected down to single cases. Each crashing case is re-run on the original (--orig skips that). Writes
auto/propsweep.json {crash: [case...], orig_crash: [...], groups: n}."""
import json, os, subprocess, sys, time
from pathlib import Path
import ieclean
H = Path(__file__).parent
a = sys.argv[1:]
EXE = os.path.abspath(next((x for x in a if x.lower().endswith('.exe')), str(H / 'run/RobloxQT.exe')))
ORIG = os.path.abspath(H / 'run/RobloxOrig.exe')
V3, CF, C3 = 'Vector3.new(3,4,5)', 'CFrame.new(1,8,2)', 'Color3.new(0.2,0.6,0.9)'
P = 'local o=Instance.new("Part") o.Anchored=true o.Position=Vector3.new(0,6,0) o.Parent=workspace '
# (label, setup creating `o`, assignment)
CASES = []
def add(cls, props, parent='workspace', setup=None):
    for k, v in props:
        CASES.append(('%s.%s=%s' % (cls, k, v), setup or 'local o=Instance.new("%s") o.Parent=%s ' % (cls, parent), 'o.%s=%s' % (k, v)))
add('Part', [('Name', '"X"'), ('Size', V3), ('Position', V3), ('CFrame', CF), ('Color', C3), ('BrickColor', 'BrickColor.new(21)'),
             ('Transparency', '0.5'), ('Reflectance', '0.5'), ('Anchored', 'false'), ('CanCollide', 'false'), ('Locked', 'true'),
             ('Shape', 'Enum.PartType.Ball'), ('Shape', 'Enum.PartType.Cylinder'), ('formFactor', 'Enum.FormFactor.Plate'),
             ('Material', 'Enum.Material.Wood'), ('Velocity', V3), ('RotVelocity', V3), ('Elasticity', '0.9'), ('Friction', '0.1')]
    + [(s + 'Surface', 'Enum.SurfaceType.' + t) for s in ('Top', 'Bottom', 'Front', 'Back', 'Left', 'Right')
       for t in ('Smooth', 'Glue', 'Weld', 'Studs', 'Inlet', 'Universal', 'Hinge', 'Motor', 'SteppingMotor')],
    setup=P)
add('Seat', [('Size', V3), ('Color', C3), ('Disabled', 'true')], setup=P.replace('"Part"', '"Seat"'))
add('SpawnLocation', [('Size', V3), ('Neutral', 'false'), ('TeamColor', 'BrickColor.new(21)')], setup=P.replace('"Part"', '"SpawnLocation"'))
add('Model', [('Name', '"M"'), ('PrimaryPart', 'nil')])
for c, v in (('IntValue', '5'), ('NumberValue', '2.5'), ('StringValue', '"hi"'), ('BoolValue', 'true'), ('Vector3Value', V3),
             ('CFrameValue', CF), ('Color3Value', C3), ('BrickColorValue', 'BrickColor.new(21)'), ('ObjectValue', 'workspace')):
    add(c, [('Value', v), ('Name', '"V"')])
add('Decal', [('Texture', '"rbxasset://textures/face.png"'), ('Face', 'Enum.NormalId.Front'), ('Transparency', '0.5')], setup=P + 'local d=o o=Instance.new("Decal") o.Parent=d ')
add('Texture', [('Texture', '"rbxasset://textures/face.png"'), ('Face', 'Enum.NormalId.Top'), ('StudsPerTileU', '4')], setup=P + 'local d=o o=Instance.new("Texture") o.Parent=d ')
add('SpecialMesh', [('MeshType', 'Enum.MeshType.Sphere'), ('MeshType', 'Enum.MeshType.Head'), ('MeshType', 'Enum.MeshType.Brick'),
                    ('MeshType', 'Enum.MeshType.Wedge'), ('MeshType', 'Enum.MeshType.Torso'), ('MeshType', 'Enum.MeshType.FileMesh'),
                    ('Scale', V3), ('MeshId', '"rbxasset://fonts/sword.mesh"'), ('TextureId', '"rbxasset://textures/SwordTexture.png"')],
    setup=P + 'local d=o o=Instance.new("SpecialMesh") o.Parent=d ')
add('BlockMesh', [('Scale', V3)], setup=P + 'local d=o o=Instance.new("BlockMesh") o.Parent=d ')
add('CylinderMesh', [('Scale', V3)], setup=P + 'local d=o o=Instance.new("CylinderMesh") o.Parent=d ')
add('Fire', [('Size', '5'), ('Heat', '9'), ('Color', C3), ('SecondaryColor', C3), ('Enabled', 'false')], setup=P + 'local d=o o=Instance.new("Fire") o.Parent=d ')
add('Smoke', [('Size', '5'), ('Opacity', '0.5'), ('RiseVelocity', '3'), ('Color', C3)], setup=P + 'local d=o o=Instance.new("Smoke") o.Parent=d ')
add('Sparkles', [('SparkleColor', C3), ('Enabled', 'false')], setup=P + 'local d=o o=Instance.new("Sparkles") o.Parent=d ')
add('Explosion', [('BlastRadius', '2'), ('BlastPressure', '10'), ('Position', V3)])
add('Message', [('Text', '"hello"')])
add('Hint', [('Text', '"hello"')])
add('Sound', [('SoundId', '"rbxasset://sounds/uuhhh.wav"'), ('Volume', '0.3'), ('Pitch', '1.5'), ('Looped', 'true')])
add('ClickDetector', [('MaxActivationDistance', '10')], setup=P + 'local d=o o=Instance.new("ClickDetector") o.Parent=d ')
add('BodyVelocity', [('velocity', V3), ('maxForce', V3), ('P', '500')], setup=P.replace('o.Anchored=true', 'o.Anchored=false') + 'local d=o o=Instance.new("BodyVelocity") o.Parent=d ')
add('BodyPosition', [('position', V3), ('maxForce', V3), ('D', '100')], setup=P.replace('o.Anchored=true', 'o.Anchored=false') + 'local d=o o=Instance.new("BodyPosition") o.Parent=d ')
add('BodyGyro', [('cframe', CF), ('maxTorque', V3)], setup=P.replace('o.Anchored=true', 'o.Anchored=false') + 'local d=o o=Instance.new("BodyGyro") o.Parent=d ')
add('BodyForce', [('force', V3)], setup=P.replace('o.Anchored=true', 'o.Anchored=false') + 'local d=o o=Instance.new("BodyForce") o.Parent=d ')
add('BodyThrust', [('force', V3), ('location', V3)], setup=P.replace('o.Anchored=true', 'o.Anchored=false') + 'local d=o o=Instance.new("BodyThrust") o.Parent=d ')
add('BodyAngularVelocity', [('angularvelocity', V3), ('maxTorque', V3)], setup=P.replace('o.Anchored=true', 'o.Anchored=false') + 'local d=o o=Instance.new("BodyAngularVelocity") o.Parent=d ')
add('Humanoid', [('Health', '50'), ('MaxHealth', '200'), ('WalkSpeed', '30'), ('Jump', 'true'), ('Sit', 'true')], setup='local m=Instance.new("Model") m.Parent=workspace local o=Instance.new("Humanoid") o.Parent=m ')
add('Tool', [('GripPos', V3), ('Enabled', 'false'), ('TextureId', '"rbxasset://textures/face.png"')], parent='game.StarterPack')
add('HopperBin', [('BinType', 'Enum.BinType.Hammer'), ('BinType', 'Enum.BinType.Clone')], parent='game.StarterPack')
add('Script', [('Source', '"local x=1"'), ('Disabled', 'true'), ('Name', '"S"')])
add('LocalScript', [('Source', '"local x=1"'), ('Disabled', 'true')], parent='game.StarterPack')
add('Weld', [('C0', CF), ('C1', CF)], setup=P + 'local q=Instance.new("Part") q.Parent=workspace o=Instance.new("Weld") o.Part0=q o.Part1=workspace:FindFirstChild("Part") o.Parent=q ')
add('Lighting', [('TimeOfDay', '"06:00:00"'), ('TimeOfDay', '"14:30:00"'), ('Brightness', '2'), ('Ambient', C3), ('ShadowColor', C3),
                 ('ColorShift_Top', C3), ('ColorShift_Bottom', C3), ('GeographicLatitude', '10'), ('TopAmbientV9', C3),
                 ('BottomAmbientV9', C3), ('SpotLightV9', C3)], setup='local o=game.Lighting ')
add('Sky', [('SkyboxBk', '"rbxasset://textures/sky/null_plainsky512_bk.jpg"'), ('StarCount', '100'), ('CelestialBodiesShown', 'false')], parent='game.Lighting')
add('Workspace', [('Name', '"Workspace"'), ('CurrentCamera', 'workspace.CurrentCamera')], setup='local o=workspace ')
add('Camera', [('CoordinateFrame', CF), ('Focus', CF), ('FieldOfView', '50'), ('CameraType', 'Enum.CameraType.Fixed')], setup='local o=workspace.CurrentCamera ')
add('Players', [('MaxPlayers', '10')], setup='local o=game.Players ')
add('Team', [('TeamColor', 'BrickColor.new(21)'), ('Name', '"T"')], parent='game:GetService("Teams")')
add('Flag', [('TeamColor', 'BrickColor.new(21)')], setup='local o=Instance.new("Flag") local h=Instance.new("Part") h.Name="Handle" h.Parent=o o.Parent=workspace ')
add('Shirt', [('ShirtTemplate', '"rbxasset://textures/face.png"')])
add('Pants', [('PantsTemplate', '"rbxasset://textures/face.png"')])
add('ShirtGraphic', [('Graphic', '"rbxasset://textures/face.png"')])
add('BodyColors', [('HeadColor', 'BrickColor.new(21)'), ('TorsoColor', 'BrickColor.new(21)')])
add('Hat', [('AttachmentPos', V3)])
add('ForceField', [('Name', '"FF"')], setup=P + 'local d=o o=Instance.new("ForceField") o.Parent=d ')
add('Selection', [('Name', '"Sel"')], setup='local o=game:GetService("Selection") ')

if '--only' in a:
    want = set(a[a.index('--only') + 1].split(','))
    CASES = [c for c in CASES if c[0] in want]


def lua(cases):
    body = ' '.join('pcall(function() %s %s end)' % (s, x) for _, s, x in cases)
    return body + ' wait(3) local v=Instance.new("StringValue") v.Name="PSDONE" v.Parent=workspace'


def survives(exe, cases, secs=22):
    ieclean.clean()
    p = subprocess.Popen([exe, '-script', lua(cases)], cwd=os.path.dirname(exe))
    t0 = time.time()
    while time.time() - t0 < secs and p.poll() is None:
        time.sleep(0.5)
    rc = p.poll()
    if rc is None:
        p.kill(); p.wait()
        return True, None
    return False, '0x%08X' % (rc & 0xFFFFFFFF)


def bisect(exe, cases, out, depth=0):
    ok, rc = survives(exe, cases)
    print('  ' * depth + '%-3d cases %s' % (len(cases), 'ok' if ok else 'CRASH ' + rc), flush=True)
    if ok:
        return
    if len(cases) == 1:
        out.append((cases[0][0], rc)); return
    m = len(cases) // 2
    bisect(exe, cases[:m], out, depth + 1); bisect(exe, cases[m:], out, depth + 1)


G = 12
crash = []
for i in range(0, len(CASES), G):
    bisect(EXE, CASES[i:i + G], crash)
orig = []
if '--orig' not in a:
    for name, _ in crash:
        ok, rc = survives(ORIG, [c for c in CASES if c[0] == name][:1])
        if not ok:
            orig.append(name)
res = {'exe': EXE, 'cases': len(CASES), 'crash': crash, 'orig_crash': orig}
(H / 'auto/propsweep.json').write_text(json.dumps(res, indent=1))
print('cases %d, crashing %d (%s), also crash orig: %s' % (len(CASES), len(crash), ', '.join(n for n, _ in crash), orig))
