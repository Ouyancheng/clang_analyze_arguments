//
//  main.cpp
//  libclang-analyze
//
//  Created by 区彦成 on 2018-02-02.
//  Copyright © 2018 区彦成. All rights reserved.
//

#include <iostream>
#include <clang-c/Index.h>
using namespace std;
ostream & operator << (ostream &os, const CXString &str) {
    os << clang_getCString(str);
    clang_disposeString(str);
    return os;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    // std::cout << "Hello, World!\n";
    CXIndex index = clang_createIndex(0, 0);
    CXTranslationUnit unit = clang_parseTranslationUnit(index,
                                                        "/Volumes/Data/Workspaces/CPPWORKSPACE/libclang-analyze/source.cpp",
                                                        nullptr, 0, nullptr, 0,
                                                        CXTranslationUnit_None);
    if (!unit) {
        fprintf(stderr, "Error opening file");
        return -1;
    }
    cout << "Success!" << endl;
    CXCursor cursor = clang_getTranslationUnitCursor(unit);
    clang_visitChildren(cursor,
                        [](CXCursor c, CXCursor parent, CXClientData clientdata){
                            cout << "Cursor: " << clang_getCursorSpelling(c)
                            << " Kind: " << clang_getCursorKindSpelling(clang_getCursorKind(c)) << endl;
                            if (clang_getCursorKind(c) == CXCursor_CXXMethod) {
                                cout << "Hello method" << endl;
                                cout << clang_getCursorSpelling(clang_Cursor_getArgument(c, 0)) << endl;
                            }
                            return CXChildVisit_Recurse;
                            
                        },
                        nullptr);
    
    clang_disposeTranslationUnit(unit);
    clang_disposeIndex(index);
    return 0;
}
