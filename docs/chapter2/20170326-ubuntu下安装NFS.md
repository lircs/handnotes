# ubuntu 下安装nfs #

     $ sudo apt-get install nfs-kernel-server`

配置nfs

修改`/etc/exports`里的内容，在文件最后加入nfs文件夹的路径及权限，

    /work/nfs_root/first_nfs  *(rw,sync,no_root_squash)

*：允许所有的网段访问，也可以使用具体的IP

rw：挂接此目录的客户端对该共享目录具有读写权限

sync：资料同步写入内存和硬盘

no_root_squash：root用户具有对根目录的完全管理访问权限

启动nfs

    $ sudo /etc/init.d/nfs-kernel-server start

停止nfs

    $ sudo /etc/init.d/nfs-kernel-server stop



