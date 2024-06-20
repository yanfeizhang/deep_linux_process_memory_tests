#!/bin/bash

TIME_INTERVAL=10 # 获取10秒的平均CPU利用率

function is_cgroup_v2(){
	hierarchy=`cat /proc/cgroups | grep cpuacct | awk '{print $2}'`
	if [ $hierarchy -eq 0 ]; then
		IS_CGROUP_V2=true
  	else
  	  	IS_CGROUP_V2=false
  	fi
  	echo "IS_CGROUP_V2:${IS_CGROUP_V2}"
}

# 获取容器的 CPU 用量
# 注意：用量返回的是实际用了几个核的时间，比如 0.5 代表的是使用了 0.5 个核，而不是 50% 的核。
function get_cgroup_v1_pod_cpu_usage(){
	# 获取当前容器的 cgroup 路径 & usage 文件
	fs_usage="/sys/fs/cgroup/cpu,cpuacct"$(cat /proc/1/cgroup | grep "cpu,cpuacct" | awk -F ':' '{print $3}')"/cpuacct.usage"

	# 获取 t1 的当前时间（纳秒）和 cpu usage（纳秒）
	T1_USAGE=`cat ${fs_usage}`
	T1=`date +%s%N`
	sleep ${TIME_INTERVAL}

	# 获取 t2 的当前时间（纳秒）和 cpu usage（纳秒）
	T2_USAGE=`cat ${fs_usage}`
	T2=`date +%s%N`
	CPU_USAGE_POD=`echo ${T1_USAGE} ${T1} ${T2_USAGE} ${T2}| awk '{printf "%.5f", ($3-$1)/($4-$2)}'`
    echo "Pod CPU Usage:${CPU_USAGE_POD}"
}

# 获取容器的 CPU 用量
function get_cgroup_v2_pod_cpu_usage(){
	# 获取当前容器的 cgroup 路径
	cgroup=$(cat /proc/1/cgroup | awk -F ':' '{print $3}')
	cgroup=`echo ${cgroup%init.scope}`

	# 获取当前容器的 cpu.stat 路径
	fs_usage="/sys/fs/cgroup"$cgroup"cpu.stat"

	# 获取 t1 的当前时间（微秒）和 cpu usage（微秒）
	T1_USAGE=`cat ${fs_usage} | grep usage_usec | awk '{print $2}'`
	T1=`echo $(date +%s%N) 1000 | awk '{printf "%.2f", ($1/$2)}'`
	sleep ${TIME_INTERVAL}

	# 获取 t2 的当前时间（微秒）和 cpu usage（微秒）
	T2_USAGE=`cat ${fs_usage} | grep usage_usec | awk '{print $2}'`
	T2=`echo $(date +%s%N) 1000 | awk '{printf "%.2f", ($1/$2)}'`
	CPU_USAGE_POD=`echo ${T1_USAGE} ${T1} ${T2_USAGE} ${T2}| awk '{printf "%.5f", ($3-$1)/($4-$2)}'`
	echo "Pod CPU Usage:${CPU_USAGE_POD}"
}

# 获取当前POD cgroup版本 && 获取pod的CPU利用率
is_cgroup_v2
if [[ "$IS_CGROUP_V2" = true ]] ; then
  	get_cgroup_v2_pod_cpu_usage
else
	get_cgroup_v1_pod_cpu_usage
fi