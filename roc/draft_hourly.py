"""Bounded unattended draft improvements. This runner forbids model generation."""
import argparse
from contextlib import redirect_stderr, redirect_stdout
import json
import os
from pathlib import Path
import subprocess
import time
import uuid

from roc import draft_family_queue, draft_merger, draft_publish, draft_report, draft_source_queue, native_drafts, providers


def run_once(root, family_limit=2, source_limit=3, apply=True, publish=True):
    root = Path(root).resolve()
    if publish and not apply:
        raise ValueError('Publication requires source application')
    if not 0 <= family_limit <= 100 or not 0 <= source_limit <= 100:
        raise ValueError('Unattended work limits must be between 0 and 100')
    folder = root / 'work/draft-merger/hourly'
    folder.mkdir(parents=True, exist_ok=True)
    run = folder / uuid.uuid4().hex
    status = dict(state='running', pid=os.getpid(), started=time.time(), stages=[], models_used=0, model_attempts_blocked=0)
    saved_generate = providers.generate

    def deny_models(*args, **kwargs):
        status['model_attempts_blocked'] += 1
        raise RuntimeError('Model generation is disabled in the unattended draft runner')

    def save():
        native_drafts.atomic(run / 'status.json', status)
        native_drafts.atomic(folder / 'latest.json', status)

    def stage(name, function):
        row = dict(name=name, state='running')
        status['stages'].append(row)
        save()
        row['result'] = function()
        row['state'] = 'done'
        save()
        return row['result']

    try:
        with native_drafts.lock(folder / 'runner.lock'):
            run.mkdir()
            providers.generate = deny_models
            try:
                if (root / 'work/draft-merger/STOP_AUTO').exists():
                    status['state'] = 'disabled'
                    return status
                branch = subprocess.run(['git', '-C', str(root), 'branch', '--show-current'],
                                        capture_output=True, check=True, text=True).stdout.strip()
                if branch != draft_publish.BRANCH:
                    raise ValueError('Unattended integration requires the authorized branch')
                # Intake is synchronous; hold the real lock in this process instead
                # of leaving a detached guard that races the following stages.
                with native_drafts.lock(root / 'work/draft-integration.lock'):
                    stage('intake', lambda: draft_merger._process(root, None, True, False))
                if family_limit:
                    planned = stage('family-plan', lambda: draft_family_queue.plan(root))
                    if planned['stale']:
                        status['state'] = 'inputs-changed'
                        return status
                    measured = stage('family-work', lambda: draft_family_queue.work(root, family_limit))
                    if measured['stale']:
                        status['state'] = 'inputs-changed'
                        return status
                stage('source-discovery', lambda: draft_source_queue.discover(root))
                stage('source-work', lambda: draft_source_queue.work(root, source_limit, apply))
                if publish:
                    publication = stage('publication', lambda: draft_publish.publish(root, push=True))
                    if publication['state'] not in ('pushed', 'nothing-current-to-publish'):
                        status['publication_pending'] = publication
                stage('dispositions', lambda: draft_report.reconcile(root, run / 'dispositions.json', True))
                status['state'] = 'completed-with-publication-blocker' if status.get('publication_pending') else 'completed'
                return status
            except Exception as error:
                status.update(state='busy' if isinstance(error, RuntimeError) and str(error).startswith('Already running:')
                              else 'failed', error=type(error).__name__ + ': ' + str(error))
                if status['stages'] and status['stages'][-1]['state'] == 'running':
                    status['stages'][-1]['state'] = status['state']
                return status
            finally:
                providers.generate = saved_generate
                status['finished'] = time.time()
                save()
    except RuntimeError as error:
        if str(error).startswith('Already running:'):
            return dict(state='busy', error=str(error), models_used=0)
        raise


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--family-limit', type=int, default=2)
    parser.add_argument('--source-limit', type=int, default=3)
    parser.add_argument('--dry-run', action='store_true')
    parser.add_argument('--no-push', action='store_true')
    args = parser.parse_args()
    log = args.root / 'work/draft-merger/hourly/runner.log'
    log.parent.mkdir(parents=True, exist_ok=True)
    with log.open('a', encoding='utf-8') as stream, redirect_stdout(stream), redirect_stderr(stream):
        result = run_once(args.root, args.family_limit, args.source_limit, not args.dry_run,
                          not args.dry_run and not args.no_push)
        print(json.dumps(result, indent=2), flush=True)
    raise SystemExit(1 if result['state'] == 'failed' else 0)
