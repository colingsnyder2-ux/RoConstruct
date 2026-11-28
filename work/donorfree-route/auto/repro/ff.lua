local pass, fail = 0, {}
local function rec(name, ok)
    if ok then pass = pass + 1 else table.insert(fail, name) end
end
local function flush(tag)
    local v = workspace:FindFirstChild("R6_OUT")
    if not v then v = Instance.new("StringValue"); v.Parent = workspace end
    v.Name = tag .. " pass=" .. pass .. " fail=" .. table.concat(fail, ",")
end

local errOk = pcall(function() error("intentional test error") end)
rec("error_pcall", not errOk)

local m = Instance.new("Model")
m.Name = "GroupTest"
local p1 = Instance.new("Part"); p1.Name = "P1"; p1.Size = Vector3.new(4,1,4); p1.Position = Vector3.new(0,10,0); p1.Anchored = false; p1.Parent = m
local p2 = Instance.new("Part"); p2.Name = "P2"; p2.Size = Vector3.new(4,1,4); p2.Position = Vector3.new(0,11.2,0); p2.Anchored = false; p2.Parent = m
m.Parent = workspace
m:MakeJoints()
m:MoveTo(Vector3.new(10, 15, 0))
local mClone = m:Clone()
mClone.Name = "GroupClone"
mClone.Parent = workspace
rec("model_group_clone", #mClone:GetChildren() == 2)
m:BreakJoints()

local bpPart = Instance.new("Part"); bpPart.Name = "BodyPart"; bpPart.Position = Vector3.new(-10, 10, 0); bpPart.Anchored = false; bpPart.Parent = workspace
local bv = Instance.new("BodyVelocity"); bv.velocity = Vector3.new(0, 5, 0); bv.Parent = bpPart
local bp = Instance.new("BodyPosition"); bp.position = Vector3.new(-10, 20, 0); bp.Parent = bpPart
local bg = Instance.new("BodyGyro"); bg.cframe = CFrame.new(0, 0, 0); bg.Parent = bpPart
rec("body_movers", bv.Parent == bpPart and bp.Parent == bpPart and bg.Parent == bpPart)

local hPart = Instance.new("Part"); hPart.Name = "HingePart"; hPart.TopSurface = Enum.SurfaceType.Hinge; hPart.BottomSurface = Enum.SurfaceType.Motor; hPart.Anchored = true; hPart.Parent = workspace
rec("hinge_motor_surface", hPart.TopSurface == Enum.SurfaceType.Hinge and hPart.BottomSurface == Enum.SurfaceType.Motor)

local msg = Instance.new("Message"); msg.Text = "TestMsg"; msg.Parent = workspace
local hint = Instance.new("Hint"); hint.Text = "TestHint"; hint.Parent = workspace
local snd = Instance.new("Sound"); snd.SoundId = "rbxasset://sounds/uuhhh.wav"; snd.Looped = false; snd.Volume = 0.5; snd.Parent = workspace
pcall(function() snd:Play() end)
local dec = Instance.new("Decal"); dec.Face = Enum.NormalId.Top; dec.Texture = "rbxasset://textures/face.png"; dec.Parent = hPart
local tex = Instance.new("Texture"); tex.Face = Enum.NormalId.Front; tex.Texture = "rbxasset://textures/face.png"; tex.Parent = hPart
local sky = Instance.new("Sky"); sky.Parent = game.Lighting
game.Lighting.TimeOfDay = "14:30:00"
game.Lighting.Brightness = 1.5
game.Lighting.Ambient = Color3.new(0.4, 0.4, 0.4)
rec("lighting_sky_media", game.Lighting.Brightness == 1.5 and sky.Parent == game.Lighting and dec.Parent == hPart and tex.Parent == hPart)

local tool = Instance.new("Tool"); tool.Name = "TestTool"
local handle = Instance.new("Part"); handle.Name = "Handle"; handle.Size = Vector3.new(1,1,1); handle.Parent = tool
local ls = Instance.new("LocalScript"); ls.Name = "TestLS"; ls.Source = "local x = 1 + 1"; ls.Parent = tool
tool.Parent = game.StarterPack
local sp = Instance.new("SpawnLocation"); sp.Position = Vector3.new(0, 2, 0); sp.Anchored = true; sp.Parent = workspace

local okP, plr = pcall(function() return game.Players:createLocalPlayer(0) end)
if okP and plr then
    pcall(function() plr:LoadCharacter() end)
end
rec("tool_and_solo_setup", tool.Parent == game.StarterPack and (plr ~= nil))
flush("R6")
wait(2)
flush("R7a")
local okStop, errStop = pcall(function() snd:Stop() end)
flush("R7b")
local okMsg, errMsg = pcall(function() msg:Remove() end)
flush("R7c")
local okHint, errHint = pcall(function() hint:Remove() end)
flush("R7d")
rec("sound_stop", okStop)
rec("message_remove", okMsg)
rec("hint_remove", okHint)
rec("all_survived", true)
flush("R7")
