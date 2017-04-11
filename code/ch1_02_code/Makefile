KERN_DIR = /work/other_board/linux-2.6.25.8/opt/EmbedSky/linux-2.6.25.8

all:
	make -C $(KERN_DIR) M=`pwd` modules 

clean:
	make -C $(KERN_DIR) M=`pwd` modules clean
	rm -rf modules.order

obj-m	+= second_drv.o
