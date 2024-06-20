#!/bin/bash

# 获取进程 ID
pid=$1

# 读取进程的 CPU 时间数据
utime=$(awk '{print $14}' /proc/"$pid"/stat)
stime=$(awk '{print $15}' /proc/"$pid"/stat)
cutime=$(awk '{print $16}' /proc/"$pid"/stat)
cstime=$(awk '{print $17}' /proc/"$pid"/stat)

# 获取系统的 CPU 时间总数
cpu_total_time=$(grep '^cpu ' /proc/stat | awk '{print $2+$3+$4+$5+$6+$7+$8}')

# 计算进程的 CPU 时间总数
process_total_time=$((utime+stime+cutime+cstime))

# 计算进程的 CPU 利用率
cpu_usage=$(echo "scale=2;100*$process_total_time/$cpu_total_time" | bc)

echo "PID: $pid, CPU Usage: $cpu_usage%"