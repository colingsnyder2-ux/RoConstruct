local function report(tag, pass)
    local v = Instance.new("StringValue")
    v.Name = tag .. " pass=" .. tostring(pass) .. " fail="
    v.Parent = workspace
end
report("R1", 0)
wait(2)
report("R2", 1)
wait()
report("R3", 2)
