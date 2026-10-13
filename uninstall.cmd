@echo off
setlocal
cd /d "%~dp0"
title RoConstruct uninstall
py -3.12 roc.py uninstall %*
pause
