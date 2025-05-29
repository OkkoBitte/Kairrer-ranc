/*

 NEW WRITE FILE

*/
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <filesystem> 
#include <string>
#include <iostream>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>

namespace file{
    void new_dir(const std::string& dirname) {

        std::filesystem::create_directory(dirname);
    
    }

    template <typename T>
    void new_file(const std::string& filename, const T& write_data) {
        std::ofstream ofa(filename);
        ofa << write_data;
        ofa.close();
    }

    template <typename T>
    T read_file(const std::string& filename) {
        std::ifstream ifa(filename);
        T read_data;
        getline(ifa, read_data, '\0');
        ifa.close();
        return read_data;
    }

    bool is_dir(const std::string& path) {
        struct stat info;
        if (stat(path.c_str(), &info) != 0) {
            return false;
        } else if (info.st_mode & S_IFDIR) {
            return true;     } else {
            return false;
        }
    }

    bool is_file(const std::string& path) {
        return std::filesystem::exists(path) && std::filesystem::is_regular_file(path);
    }
}
