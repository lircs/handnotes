安装tftp服务器
sudo apt-get install tftpd-hpa

安装tftp客户端
sudo apt-get install tftp-hpa

配置tftp服务器/etc/default/tftpd-hpa
sudo vim /etc/default/tftpd-hpa

重启tftp
sudo service tftpd-hpa restart

测试
# cd /home
# tftp localhost  #localhost 表示本机
tftp>get test.txt  //test.txt 是之前在 /tftpboot 目录下新建的文件
tftp>put test1.txt //test1.txt 是在 /home 目录下新建的文件
tftp>q
退出后，在/home目录下会有一个test.txt文件，在/tftpboot 目录下有test1.txt，表示tftp服务器安装成功！


完全卸载vsftpd
sudo apt-get purge vsftpd

安装vsftpd
sudo apt-get install vsftpd

配置vsftpd.cof
userlist_deny=NO
userlist_enable=YES
#允许登录的用户
userlist_file=/etc/allowed_users
seccomp_sandbox=NO
#默认ftp下载目录
local_root=/home/uftp/

local_enable=YES
#设置文件上传
write_enable=YES
#使用utf8
utf8_filesystem=YES

添加允许登录的用户
sudo vim /etc/allowed_users

停止或重启服务
sudo /etc/init.d/vsftpd start 或者 sudo service vsftpd start
sudo /etc/init.d/vsftpd stop 或者 sudo service vsftpd stop
sudo /etc/init.d/vsftpd restart 或者 sudo service vsftpd restart
