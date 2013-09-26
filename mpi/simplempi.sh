#!/bin/bash
#PBS -N task_grid1mpiavm
#PBS -o simplempitxt.out
#PBS -e simplempitxt.err
#PBS -l nodes=1:ppn=4
date
mpirun /home/localusers/da82/da8206/grid1/simplempi.out
date