CppApplication {
    files: [
        "main.cpp",
        "src/randomConvexShape.cpp",
        "include/randomConvexShape.hpp"
    ]
    name: "Raycasting2D"

    Depends { name: "cpp" }
    Depends { name: "sfml-all" }

    cpp.cxxLanguageVersion: "c++20"
    cpp.includePaths: {"include","src"}
    cpp.warningLevel: "all"
}