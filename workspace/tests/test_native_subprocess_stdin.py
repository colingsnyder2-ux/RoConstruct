"""Real Windows startup regression: controller is actively reading its stdin pipe."""
import json
import os
from pathlib import Path
import subprocess
import sys

import pytest


@pytest.mark.skipif(os.name != 'nt', reason='Windows inherited synchronous stdin pipe blocks Python startup')
@pytest.mark.parametrize('operation', ['generator', 'verifier', 'compiler_wrapper', 'controller_shutdown'])
def test_native_child_starts_while_controller_command_reader_waits(tmp_path, operation):
    generator = tmp_path/'generator.py'
    marker = tmp_path/'result.txt'
    generator.write_text('from pathlib import Path\nPath(__file__).with_name("result.txt").write_text("proved")\n')
    script = r'''
import json,os,subprocess,sys,threading,time
from pathlib import Path
sys.path.insert(0,sys.argv[1])
os.environ['PYTHONPATH']=sys.argv[1]
from roc import integration,integration_verify,rebuild,gui_worker
folder=Path(sys.argv[2]);operation=sys.argv[3]
reader=(lambda:list(gui_worker.command_lines(sys.stdin))) if operation=='controller_shutdown' else (lambda:os.read(sys.stdin.fileno(),1))
threading.Thread(target=reader,daemon=True).start()
time.sleep(.1)
started=time.monotonic()
if operation=='controller_shutdown':
 (folder/'result.txt').write_text('proved')
elif operation=='generator':
 integration.run_generator(folder/'generator.py',folder,timeout=2)
elif operation=='verifier':
 integration_verify.tool_inventory=lambda:dict(sdk='fixture',ml='fixture',toolchain=dict(build=21022,cl=sys.executable))
 integration_verify.run(folder,['-c','from pathlib import Path; Path("result.txt").write_text("proved")'],folder/'verify.log')
else:
 rebuild.env=lambda _:dict(os.environ)
 code,text=rebuild.run({'cl':sys.executable},'cl',['-c','from pathlib import Path; Path("result.txt").write_text("proved")'],folder,timeout=2)
 assert code==0,text
print(json.dumps({'seconds':time.monotonic()-started,'result':(folder/'result.txt').read_text()}),flush=True)
'''
    process = subprocess.Popen([sys.executable,'-u','-c',script,str(Path(__file__).resolve().parents[1]),str(tmp_path),operation],
        stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,creationflags=subprocess.CREATE_NO_WINDOW)
    try:
        # Keep the control pipe open. communicate() would close it and mask the bug.
        process.wait(timeout=8)
        output = process.stdout.read().decode(errors='replace')
        assert process.returncode == 0,output
        row = json.loads(output.splitlines()[-1])
        assert row['result'] == 'proved' and marker.read_text() == 'proved'
        assert row['seconds'] < 2
    finally:
        process.stdin.close()
        if process.poll() is None:
            subprocess.run(['taskkill','/PID',str(process.pid),'/T','/F'],stdin=subprocess.DEVNULL,capture_output=True,
                           creationflags=subprocess.CREATE_NO_WINDOW)
            process.wait(timeout=5)
