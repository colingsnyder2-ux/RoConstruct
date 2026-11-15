import importlib.util
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch


spec=importlib.util.spec_from_file_location('luna_cli_entry',Path(__file__).resolve().parents[1]/'roc.py')
cli=importlib.util.module_from_spec(spec)
spec.loader.exec_module(cli)


def test_luna_entry_reuses_tool_agent_engine_with_fifteen_workers():
    args=SimpleNamespace(workers=15,compile_workers=3,agent_minutes=4,agent_checks=6,
        max_cloud_requests=1,agent_tasks=None,user=None,server='http://127.0.0.2:8765')
    with patch.object(cli,'main') as dispatch:
        cli.cmd_luna_workers(args)
    argv=dispatch.call_args.args[0]
    assert argv[0]=='integrator'
    for flag,value in (('--generation','agent'),('--model','codex:gpt-6-luna'),
                       ('--reasoning-effort','medium'),('--workers','15'),('--compile-workers','3'),
                       ('--max-cloud-requests','1'),('--server',args.server)):
        assert argv[argv.index(flag)+1]==value
    assert '--allow-cloud' in argv and '--no-agent-submit' in argv
    assert '--source-recovery-only' in argv


def test_luna_entry_resolves_manifest_before_private_workspace(tmp_path, monkeypatch):
    monkeypatch.chdir(tmp_path)
    args=SimpleNamespace(workers=5,compile_workers=3,agent_minutes=15,agent_checks=20,
        max_cloud_requests=5,agent_tasks='local/tasks.json',user=None,server=None)
    with patch.object(cli,'main') as dispatch:
        cli.cmd_luna_workers(args)
    argv=dispatch.call_args.args[0]
    assert argv[argv.index('--agent-tasks')+1] == str(tmp_path/'local/tasks.json')
