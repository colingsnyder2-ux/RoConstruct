import sys, subprocess, os, time
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.argv = [sys.argv[0]]
import scripttest as st
C = ["Part","Seat","SpawnLocation","Message","Hint","Sky","Script","LocalScript","Model","IntValue","NumberValue","StringValue","BoolValue","ObjectValue","Vector3Value","Color3Value","BrickColorValue","CFrameValue","BodyVelocity","BodyPosition","BodyGyro","BodyForce","BodyAngularVelocity","BodyThrust","Explosion","Sound","Decal","Texture","Backpack","Tool","HopperBin","Humanoid","SpecialMesh","Sparkles","ForceField","ClickDetector","Team","Hole","Flag","FlagStand","Shirt","Pants","ShirtGraphic","Skin","BodyColors","Accoutrement","RocketPropulsion"]
def crash(cs):
    lua = 'for _, c in ipairs({%s}) do pcall(function() local o = Instance.new(c) o.Parent = workspace o:Remove() end) end\nlocal v = Instance.new("StringValue") v.Name = "R1 pass=1 fail=" v.Parent = workspace' % ','.join('"%s"' % c for c in cs)
    r = st.run(st.EXE, lua, wait=14)
    return '_exit' in r, r
lo = C
ok, r = crash(lo); print('all', ok, r, flush=True)
while ok and len(lo) > 1:
    a, b = lo[:len(lo)//2], lo[len(lo)//2:]
    ca, ra = crash(a); print(a, ca, flush=True)
    lo = a if ca else b
    if not ca:
        cb, rb = crash(b); print(b, cb, flush=True)
        if not cb: print('neither half alone crashes'); break
print('culprit', lo)
