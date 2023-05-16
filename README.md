# Godot4 With C++

> VSCODE C++环境配置；
>
> Godot使用C++编写脚本；

版本：Godot_v4.0.1-stable_win64、Python3.10.2、Scones4.5.2、MinGW8.1.0

[示例源码](https://github.com/aguoxing/godot-cpp-example)

## 安装C++编译器

三大常见编译器GCC，Clang，MSVC，这里以GCC为例

安装[MinGW](https://www.mingw-w64.org/downloads/)，[下载地址](https://sourceforge.net/projects/mingw-w64/files/)

找到`MinGW-W64 GCC-8.1.0`，选择`x86_64-win32-seh`，

各版本区别参考 [^版本区别]

下载完解压，配置环境变量

系统变量下新建 变量名：`MINGW_HOME`，变量值：解压后的MinGw路径，比如`D:\devEnv\x86_64-8.1.0-release-win32-seh-rt_v6-rev0\mingw64`

`Path`编辑，新增 `%MINGW_HOME%\bin`

打开cmd，` gcc --version` 显示版本号则配置完成

## VSCode配置

安装`C/C++`扩展，带`Microsoft`蓝标的那个

新建个cpp项目，gdextension

在gdextension/src目录下新建个hello.cpp文件

```cpp
#include <iostream>
using namespace std;

int main() {
	cout<< "hello cpp "<<endl;
	return 0;
}
```

### 配置编译器

`Ctrl+Shift+P`快捷键调出命令面板，选择`C/C++:编辑配置(UI)`或`C/C++:Edit Configurations(UI)`

打开后的界面可以设置`编译器路径`、`IntelliSense 模式`、`C++ 标准`等，同时在`.vscode`文件夹下生成了`c_cpp_properties.json`文件

```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "compilerPath": "D:/devEnv/x86_64-8.1.0-release-win32-seh-rt_v6-rev0/mingw64/bin/gcc.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "gcc-x64"
        }
    ],
    "version": 4
}
```

### 配置构建任务

同样是`Ctrl+Shift+P`快捷键，输入`tasks`，选择`任务: 配置默认测试任务 `或`Tasks:Configure Default Build Task`，选择`C/C++: g++.exe build active file`，如果没有这个选项可以先运行下之前写的hello.cpp文件，项目路径下`g++ .\src\hello.cpp`

`.vscode`文件夹下生成了`tasks.json`文件

```json
{
  // See https://go.microsoft.com/fwlink/?LinkId=733558
  // for the documentation about the tasks.json format
  "version": "2.0.0",
  "tasks": [
    {
      "type": "shell",
      "label": "g++.exe build active file",
      "command": "D:/devEnv/x86_64-8.1.0-release-win32-seh-rt_v6-rev0/mingw64/bin/g++.exe",
      "args": [
        "-fdiagnostics-color=always",
        "-g",
        "${file}",
        "-o",
        "${fileDirname}\\${fileBasenameNoExtension}.exe"
      ],
      "options": {
        "cwd": "D:/devEnv/x86_64-8.1.0-release-win32-seh-rt_v6-rev0/mingw64/bin"
      },
      "problemMatcher": ["$gcc"],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "detail": "编译器: D:/devEnv/x86_64-8.1.0-release-win32-seh-rt_v6-rev0/mingw64/bin/g++.exe"
    }
  ]
}
```

### 配置调试

点击菜单栏，`运行R/启动调试F11`，`.vscode`文件夹下生成`launch.json`文件，打开后右下角有添加配置的按钮，或者直接copy下面的

```json
{
  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
  "version": "0.2.0",
  "configurations": [
    {
      "name": "(gdb) Launch",
      "preLaunchTask": "g++.exe build active file", //调试前执行的任务，就是之前配置的tasks.json中的label字段
      "type": "cppdbg", //配置类型，只能为cppdbg
      "request": "launch", //请求配置类型，可以为launch（启动）或attach（附加）
      "program": "${fileDirname}\\${fileBasenameNoExtension}.exe", //调试程序的路径名称
      "args": [], //调试传递参数
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": true, //true显示外置的控制台窗口，false显示内置终端
      "MIMode": "gdb",
      "miDebuggerPath": "D:/devEnv/x86_64-8.1.0-release-win32-seh-rt_v6-rev0/mingw64/bin/gdb.exe",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ]
    }
  ]
}
```

至此，vscode`1.78.2`中c++环境配置完成

## Godot

1、下载[godot](https://github.com/godotengine/godot/releases)，Windows下选`Godot_v4.0.X-stable_win64.exe.zip`版本

2、clone `godot-cpp`，`git clone https://github.com/godotengine/godot-cpp.git`

3、新建godot项目`godot-cpp-example`，把之前建的`gdextension`项目放到godot项目根目录下，同时把clone的`godot-cpp`官方模板放到`gdextension`文件夹下，并在`.vscode`的`c_cpp_properties.json`includePath中加上刚刚的`godot-cpp`路径

```json
{
  "configurations": [
    {
      "name": "Win32",
      "includePath": [
        "${workspaceFolder}/**",
        "${workspaceFolder}/src/**",
        "${workspaceFolder}/godot-cpp/**" // 把克隆的官方模板加到项目根路径下
      ],
      "defines": ["_DEBUG", "UNICODE", "_UNICODE"],
      "compilerPath": "D:/devEnv/x86_64-8.1.0-release-win32-seh-rt_v6-rev0/mingw64/bin/gcc.exe",
      "cStandard": "c17",
      "cppStandard": "c++17",
      "intelliSenseMode": "gcc-x64"
    }
  ],
  "version": 4
}
```

此时整个目录结构如下，src路径下的文件可以参考godot-cpp下的test文件夹，里面有完整的使用示例

```
godot-cpp-example
--gdextension
	--godot-cpp // clone的官方模板
	--src // 新建的写cpp的路径
		--hello.cpp
		--hello.h
		--register_types.cpp
		--register_types.h
	--SConstruct 
```

4.编译写好的cpp项目，再此之前，需要有python3的环境，并且安装了[scons](https://scons.org/pages/download.html)，在cpp-example根目录下输入`scons`，等待编译完成

最后提示`scons: done building targets.`表示编译成功

godot-cpp-example项目根目录下，将生成的dll文件放到的bin文件夹，配置`hello.gdextension`

```
[configuration]

entry_symbol = "hello_library_init" // 对应cpp项目中的register_types.cpp文件中的 GDE_EXPORT hello_library_init 名称

[libraries]

windows.debug.x86_64 = "res://bin/libgdexample.windows.template_debug.x86_64.dll" // 生成的动态库路径
```

5.打开之前新建好的godot项目`godot-cpp-example`，此时新建节点时将可以看到之前创建的hello类，可以像其他节点一样使用，也可以在gd脚本中直接调用

## 参考

[^版本区别]: [MinGW gcc下载链接及sjlj、dwarf、seh异同以及gcc安装](https://blog.csdn.net/AMDDMA/article/details/111600238)

[Godot引擎如何用C++编写脚本？](https://www.zhihu.com/question/561675567?write)

[VSCode配置C/C++环境](https://zhuanlan.zhihu.com/p/87864677)

[Godot文档](https://docs.godotengine.org/zh_CN/stable/development/cpp/custom_modules_in_cpp.html)

