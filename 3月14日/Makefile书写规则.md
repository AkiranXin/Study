
### 书写规则

#### 文件搜寻
```Makefile
VPATH = src:../headers
```
VPATH特殊变量可以在当前目录找到依赖文件和目标文件的情况下，去对应的目录下寻找

#### 伪目标(.PHONY)
```Makefile
.PHONY: clean
clean:
   -rm main $(objects)
```
这样并不会生成clean文件，而是一个标签

#### 多目标
```Makefile
bigoutput littleoutput: test.g
   generate test.g -$(subst output,,$@) > bigoutput

#等于下面这个
bigoutput: test.g
   generate test.g -big > bigoutput
littleoutput: test.g
   generate test.g -little > littleoutput

# 其中，-$(subst output,,$@)中的$表示执行一个Makefile函数，函数名为subst
```

#### 静态模式

```Makefile
<targets ...>: <target-pattern>: <prereq-patterns>
   <commands>
   ...
#  比如说：
#  <target-pattern>定义成"%.o"
#  意思是<target>集合中都是以".o"结尾的
#  <prereq-patterns>定义成"%.c"
#  则在<target-pattern>集合中形成的目标文件二次定义
#  去掉.o结尾，加上.c结尾
objects = foo.o bar.o

all: $(objects)

$(objects): %.o : %.c
   $(CC -c $(CFLAGS) $< -o $@

# 上面的例子，foo.o和bar.o被获取后，按照之前的描述，
#  则依赖目标应该是foo.c和bar.c
#  $<和$@为自动化变量
#  $<表示所有的目标依赖集 foo.c bar.c
#  $@表示目标集合 foo.o bar.o

#  上面的规则等于下面的规则
foo.o: foo.c
   $(CC -c $(CFLAGS) foo.c -o foo.o
bar.o: bar.c
   $(CC -c $(CFLAGS) bar.c -o bar.o

# 再看一个例子
files = foo.elc bar.o lose.o

$(filter %.o,$(files)): %.o: %.c
   $(CC) -c $(CFLAGS) $< -o $@
$(filter %.elc,$(files)): %.elc: %.el
   emacs -f batch-byte-compile %<
```

#### 自动生成依赖性
如果是一个比较大型的工程，你必须清楚哪些c文件包含了哪些头文件，并且在添加或删除这些头文件时，也需要小心地修改Makefile，这是一个很没有维护性地工作。
为了避免这样的事情发生，可以使用大多数c/c++编译器支持的"-M"选项，会自动寻找源文件中包含的头文件并生成一个依赖关系
比如
```bash
   cc -M main.c
   #其输出结果
   main.o: main.c defs.h
```
如果使用的是GNU的c/c++编译器，得用"-MM"参数，不然会把标准库的头文件也包含进来
```bash
   gcc -M main.c
   #其输出结果
   main.o: main.c defs.h /usr/include/stdio.h
   /usr/include/features.h \ 
      /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
   ...
```
Makefile也要根据这些源文件重新生成。
每个"name.c"的文件都要生成"name.d"的Makefile文件，[.d]文件中存放着[.c]
于是，我们可以写出[.c]和[.d]文件的依赖关系，并让make自动更新[.d]文件，并把其包含在我们的主Makefile文件里，这样就可以自动化地生成每个文件的依赖关系
```Makefile
main.o: main.c defs.h
#转换成
main.o main.d : main.c defs.h
```
这样的话，[.d]文件就会自动更新了
然后可以使用include命令来引入别的Makefile文件
```Makefile
sources = foo.c bar.c

include $(sources:.c=.d)
```