# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# User specific aliases and functions

PATH=$PATH:/opt/torque/bin

export  PVM_ROOT=$HOME/pvm3
export PVM_ARCH=LINUX64
export PATH=$PATH:$PVM_ROOT/lib
