local function report(tag, pass, fail)
    local v = Instance.new("StringValue")
    v.Name = tag .. " pass=" .. tostring(pass) .. " fail=" .. tostring(fail or "")
    v.Parent = workspace
end
report("R1", 0)
local ok, elapsed = pcall(function() return wait(2) end)
report("R2", 1, "wait2_ok=" .. tostring(ok) .. "_elapsed=" .. tostring(elapsed))
local ok2, elapsed2 = pcall(function() return wait() end)
report("R3", 2, "wait0_ok=" .. tostring(ok2) .. "_elapsed=" .. tostring(elapsed2))
