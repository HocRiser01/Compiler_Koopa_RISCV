# 东北重工业：SysY编译器设计

- 参与者：胡剑铮，衣然，郭冠男

## 一些约定

### 结构树管理器 `ObjTree`

- 在 `ObjTree` 名字空间中定义了通用的树结构管理器
- 树结构管理器负责管理抽象语法树以及中间代码的内存表示
- 例如我们可以用如下的方法创建一棵树

```cpp
#include ".../ObjTree/ObjManager.h" // 树结构管理器

using namespace ObjTree;

ObjManager obj_manager; // 创建树形结构管理器

ObjUuid a = obj_manager.get_uuid(); // 创建节点 A
obj_manager.set_info(a, "A");
obj_manager.set_type(a, "AstNode1");

ObjUuid b = obj_manager.get_uuid(); // 创建节点 B
obj_manager.set_info(b, "B");
obj_manager.set_type(b, "AstNode2");

ObjUuid c = obj_manager.get_uuid(); //创建节点 C
obj_manager.set_info(c, "C");
obj_manager.set_type(c, "AstNode3");

// A -> {B, C}
obj_manager.add_son(a, {b, c}); // 节点 A 的儿子是 B 和 C (有序)
```

### 引用自定义头文件

- 所有自定义头文件应该以 **相对路径** 的方式被引用
- **相对路径** 是指相对于当前源代码文件 (`.cpp` 文件) 所在目录的路径
- 例如
    - 文件夹 `RootFolder` 下有两个文件夹： `FolderA` 与 `FolderB`
    - 文件夹 `FolderA` 下有两个文件：`A.h` 与 `A.cpp`
    - 文件夹 `FolderB` 下有两个文件：`B.h` 与 `B.cpp`
    - 那么当 `A.cpp` 中想要引用 `B.h` 时应该使用如下代码：

```cpp
#include "../FolderB/B.h"
```

### 错误检查 `ErrorMessage.h`

- 在程序运行过程中进行必要的错误检查，当程序遇到了不可纠正的错误时，退出程序
- 例如：当文件 output_file 无法打开时，程序无法进行下去，此时需要编写如下代码检验

```cpp
#include ".../ErrorMessage.h" // 以相对路径方式引用 ErrorMessage.h

// ... 前驱代码 ...

FILE* fpout = fopen(output_file, "w");

// 检查 fpout 是否非零，如果为零输出错误信息并退出程序
die_if_error(fpout, make_error_message("output file can not open"));

// ... 后续代码 ...
```
- 上文代码中的 `die_if_error` 与 `make_error_message` 均在 `ErrorMessage.h` 中定义
- **不建议** 输出长度超过一千个字节的错误信息
