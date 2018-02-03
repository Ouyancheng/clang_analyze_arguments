# clang_analyze_arguments

From Prof. Sarah Nadi's challenge... 

This small toy will prompt a warning if a method has more than 3 arguments. 

How to compile: 
Install libclang: on macOS, make sure your Homebrew is successfully installed, then type "brew install llvm"
If you are using other platforms or installing libclang to another path, please modify the CMakeLists.txt in libclang-analyze and set the libclang_include_path and libclang_lib_path to the corresponding locations. 
Go to libclang-analyze. 
Then type cmake . and make to generate the executable file. 
Usage: clang_analyze_arguments <file>

