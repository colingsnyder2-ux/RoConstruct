@echo off
setlocal
cd /d "%~dp0"
title RoConstruct API keys
py -3.12 roc.py provider setup
pause
