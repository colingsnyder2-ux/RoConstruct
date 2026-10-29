import os
from pathlib import Path
import shutil
import subprocess
import sys

import pytest


@pytest.mark.skipif(sys.platform != 'win32', reason='Windows launcher required')
@pytest.mark.parametrize('code', [0, 7])
def test_windows_launcher_preserves_python_exit_code(tmp_path, code):
    launcher = tmp_path / 'roc.cmd'
    shutil.copyfile(Path(__file__).resolve().parents[1] / 'roc.cmd', launcher)
    (tmp_path / 'roc.py').write_text('raise SystemExit(%d)\n' % code)
    for module in ('pefile', 'capstone'):
        (tmp_path / (module + '.py')).write_text('')
    result = subprocess.run([os.environ['COMSPEC'], '/d', '/c', str(launcher), 'test'], capture_output=True)
    assert result.returncode == code


@pytest.mark.skipif(sys.platform != 'win32' or sys.version_info[:2] != (3, 12), reason='Windows Python 3.12 required')
@pytest.mark.parametrize('installer', [False, True])
def test_working_python_with_broken_py_launcher(tmp_path, installer):
    import json
    root = Path(__file__).resolve().parents[1]
    for filename in ('roc.cmd', 'install.cmd'):
        shutil.copyfile(root / filename, tmp_path / filename)
    # where.exe rejects Python options, simulating an unusable launcher. A winget
    # shim also keeps a regressed installer from downloading anything during this test.
    for name in ('py.exe', 'winget.exe'):
        shutil.copyfile(Path(os.environ['SystemRoot']) / 'System32/where.exe', tmp_path / name)
    env = dict(os.environ, PATH=str(tmp_path) + os.pathsep + str(Path(sys.executable).parent) + os.pathsep + os.environ['PATH'],
               PYTHONHOME=sys.prefix, ROC_NONINTERACTIVE='1', PIP_NO_INDEX='1')
    env.pop('ROC_UPDATED', None)
    broken = subprocess.run([str(tmp_path / 'py.exe'), '-3.12', '--version'], env=env, capture_output=True)
    assert broken.returncode != 0
    (tmp_path / 'roc.py').write_text(
        'import json,sys\nfrom pathlib import Path\n'
        'with Path("calls.jsonl").open("a") as f: f.write(json.dumps(sys.argv[1:])+"\\n")\n')
    (tmp_path / 'roconstruct-package.json').write_text('{}')
    cmd = ['install.cmd'] if installer else ['roc.cmd', 'native-try', '--help']
    result = subprocess.run([os.environ['COMSPEC'], '/d', '/c', *cmd], cwd=tmp_path,
                            env=env, capture_output=True, text=True, timeout=60)
    assert result.returncode == 0, result.stdout + result.stderr
    calls = [json.loads(line) for line in (tmp_path / 'calls.jsonl').read_text().splitlines()]
    assert ['update'] not in calls
    assert calls == [['install', '--yes'], ['link', 'install'], ['doctor']] if installer else calls == [['native-try', '--help']]
