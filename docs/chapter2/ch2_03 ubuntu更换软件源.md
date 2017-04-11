# ubuntu 下更新软件源

## 编辑 `/etc/apt/source.list`

```shell
$ cd /etc/apt/
$ sudo vi source.list
```
做好备份`sudo cp source.list source.list.bak`，并且在该文件中直接加入软件源。

```
deb https://mirrors.ustc.edu.cn/ubuntu/ xenial main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ xenial main restricted universe multiverse

deb https://mirrors.ustc.edu.cn/ubuntu/ xenial-security main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ xenial-security main restricted universe multiverse

deb https://mirrors.ustc.edu.cn/ubuntu/ xenial-updates main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ xenial-updates main restricted universe multiverse

deb https://mirrors.ustc.edu.cn/ubuntu/ xenial-backports main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ xenial-backports main restricted universe multiverse
```

## 更新

```shell
$ sudo apt-get update  
```
[中科大 ubuntu 16.04的源列表](https://mirrors.ustc.edu.cn/repogen/)
