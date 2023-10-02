# clientDemo
基于Linux简单实现多线程分段下载

1. centos下使用yum install libcurl-devel 下载libcurl库

2. 项目架构：
    bin：存放生成的二进制文件
    build：存放构建脚本
    src：存放源码
        protocol：协议接口，用于实现不同协议的下载操作
        task：任务接口，用于任务调度
        thread：线程类，用于调度线程



