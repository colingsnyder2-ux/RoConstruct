import sys, os
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
lua = sys.argv[1]; sys.argv = [sys.argv[0]]
import scripttest as st
print(st.run(st.EXE, lua + '\nlocal v = Instance.new("StringValue") v.Name = "R1 pass=1 fail=" v.Parent = workspace', wait=14))
