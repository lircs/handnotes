#  \[TIPS\] error: implicit declaration of function 'class\_create'

---

编译驱动时提示如下错误：

内核版本：linux-2..6.25.8

![](/images/chapter3/error_1.png)

查阅资料资料得知，这个可能是由于内核版本升级，新版的API对早期的API不一致导致的，但是具体从哪个版本开始的，说法不一，有说是从linux-2.6.29.x 开始的，有的说是从linux-2.6.30.x开始的。发现都不是我所使用的版本。

而相关的

`class_create` 、`class_device_create`  、`class_device_unregister`  、`class_destroy`

函数原型在

`/include/linux/device.h` 文件中，

在该目录中，我们找到如下的代码：

![](/images/chapter3/code_1.png)

可见问题并不是出在内核API上面，或者说在这个版本linux-2.6.25.8 中上述的写法仍然可以使用，那么问题出在哪儿呢，仔细检查发现，应该还要包含该头文件路径。

```
#include <linux/device.h>
```

然后，编译顺利通过 。

![](/images/chapter3/images_1.png)

