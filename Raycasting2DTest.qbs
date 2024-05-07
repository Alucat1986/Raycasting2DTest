CppApplication {
    files: [
        "main.cpp"
    ]
    name: "Raycasting2D"

    Depends { name: "cpp" }
    Depends { name: "sfml-all" }

    cpp.cxxLanguageVersion: "c++20"
    cpp.warningLevel: "all"
}